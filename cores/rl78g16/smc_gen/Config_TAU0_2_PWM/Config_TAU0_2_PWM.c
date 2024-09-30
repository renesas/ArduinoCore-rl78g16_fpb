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
* File Name        : Config_TAU0_2_PWM.c
* Component Version: 1.4.0
* Device(s)        : R5F121BCxFP
* Description      : This file implements device driver for Config_TAU0_2_PWM.
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
#include "Config_TAU0_2_PWM.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
volatile uint8_t g_tau_output_enable = 0;
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_TAU0_2_PWM_Create
* Description  : This function initializes the TAU0 channel2 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TAU0_2_PWM_Create(void)
{
    TPS0 &= _FFF0_TAU_CKM0_CLEAR;
    TPS0 |= _0000_TAU_CKM0_FCLK_0;
    TT0 |= (_0010_TAU_CH4_STOP_TRG_ON | _0008_TAU_CH3_STOP_TRG_ON | _0004_TAU_CH2_STOP_TRG_ON);
    TMMK02 = 1U;    /* disable INTTM02 interrupt */
    TMIF02 = 0U;    /* clear INTTM02 interrupt flag */
    TMMK03 = 1U;    /* disable INTTM03 interrupt */
    TMIF03 = 0U;    /* clear INTTM03 interrupt flag */
    TMMK04 = 1U;    /* disable INTTM04 interrupt */
    TMIF04 = 0U;    /* clear INTTM04 interrupt flag */
    /* Set INTTM02 low priority */
    TMPR102 = 1U;
    TMPR002 = 1U;
    /* Channel 2 is used as master channel for PWM output function */
    TMR02 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0800_TAU_COMBINATION_MASTER |
            _0000_TAU_TRIGGER_SOFTWARE | _0001_TAU_MODE_PWM_MASTER;
    TDR02 = _7CFF_TAU_TDR02_VALUE;
    TOM0 &= (uint16_t)~_0004_TAU_CH2_SLAVE_OUTPUT;
    TOL0 &= (uint16_t)~_0004_TAU_CH2_OUTPUT_LEVEL_L;
    TO0 &= (uint16_t)~_0004_TAU_CH2_OUTPUT_VALUE_1;
    TOE0 &= (uint16_t)~_0004_TAU_CH2_OUTPUT_ENABLE;
    /* Channel 3 is used as slave channel for PWM output function */
    TMR03 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_COMBINATION_SLAVE |
            _0400_TAU_TRIGGER_MASTER_INT | _0009_TAU_MODE_PWM_SLAVE;
    TDR03 = _7D00_TAU_TDR03_VALUE;
    TOM0 |= _0008_TAU_CH3_SLAVE_OUTPUT;
    TOL0 |= _0008_TAU_CH3_OUTPUT_LEVEL_L;
    TO0 &= (uint16_t)~_0008_TAU_CH3_OUTPUT_VALUE_1;
    /* Channel 4 is used as slave channel for PWM output function */
    TMR04 = _0000_TAU_CLOCK_SELECT_CKM0 | _0000_TAU_CLOCK_MODE_CKS | _0000_TAU_COMBINATION_SLAVE |
            _0400_TAU_TRIGGER_MASTER_INT | _0009_TAU_MODE_PWM_SLAVE;
    TDR04 = _7D00_TAU_TDR04_VALUE;
    TOM0 |= _0010_TAU_CH4_SLAVE_OUTPUT;
    TOL0 |= _0010_TAU_CH4_OUTPUT_LEVEL_L;
    TO0 &= (uint16_t)~_0010_TAU_CH4_OUTPUT_VALUE_1;

    R_Config_TAU0_2_PWM_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_TAU0_2_PWM_Start
* Description  : This function starts the TAU0 channel2 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TAU0_2_PWM_Start(void)
{
    TMIF02 = 0U;    /* clear INTTM02 interrupt flag */
    TMMK02 = 0U;    /* enable INTTM02 interrupt */
    TS0 |= (_0010_TAU_CH4_START_TRG_ON | _0008_TAU_CH3_START_TRG_ON | _0004_TAU_CH2_START_TRG_ON);
}

/***********************************************************************************************************************
* Function Name: R_Config_TAU0_2_PWM_Stop
* Description  : This function stops the TAU0 channel2 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TAU0_2_PWM_Stop(void)
{
    TT0 |= (_0010_TAU_CH4_STOP_TRG_ON | _0008_TAU_CH3_STOP_TRG_ON | _0004_TAU_CH2_STOP_TRG_ON);
    TOE0 &= (uint16_t)~(_0010_TAU_CH4_OUTPUT_ENABLE | _0008_TAU_CH3_OUTPUT_ENABLE);
    TMMK02 = 1U;    /* disable INTTM02 interrupt */
    TMIF02 = 0U;    /* clear INTTM02 interrupt flag */
}

/* Start user code for adding. Do not edit comment generated here */

void R_Config_TAU0_23_PWM_Create(void)
{
    /* Set TO03 pin */
    P1 &= 0xFEU;
    PM1 &= 0xFEU;
}

void R_Config_TAU0_23_PWM_Start(void)
{
	g_tau_output_enable |= _0008_TAU_CH3_OUTPUT_ENABLE;
}

void R_Config_TAU0_23_PWM_Stop(void)
{
	g_tau_output_enable &= ~_0008_TAU_CH3_OUTPUT_ENABLE;
	TOE0 &= ~_0008_TAU_CH3_OUTPUT_ENABLE;
	TO0 &= (uint16_t)~_0008_TAU_CH3_OUTPUT_VALUE_1;
}

void R_Config_TAU0_24_PWM_Create(void)
{
    /* Set TO04 pin */
    POM1 &= 0x7FU;
    P1 &= 0x7FU;
    PM1 &= 0x7FU;
    TSSEL0 &= 0xFBU;
}

void R_Config_TAU0_24_PWM_Start(void)
{
	g_tau_output_enable |= _0010_TAU_CH4_OUTPUT_ENABLE;
}

void R_Config_TAU0_24_PWM_Stop(void)
{
	g_tau_output_enable &= ~_0010_TAU_CH4_OUTPUT_ENABLE;
	TOE0 &= ~_0010_TAU_CH4_OUTPUT_ENABLE;
	TO0 &= (uint16_t)~_0010_TAU_CH4_OUTPUT_VALUE_1;
}

void R_Config_TAU0_2_PWM_Enable_IRQ(void)
{
    TMIF02 = 0U;    /* clear INTTM02 interrupt flag */
    TMMK02 = 0U;    /* enable INTTM02 interrupt */
}
/* End user code. Do not edit comment generated here */

