/* Generated configuration header file - do not edit */
/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No 
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all 
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM 
* EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES 
* SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS 
* SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of 
* this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2022 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : r_bsp_config_reference.h
* H/W Platform : GENERIC_RL78_G16
* Description  : 
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 28.12.2022 1.50     First Release
***********************************************************************************************************************/

#ifndef R_BSP_CONFIG_REF_HEADER_FILE
#define R_BSP_CONFIG_REF_HEADER_FILE
/*************************************************
 * MCU information
 *************************************************/
/*
 R 5 F 121  6 8 M SP #V0
 | | |  |   | | |  |  |  
 | | |  |   | | |  |  |  
 | | |  |   | | |  |  |________not used                   Package type
 | | |  |   | | |  |___________not used                   ROM number(Omitted for blank products)
 | | |  |   | | |______________not used                   Fields of application, Ambient operating temperature range
 | | |  |   | |________________BSP_CFG_MCU_PART_ROM_SIZE  ROM capacity
 | | |  |   |__________________BSP_CFG_MCU_PART_PIN_NUM   Pin count
 | | |  |______________________not used                   RL78/G16
 | | |_________________________BSP_CFG_MCU_PART_ROM_TYPE  Device type
 | |___________________________not used                   Renesas MCU
 |_____________________________not used                   Renesas semiconductor product
*/

/* ROM capacity
 B = 16(KB) : 0x0
 C = 32   : 0x1
*/
#define BSP_CFG_MCU_PART_ROM_SIZE (0x1) /* Generated value. Do not edit this manually */

/* Pin count
 1 = 10-pin  : 0x1
 4 = 16-pin  : 0x2
 6 = 20-pin  : 0x3
 7 = 24-pin  : 0x4
 B = 32-pin  : 0x5
*/
#define BSP_CFG_MCU_PART_PIN_NUM (0x5) /* Generated value. Do not edit this manually */

/* group
 121 = RL78/G16 : (true)
*/
#define BSP_CFG_MCU_PART_HAS_DATA_FLASH (true)

/* Device type
 F = Flash memory : 0
*/
#define BSP_CFG_MCU_PART_ROM_TYPE (0)

#if defined(__ICCRL78__)
/* Option byte setting(When using IAR) */
#define BSP_CFG_OPTBYTE0_VALUE (0xEFU) /* Generated value. Do not edit this manually */
#define BSP_CFG_OPTBYTE1_VALUE (0xE7U) /* Generated value. Do not edit this manually */
#define BSP_CFG_OPTBYTE2_VALUE (0xF9U) /* Generated value. Do not edit this manually */
#define BSP_CFG_OPTBYTE3_VALUE (0x05U) /* Generated value. Do not edit this manually */
/* Security ID Codes for On-Chip Debugging setting(When using IAR) */
#define BSP_CFG_SECUID0_VALUE (0x00U) /* Generated value. Do not edit this manually */
#define BSP_CFG_SECUID1_VALUE (0x00U) /* Generated value. Do not edit this manually */
#define BSP_CFG_SECUID2_VALUE (0x00U) /* Generated value. Do not edit this manually */
#define BSP_CFG_SECUID3_VALUE (0x00U) /* Generated value. Do not edit this manually */
#define BSP_CFG_SECUID4_VALUE (0x00U) /* Generated value. Do not edit this manually */
#define BSP_CFG_SECUID5_VALUE (0x00U) /* Generated value. Do not edit this manually */
#define BSP_CFG_SECUID6_VALUE (0x00U) /* Generated value. Do not edit this manually */
#define BSP_CFG_SECUID7_VALUE (0x00U) /* Generated value. Do not edit this manually */
#define BSP_CFG_SECUID8_VALUE (0x00U) /* Generated value. Do not edit this manually */
#define BSP_CFG_SECUID9_VALUE (0x00U) /* Generated value. Do not edit this manually */
#endif

/*************************************************
 * Pin assignment setting
 *************************************************/
/* Peripheral I/O redirection register(PIOR0-PIOR01/PIOR00)
   10/16 pins
 00 : TO00 - P03
      TI00 - P137
 01 : TO00 - P03
      TI00 - P03
 Set PIOR01 to 0. 

   20/24 pins
 00 : TO00 - P03
      TI00 - P137
 01 : TO00 - P03
      TI00 - P03
 10 : TO00 - P21
      TI00 - P20
 11 : TO00 - P20
      TI00 - -

   32 pins
 00 : TO00 - P03
      TI00 - P137
 01 : TO00 - P03
      TI00 - P03
 10 : TO00 - P21
      TI00 - P20
 11 : TO00 - P20
      TI00 - P42
*/
#define BSP_CFG_PIOR01 (1) /* Generated value. Do not edit this manually */
#define BSP_CFG_PIOR00 (0) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR0-PIOR03/PIOR02)
   10/16/20/24/32 pins 
 00 : TI01/TO01 - P02
 01 : TI01/TO01 - P40
 10 : TI01/TO01 - P04
 11 : TI01/TO01 - P01
