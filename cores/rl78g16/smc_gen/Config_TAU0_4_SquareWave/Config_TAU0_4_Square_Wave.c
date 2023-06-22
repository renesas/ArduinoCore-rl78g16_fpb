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
* Copyright (C) 2020 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : Config_TAU0_4.c
* Version      : 1.1.0
* Device(s)    : R5F12068xSP
* Description  : This file implements device driver for Config_TAU0_4.
* Creation Date: 
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
#include "Config_TAU0_4_Square_Wave.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_TAU0_4_Create
* Description  : This function initializes the TAU0 channel3 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TAU0_4_Square_Wave_Create(void)
{
    TPS0 &= _FFF0_TAU_CKM0_CLEAR;
    TPS0 |= _0000_TAU_CKM0_FCLK_0;
    /* Stop channel 3 */
    TT0 |= _0010_TAU_CH4_STOP_TRG_ON;
    /* Mask channel 3 interrupt */
    TMMK04 = 1U;    /* disable INTTM03 interrupt */
    TMIF04 = 0U;    /* clear INTTM03 interrupt flag */
    /* Set INTTM03 low priority */
    TMPR104 = 1U;
    TMPR004 = 1U;
    /* TAU03 used as square output function */
    TMR04 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_16BITS_MODE | 
            _0000_TAU_TRIGGER_SOFTWARE | _0000_TAU_MODE_INTERVAL_TIMER | _0000_TAU_START_INT_UNUSED;
    TDR04 = _063F_TAU_TDR04_VALUE;
    TOM0 &= (uint16_t)~_0010_TAU_CH4_SLAVE_OUTPUT;
    TOL0 &= (uint16_t)~_0010_TAU_CH4_OUTPUT_LEVEL_L;
    TO0 &= (uint16_t)~_0010_TAU_CH4_OUTPUT_VALUE_1;
    TOE0 |= _0010_TAU_CH4_OUTPUT_ENABLE;

    //    PIOR1 |= 0x10;

    /* Set TO04 pin (=P17) */
    POM1 &= 0x7FU;
    P1 &= 0x7FU;
    PM1 &= 0x7FU;
    
    R_Config_TAU0_4_Square_Wave_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_TAU0_4_Start
* Description  : This function starts the TAU0 channel3 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TAU0_4_Square_Wave_Start(void)
{
    TMIF04 = 0U;    /* clear INTTM03 interrupt flag */
    TMMK04 = 0U;    /* enable INTTM03 interrupt */
    TOE0 |= _0010_TAU_CH4_OUTPUT_ENABLE;
    TS0 |= _0010_TAU_CH4_START_TRG_ON;
}

/***********************************************************************************************************************
* Function Name: R_Config_TAU0_4_Stop
* Description  : This function stops the TAU0 channel3 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TAU0_4_Square_Wave_Stop(void)
{
    TT0 |= _0010_TAU_CH4_STOP_TRG_ON;
    TOE0 &= (uint16_t)~_0010_TAU_CH4_OUTPUT_ENABLE;
    /* Mask channel 3 interrupt */
    TMMK04 = 1U;    /* disable INTTM03 interrupt */
    TMIF04 = 0U;    /* clear INTTM03 interrupt flag */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
