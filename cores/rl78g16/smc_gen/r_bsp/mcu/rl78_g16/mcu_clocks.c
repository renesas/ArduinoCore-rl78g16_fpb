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
* Copyright (C) 2023 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : mcu_clocks.c
* Description  :
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 31.01.2023 1.50     First Release
*         : 28.02.2023 1.60     Added space after *.
*         : 31.08.2023 1.61     Changed comment about setting CMC register.
*                               Removed the process of setting the CSS bit to 0, 
*                               when SYSCLK is set as the argument of the R_BSP_SetClockSource function.
*         : 30.11.2023 1.62     Added processing to check CLS after setting CSS bit.
*                               Added processing to check MCS after setting MCM0 bit.
*                               Added parentheses to the #if condition to clarify the order of evaluation.
*                               Adjusted indentation of equal sign.
***********************************************************************************************************************/
/*************************************************
 * Includes  <System Includes> , "Project Includes"
 *************************************************/
#include "platform.h"

/*************************************************
 * Macro definitions
 *************************************************/

/*************************************************
 * External function Prototypes
 *************************************************/

/*************************************************
 * Private global variables and functions
 *************************************************/
/* Frequency of the high-speed on-chip oscillator */
#if BSP_CFG_GET_FREQ_API_FUNCTIONS_DISABLE == 0
const uint32_t g_fih_hz[] = {
    0,                  /* Setting prohibited */
    16000000,
    8000000,
    4000000,
    2000000,
    1000000,
    0,                  /* Setting prohibited */
    0                   /* Setting prohibited */
};
#endif

/*************************************************
 * Function definition
 *************************************************/
/*************************************************
 * Function name: start_clock
 * Description  : Start the specified clock
 * Arguments    : Clock to start
 * Return value : BSP_OK if the specified clock is started.
 *                BSP_ARG_ERROR if the specified clock is incorrect.
**************************************************/
#if BSP_CFG_CLOCK_OPERATION_API_FUNCTIONS_DISABLE == 0
e_bsp_err_t start_clock(e_clock_mode_t mode)
{
    e_bsp_err_t           status = BSP_OK;
#if BSP_CFG_MCU_PART_PIN_NUM >= 1
#if BSP_CFG_HISYSCLK_SOURCE == 1
    uint8_t             tmp_stab_wait;
    uint8_t             tmp_stab_set;
#endif
#endif
    volatile uint32_t   w_count;

    switch (mode)
    {
#if BSP_CFG_MCU_PART_PIN_NUM >= 1
        case SYSCLK:

            if (1U == MSTOP)
            {
                MSTOP = 0U;

#if BSP_CFG_HISYSCLK_SOURCE == 1
                tmp_stab_set = (uint8_t)~(0x7FU >> OSTS);

                /* WAIT_LOOP */
                do
                {
                    tmp_stab_wait  = OSTC;
                    tmp_stab_wait &= tmp_stab_set;
                }
                while (tmp_stab_wait != tmp_stab_set);
#endif
            }

            break;

        case SXCLK:

            if (1U == XTSTOP)
            {
                XTSTOP = 0U;

#if BSP_CFG_SUBCLK_SOURCE == 1
                /* WAIT_LOOP */
                for (w_count = 0U; w_count <= BSP_CFG_SUBWAITTIME; w_count++)
                {
#if BSP_CFG_WDT_REFRESH_ENABLE == 0
                    BSP_NOP();
#else
                    WDTE = 0xACU;
#endif
                }
#endif
            }

            break;
#endif /* BSP_CFG_MCU_PART_PIN_NUM >= 1 */

        case HIOCLK:

            if (1U == HIOSTOP)
            {
                HIOSTOP = 0U;

                /* WAIT_LOOP */
                for (w_count = 0U; w_count <= BSP_CFG_FIHWAITTIME; w_count++)
                {
                    BSP_NOP();
                }
            }

            break;

        default:

            status = BSP_ARG_ERROR;

            break;

    }

    return status;
} /* End of function start_clock() */
#endif /* BSP_CFG_CLOCK_OPERATION_API_FUNCTIONS_DISABLE == 0 */