*/
#define BSP_CFG_PIOR03 (0) /* Generated value. Do not edit this manually */
#define BSP_CFG_PIOR02 (0) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR0-PIOR06/PIOR05/PIOR04)
   10 pins 
 000 : TI02/TO02 - P01
 001 : TI02/TO02 - P00
 Set PIOR06,05 to 0.

   16/20/24/32 pins
 000 : TI02/TO02 - P01
 001 : TI02/TO02 - P00
 010 : TI02/TO02 - P02
 011 : TI02/TO02 - P05
 100 : TI02/TO02 - P41
 101 : TI02/TO02 - -
 110 : TI02/TO02 - -
 111 : TI02/TO02 - -
*/
#define BSP_CFG_PIOR06 (0) /* Generated value. Do not edit this manually */
#define BSP_CFG_PIOR05 (1) /* Generated value. Do not edit this manually */
#define BSP_CFG_PIOR04 (1) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR1-PIOR12/PIOR11/PIOR10)
   10 pins 
 000 : Fixed

   16 pins 
 000 : TO03 - P41
       TI03 - P41
 001 : TO03 - P07
       TI03 - P41
 010 : TO03 - P06
       TI03 - P06
 011 : TO03 - -
       TI03 - -
 Set PIOR12 to 0.

   20 pins 
 000 : TO03 - P41
       TI03 - P41
 001 : TO03 - P07
       TI03 - P41
 010 : TO03 - P06
       TI03 - P06
 011 : TO03 - P20
       TI03 - P20
  Set PIOR12 to 0.

   24 pins 
 000 : TO03 - P41
       TI03 - P41
 001 : TO03 - P07
       TI03 - P41
 010 : TO03 - P06
       TI03 - P06
 011 : TO03 - P20
       TI03 - P20
 100 : TO03 - P10
       TI03 - P10
 101 : TO03 - P11
       TI03 - P11
 110 : TO03 - -
       TI03 - -
 111 : TO03 - -
       TI03 - -

   32 pins 
 000 : TO03 - P41
       TI03 - P41
 001 : TO03 - P07
       TI03 - P41
 010 : TO03 - P06
       TI03 - P06
 011 : TO03 - P20
       TI03 - P20
 100 : TO03 - P10
       TI03 - P10
 101 : TO03 - P11
       TI03 - P11
 110 : TO03 - P16
       TI03 - P16
 111 : TO03 - -
       TI03 - -
*/
#define BSP_CFG_PIOR12 (1) /* Generated value. Do not edit this manually */
#define BSP_CFG_PIOR11 (0) /* Generated value. Do not edit this manually */
#define BSP_CFG_PIOR10 (0) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR1-PIOR14/PIOR13)
   10 pins 
 00 : Fixed

   16 pins
 00 : TI04/TO04 - P07
 01 : TI04/TO04 - Setting prohibited
 10 : TI04/TO04 - Setting prohibited
 11 : TI04/TO04 - Setting prohibited

   20 pins 
 00 : TI04/TO04 - P07
 01 : TI04/TO04 - P23
 10 : TI04/TO04 - Setting prohibited
 11 : TI04/TO04 - Setting prohibited

   24 pins 
 00 : TI04/TO04 - P07
 01 : TI04/TO04 - P23
 10 : TI04/TO04 - Setting prohibited
 11 : TI04/TO04 - P07

   32 pins 
 00 : TI04/TO04 - P07
 01 : TI04/TO04 - P23
 10 : TI04/TO04 - P17
 11 : TI04/TO04 - P07
*/
#define BSP_CFG_PIOR14 (1) /* Generated value. Do not edit this manually */
#define BSP_CFG_PIOR13 (0) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR1-PIOR15)
   10 pins 
0 : Fixed

   16/20/24/32 pins
 0 : TI05/TO05 - P122
 1 : TI05/TO05 - P03
*/
#define BSP_CFG_PIOR15 (1) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR1-PIOR16)
   10/16 pins 
 0 : Fixed

   20/24/32 pins 
 0 : TI06/TO06 - P04
 1 : TI06/TO06 - P22
