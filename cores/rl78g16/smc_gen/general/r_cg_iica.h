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
* File Name        : r_cg_iica.h
* Version          : 1.0.1
* Device(s)        : R5F121BCxFP
* Description      : General header file for IICA peripheral.
* Creation Date    : 
***********************************************************************************************************************/

#ifndef IICA_H
#define IICA_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Peripheral Enable Register 0 (PER0)
*/
/* Control of IICA0 input clock (IICA0EN) */
#define _00_IICA0_CLOCK_STOP                 (0x00U)    /* stops supply of input clock */
#define _10_IICA0_CLOCK_SUPPLY               (0x10U)    /* supplies input clock */

/*
    IICA Control Register 00 (IICCTL00)
*/
/* IIC operation enable (IICE0) */
#define _00_IICA_OPERATION_DISABLE           (0x00U)    /* stop operation */
#define _80_IICA_OPERATION_ENABLE            (0x80U)    /* enable operation */
/* Exit from communications (LREL0) */
#define _00_IICA_COMMUNICATION_NORMAL        (0x00U)    /* normal operation */
#define _40_IICA_COMMUNICATION_EXIT          (0x40U)    /* exit from current communication */
/* Wait cancellation (WREL0) */
#define _00_IICA_WAIT_NOTCANCEL              (0x00U)    /* do not cancel wait */
#define _20_IICA_WAIT_CANCEL                 (0x20U)    /* cancel wait */
/* Generation of interrupt when stop condition (SPIE0) */
#define _00_IICA_STOPINT_DISABLE             (0x00U)    /* disable */
#define _10_IICA_STOPINT_ENABLE              (0x10U)    /* enable */
/* Wait and interrupt generation (WTIM0) */
#define _00_IICA_WAITINT_CLK8FALLING         (0x00U)    /* generated at the eighth clock's falling edge */
#define _08_IICA_WAITINT_CLK9FALLING         (0x08U)    /* generated at the ninth clock's falling edge */
/* Acknowledgement control (ACKE0) */
#define _00_IICA_ACK_DISABLE                 (0x00U)    /* disable acknowledgement */
#define _04_IICA_ACK_ENABLE                  (0x04U)    /* enable acknowledgement */
/* Start condition trigger (STT0) */
#define _00_IICA_START_NOTGENERATE           (0x00U)    /* do not generate start condition */
#define _02_IICA_START_GENERATE              (0x02U)    /* generate start condition */
/* Stop condition trigger (SPT0) */
#define _00_IICA_STOP_NOTGENERATE            (0x00U)    /* do not generate stop condition */
#define _01_IICA_STOP_GENERATE               (0x01U)    /* generate stop condition */

/*
    IICA Status Register 0 (IICS0)
*/
/* Master device status (MSTS0) */
#define _00_IICA_STATUS_NOTMASTER            (0x00U)    /* slave device status or communication standby status */
#define _80_IICA_STATUS_MASTER               (0x80U)    /* master device communication status */
/* Detection of arbitration loss (ALD0) */
#define _00_IICA_ARBITRATION_NO              (0x00U)    /* arbitration win or no arbitration */
#define _40_IICA_ARBITRATION_LOSS            (0x40U)    /* arbitration loss */
/* Detection of extension code reception (EXC0) */
#define _00_IICA_EXTCODE_NOT                 (0x00U)    /* extension code not received */
#define _20_IICA_EXTCODE_RECEIVED            (0x20U)    /* extension code received */
/* Detection of matching addresses (COI0) */
#define _00_IICA_ADDRESS_NOTMATCH            (0x00U)    /* addresses do not match */
#define _10_IICA_ADDRESS_MATCH               (0x10U)    /* addresses match */
/* Detection of transmit/receive status (TRC0) */
#define _00_IICA_STATUS_RECEIVE              (0x00U)    /* receive status */
#define _08_IICA_STATUS_TRANSMIT             (0x08U)    /* transmit status */
/* Detection of acknowledge signal (ACKD0) */
#define _00_IICA_ACK_NOTDETECTED             (0x00U)    /* ACK signal was not detected */
#define _04_IICA_ACK_DETECTED                (0x04U)    /* ACK signal was detected */
/* Detection of start condition (STD0) */
#define _00_IICA_START_NOTDETECTED           (0x00U)    /* start condition not detected */
#define _02_IICA_START_DETECTED              (0x02U)    /* start condition detected */
/* Detection of stop condition (SPD0) */
#define _00_IICA_STOP_NOTDETECTED            (0x00U)    /* stop condition not detected */
#define _01_IICA_STOP_DETECTED               (0x01U)    /* stop condition detected */

/*
    IICA Flag Register 0 (IICF0)
*/
/* STT clear flag (STCF0) */
#define _00_IICA_STARTFLAG_GENERATE          (0x00U)    /* generate start condition */
#define _80_IICA_STARTFLAG_UNSUCCESSFUL      (0x80U)    /* start condition generation unsuccessful */
/* IIC bus status flag (IICBSY0) */
#define _00_IICA_BUS_RELEASE                 (0x00U)    /* bus release status */
#define _40_IICA_BUS_COMMUNICATION           (0x40U)    /* bus communication status */
/* Initial start enable trigger (STCEN0) */
#define _00_IICA_START_WITHSTOP              (0x00U)    /* generate start condition upon detecting a stop condition */
#define _02_IICA_START_WITHOUTSTOP           (0x02U)    /* generate start condition no detection a stop condition */
/* Communication reservation function disable bit (IICRSV0) */
#define _00_IICA_RESERVATION_ENABLE          (0x00U)    /* enable communication reservation */
#define _01_IICA_RESERVATION_DISABLE         (0x01U)    /* disable communication reservation */

/*
    IICA Control Register 01 (IICCTL01)
*/
/* Control of address match wakeup (WUP0) */
#define _00_IICA_WAKEUP_STOP                 (0x00U)    /* stop address match wakeup function in STOP mode */
#define _80_IICA_WAKEUP_ENABLE               (0x80U)    /* enable address match wakeup function in STOP mode */
/* Detection of SCL0 pin level (CLD0) */
#define _00_IICA_SCL_LOW                     (0x00U)    /* detect clock line at low level */
#define _20_IICA_SCL_HIGH                    (0x20U)    /* detect clock line at high level */
/* Detection of SDA0 pin level (DAD0) */
#define _00_IICA_SDA_LOW                     (0x00U)    /* detect data line at low level */
#define _10_IICA_SDA_HIGH                    (0x10U)    /* detect data line at high level */
/* Operation mode switching (SMC0) */
#define _00_IICA_MODE_STANDARD               (0x00U)    /* operates in standard mode */
#define _08_IICA_MODE_HIGHSPEED              (0x08U)    /* operates in high-speed mode */
/* Digital filter operation control (DFC0) */
#define _00_IICA_FILTER_OFF                  (0x00U)    /* digital filter off */
#define _04_IICA_FILTER_ON                   (0x04U)    /* digital filter on */
/* IICA used flag */
#define _80_IICA_ADDRESS_COMPLETE            (0x80U)
#define _00_IICA_MASTER_FLAG_CLEAR           (0x00U)

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
#define _40_IICA_DATA_COMPLETE           (0x40U)
#define I2C_CLOCK_DEFAULT                ( 100000UL)
#define I2C_CLOCK_STANDARD               ( 100000UL)
#define I2C_CLOCK_FAST                   ( 400000UL)
#define I2C_CLOCK_FAST_PLUS              (1000000UL)
/* End user code. Do not edit comment generated here */
#endif

