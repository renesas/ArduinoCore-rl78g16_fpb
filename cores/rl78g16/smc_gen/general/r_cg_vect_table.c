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
* File Name        : r_cg_vect_table.c
* Version          : 1.0.1
* Device(s)        : R5F121BCxFP
* Description      : None
* Creation Date    : 
***********************************************************************************************************************/

#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"

extern void PowerON_Reset (void);

const unsigned char Option_Bytes[]  __attribute__ ((section (".option_bytes"))) = {
    0xEFU, 0xFFU, 0xF9U, 0x85U
};

const unsigned char Security_Id[]  __attribute__ ((section (".security_id"))) = {
    0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U,0x00U
};

#define VEC          __attribute__ ((section (".vec")))
const void __near *HardwareVectors[] VEC = {
    // Address 0x0
    PowerON_Reset,
    // Secure for Debugging
    (void*)0xFFFF
};

#define VECT_SECT          __attribute__ ((section (".vects")))
const void __near *Vectors[] VECT_SECT = {
/*
 * INT_WDTI (0x4)
 */
INT_WDTI,

/*
 * INT_P0 (0x6)
 */
    r_Config_INTC_intp0_interrupt,

/*
 * INT_P1 (0x8)
 */
    INT_P1,

/*
 * INT_P2 (0xA)
 */
    r_Config_INTC_intp2_interrupt,

/*
 * INT_P3 (0xC)
 */
	r_Config_INTC_intp3_interrupt,

/*
 * INT_P4 (0xE)
 */
    r_Config_INTC_intp4_interrupt,

/*
 * INT_P5 (0x10)
 */
    INT_P5,

/*
 * INT_CSI00/INT_IIC00/INT_ST0 (0x12)
 */
    r_Config_UART0_interrupt_send,

/*
 * INT_SR0 (0x14)
 */
    r_Config_UART0_interrupt_receive,

/*
 * INT_SRE0 (0x16)
 */
    r_Config_UART0_interrupt_error,

/*
 * INT_TM01H (0x18)
 */
    INT_TM01H,

/*
 * INT_TM00 (0x1A)
 */
	INT_TM00,
/*
 * INT_TM01 (0x1C)
 */
//    r_Config_TAU0_1_interrupt,
//    INT_TM01H,
	r_Config_TAU0_1_Micros_interrupt,
/*
 * INT_ST1 (0x1E)
 */
//    INT_ST1,
    r_Config_UART1_interrupt_send,

/*
 * INT_CSI11/INT_IIC11/INT_SR1 (0x20)
 */
//    r_Config_CSI11_interrupt,
//    INT_DUMMY,
    r_Config_UART1_interrupt_receive,
    
/*
 * INT_SRE1 (0x22)
 */
//    INT_SRE1,
    r_Config_UART1_interrupt_error,
    
/*
 * INT_CSI20/INT_IIC20/INT_ST2 (0x24)
 */
    INT_ST2,
//    INT_CSI20,
//    INT_IIC20,

/*
 * INT_SR2 (0x26)
 */
    INT_SR2,

/*
 * INT_SRE2 (0x28)
 */
    INT_SRE2,

/*
 * INT_TM03H (0x2A)
 */
    INT_TM03H,

/*
 * INT_IICA0 (0x2C)
 */
    r_Config_IICA0_interrupt,

/*
 * INT_TM02 (0x2E)
 */
//    r_Config_TAU0_2_interrupt,
	r_Config_TAU0_2_Measure_Signal_interrupt,

/*
 * INT_TM03 (0x30)
 */
//    r_Config_TAU0_3_interrupt,
	r_Config_TAU0_3_Measure_Signal_interrupt,
/*
 * INT_AD (0x32)
 */
    r_Config_ADC_interrupt,

/*
 * INT_RTC (0x34)
 */
    INT_RTC,

/*
 * INT_RTIT (0x36)
 */
    INT_RTIT,

/*
 * INT_IT (0x38)
 */
    r_Config_IT_interrupt,

/*
 * INT_TM04 (0x3A)
 */
//    r_Config_TAU0_4_interrupt,
	r_Config_TAU0_4_Measure_Signal_interrupt,
/*
 * INT_TM05 (0x3C)
 */
//    r_Config_TAU0_5_interrupt,
//	r_Config_TAU0_5_Measure_Signal_interrupt,
	    INT_DUMMY,

/*
 * INT_TM06 (0x3E)
 */
//    r_Config_TAU0_6_interrupt,
    INT_DUMMY,
//      r_Config_TAU0_6_Micros_interrupt,

/*
 * INT_TM07 (0x40)
 */
//    r_Config_TAU0_7_interrupt,
    INT_DUMMY,
/*
 * INT_P6 (0x42)
 */
    r_Config_INTC_intp6_interrupt,

/*
 * INT_P7 (0x44)
 */
    INT_P7,

/*
 * INT_P8 (0x46)
 */
    r_Config_INTC_intp8_interrupt,

/*
 * INT_P9 (0x48)
 */
    r_Config_INTC_intp9_interrupt,

/*
 * INT_CMP0 (0x4A)
 */
    INT_CMP0,

/*
 * INT_CMP1 (0x4C)
 */
    INT_CMP1,

/*
 * INT_CTSUWR (0x4E)
 */
    INT_CTSUWR,

/*
 * INT_CTSURD (0x50)
 */
    INT_CTSURD,

/*
 * INT_CTSUFN (0x52)
 */
    INT_CTSUFN,

/*
 * Padding for reserved interrupt source (0x54)
 */
    INT_DUMMY,

/*
 * Padding for reserved interrupt source (0x56)
 */
    INT_DUMMY,

/*
 * Padding for reserved interrupt source (0x58)
 */
    INT_DUMMY,

/*
 * Padding for reserved interrupt source (0x5A)
 */
    INT_DUMMY,

/*
 * Padding for reserved interrupt source (0x5C)
 */
    INT_DUMMY,

/*
 * Padding for reserved interrupt source (0x5E)
 */
    INT_DUMMY,

/*
 * Padding for reserved interrupt source (0x60)
 */
    INT_DUMMY,

/*
 * Padding for reserved interrupt source (0x62)
 */
    INT_DUMMY,

/*
 * Padding for reserved interrupt source (0x64)
 */
    INT_DUMMY,

/*
 * Padding for reserved interrupt source (0x66)
 */
    INT_DUMMY,

/*
 * Padding for reserved interrupt source (0x68)
 */
    INT_DUMMY,

/*
 * Padding for reserved interrupt source (0x6A)
 */
    INT_DUMMY,

/*
 * Padding for reserved interrupt source (0x6C)
 */
    INT_DUMMY,

/*
 * Padding for reserved interrupt source (0x6E)
 */
    INT_DUMMY,

/*
 * Padding for reserved interrupt source (0x70)
 */
    INT_DUMMY,

/*
 * Padding for reserved interrupt source (0x72)
 */
    INT_DUMMY,

/*
 * Padding for reserved interrupt source (0x74)
 */
    INT_DUMMY,

/*
 * Padding for reserved interrupt source (0x76)
 */
    INT_DUMMY,

/*
 * Padding for reserved interrupt source (0x78)
 */
    INT_DUMMY,

/*
 * Padding for reserved interrupt source (0x7A)
 */
    INT_DUMMY,

/*
 * Padding for reserved interrupt source (0x7C)
 */
    INT_DUMMY,

/*
 * INT_BRK_I (0x7E)
 */
    INT_BRK_I,
};
