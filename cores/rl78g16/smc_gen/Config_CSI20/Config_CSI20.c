/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2021, 2024 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : Config_CSI20.c
* Component Version: 1.5.0
* Device(s)        : R5F121BCxFP
* Description      : This file implements device driver for Config_CSI20.
* Creation Date    : 
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "Config_CSI20.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
volatile uint8_t * gp_csi20_tx_address;    /* csi20 send buffer address */
volatile uint16_t g_csi20_tx_count;        /* csi20 send data count */
volatile uint8_t * gp_csi20_rx_address;    /* csi20 receive buffer address */
/* Start user code for global. Do not edit comment generated here */
volatile uint16_t g_csi20_status_flag;
uint32_t R_BSP_GetFclkFreqHz(void);
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_CSI20_Create
* Description  : This function initializes the CSI20 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_CSI20_Create(void)
{
    SPS1 &= _00F0_SAU_CK00_CLEAR;
    SPS1 |= _0000_SAU_CK00_FCLK_0;
    /* Stop channel 0 */
    ST1 |= _0001_SAU_CH0_STOP_TRG_ON;
    /* Mask channel 0 interrupt */
    CSIMK20 = 1U;    /* disable INTCSI20 interrupt */
    CSIIF20 = 0U;    /* clear INTCSI20 interrupt flag */
    /* Set INTCSI20 low priority */
    CSIPR120 = 1U;
    CSIPR020 = 1U;
    SIR10 = _0002_SAU_SIRMN_PECTMN | _0001_SAU_SIRMN_OVCTMN;    /* clear error flag */
    SMR10 = _0020_SAU_SMRMN_INITIALVALUE | _0000_SAU_CLOCK_SELECT_CK00 | _0000_SAU_CLOCK_MODE_CKS | 
            _0000_SAU_TRIGGER_SOFTWARE | _0000_SAU_MODE_CSI | _0000_SAU_TRANSFER_END;
//    SCR10 = _0004_SAU_SCRMN_INITIALVALUE | _C000_SAU_RECEPTION_TRANSMISSION | _0000_SAU_TIMING_1 | _0080_SAU_LSB | 
    SCR10 = _0004_SAU_SCRMN_INITIALVALUE | _C000_SAU_RECEPTION_TRANSMISSION | _3000_SAU_TIMING_4 | _0000_SAU_MSB | 
            _0003_SAU_LENGTH_8;
    SDR10 = _0200_SAU1_CH0_BAUDRATE_DIVISOR;
//    SO1 |= _0100_SAU_CH0_CLOCK_OUTPUT_1;    /* CSI20 clock initial level */
    SO1 &= (uint16_t)~_0100_SAU_CH0_CLOCK_OUTPUT_1;    /* CSI20 clock initial level */
    SO1 &= (uint16_t)~_0001_SAU_CH0_DATA_OUTPUT_1;    /* CSI20 SO initial level */
    SOE1 |= _0001_SAU_CH0_OUTPUT_ENABLE;    /* enable CSI20 output */
    /* Set SI20 pin */
    PMC2 &= 0xFEU;
    PM2 |= 0x01U;
    TSSEL1 &= 0xF7U;
    /* Set SO20 pin */
    PMC2 &= 0xFDU;
    P2 |= 0x02U;
    PM2 &= 0xFDU;
    TSSEL1 &= 0xFBU;
    /* Set SCK20 pin */
    P4 |= 0x02U;
    PM4 &= 0xFDU;

    R_Config_CSI20_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_CSI20_Start
* Description  : This function starts the CSI20 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_CSI20_Start(void)
{
//    SO1 |= _0100_SAU_CH0_CLOCK_OUTPUT_1;    /* CSI20 clock initial level */
//    SO1 &= (uint16_t)~_0001_SAU_CH0_DATA_OUTPUT_1;    /* CSI20 SO initial level */
    SOE1 |= _0001_SAU_CH0_OUTPUT_ENABLE;    /* enable CSI20 output */
    SS1 |= _0001_SAU_CH0_START_TRG_ON;    /* enable CSI20 */
    CSIIF20 = 0U;    /* clear INTCSI20 interrupt flag */
    CSIMK20 = 0U;    /* enable INTCSI20 interrupt */
}

/***********************************************************************************************************************
* Function Name: R_Config_CSI20_Stop
* Description  : This function stops the CSI20 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_CSI20_Stop(void)
{
    CSIMK20 = 1U;    /* disable INTCSI20 interrupt */
    ST1 |= _0001_SAU_CH0_STOP_TRG_ON;    /* disable CSI20 */
    SOE1 &= (uint16_t)~_0001_SAU_CH0_OUTPUT_ENABLE;    /* disable CSI20 output */
    CSIIF20 = 0U;    /* clear INTCSI20 interrupt flag */
}

