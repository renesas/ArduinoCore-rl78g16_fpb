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
* File Name        : r_cg_ad.h
* Version          : 1.0.1
* Device(s)        : R5F121BCxFP
* Description      : General header file for ADC peripheral.
* Creation Date    : 
***********************************************************************************************************************/

#ifndef ADC_H
#define ADC_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Peripheral Enable Register 0 (PER0)
*/
/* Control of A/D converter input clock (ADCEN) */
#define _00_AD_CLOCK_STOP                      (0x00U)    /* stop supply of input clock */
#define _20_AD_CLOCK_SUPPLY                    (0x20U)    /* supply input clock */

/*
    A/D Converter Mode Register 0 (ADM0)
*/
/* A/D conversion operation control (ADCS) */
#define _00_AD_RESET_RELEASE                   (0x00U)    /* stop supply of input clock */
#define _20_AD_RESET_SET                       (0x20U)    /* supply input clock */
#define _80_AD_CONVERSION_ENABLE               (0x80U)    /* enable AD conversion operation control */
#define _00_AD_CONVERSION_DISABLE              (0x00U)    /* disable AD conversion operation control */
/* A/D conversion clock selection (FR1 - FR0) */
#define _00_AD_CONVERSION_CLOCK_8              (0x00U)    /* fCLK/8 */
#define _08_AD_CONVERSION_CLOCK_4              (0x08U)    /* fCLK/4 */
#define _10_AD_CONVERSION_CLOCK_2              (0x10U)    /* fCLK/2 */
#define _18_AD_CONVERSION_CLOCK_1              (0x18U)    /* fCLK/1 */
/* Specification A/D conversion time mode (LV0) */
#define _00_AD_TIME_MODE_NORMAL_1              (0x00U)    /* normal 1 mode */
#define _02_AD_TIME_MODE_NORMAL_2              (0x02U)    /* normal 2 mode */
#define _04_AD_TIME_MODE_LOWVOLTAGE_1          (0x04U)    /* low-voltage 1 mode */
#define _06_AD_TIME_MODE_LOWVOLTAGE_2          (0x06U)    /* low-voltage 2 mode */
/* A/D comparator operation control (ADCE) */
#define _01_AD_COMPARATOR_ENABLE               (0x01U)    /* enable comparator operation control */
#define _00_AD_COMPARATOR_DISABLE              (0x00U)    /* disable comparator operation control */