*/
#define BSP_CFG_PIOR16 (0) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR1-PIOR17)
   10 pins 
 0 : Fixed

   16/20/24/32 pins 
 0 : TI07/TO07 - P121
 1 : TI07/TO07 - P05
*/
#define BSP_CFG_PIOR17 (0) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR0-PIOR21/PIOR20)
   10 pins 
 00 : Fixed

   16/20/24/32 pins 
 00 : SO00/TxD0       - P00
      SI00/RxD0/SDA00 - P01
      SCK00/SCL00     - P02
 01 : SO00/TxD0       - P04
      SI00/RxD0/SDA00 - P05
      SCK00/SCL00     - P06
 10 : SO00/TxD0       - P03
      SI00/RxD0/SDA00 - P04
      SCK00/SCL00     - P05
 11 : SO00/TxD0       - -
      SI00/RxD0/SDA00 - -
      SCK00/SCL00     - -
*/
#define BSP_CFG_PIOR21 (0) /* Generated value. Do not edit this manually */
#define BSP_CFG_PIOR20 (0) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR2-PIOR24/PIOR23/PIOR22)
   10 pins 
 000 : Fixed

   16pins 
 000 : SO11  - P05
       SDA11 - P06
       SI11  - P06
       SCL11 - P07
       SCK11 - P07
 001 : SO11  - P02
       SDA11 - P01
       SI11  - P01
       SCL11 - P00
       SCK11 - P00
 010 : SO11  - Setting prohibited
       SDA11 - Setting prohibited
       SI11  - Setting prohibited
       SCL11 - Setting prohibited
       SCK11 - Setting prohibited
 011 : SO11  - P05
       SDA11 - Setting prohibited
       SI11  - P06
       SCL11 - Setting prohibited
       SCK11 - P07
  Set PIOR24 to 0. 

   20 pins 
 000 : SO11  - P05
       SDA11 - P06
       SI11  - P06
       SCL11 - P07
       SCK11 - P07
 001 : SO11  - P02
       SDA11 - P01
       SI11  - P01
       SCL11 - P00
       SCK11 - P00
 010 : SO11  - P41
       SDA11 - P41
       SI11  - P125
       SCL11 - P20
       SCK11 - P20
 011 : SO11  - P05
       SDA11 - P22
       SI11  - P06
       SCL11 - P23
       SCK11 - P07
 Set PIOR24 to 0. 

   24 pins 
 000 : SO11  - P05
       SDA11 - P06
       SI11  - P06
       SCL11 - P07
       SCK11 - P07
 001 : SO11  - P02
       SDA11 - P01
       SI11  - P01
       SCL11 - P00
       SCK11 - P00
 010 : SO11  - P41
       SDA11 - P41
       SI11  - P125
       SCL11 - P20
       SCK11 - P20
 011 : SO11  - P05
       SDA11 - P22
       SI11  - P06
       SCL11 - P23
       SCK11 - P07
 100 : SO11  - P61
       SDA11 - P61
       SI11  - P60
       SCL11 - P10
       SCK11 - P10
 101 : SO11  - P01
       SDA11 - P00
       SI11  - P00
       SCL11 - P11
       SCK11 - P11
 110 : SO11  - -
       SDA11 - -
       SI11  - -
       SCL11 - -
       SCK11 - -
 111 : SO11  - -
       SDA11 - -
       SI11  - -
       SCL11 - -
       SCK11 - -

   32 pins 
 000 : SO11  - P05
       SDA11 - P06
       SI11  - P06
       SCL11 - P07
       SCK11 - P07
 001 : SO11  - P02
       SDA11 - P01
       SI11  - P01
       SCL11 - P00
       SCK11 - P00
 010 : SO11  - P41
       SDA11 - P41
       SI11  - P125
       SCL11 - P20
       SCK11 - P20
 011 : SO11  - P05
       SDA11 - P22
       SI11  - P06
       SCL11 - P23
       SCK11 - P07
 100 : SO11  - P61
       SDA11 - P61
       SI11  - P60
       SCL11 - P10
       SCK11 - P10
 101 : SO11  - P01
       SDA11 - P00
       SI11  - P00
       SCL11 - P11
       SCK11 - P11
 110 : SO11  - P15
       SDA11 - P14
       SI11  - P14
       SCL11 - P13
       SCK11 - P13
 111 : SO11  - -
       SDA11 - -
       SI11  - -
       SCL11 - -
       SCK11 - -