/***********************************************************************************************************************
* Function Name: R_Config_CSI20_Send_Receive
* Description  : This function sends and receives CSI20 data.
* Arguments    : tx_buf -
*                    transfer buffer pointer
*                tx_num -
*                    buffer size
*                rx_buf -
*                    receive buffer pointer
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_Config_CSI20_Send_Receive(uint8_t * const tx_buf, uint16_t tx_num, uint8_t * const rx_buf)
{
    MD_STATUS status = MD_OK;

    if (tx_num < 1U)
    {
        status = MD_ARGERROR;
    }
    else
    {
        g_csi20_tx_count = tx_num;    /* send data count */
        gp_csi20_tx_address = tx_buf;    /* send buffer pointer */
        gp_csi20_rx_address = rx_buf;    /* receive buffer pointer */
        CSIMK20 = 1U;    /* disable INTCSI20 interrupt */

        if (0U != gp_csi20_tx_address)
        {
            SIO20 = *gp_csi20_tx_address;    /* started by writing data to SDR10[7:0] */
            gp_csi20_tx_address++;
        }
        else
        {
            SIO20 = 0xFFU;
        }

        g_csi20_tx_count--;
        CSIMK20 = 0U;    /* enable INTCSI20 interrupt */
    }

    return (status);
}

/* Start user code for adding. Do not edit comment generated here */
/**********************************************************************************************************************
 * Function Name: R_Config_CSI20_GetBitOrder
 * Description  : Get the order of the bits shifted out of and into the SPI bus.
 * Arguments    : -
 * Return Value : Current bit order setting
 *              :   LSBFIRST
 *              :   MSBFIRST
 *********************************************************************************************************************/
uint8_t R_Config_CSI20_GetBitOrder(void) {
    return (SCR10 & (uint16_t)_0080_SAU_LSB) == _0080_SAU_LSB
                ? LSBFIRST : MSBFIRST;
}

/**********************************************************************************************************************
 * Function Name: R_Config_CSI20_SetBitOrder
 * Description  : Set the order of the bits shifted out of and into the SPI bus.
 * Arguments    : bitOrder - Bit order setting
 *              :   LSBFIRST
 *              :   MSBFIRST
 * Return Value : -
 *********************************************************************************************************************/
void R_Config_CSI20_SetBitOrder(uint8_t bitOrder) {
    ST1     |= _0001_SAU_CH0_STOP_TRG_ON;                       /* Stop unit 1, channel 0 */
    SOE1    &= (uint16_t)~_0001_SAU_CH0_OUTPUT_ENABLE;          /* disable CSI20 output */

    SCR10    = (SCR10 & (uint16_t)~_0080_SAU_LSB)
             | (bitOrder == LSBFIRST ? _0080_SAU_LSB : _0000_SAU_MSB);

    CSIIF20  = 0U;                                              /* clear INTCSI20 interrupt flag */

//    SO1     |= _0100_SAU_CH0_CLOCK_OUTPUT_1;                    /* CSI20 clock initial level */
//    SO1     &= (uint16_t)~_0001_SAU_CH0_DATA_OUTPUT_1;          /* CSI20 SO initial level */
    SOE1    |= _0001_SAU_CH0_OUTPUT_ENABLE;                     /* enable CSI20 output */
    SS1     |= _0001_SAU_CH0_START_TRG_ON;                      /* enable CSI20 */
}

/**********************************************************************************************************************
 * Function Name: R_Config_CSI20_SetDataMode
 * Description  : Set the SPI data mode (clock polarity and phase).
 * Arguments    : dataMode - SPI data mode
 *              :   SPI_MODE0
 *              :   SPI_MODE1
 *              :   SPI_MODE2
 *              :   SPI_MODE3
 * Return Value : -
 *********************************************************************************************************************/
