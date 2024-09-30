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
* File Name        : Config_TAU0_2_PWM.h
* Component Version: 1.4.0
* Device(s)        : R5F121BCxFP
* Description      : This file implements device driver for Config_TAU0_2_PWM.
* Creation Date    : 
***********************************************************************************************************************/

#ifndef CFG_Config_TAU0_2_PWM_H
#define CFG_Config_TAU0_2_PWM_H

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_tau.h"

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _7CFF_TAU_TDR02_VALUE                              (0x7CFFU)    /* 16-bit timer data register 02 (TDR02) */
#define _7D00_TAU_TDR03_VALUE                              (0x7D00U)    /* 16-bit timer data register 03 (TDR03) */
#define _7D00_TAU_TDR04_VALUE                              (0x7D00U)    /* 16-bit timer data register 04 (TDR04) */
/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_TAU0_2_PWM_Create (void);
void R_Config_TAU0_2_PWM_Start (void);
void R_Config_TAU0_2_PWM_Stop (void);
void R_Config_TAU0_2_PWM_Create_UserInit (void);
/* Start user code for function. Do not edit comment generated here */
void R_Config_TAU0_23_PWM_Create(void);
void R_Config_TAU0_23_PWM_Start(void);
void R_Config_TAU0_24_PWM_Create(void);
void R_Config_TAU0_24_PWM_Start(void);
void R_Config_TAU0_23_PWM_Stop(void);
void R_Config_TAU0_24_PWM_Stop(void);
void R_Config_TAU0_2_PWM_Enable_IRQ(void);
/* End user code. Do not edit comment generated here */
#endif

