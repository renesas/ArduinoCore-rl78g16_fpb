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
* File Name        : r_cg_it.h
* Version          : 1.0.1
* Device(s)        : R5F121BCxFP
* Description      : General header file for IT peripheral.
* Creation Date    : 
***********************************************************************************************************************/

#ifndef IT_H
#define IT_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Peripheral Enable Register 0 (PER0)
*/
/* Control of 12-bit interval timer input clock supply (TMKAEN) */
#define _00_IT_CLOCK_STOP                           (0x00U)    /* stops input clock supply */
#define _80_IT_CLOCK_SUPPLY                         (0x80U)    /* enables input clock supply */

/*
    Operation Speed Mode Control Register (OSMC)
*/
/* Supply of count clock for 12-bit interval timer (WUTMMCK0) */
#define _00_IT_CLOCK_SUPPLY_FSUB                    (0x00U)    /* supplies the subsystem clock (fSUB) */
#define _10_IT_CLOCK_SUPPLY_FIL                     (0x10U)    /* low-speed on-chip oscillator clock (fIL) supply */

/*
    Interval Timer Control Register (ITMC)
*/
/* 12-bit interval timer operation control (RINTE) */
#define _0000_IT_COUNTER_STOP                       (0x0000U)    /* count operation stopped (count clear) */
#define _8000_IT_COUNTER_START                      (0x8000U)    /* count operation started */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif

