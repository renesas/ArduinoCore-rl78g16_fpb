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
* Copyright (C) 2021, 2022 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : r_cg_sau_common.c
* Version          : 1.0.1
* Device(s)        : R5F121BCxFP
* Description      : None
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
#include "Config_UART0.h"
#if ( UART1_CHANNEL == 1 )
    #include "Config_UART1.h"
#endif /* ( UART1_CHANNEL == 1 ) */
#include "r_cg_sau_common.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_SAU0_Create
* Description  : This function enables SAU0 input clock supply and initializes SAU0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU0_Create(void)
{
    SAU0EN = 1U;    /* supplies input clock */
    R_Config_CSI20_Create();
//    R_Config_UART0_Create();
//    R_Config_UART1_Create();
}

/***********************************************************************************************************************
* Function Name: R_SAU1_Create
* Description  : This function enables SAU1 input clock supply and initializes SAU1 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU1_Create(void)
{
    SAU1EN = 1U;    /* supplies input clock */
}

/***********************************************************************************************************************
* Function Name: R_SAU0_Set_PowerOn
* Description  : This function starts the clock supply for SAU0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU0_Set_PowerOn(void)
{
    SAU0EN = 1U;    /* supplies input clock */
}

/***********************************************************************************************************************
* Function Name: R_SAU0_Set_PowerOff
* Description  : This function stops the clock supply for SAU0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU0_Set_PowerOff(void)
{
    SAU0EN = 0U;    /* stops input clock supply */
}

/***********************************************************************************************************************
* Function Name: R_SAU1_Set_PowerOn
* Description  : This function starts the clock supply for SAU1.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU1_Set_PowerOn(void)
{
    SAU1EN = 1U;    /* supplies input clock */
}

/***********************************************************************************************************************
* Function Name: R_SAU1_Set_PowerOff
* Description  : This function stops the clock supply for SAU1.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU1_Set_PowerOff(void)
{
    SAU1EN = 0U;    /* stops input clock supply  */
}

/* Start user code for adding. Do not edit comment generated here */
#if defined(UART_CHANNEL) && ( UART_CHANNEL == 0 )&& defined(CSI_CHANNEL0)

void r_Config_CSI00_UART0_interrupt_switching(void) {
#if defined(UART_CHANNEL) && ( UART_CHANNEL == 0 ) 
    /* Check bit [2:1] of register SMR03 == 01 , which is set in R_Config_UART1_Create(). */
    if ( (SMR00 & _0002_SAU_MODE_UART) == _0002_SAU_MODE_UART) {
        /*
         */
        r_Config_UART0_interrupt_send();
        return;
    }
#endif

#if defined(CSI_CHANNEL0)
    /* Check bit [2:1] of register SMR03 == 00 , which is set in R_Config_CSI11_Create(). */
    if ( (SMR00 & _0000_SAU_MODE_CSI) == _0000_SAU_MODE_CSI) {
        /* Call the interrupt handler for CSI11 (Master)
         * If it is possible to distinguish between CSI11 (master) and CSI111 (slave), do so here. */
        r_Config_CSI00_interrupt();
        return;
    }
#endif
}

#endif  // defined(UART_CHANNEL) && ( UART_CHANNEL == 0 ) && defined(CSI_CHANNEL3)

/* End user code. Do not edit comment generated here */