*/
#define BSP_CFG_PIOR24 (0) /* Generated value. Do not edit this manually */
#define BSP_CFG_PIOR23 (0) /* Generated value. Do not edit this manually */
#define BSP_CFG_PIOR22 (0) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR2-PIOR26/PIOR25)
   10/16 pins 
 00 : Fixed

   20 pins 
 00 : SO20/TxD2       - P21
      SI20/RxD2/SDA20 - P20
      SCK20/SCL20     - P41
 01 : SO20/TxD2       - -
      SI20/RxD2/SDA20 - -
      SCK20/SCL20     - -
 Set PIOR26 to 0. 
 
   24 pins 
 00 : SO20/TxD2       - P21
      SI20/RxD2/SDA20 - P20
      SCK20/SCL20     - P41
 01 : SO20/TxD2       - P17
      SI20/RxD2/SDA20 - P16
      SCK20/SCL20     - P02
 Set PIOR26 to 0. 

   32 pins
 00 : SO20/TxD2       - P21
      SI20/RxD2/SDA20 - P20
      SCK20/SCL20     - P41
 01 : SO20/TxD2       - P17
      SI20/RxD2/SDA20 - P16
      SCK20/SCL20     - P02
 10 : SO20/TxD2       - P15
      SI20/RxD2/SDA20 - P14
      SCK20/SCL20     - P13
 11 : SO20/TxD2       - -
      SI20/RxD2/SDA20 - -
      SCK20/SCL20     - -
*/
#define BSP_CFG_PIOR26 (0) /* Generated value. Do not edit this manually */
#define BSP_CFG_PIOR25 (0) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR3-PIOR31/PIOR30)
   10/16 pins 
 00 : Fixed

   20 pins
 00 : TxD1 - P04
      RxD1 - P03
 01 : TxD1 - P20
      RxD1 - P21
 Set PIOR31 to 0. 

24 pins
 00 : TxD1 - P04
      RxD1 - P03
 01 : TxD1 - P20
      RxD1 - P21
 10 : TxD1 - P11
      RxD1 - P10
 11 : TxD1 - -
      RxD1 - -

32 pins 
 00 : TxD1 - P04
      RxD1 - P03
 01 : TxD1 - P20
      RxD1 - P21
 10 : TxD1 - P11
      RxD1 - P10
 11 : TxD1 - P42
      RxD1 - P20
*/
#define BSP_CFG_PIOR31 (0) /* Generated value. Do not edit this manually */
#define BSP_CFG_PIOR30 (0) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR3-PIOR33/PIOR32)
   10 pins 
 00 : SDAA0 - P04
      SCLA0 - P03
 01 : SDAA0 - P01
      SCLA0 - P00
 Set PIOR33 to 0.

   16/20 pins 
 00 : SDAA0 - P07
      SCLA0 - P06
 01 : SDAA0 - P01
      SCLA0 - P00
 Set PIOR33 to 0.

   24/32 pins 
 00 : SDAA0 - P07
      SCLA0 - P06
 01 : SDAA0 - P01
      SCLA0 - P00
 10 : SDAA0 - P01
      SCLA0 - P00
 11 : SDAA0 - P61
      SCLA0 - P60
*/
#define BSP_CFG_PIOR33 (0) /* Generated value. Do not edit this manually */
#define BSP_CFG_PIOR32 (0) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR4-PIOR40)
   10/16/20/24/32 pins 
 0 : INTP0 - P137
 1 : INTP0 - P125
*/
#define BSP_CFG_PIOR40 (0) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR4-PIOR41)
     10/16 pins 
  0 : Fixed

   20/24/32 pins 
 0 : INTP1 - P125
 1 : INTP1 - P20
*/
#define BSP_CFG_PIOR41 (0) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR4-PIOR43/PIOR42)
     10 pins 
 00 : Fixed

   16/20/24 pins 
 00 : INTP2 - P40
 01 : INTP2 - P122
 Set PIOR43 to 0.

   32 pins 
 00 : INTP2 - P40
 01 : INTP2 - P122
 10 : INTP2 - P13
 11 : INTP2 - P14
*/
#define BSP_CFG_PIOR43 (1) /* Generated value. Do not edit this manually */
#define BSP_CFG_PIOR42 (1) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR4-PIOR45/PIOR44)
     10 pins 
 00 : Fixed

   16/20 pins 
 00 : INTP3 - P04
 01 : INTP3 - P121
 10 : INTP3 - P41
 11 : INTP3 - -

   24/32 pins 
 00 : INTP3 - P04
 01 : INTP3 - P121
 10 : INTP3 - P41
 11 : INTP3 - P60