void R_Config_CSI20_SetDataMode(uint8_t dataMode) {

    ST1     |= _0001_SAU_CH0_STOP_TRG_ON;                       /* Stop unit 1, channel 0 */
    SOE1    &= (uint16_t)~_0001_SAU_CH0_OUTPUT_ENABLE;          /* disable CSI11 output */
    /*
     * This mapping is obeying the base code.
     * Fix the `SPI_MODEx` macros together.
     */
    switch (dataMode) {
    case SPI_MODE3:
        SCR10 = (SCR10 & (uint16_t)~SPI_MODE_MASK) | _0000_SAU_TIMING_1;
        SO1     |= _0100_SAU_CH0_CLOCK_OUTPUT_1;                    /* CSI20 clock initial level */
        break;
    case SPI_MODE2:
        SCR10 = (SCR10 & (uint16_t)~SPI_MODE_MASK) | _2000_SAU_TIMING_3;
        SO1     |= _0100_SAU_CH0_CLOCK_OUTPUT_1;                    /* CSI20 clock initial level */
        break;
    case SPI_MODE1:
        SCR10 = (SCR10 & (uint16_t)~SPI_MODE_MASK) | _1000_SAU_TIMING_2;
        SO1     &= (uint16_t)~_0100_SAU_CH0_CLOCK_OUTPUT_1;                    /* CSI20 clock initial level */
        break;
    case SPI_MODE0:
    default:
        SCR10 = (SCR10 & (uint16_t)~SPI_MODE_MASK) | _3000_SAU_TIMING_4;
        SO1     &= (uint16_t)~_0100_SAU_CH0_CLOCK_OUTPUT_1;                    /* CSI20 clock initial level */
        break;
    }

    CSIIF20  = 0U;                                              /* clear INTCSI20 interrupt flag */

//    SO1     |= _0100_SAU_CH0_CLOCK_OUTPUT_1;                    /* CSI20 clock initial level */
//    SO1     &= (uint16_t)~_0001_SAU_CH0_DATA_OUTPUT_1;          /* CSI20 SO initial level */
    SOE1    |= _0001_SAU_CH0_OUTPUT_ENABLE;                     /* enable CSI20 output */
    SS1     |= _0001_SAU_CH0_START_TRG_ON;                      /* enable CSI20 */
}

/**********************************************************************************************************************
 * Function Name: R_Config_CSI20_SetClockDivider
 * Description  : Set the SPI clock divider relative to the system clock.
 * Arguments    : clockDiv - SPI clock divider
 *              :   SPI_CLOCK_DIV2
 *              :   SPI_CLOCK_DIV4
 *              :   SPI_CLOCK_DIV8
 *              :   SPI_CLOCK_DIV16
 *              :   SPI_CLOCK_DIV32
 *              :   SPI_CLOCK_DIV64
 *              :   SPI_CLOCK_DIV128
 *              :   or an immediate { 2, 4, 6, 8, ..., 256 }
 * Return Value : -
 *********************************************************************************************************************/
void R_Config_CSI20_SetClockDivider(uint16_t clockDiv) {
    ST1     |= _0001_SAU_CH0_STOP_TRG_ON;                       /* Stop unit 1, channel 0 */
    SOE1    &= (uint16_t)~_0001_SAU_CH0_OUTPUT_ENABLE;          /* disable CSI11 output */

//    clockDiv = clockDiv <   2 ?   2U
    clockDiv = clockDiv <   4 ?   4U
             : clockDiv > 256 ? 256U
             :                  clockDiv + (clockDiv & 1U);

    SDR10    = ((clockDiv >> 1) - 1) << 9;

    CSIIF20  = 0U;                                              /* clear INTCSI20 interrupt flag */

//    SO1     |= _0100_SAU_CH0_CLOCK_OUTPUT_1;                    /* CSI20 clock initial level */
//    SO1     &= (uint16_t)~_0001_SAU_CH0_DATA_OUTPUT_1;          /* CSI20 SO initial level */
    SOE1    |= _0001_SAU_CH0_OUTPUT_ENABLE;                     /* enable CSI20 output */
    SS1     |= _0001_SAU_CH0_START_TRG_ON;                      /* enable CSI20 */
}

/**********************************************************************************************************************
 * Function Name: R_Config_CSI20_SetClock
 * Description  : Set the SPI maximum speed of communication.
 * Arguments    : clock - SPI clock speed
 * Return Value : -
 *********************************************************************************************************************/
void R_Config_CSI20_SetClock(uint32_t clock) {
    uint16_t clockDiv;
    uint32_t spi_frequency = R_BSP_GetFclkFreqHz() >> ((SPS1 >> 4) & 0x0F);

    for (clockDiv = 2; clockDiv < 256; clockDiv += 2) {
        if (clock >= spi_frequency / clockDiv) {
            break;
        }
    }

    R_Config_CSI20_SetClockDivider(clockDiv);
}
/* End user code. Do not edit comment generated here */
