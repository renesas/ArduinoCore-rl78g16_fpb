#ifndef WiringVariante_h
#define WiringVariante_h

#include <stdio.h>
#include <stdarg.h>
#include "Arduino.h"
#include "utilities.h"

#ifdef __cplusplus
extern "C"{
#endif

#define ANALOG_PIN_START_NUMBER (23)
#define MAX_CYCLIC_HANDLER       (4)
#define EXTERNAL_NUM_INTERRUPTS  (7)

#define TEMPERATURE_OFFSET 400

/* PWM defines. */
#define PWM_MIN         0
#define PWM_MAX         255

/* External interrupt define. */

#define EXTERNAL_INTERRUPT_0    0
#define EXTERNAL_INTERRUPT_1    2
#define EXTERNAL_INTERRUPT_2    3
#define EXTERNAL_INTERRUPT_3    4
#define EXTERNAL_INTERRUPT_4    15
#define EXTERNAL_INTERRUPT_5    17
#define EXTERNAL_INTERRUPT_6    23

#define PWM_CH_NUM  (2)

#define FREQUENCY_MIN_VAL   (500)
#define FREQUENCY_MAX_VAL   (8000000)

#ifdef __cplusplus
} // extern "C"
#endif

extern volatile uint8_t g_tau0_ch2_interrupt_flag;

extern volatile uint8_t g_tau0_ch3_interrupt_flag;
extern volatile uint8_t g_tau0_ch4_interrupt_flag;

//extern uint32_t R_BSP_GetFclkFreqHz(void);

extern volatile uint8_t g_pulse_enable_interrupt_flag;
extern volatile unsigned short *g_timer_pulse_mode_reg[PULSE_IN_CH_NUM];
extern volatile unsigned short *g_timer_pulse_clock_select_reg;
extern volatile unsigned short *g_timer_timeout_data_reg;
extern volatile unsigned short *g_timer_timeout_mode_reg;
extern const uint8_t  pulse_in_channel_table[PULSE_IN_CH_NUM];
extern pulse_in_func pulse_in_ch[PULSE_IN_CH_NUM];

#endif /* WiringVariante_h */