*/
#define BSP_CFG_PIOR45 (0) /* Generated value. Do not edit this manually */
#define BSP_CFG_PIOR44 (0) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR4-PIOR47/PIOR46)
     10 pins 
 00 : Fixed

   16/20/24 pins 
 00 : INTP4 - P03
 01 : INTP4 - P41
 10 : INTP4 - P121
 11 : INTP4 - -

   32 pins 
 00 : INTP4 - P03
 01 : INTP4 - P41
 10 : INTP4 - P121
 11 : INTP4 - P13
*/
#define BSP_CFG_PIOR47 (1) /* Generated value. Do not edit this manually */
#define BSP_CFG_PIOR46 (1) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR5-PIOR51/PIOR50)
   10 pins 
 00 : Fixed

   16 pins 
 00 : INTP5 - P01
 01 : INTP5 - P07
 10 : INTP5 - P121
 11 : INTP5 - -

   20/24/32 pins 
 00 : INTP5 - P01
 01 : INTP5 - P07
 10 : INTP5 - P121
 11 : INTP5 - P22
*/
#define BSP_CFG_PIOR51 (0) /* Generated value. Do not edit this manually */
#define BSP_CFG_PIOR50 (0) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR5-PIOR53/PIOR52)
   10 pins 
 00 : Fixed

   16 pins 
 00 : INTP6 - P00
 01 : INTP6 - P05
 Set PIOR53 to 0.

   24 pins 
 00 : INTP6 - P00
 01 : INTP6 - P05
 10 : INTP6 - P23
 11 : INTP6 - -

   24/32 pins 
 00 : INTP6 - P00
 01 : INTP6 - P05
 10 : INTP6 - P23
 11 : INTP6 - P60
*/
#define BSP_CFG_PIOR53 (0) /* Generated value. Do not edit this manually */
#define BSP_CFG_PIOR52 (1) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR5-PIOR55/PIOR54)
   10 pins 
 00 : Fixed

   16 pins 
 00 : INTP7 - P02
 01 : INTP7 - P06
 Set PIOR55 to 0.

   20 pins 
 00 : INTP7 - P02
 01 : INTP7 - P06
 10 : INTP7 - P21
 11 : INTP7 - -

   24/32 pins 
 00 : INTP7 - P02
 01 : INTP7 - P06
 10 : INTP7 - P21
 11 : INTP7 - P61
*/
#define BSP_CFG_PIOR55 (0) /* Generated value. Do not edit this manually */
#define BSP_CFG_PIOR54 (0) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR5-PIOR56)
   10/16/20/24 pins 
 0 : Fixed

   32 pins 
 0 : INTP8 - P10
 1 : INTP8 - P12
*/
#define BSP_CFG_PIOR56 (0) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR5-PIOR57)
   10/16/20/24 pins
 0 : Fixed

   32 pins 
 0 : INTP9 - P11
 1 : INTP9 - P15
*/
#define BSP_CFG_PIOR57 (0) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR6-PIOR62/PIOR61/PIOR60)
   10 pins 
 000 : PCLBUZ0 - P02
 001 : PCLBUZ0 - P40
 Set PIOR62,61 to 0.

   16/20 pins 
 000 : PCLBUZ0 - P02
 001 : PCLBUZ0 - P40
 010 : PCLBUZ0 - P06
 011 : PCLBUZ0 - -
 Set PIOR62 to 0.

   24/32 pins 
 000 : PCLBUZ0 - P02
 001 : PCLBUZ0 - P40
 010 : PCLBUZ0 - P06
 011 : PCLBUZ0 - P10
 100 : PCLBUZ0 - P11
 101 : PCLBUZ0 - -
 110 : PCLBUZ0 - -
 111 : PCLBUZ0 - -
*/
#define BSP_CFG_PIOR62 (0) /* Generated value. Do not edit this manually */
#define BSP_CFG_PIOR61 (0) /* Generated value. Do not edit this manually */
#define BSP_CFG_PIOR60 (0) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR6-PIOR65/PIOR64/PIOR63)
   10 pins 
 000 : VCOUT0 - P02
 001 : VCOUT0 - P125
 010 : VCOUT0 - P02
 011 : VCOUT0 - -
 100 : VCOUT0 - P02
 101 : VCOUT0 - -
 110 : VCOUT0 - P125
 111 : VCOUT0 - -

   16/20/24/32pin 
 000 : VCOUT0 - P02
       VCOUT1 - P07
 001 : VCOUT0 - P125
       VCOUT1 - P07
 010 : VCOUT0 - P02
       VCOUT1 - P125
 011 : VCOUT0 - P41
       VCOUT1 - P07
 100 : VCOUT0 - P02
       VCOUT1 - P41
 101 : VCOUT0 - P41
       VCOUT1 - P125
 110 : VCOUT0 - P125
       VCOUT1 - P41
 111 : VCOUT0 - -
       VCOUT1 - -