/*************************************************
 * Function name: stop_clock
 * Description  : Stop the specified clock
 * Arguments    : Clock to stop
 * Return value : BSP_OK if the specified clock is stopped.
 *                BSP_ARG_ERROR if the specified clock is incorrect.
**************************************************/
#if BSP_CFG_CLOCK_OPERATION_API_FUNCTIONS_DISABLE == 0
e_bsp_err_t stop_clock(e_clock_mode_t mode)
{
    e_bsp_err_t    status = BSP_OK;

    switch (mode)
    {
#if BSP_CFG_MCU_PART_PIN_NUM >= 1
        case SYSCLK:

            MSTOP = 1U;

            break;

        case SXCLK:

            XTSTOP = 1U;

            break;
#endif

        case HIOCLK:

            HIOSTOP = 1U;

            break;

        default:

            status = BSP_ARG_ERROR;

            break;

    }

    return status;
} /* End of function stop_clock() */
#endif /* BSP_CFG_CLOCK_OPERATION_API_FUNCTIONS_DISABLE == 0 */

/*************************************************
 * Function name: set_fclk_clock_source
 * Description  : Switch CPU/peripheral hardware clock(fCLK) clock source.
 * Arguments    : Clock to switch.
 * Return value : BSP_OK when switching to the specified clock.
 *                BSP_ERROR1 The specified clock is not oscillating.
 *                BSP_ERROR2 When switching between clock resource, a clock resource that is not
 *                           oscillating may have been switched to.
 *                BSP_ERROR3 An unsupported state transition was specified. Refer to the user's manual.
 *                BSP_ARG_ERROR An invalid argument was input.
 * Attention    : Start the clock to switch to before calling this function.
**************************************************/
#if BSP_CFG_SET_CLOCK_SOURCE_API_FUNCTIONS_DISABLE == 0
e_bsp_err_t set_fclk_clock_source(e_clock_mode_t mode)
{
    e_bsp_err_t       status = BSP_OK;
    e_clock_mode_t    old_mode;

    /* Get current clock source */
    if (1U == CLS)
    {
        old_mode = SXCLK;
    }
    else
    {
        if (1U == MCS)
        {
            old_mode = SYSCLK;
        }
        else
        {
            old_mode = HIOCLK;
        }
    }

    /* Only switch if the current clock source and the
     * specified clock source are different.
     */
    if (mode != old_mode)
    {
        switch (mode)
        {
            case HIOCLK:

                if (1U == HIOSTOP)
                {
                    /* Error if the high-speed on-chip oscillator is stopped. */
                    status = BSP_ERROR1;
                }
#if BSP_CFG_PARAM_CHECKING_ENABLE == 1
                else if ((1U == CLS) && (0U != MCS))
                {
                    /* Error if the high-speed on-chip oscillator is not selected. */
                    status = BSP_ERROR2;
                }
#endif
                else
                {
                    CSS = 0U;

                    /* WAIT_LOOP */
                    /* Confirm that Main system clock(fMAIN) is selected. */
                    while (1U == CLS)
                    {
                        ;
                    }

                    MCM0 = 0U;

                    /* WAIT_LOOP */
                    /* Confirm that high-speed on-chip oscillator clock(fIH) is selected. */
                    while (1U == MCS)
                    {
                        ;
                    }
                }

                break;

#if BSP_CFG_MCU_PART_PIN_NUM >= 1
            case SYSCLK:

                if (1U == MSTOP)
                {
                    /* Error if the high-speed system clock is stopped. */
                    status = BSP_ERROR1;
                }
#if BSP_CFG_PARAM_CHECKING_ENABLE == 1
                else if ((CMC & 0x40U) != 0x40U)
                {
                    /* Error if the high-speed system clock is invalid. */
                    status = BSP_ERROR1;
                }
                else if (SXCLK == old_mode)
                {
                    /* Error if switch SXCLK to SYSCLK. */
                    status = BSP_ERROR3;
                }
#endif
                else
                {
                    MCM0 = 1U;

                    /* WAIT_LOOP */
                    /* Confirm that high-speed system clock(fMX) is selected. */
                    while (0U == MCS)
                    {
                        ;
                    }
                }

                break;

            case SXCLK:

                if (1U == XTSTOP)
                {
                    /* Error if the subsystem clock is stopped. */
                    status = BSP_ERROR1;
                }
#if BSP_CFG_PARAM_CHECKING_ENABLE == 1
                else if ((CMC & 0x18U) != 0x18U)
                {
                    /* Error if the subsystem clock is invalid. */
                    status = BSP_ERROR1;
                }
                else if (SYSCLK == old_mode)
                {
                    /* Error if switch SYSCLK to SXCLK. */
                    status = BSP_ERROR3;
                }
#endif
                else
                {
                    CSS = 1U;

                    /* WAIT_LOOP */
                    /* Confirm that Subsystem clock(fSUB) is selected. */
                    while (0U == CLS)
                    {
                        ;
                    }
                }

                break;
#endif /* BSP_CFG_MCU_PART_PIN_NUM >= 1 */

            default:

                status = BSP_ARG_ERROR;

                break;

        }
    }

    return status;
} /* End of function set_fclk_clock_source() */
#endif /* BSP_CFG_SET_CLOCK_SOURCE_API_FUNCTIONS_DISABLE == 0 */