/*
    Analog Input Channel Specification Register (ADS)
*/
/* Specification of analog input channel (ADS3 - ADS0) */
#define _00_AD_INPUT_CHANNEL_0                 (0x00U)    /* ANI0 */
#define _01_AD_INPUT_CHANNEL_1                 (0x01U)    /* ANI1 */
#define _02_AD_INPUT_CHANNEL_2                 (0x02U)    /* ANI2 */
#define _03_AD_INPUT_CHANNEL_3                 (0x03U)    /* ANI3 */
#define _04_AD_INPUT_CHANNEL_4                 (0x04U)    /* ANI4 */
#define _05_AD_INPUT_CHANNEL_5                 (0x05U)    /* ANI5 */
#define _06_AD_INPUT_CHANNEL_6                 (0x06U)    /* ANI6 */
#define _07_AD_INPUT_CHANNEL_7                 (0x07U)    /* ANI7 */
#define _08_AD_INPUT_CHANNEL_8                 (0x08U)    /* ANI8 */
#define _09_AD_INPUT_CHANNEL_9                 (0x09U)    /* ANI9 */
#define _0A_AD_INPUT_CHANNEL_10                (0x0AU)    /* ANI10 */
#define _0B_AD_INPUT_CTSUTSCAP                 (0x0BU)    /* CTSU TSCAP voltage */
#define _0C_AD_INPUT_TEMPERSENSOR_0            (0x0CU)    /* temperature sensor output voltage */
#define _0D_AD_INPUT_INTERREFVOLT              (0x0DU)    /* internal reference voltage output is the input channel */
/*
    A/D Converter Mode Register 2 (ADM2)
*/
/* A/D resolution selection (ADTYP) */
/*
    AD Converter Mode Register 1 (ADM1)
*/
/* AD trigger mode selection (ADTMD1, ADTMD0) */
#define _00_AD_TRIGGER_SOFTWARE                (0x00U)    /* software trigger mode (no wait) */
#define _80_AD_TRIGGER_HARDWARE_NOWAIT         (0x80U)    /* hardware trigger mode (no wait) */
#define _C0_AD_TRIGGER_HARDWARE_WAIT           (0xC0U)    /* hardware/software trigger mode (wait) */
/* fCLK input frequency setting (ADLSP)*/
#define _00_AD_FCLK_BETWEEN_4_32               (0x00U)    /* continuous conversion mode */
#define _08_AD_FCLK_BETWEEN_1_4                (0x08U)    /* one-shot conversion mode */
/* AD conversion mode selection (ADSCM)*/
#define _00_AD_CONVMODE_CONSELECT              (0x00U)    /* continuous conversion mode */
#define _20_AD_CONVMODE_ONESELECT              (0x20U)    /* one-shot conversion mode */
/* Trigger signal selection (ADTRS2, ADTRS1, ADTRS0) */
#define _00_AD_TRIGGER_INTTM01                 (0x00U)    /* INTTM01 */
#define _02_AD_TRIGGER_INTRTC                  (0x02U)    /* INTRTC */
#define _03_AD_TRIGGER_INTITL                  (0x03U)    /* INTITL */
#define _04_AD_TRIGGER_ELCL                    (0x04U)    /* ELCL event*/

/*
    AD Converter Mode Register 2 (ADM2)
*/
/* AD VREF(+) selection (ADREFP1, ADREFP0) */
#define _00_AD_POSITIVE_VDD                    (0x00U)    /* use VDD as VREF(+) */
#define _40_AD_POSITIVE_AVREFP                 (0x40U)    /* use AVREFP as VREF(+) */
#define _80_AD_POSITIVE_INTERVOLT              (0x80U)    /* use internal voltage as VREF(+) */
#define _C0_AD_POSITIVE_DISCHARGE              (0xC0U)    /* discharge */
#define _3F_AD_POSITIVE_CLEAR                  (0x3FU)    /* clear ADREFP1 and ADREFP0 */
/* AD VREF(-) selection (ADREFM) */
#define _00_AD_NEGATIVE_VSS                    (0x00U)    /* use VSS as VREF(-) */
#define _20_AD_NEGATIVE_AVREFM                 (0x20U)    /* use AVREFM as VREF(-) */
/* AD conversion result upper/lower bound value selection (ADRCK) */
#define _00_AD_AREA_MODE_1                     (0x00U)    /* generates INTAD when ADLL <= ADCRH <= ADUL */
#define _08_AD_AREA_MODE_2_3                   (0x08U)    /* generates INTAD when ADUL < ADCRH or ADLL > ADCRH */
/* AD wake-up function selection (AWC) */
#define _00_AD_WAKEUP_OFF                      (0x00U)    /* stop wake-up function */
#define _04_AD_WAKEUP_ON                       (0x04U)    /* use wake-up function */
/* AD resolution selection (ADTYP1, ADTYP0) */
#define _00_AD_RESOLUTION_10BIT                (0x00U)    /* 10 bits */
#define _01_AD_RESOLUTION_8BIT                 (0x01U)    /* 8 bits */

/*
    A/D Test Register (ADTES)
*/
/* A/D test mode signal (ADTES1, ADTES0)*/
#define _00_AD_NORMAL_INPUT                    (0x00U)    /* normal mode */
#define _02_AD_TEST_VSS                        (0x02U)    /* use VSS as test signal */
#define _03_AD_TEST_VDD                        (0x03U)    /* use VDD as test signal */

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