*/
#define BSP_CFG_PIOR65 (0) /* Generated value. Do not edit this manually */
#define BSP_CFG_PIOR64 (0) /* Generated value. Do not edit this manually */
#define BSP_CFG_PIOR63 (0) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register(PIOR6-PIOR67/PIOR66)
   10 pins
 00 : Fixed

   16/20 pins 
 00 : RTC1HZ - P41
 01 : RTC1HZ - P00
 Set PIOR67 to 0.

   24 pins 
 00 : RTC1HZ - P41
 01 : RTC1HZ - P00
 10 : RTC1HZ - P11
 11 : RTC1HZ - -
 
   32 pins 
 00 : RTC1HZ - P41
 01 : RTC1HZ - P00
 10 : RTC1HZ - P11
 11 : RTC1HZ - P13
*/
#define BSP_CFG_PIOR67 (0) /* Generated value. Do not edit this manually */
#define BSP_CFG_PIOR66 (0) /* Generated value. Do not edit this manually */

/***********************************************************
 * Invalid memory access detection control register (IAWCTL)
 ***********************************************************/
/* RAM guard space(GRAM0-1)
 0 : Disabled. RAM can be written to.
 1 : The 128 bytes of space starting at the start address in the RAM.
 2 : The 256 bytes of space starting at the start address in the RAM.
 3 : The 512 bytes of space starting at the start address in the RAM.
*/
#define BSP_CFG_RAM_GUARD_FUNC (0)

/* Guard of control registers of port function(GPORT)
 0 : Disabled. Control registers of the port function can be read from or written to.
 1 : Enabled. Writing to control registers of the port function is disabled. Reading is enabled.
 [Guarded SFRs] PMxx, PUxx, POMxx, PMCxx, PIOR0-PIOR6, TSSEL0-1, VTSEL
 Note:Pxx(Port register) is not guarded.
*/
#define BSP_CFG_PORT_FUNCTION_GUARD (0)

/* Guard of registers of interrupt function(GINT)
 0 : Disabled. Registers of the interrupt function can be read from or written to.
 1 : Enabled. Writing to registers of the interrupt function is disabled. Reading is enabled.
 [Guarded SFRs] IFxx, MKxx, PRxx, EGPx, EGNx
*/
#define BSP_CFG_INT_FUNCTION_GUARD (0)

/* Guard of control registers of clock control function, voltage detector,
   and RAM parity error detection function(GCSC)
 0 : Disabled. Control registers of the clock control function, voltage detector
     and RAM parity error detection function can be read from or written to.
 1 : Enabled. Writing to control registers of the clock control function, voltage detector
     and RAM parity error detection function is disabled. Reading is enabled.
 [Guarded SFRs] CMC, CSC, OSTS, CKC, PERx, OSMC, RPECTL
*/
#define BSP_CFG_CHIP_STATE_CTRL_GUARD (0)

/*************************************************
 * Definition for switching functions
 *************************************************/

/* Start up select
 0 : Enable BSP startup program.
 1 : Disable BSP startup program.(e.g. Using user startup program.)
*/
#define BSP_CFG_STARTUP_DISABLE (0)

/* Initialization of peripheral functions by Code Generator/Smart Configurator
 0 : Disable initialization of peripheral functions by Code Generator/Smart Configurator.
 1 : Enable initialization of peripheral functions by Code Generator/Smart Configurator.
*/
#define BSP_CFG_CONFIGURATOR_SELECT (1)

/* Version number of Smart Configurator.
   This macro definitions is updated by Smart Configurator.
   If you are using e2studio, set the following values.
   2021-04 : 1001
   2021-07 : 1010
   2021-10 : 1010
   2022-01 : 1030
   If you are using the standalone version of Smart Configurator,
   set the following values.
   v1.0.1  : 1001
   v1.1.0  : 1010
   v1.3.0  : 1030
*/
#define BSP_CFG_CONFIGURATOR_VERSION    (1050) /* Generated value. Do not edit this manually */

/* API function disable(R_BSP_StartClock, R_BSP_StopClock)
 0 : Enable API functions
 1 : Disable API functions
*/
#define BSP_CFG_CLOCK_OPERATION_API_FUNCTIONS_DISABLE (1)

/* API function disable(R_BSP_GetFclkFreqHz)
 0 : Enable API functions
 1 : Disable API functions
*/
#define BSP_CFG_GET_FREQ_API_FUNCTIONS_DISABLE (0)

