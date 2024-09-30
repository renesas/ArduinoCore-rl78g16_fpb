#ifndef WiringPrivateTone_h
#define WiringPrivateTone_h

#define TONE_CH_NUM (3)

#ifdef __cplusplus
extern "C"{
#endif

typedef struct {
    void (*open)();
    void (*start)();
    void (*stop)();
} tone_func;

#ifdef __cplusplus
} // extern "C"
#endif

// tone_func
int8_t get_tone_channel(uint8_t tone_num);

/* tone pin set */
extern volatile unsigned short *g_tone_period_reg[TONE_CH_NUM];
extern volatile unsigned short *g_timer_tone_mode_reg[TONE_CH_NUM];
extern volatile unsigned short *g_timer_tone_clock_select_reg;
extern const uint8_t  tone_channel_table[TONE_CH_NUM];

//#include "Config_TAU0_1_Square_Wave.h"
extern "C"{
void R_Config_TAU0_0_Square_Wave_Create(void);
void R_Config_TAU0_0_Square_Wave_Start(void);
void R_Config_TAU0_0_Square_Wave_Stop(void);
void R_Config_TAU0_0_Square_Wave_Create_UserInit(void);
void R_Config_TAU0_3_Square_Wave_Create(void);
void R_Config_TAU0_3_Square_Wave_Start(void);
void R_Config_TAU0_3_Square_Wave_Stop(void);
void R_Config_TAU0_3_Square_Wave_Create_UserInit(void);
void R_Config_TAU0_4_Square_Wave_Create(void);
void R_Config_TAU0_4_Square_Wave_Start(void);
void R_Config_TAU0_4_Square_Wave_Stop(void);
void R_Config_TAU0_4_Square_Wave_Create_UserInit(void);
}

extern tone_func tone_ch[TONE_CH_NUM];

#endif
