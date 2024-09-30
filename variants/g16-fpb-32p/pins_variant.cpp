#include "pins_variant.h"
#include "wiring_private.h"
#include "wiring_private_tone.h"
#include "r_smc_entry.h"

/*
 * Pins descriptions
 */
const uint8_t SDA = PIN_WIRE_SDA;
const uint8_t SCL = PIN_WIRE_SCL;

const uint8_t A0 = PIN_A0;

/* tone pin set */
volatile unsigned short *g_tone_period_reg[TONE_CH_NUM] = {&TDR00,&TDR03,&TDR04};
volatile unsigned short *g_timer_tone_mode_reg[TONE_CH_NUM] = {&TMR00,&TMR03,&TMR04};
volatile unsigned short *g_timer_tone_clock_select_reg = &TPS0;

const uint8_t  tone_channel_table[TONE_CH_NUM]  = {TONE_PIN_11,TONE_PIN_3,TONE_PIN_6};
tone_func tone_ch[TONE_CH_NUM] =
{
    {
        .open  = R_Config_TAU0_0_Square_Wave_Create,
        .start = R_Config_TAU0_0_Square_Wave_Start,
        .stop = R_Config_TAU0_0_Square_Wave_Stop
    },
    {
        .open  = R_Config_TAU0_3_Square_Wave_Create,
        .start = R_Config_TAU0_3_Square_Wave_Start,
        .stop = R_Config_TAU0_3_Square_Wave_Stop
    },
    {
        .open  = R_Config_TAU0_4_Square_Wave_Create,
        .start = R_Config_TAU0_4_Square_Wave_Start,
        .stop = R_Config_TAU0_4_Square_Wave_Stop
    }
};