/* API function disable(R_BSP_SetClockSource)
 0 : Enable API functions
 1 : Disable API functions
*/
#define BSP_CFG_SET_CLOCK_SOURCE_API_FUNCTIONS_DISABLE (1)

/* API function disable(R_BSP_ChangeClockSetting)
 0 : Enable API functions
 1 : Disable API functions
*/
#define BSP_CFG_CHANGE_CLOCK_SETTING_API_FUNCTIONS_DISABLE (1)

/* API function disable(R_BSP_SoftwareDelay)
 0 : Enable API functions
 1 : Disable API functions
*/
#define BSP_CFG_SOFTWARE_DELAY_API_FUNCTIONS_DISABLE (1)

/* Parameter check enable
 0 : Disable parameter check.
 1 : Enable parameter check.
*/
#define BSP_CFG_PARAM_CHECKING_ENABLE (1)

/*************************************************
 * Clock settings
 *************************************************/
/* High-speed system clock frequency(fMX)
   Clock operation mode control register(CMC)
    XTSEL/EXCLK/OSCSEL
 0 : Port
 1 : fX(Crystal/ceramic resonator connection)
 2 : fEX(External clock input)
*/
#define BSP_CFG_HISYSCLK_SOURCE (0) /* Generated value. Do not edit this manually */

/* High-speed system clock frequency(fMX)
   Clock operation status control register(CSC)
   MSTOP
 (X1 oscillation mode)
  0 : X1 oscillator operating
  1 : X1 oscillator stopped
 (External clock input mode)
  0 : External clock from EXCLK pin is valid
  1 : External clock from EXCLK pin is invalid
 (Port mode)
  0 : Port
  1 : Port
*/
#define BSP_CFG_HISYSCLK_OPERATION (1) /* Generated value. Do not edit this manually */

/* Subsystem clock oscillator clock frequency(fSX)
   Clock operation mode control register(CMC)
    XTSEL/EXCLKS/OSCSELS
 0 : Port
 1 : fXT(Crystal resonator connection)
 2 : fEXS(External clock input)
*/
#define BSP_CFG_SUBCLK_SOURCE (1) /* Generated value. Do not edit this manually */

/* Subsystem clock oscillator clock frequency(fSX)
   Clock operation status control register(CSC)
   XTSTOP
 (XT1 oscillation mode)
  0 : XT1 oscillator operating
  1 : XT1 oscillator stopped
 (External clock input mode)
  0 : External clock from EXCLKS pin is valid
  1 : External clock from EXCLKS pin is invalid
 (Port mode)
  0 : Input port
  1 : Input port
*/
#define BSP_CFG_SUBCLK_OPERATION (0) /* Generated value. Do not edit this manually */

/* Main system clock(fMAIN) operation control
   System clock control register(CKC)
   MCM0
 0 : Selects the high-speed on-chip oscillator clock(fIH) as the main system clock(fMAIN)
 1 : Selects the high-speed system clock(fMX) as the main system clock(fMAIN)
*/
#define BSP_CFG_MAINCLK_SOURCE (0) /* Generated value. Do not edit this manually */

/* Selection of CPU/peripheral hardware clock(fCLK)
   System clock control register(CKC)
   CSS
 0 : Main system clock(fMAIN)
 1 : Subsystem clock(fSUB)
*/
#define BSP_CFG_FCLK_SOURCE (0) /* Generated value. Do not edit this manually */

/* XT1 oscillator oscillation mode selection
   Clock operation mode control register(CMC)
   AMPHS1, AMPHS0
 0 : Low power consumption oscillation (default)
 1 : Normal oscillation
 2 : Extra low power consumption oscillation 
 3 : Setting prohibited
*/
#define BSP_CFG_XT1_OSCMODE (0) /* Generated value. Do not edit this manually */

/* Input clock frequency in Hz(High-speed system clock(X1))
*/
#define BSP_CFG_FMX_HZ (12000000)

/* Control of X1 clock oscillation frequency
   Clock operation mode control register(CMC)
   AMPH
 0 : 1 MHz <= fX <= 10 MHz
 1 : 10 MHz < fX <= 12 MHz
 Set the value corresponding to the setting of BSP_CFG_FMX_HZ
*/

