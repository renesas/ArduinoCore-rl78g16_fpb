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
* File Name        : r_cg_it_common.c
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
#include "r_cg_it_common.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

#ifdef USE_INTx
void R_ITL_Create(void)
{
    TML32EN = 1U;    /* start 32-bits IT clock */
    /* Set 32-bits IT settings */
    R_Config_ITL000_Create();
    R_Config_ITL012_Create();
}

/***********************************************************************************************************************
* Function Name: R_ITL_Start_Interrupt
* Description  : This function starts INTITL interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ITL_Start_Interrupt(void)
{
    /* Clear INTITL interrupt request and enable operation */
    ITLIF = 0U;    /* clear INTITL interrupt flag */
    ITLMK = 0U;    /* enable INTITL interrupt */
}

/***********************************************************************************************************************
* Function Name: R_ITL_Stop_Interrupt
* Description  : This function stops INTITL interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ITL_Stop_Interrupt(void)
{
    /* Disable INTITL interrupt operation and clear request */
    ITLMK = 1U;    /* disable INTITL interrupt */
    ITLIF = 0U;    /* clear INTITL interrupt flag */
}
#endif

/***********************************************************************************************************************
* Function Name: R_IT_Set_PowerOn
* Description  : This function starts the clock supply for 12-bits IT.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT_Set_PowerOn(void)
{
    TMKAEN = 1U;    /* starts 12-bits IT clock */
}

/***********************************************************************************************************************
* Function Name: R_IT_Set_PowerOff
* Description  : This function stops the clock supply for 12-bits IT.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT_Set_PowerOff(void)
{
    TMKAEN = 0U;    /* stops 12-bits IT clock */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