/*************************************************
 * Function name: get_fclk_freq_hz
 * Description  : Returns CPU/peripheral hardware clock(fCLK) frequency.
 * Arguments    : none
 * Return value : CPU/peripheral hardware clock(fCLK) frequency specified by the r_bsp.
 * Attention    : Error if 0Hz is returned.
 *                When fCLK is a high-speed on-chip oscillator, 0Hz is returned
 *                when the value of the register to which it refers is out of the allowable range.
**************************************************/
#if BSP_CFG_GET_FREQ_API_FUNCTIONS_DISABLE == 0
uint32_t get_fclk_freq_hz(void)
{
    uint32_t    sys_clock_src_freq;

    /* fCLK clock source is fSUB */
    /* fCLK : CPU/peripheral hardware clock */
    /* fSUB : Subsystem clock */
    if (1U == CLS)
    {
        /* fSUB clock source is fXT */
        /* fSUB : Subsystem clock */
        /* fXT : XT1 clock oscillation */
        sys_clock_src_freq = BSP_SUB_CLOCK_HZ;
    }
    /* fCLK clock source is fMAIN */
    /* fCLK  : CPU/peripheral hardware clock */
    /* fMAIN : Main system clock */
    else
    {
        /* fMAIN clock source is fMX */
        /* fMAIN : Main system clock */
        /* fMX   : High-speed system clock */
        if (1U == MCS)
        {
            /* fMX clock source is fX */
            /* fMX : High-speed system clock */
            /* fX  : X1 clock oscillation */
            sys_clock_src_freq = BSP_CFG_FMX_HZ;
        }
        /* fMAIN clock source is fIH */
        /* fMAIN : Main system clock */
        /* fIH  : High-speed on-chip oscillator clock */
        else
        {
            sys_clock_src_freq = g_fih_hz[HOCODIV];
        }
    }

    return sys_clock_src_freq;
} /* End of function get_fclk_freq_hz() */
#endif /* BSP_CFG_GET_FREQ_API_FUNCTIONS_DISABLE == 0 */

/**************************************************
 * Function name: change_clock_setting
 * Description  : Change the specified clock setting.
 * Arguments    : Clock to change setting.
 *              : Value to set for the specified clock.
 * Return value : BSP_OK if the specified clock setting is changed.
 *                BSP_ERROR1 When HIOCLK is specified.
 *                           when high-speed on-chip oscillator clock is not supplied to fCLK.
 *                           When the specified clock is started(excluding HIOCLK).
 *                BSP_ARG_ERROR An invalid argument was input.
 * Attention    : Stop the specified clock before calling this function(excluding HIOCLK).
**************************************************/
#if BSP_CFG_CHANGE_CLOCK_SETTING_API_FUNCTIONS_DISABLE == 0
e_bsp_err_t change_clock_setting(e_clock_mode_t mode, uint8_t * set_values)
{
    e_bsp_err_t    status = BSP_OK;

    switch (mode)
    {
        case HIOCLK:

            if ((1U == HIOSTOP) || (0U != CLS) || (0U != MCS))
            {
                status = BSP_ERROR1;
            }
            else
            {
                HOCODIV = set_values[0];
            }

            break;

        default:

            /* Setting prohibited */
            status = BSP_ARG_ERROR;

            break;

    }

    return status;
} /* End of function change_clock_setting() */
#endif /* BSP_CFG_CHANGE_CLOCK_SETTING_API_FUNCTIONS_DISABLE == 0 */