/* X1 clock oscillation stabilization time selection
   Oscillation stabilization time select register(OSTS)
   OSTS2, OSTS1, OSTS0
 0 : 2^8/fX(fX = 10MHz : 25.6us, fX = 20MHz : 12.8us)
 1 : 2^9/fX(fX = 10MHz : 51.2us, fX = 20MHz : 25.6us)
 2 : 2^10/fX(fX = 10MHz : 102us, fX = 20MHz : 51.2us)
 3 : 2^11/fX(fX = 10MHz : 204us, fX = 20MHz : 102us)
 4 : 2^13/fX(fX = 10MHz : 819us, fX = 20MHz : 409us)
 5 : 2^15/fX(fX = 10MHz : 3.27ms, fX = 20MHz : 1.63ms)
 6 : 2^17/fX(fX = 10MHz : 13.1ms, fX = 20MHz : 6.55ms)
 7 : 2^18/fX(fX = 10MHz : 26.2ms, fX = 20MHz : 13.1ms)
*/
#define BSP_CFG_X1_WAIT_TIME_SEL (0)

/* Setting in STOP mode or in HALT mode while the CPU is opeating with subsystem clock.
   Operation speed mode control register(OSMC)
   RTCLPC
 0 : Enables supply of subsystem clock X to peripheral functions.
 1 : Stops supply of the subsystem clock to peripheral functions
     other than the realtime clock2 and 12-bit interval timer.
*/
#define BSP_CFG_ALLOW_FSUB_IN_STOPHALT (0) /* Generated value. Do not edit this manually */

/* Selection of the operating clock for the realtime clock2, 32-bit interval timer.
   Operation speed mode control register(OSMC)
   WUTMMCK0
 0 : Subsystem clock
 1 : Low-speed on-chip oscillator clock
*/
#define BSP_CFG_RTC_OUT_CLK_SOURCE (0) /* Generated value. Do not edit this manually */

/* Selection of high-speed on-chip oscillator clock frequency
   High-Speed On-Chip Oscillator Frequency Select Register(HOCODIV)
   HOCODIV2/HOCODIV1/HOCODIV0
  1 : fIH = 16 MHz
  2 : fIH = 8 MHz
  3 : fIH = 4 MHz
  4 : fIH = 2 MHz
  5 : fIH = 1 MHz
  Other than above : Setting prohibited
 */
#define BSP_CFG_HOCO_DIVIDE (1) /* Generated value. Do not edit this manually */

/* Operation setting at initial setting */
/* Starts the high-speed on-chip oscillator at initialization
 0 : Stops the high-speed on-chip oscillator at initialization
 1 : Starts the high-speed on-chip oscillator at initialization
*/
#define BSP_CFG_FIH_START_ON_STARTUP (1) /* Generated value. Do not edit this manually */

/* This macro lets other modules no if a RTOS is being used.
   0 = RTOS is not used.
   1 = FreeRTOS is used.(This is not available.)
   2 = embOS is used.(This is not available.)
   3 = MicroC_OS is used.(This is not available.)
   4 = Renesas ITRON is used.
*/
#define BSP_CFG_RTOS_USED               (0)

/* Loop count using the main system clock. */
/* The loop count refers to a loop consisting of a "for" statement that executes a single NOP instruction. */
/* Subsystem clock oscillation stabilization wait time(T.B.D) */
#define BSP_CFG_SUBWAITTIME              (800000U)

/* High-speed on-chip oscillator  clock oscillation stabilization wait time(T.B.D) */
#define BSP_CFG_FIHWAITTIME              (30U)

/* If the user would like to determine if a warm start reset has occurred, then they may enable one or more of the
   following callback definitions AND provide a call back function name for the respective callback
   function (to be defined by the user). Setting BSP_CFG_USER_WARM_START_CALLBACK_PRE_INITC_ENABLED = 1 will result
   in a callback to the user defined my_sw_warmstart_prec_function just prior to the initialization of the C
   runtime environment by bsp_init_system.
   Setting BSP_CFG_USER_WARM_START_CALLBACK_POST_INITC_ENABLED = 1 will result in a callback to the user defined
   my_sw_warmstart_postc_function just after the initialization of the C runtime environment by bsp_init_hardware.
*/
#define BSP_CFG_USER_WARM_START_CALLBACK_PRE_INITC_ENABLED     (0)
#define BSP_CFG_USER_WARM_START_PRE_C_FUNCTION                 my_sw_warmstart_prec_function

#define BSP_CFG_USER_WARM_START_CALLBACK_POST_INITC_ENABLED    (0)
#define BSP_CFG_USER_WARM_START_POST_C_FUNCTION                my_sw_warmstart_postc_function

#define BSP_CFG_WDT_REFRESH_ENABLE                             (0)

#endif /* R_BSP_CONFIG_REF_HEADER_FILE */

