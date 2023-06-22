/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "pins_variant.h"
#include "wiring_private.h"
#include "wiring_variant.h"
#include "r_smc_entry.h"

volatile unsigned short *g_timer_period_reg[PWM_CH_NUM] = {&TDR02,&TDR02};
volatile unsigned short *g_timer_duty_reg[PWM_CH_NUM]   = {&TDR03,&TDR04};
volatile unsigned short *g_timer_analog_mode_reg[PWM_CH_NUM] = {&TMR03,&TMR04};
volatile unsigned short *g_timer_analog_clock_select_reg = &TPS0;
const uint8_t  pwm_channel_table[PWM_CH_NUM]  = {PWM_PIN_3,PWM_PIN_6};

const uint8_t g_au8AnalogPinTable[NUM_ANALOG_INPUTS] = {
ANALOG_PIN_0, ANALOG_PIN_1, ANALOG_PIN_2, ANALOG_PIN_3,
ANALOG_PIN_4, ANALOG_PIN_5
};

const uint8_t g_analog_pin_input[NUM_ANALOG_INPUTS] = {PIN_A0, PIN_A1, PIN_A2, PIN_A3, PIN_A4, PIN_A5};

Pwm_func pwm_ch[PWM_CH_NUM] =
{
    {
        .open  = (void*)R_Config_TAU0_2_PWM_Create,
        .open_slave  = (void*)R_Config_TAU0_23_PWM_Create,
        .start = (void*)R_Config_TAU0_2_PWM_Start,
		.start_slave = (void*)R_Config_TAU0_23_PWM_Start,
		.stop_slave = (void*)R_Config_TAU0_23_PWM_Stop,
		.enable_interrupt = (void*)R_Config_TAU0_2_PWM_Enable_IRQ,
        .cycle = CYCLE_VALUE,
    },
    {
        .open  = (void*)R_Config_TAU0_2_PWM_Create,
        .open_slave  = (void*)R_Config_TAU0_24_PWM_Create,
        .start = (void*)R_Config_TAU0_2_PWM_Start,
		.start_slave = (void*)R_Config_TAU0_24_PWM_Start,
		.stop_slave = (void*)R_Config_TAU0_24_PWM_Stop,
		.enable_interrupt = (void*)R_Config_TAU0_2_PWM_Enable_IRQ,
        .cycle = CYCLE_VALUE,
    }
};

volatile uint8_t g_pulse_enable_interrupt_flag = 0;
volatile unsigned short *g_timer_pulse_mode_reg[PULSE_IN_CH_NUM] = {&TMR03,&TMR04};
volatile unsigned short *g_timer_pulse_clock_select_reg = &TPS0;
volatile unsigned short *g_timer_timeout_data_reg = &TDR02;
volatile unsigned short *g_timer_timeout_mode_reg = &TMR02;

const uint8_t  pulse_in_channel_table[PULSE_IN_CH_NUM]  = {PWM_PIN_3,PWM_PIN_6};
pulse_in_func pulse_in_ch[PULSE_IN_CH_NUM] =
{

    {
        .open  = (void*)R_Config_TAU0_0_3_Measure_Signal_Create,
        .start = (void*)R_Config_TAU0_0_3_Measure_Signal_Start,
        .stop = (void*)R_Config_TAU0_0_3_Measure_Signal_Stop,
        .get_width = (void*)R_Config_TAU0_3_Measure_Signal_Get_PulseWidth,
    },
    {
        .open  = (void*)R_Config_TAU0_0_4_Measure_Signal_Create,
        .start = (void*)R_Config_TAU0_0_4_Measure_Signal_Start,
        .stop = (void*)R_Config_TAU0_0_4_Measure_Signal_Stop,
        .get_width = (void*)R_Config_TAU0_4_Measure_Signal_Get_PulseWidth,
    },
};