/*************************************************
 * Function name: mcu_clock_setup
 * Description  : Clock initialization.
 * Arguments    : none
 * Return value : none
**************************************************/
#if BSP_CFG_STARTUP_DISABLE == 0
void mcu_clock_setup(void)
{
    uint8_t cmc_tmp;

#if ((BSP_CFG_SUBCLK_OPERATION == 0) && (BSP_CFG_SUBCLK_SOURCE == 1))
    volatile uint32_t w_count;
#endif
#if (BSP_CFG_HISYSCLK_OPERATION == 0) && (BSP_CFG_HISYSCLK_SOURCE == 1)
    uint8_t tmp_stab_wait;
    uint8_t tmp_stab_set;
#endif

    cmc_tmp = 0x00U;

    /* High-speed system clock(fMX) setting */
#if BSP_CFG_HISYSCLK_SOURCE == 0
    /* Port mode */
    /* Not used.
     * When using high-speed on-chip oscillator,
     * when not using main system clock
     */
#elif BSP_CFG_HISYSCLK_SOURCE == 1
    /* X1 oscillation mode */
    /* System clock pin operation mode(EXCLK, OSCSEL) */
    /* Control of X1 clock oscillation frequency(AMPH) setting */
#if (BSP_CFG_FMX_HZ >= 1000000) && (BSP_CFG_FMX_HZ <= 10000000)
    /* 1MHz <= fX <= 10MHz */
    cmc_tmp |= 0x40U;
#else
    /* 10MHz < fX <= 12MHz */
    cmc_tmp |= 0x41U;
#endif
#else
    /* External clock input mode */
    /* System clock pin operation mode(EXCLK, OSCSEL) */
    cmc_tmp |= 0xC0U;
#endif

    /* High-speed on-chip oscillator(fIH) setting */
    /* High-speed on-chip oscillator frequency select register(HOCODIV) setting */
    HOCODIV = BSP_CFG_HOCO_DIVIDE;

    /* Subsystem clock oscillator clock(fSX) setting */
#if BSP_CFG_SUBCLK_SOURCE == 0
    /* Not used.
     * When using the low-speed on-chip oscillator or
     * when not using subsystem clock(fSUB)
     */
#elif BSP_CFG_SUBCLK_SOURCE == 1
    /* fXT(Crystal resonator connection) */
#if BSP_CFG_XT1_OSCMODE == 0
    /* Low power consumption oscillation 1(default) */
    /* XTSEL/EXCLKS/OSCSELS/AMPHS1/AMPHS0 setting */
    cmc_tmp |= 0x18U;
#elif BSP_CFG_XT1_OSCMODE == 1
    /* Normal oscillation */
    /* XTSEL/EXCLKS/OSCSELS/AMPHS1/AMPHS0 setting */
    cmc_tmp |= 0x1AU;
#elif BSP_CFG_XT1_OSCMODE == 2
    /* Extra low power consumption oscillation */
    /* XTSEL/EXCLKS/OSCSELS/AMPHS1/AMPHS0 setting */
    cmc_tmp |= 0x1CU;
#else
    /* Setting prohibited */
#endif
#else
    /* fEXS(External subsystem clock) */
    /* EXCLKS/OSCSELS/XTSEL setting */
    cmc_tmp |= 0x38U;
#endif
    /* Clock operation mode control register(CMC) setting */
    CMC = cmc_tmp;

    /* When to use X1 clock oscillator(fX) */
#if BSP_CFG_HISYSCLK_SOURCE == 1
    /* Oscillation stabilization time select register(OSTS) setting */
    OSTS = BSP_CFG_X1_WAIT_TIME_SEL;
#endif

    /* High-speed system clock oscillation */
#if BSP_CFG_HISYSCLK_OPERATION == 0
    /* Start oscillation */
    MSTOP = 0U;

#if BSP_CFG_HISYSCLK_SOURCE == 1
        /* Wait for oscillation stabilization unless external clock input */
        tmp_stab_set = (uint8_t)~(0x7FU >> OSTS);

        /* WAIT_LOOP */
        do
        {
            tmp_stab_wait  = OSTC;
            tmp_stab_wait &= tmp_stab_set;
        }
        while (tmp_stab_wait != tmp_stab_set);
#endif
#else
    /* High-speed system clock(fMX) stopped if it is not used */
    MSTOP = 1U;
#endif

    /* Main system clock(fMAIN) setting */
#if BSP_CFG_MAINCLK_SOURCE == 0
    /* High-speed on-chip oscillator clock(fIH) */
    MCM0 = 0U;

    /* WAIT_LOOP */
    /* Confirm that high-speed on-chip oscillator clock(fIH) is selected. */
    while (1U == MCS)
    {
        ;
    }
#else
    /* High-speed system clock(fMX) */
    MCM0 = 1U;

#if (BSP_CFG_MCU_PART_PIN_NUM > 1) && (BSP_CFG_HISYSCLK_SOURCE != 0) && (BSP_CFG_HISYSCLK_OPERATION == 0)
    /* WAIT_LOOP */
    /* Confirm that high-speed system clock(fMX) is selected. */
    while (0U == MCS)
    {
        ;
    }
#endif
#endif

    /* Subsystem clock oscillation */
    /* Subsystem clock supply mode control register(OSMC) setting */
#if (BSP_CFG_ALLOW_FSUB_IN_STOPHALT == 0) && (BSP_CFG_RTC_OUT_CLK_SOURCE == 0)
    OSMC |= 0x00U;
#elif (BSP_CFG_ALLOW_FSUB_IN_STOPHALT == 1) && (BSP_CFG_RTC_OUT_CLK_SOURCE == 0)
    OSMC |= 0x80U;
#elif (BSP_CFG_ALLOW_FSUB_IN_STOPHALT == 0) && (BSP_CFG_RTC_OUT_CLK_SOURCE == 1)
    OSMC |= 0x10U;
#else
    OSMC |= 0x90U;
#endif

    /* When to use subsystem clock oscillator clock(fSX) */
    /* Subsystem clock oscillator clock oscillation */
#if BSP_CFG_SUBCLK_OPERATION == 0
    /* Start oscillation */
    XTSTOP = 0U;

#if BSP_CFG_SUBCLK_SOURCE == 1
    /* Wait for oscillation stabilization unless external clock input */
    /* WAIT_LOOP */
    for (w_count = 0U; w_count <= BSP_CFG_SUBWAITTIME; w_count++)
    {
#if BSP_CFG_WDT_REFRESH_ENABLE == 0
        BSP_NOP();
#else
        WDTE = 0xACU;
#endif
    }
#endif

#else
    /* XT1 oscillator stopped if subsystem clock oscillator clock is not used */
    XTSTOP = 1U;
#endif

    /* fCLK selection */
#if BSP_CFG_FCLK_SOURCE == 0
    /* When using a high-speed system clock, high-speed on-chip oscillator */
    CSS = 0U;

    /* WAIT_LOOP */
    /* Confirm that Main system clock(fMAIN) is selected. */
    while (1U == CLS)
    {
        ;
    }
#else
    /* When using subsystem clock */
    CSS = 1U;

#if (BSP_CFG_MCU_PART_PIN_NUM > 1) && (BSP_CFG_SUBCLK_SOURCE != 0) && (BSP_CFG_SUBCLK_OPERATION == 0)
    /* WAIT_LOOP */
    /* Confirm that Subsystem clock(fSUB) is selected. */
    while (0U == CLS)
    {
        ;
    }
#endif
#endif

    /* Starts high-speed on-chip oscillator */
    /* Only the high-speed on-chip oscillator is activated after reset,
     * so stop this clock last.
     */
#if BSP_CFG_FIH_START_ON_STARTUP == 1
    HIOSTOP = 0U;
#else
    HIOSTOP = 1U;
#endif
} /* End of function mcu_clock_setup() */
#endif /* BSP_CFG_STARTUP_DISABLE == 0 */
