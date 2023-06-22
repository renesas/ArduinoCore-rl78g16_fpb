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
* Copyright (C) 2021, 2023 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : Config_TAU0_4_Measure_Signal_user.c
* Component Version: 1.4.0
* Device(s)        : R5F121BCxFP
* Description      : This file implements device driver for Config_TAU0_4_Measure_Signal.
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
#include "Config_TAU0_4_Measure_Signal.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* For TAU0_ch4 pulse measurement */
volatile uint32_t g_tau0_ch4_width = 0UL;
/* Start user code for global. Do not edit comment generated here */
volatile uint8_t g_tau0_ch4_interrupt_flag = 0UL;
extern volatile uint8_t g_pulse_enable_interrupt_flag;
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_TAU0_4_Measure_Signal_Create_UserInit
* Description  : This function adds user code after initializing the TAU0 channel4.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TAU0_4_Measure_Signal_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_TAU0_4_Measure_Signal_interrupt
* Description  : This function is INTTM04 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_Config_TAU0_4_Measure_Signal_interrupt(void)
{
    if (g_pulse_enable_interrupt_flag == 1UL)
    {
        if (1U == (TSR04 & _0001_TAU_OVERFLOW_OCCURS))    /* overflow occurs */
        {
            g_tau0_ch4_width = (uint32_t)(TDR04 + 1UL) + 0x10000UL;
        }
        else
        {
            g_tau0_ch4_width = (uint32_t)(TDR04 + 1UL);
        }
        /* Start user code for r_Config_TAU0_4_Mesure_Signal_interrupt. Do not edit comment generated here */
        g_tau0_ch4_interrupt_flag = 1UL;
    }
    else
    {
        ;
    }
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
