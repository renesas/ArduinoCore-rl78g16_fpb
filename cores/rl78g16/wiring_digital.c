#define ARDUINO_MAIN
#include "wiring_private.h"
#include "pins_variant.h"
#include "wiring_private.h"
#include "api/Common.h"
#include "pintable.h"

#define PMPUPIMPOM_CHECK_ENABLE        /* Do not change invalid bits */

extern bool g_u8AnalogWriteAvailableTable[NUM_DIGITAL_PINS];
extern const PinTableType * pinTablelist[NUM_DIGITAL_PINS];
extern Pwm_func pwm_ch[PWM_CH_NUM];
extern int8_t get_pwm_channel(uint8_t pwm_num);
extern bool g_u8AnalogReadAvailableTable[NUM_ANALOG_INPUTS];
/**********************************************************************************************************************
 * Function Name: pintable setting
 * Description  : Set the pintable.
 * Arguments    : pin  - pin number
 *              : pp   - pin table
 * Return Value : -
 *********************************************************************************************************************/

/**
 * PWM STOP~
 *
 * @param[in] u8Timer Timer Number of PWM
 *
 * @return Nothing
 *
 * @attention Nothing
 ***************************************************************************/
void _turnOffPwmPin(uint8_t u8Pin)
{
    if (u8Pin < NUM_DIGITAL_PINS) {
        g_u8AnalogWriteAvailableTable[u8Pin] = false;
    }
    int8_t pwm_channel = get_pwm_channel(u8Pin);
    if(pwm_channel != -1)
    {
        pwm_ch[pwm_channel].stop_slave();
    }
}

/**********************************************************************************************************************
 * Function Name: pinmode setting
 * Description  : Set the port register.
 * Arguments    : -
 * Return Value : -
 *********************************************************************************************************************/
// void pinMode(uint8_t pin, uint8_t u8Mode)
void pinMode(pin_size_t pin, PinMode pinMode)
{
    uint8_t u8Mode = (uint8_t)pinMode;
    if (pin < NUM_DIGITAL_PINS) {
        if(CHECK_PINMODE_INHIBIT_RL78(pin))
        {
            return;
        }
        const PinTableType **pp;
        PinTableType *p;
        pp = &pinTablelist[pin];
        p = (PinTableType *)*pp;

#ifdef PMPUPIMPOM_CHECK_ENABLE
        if (0 != p->pm){
#endif
            switch (u8Mode) {
                 case OUTPUT:
                    *p->portModeRegisterAddr &= (unsigned long)~(0x1 << p->bit);
                    break;
                 case INPUT:
                    *p->portModeRegisterAddr |=  (unsigned long)(0x1 << p->bit);
                    break;
                 default:
                     break;
            }
#ifdef PMPUPIMPOM_CHECK_ENABLE
        }
#endif

        /* clear pmca register when analog pin */
#if defined(G22_FPB) || defined(G23_FPB)

        if (0!=p->pmca)
        {
            *p->portModeControlARegisterAddr &= (unsigned long)~(p->pmca);
            int8_t pin_index = (int8_t)pin - ANALOG_PIN_START_NUMBER;
            if ((pin_index >= 0) && (pin_index < NUM_ANALOG_INPUTS))
            {
                g_u8AnalogReadAvailableTable[pin_index] = false;
            }
        }
#endif //  defined(G22_FPB) || defined(G23_FPB)
#if defined(G16_FPB)
        if (0!=p->pmc)
        {
            *p->portModeControlRegisterAddr &= (unsigned long)~(p->pmc);
            int8_t pin_index = (int8_t)pin - ANALOG_PIN_START_NUMBER;
            if ((pin_index >= 0) && (pin_index < NUM_ANALOG_INPUTS))
            {
                g_u8AnalogReadAvailableTable[pin_index] = false;
            }
        }
#endif
        /* clear pmct register when touch pin */
#if defined(G22_FPB) || defined(G23_FPB)
        if (0!=p->pmct)
        {
            *p->portModeControlTRegisterAddr &= (unsigned long)~(p->pmct);
        }
#endif //  defined(G22_FPB) || defined(G23_FPB)

        /* clear pmce register when ELCL pin */
#if defined(G23_FPB)
        if (0!=p->pmce)
        {
            *p->portModeControlERegisterAddr &= (unsigned long)~(p->pmce);
        }
#endif // G23_FPB
        /* clear ccde register */
#if defined(G23_FPB)
        if (0!=p->ccde)
        {
            *p->portOutCurControlRegisterAddr &= (unsigned long)~(p->ccde);
        }
#endif // G23_FPB

        if (g_u8AnalogWriteAvailableTable[pin]) {
            _turnOffPwmPin(pin);    /* PWM setting cancel */
        }
        if (!(*p->portModeRegisterAddr & p->mask)) {
            if (*p->portRegisterAddr & p->mask) {
                if (u8Mode == INPUT) {
                    u8Mode = INPUT_PULLUP;
                } else if (u8Mode == INPUT_TTL) {
                    u8Mode = INPUT_TTL_PULLUP;
                }
            }
        }

        switch (u8Mode) {
        case INPUT:
        case INPUT_PULLUP:
        case INPUT_TTL:
        case INPUT_TTL_PULLUP:
            if (0 != p->pu){
                if (u8Mode == INPUT_PULLUP || u8Mode == INPUT_TTL_PULLUP) {
                    *p->portPullUpRegisterAddr |= (unsigned long)(0x1 << p->bit);    /* Enable Pullup Reg */
                } else {
                    *p->portPullUpRegisterAddr &= (unsigned long)~(0x1 << p->bit);    /* Disable Pullup Reg */
                }
            }
#if defined(G22_FPB) || defined(G23_FPB)
            if (0 != p->pim){
                if (u8Mode == INPUT_TTL || u8Mode == INPUT_TTL_PULLUP) {
                    *p->portInputModeRegisterAddr |= (unsigned long)(0x1 << p->bit);    /* set TTL Input */
                } else {
                    *p->portInputModeRegisterAddr &= (unsigned long)~(0x1 << p->bit);    /* set CMOS Onput */
                }
            }
#endif // G23_FPB
            if (0 != p->pm){
                *p->portModeRegisterAddr |= (unsigned long)(1U << p->bit);             /* set Input Mode */
            }
            if (0 != p->pom){
                *p->portOutputModeRegisterAddr &= (unsigned long)~(0x1 << p->bit);  /* set Normal Output */
            }
#if defined(G23_FPB)
            if (0 != p->pdidis){
                *p->portDigInputDisRegisterAddr &= (unsigned long)~(0x1 << p->bit);    /* set Input enable */
            }
#endif // G23_FPB
            break;
        case OUTPUT:
        case OUTPUT_OPENDRAIN:
            if(CHECK_OUTPUT_INHIBIT_RL78(pin))
            {
                break;
            }
            if (u8Mode == OUTPUT_OPENDRAIN) {
                if (0 != p->pom){
                    *p->portOutputModeRegisterAddr |= (unsigned long)(0x1 << p->bit);    /* set N-ch OpenDrain output */
                }
#if defined(G23_FPB)
                if (0 != p->pdidis){
                    *p->portDigInputDisRegisterAddr |= (unsigned long)(0x1 << p->bit);    /* set N-ch Input disable */
                }
#endif // G23_FPB
            } else {
                if (0 != p->pom){
                    *p->portOutputModeRegisterAddr &= (unsigned long)~(0x1 << p->bit);  /* set Normal Output */
                }
#if defined(G23_FPB)
                if (0 != p->pdidis){
                    *p->portDigInputDisRegisterAddr &= (unsigned long)~(0x1 << p->bit);    /* set Input enable */
                }
#endif // G23_FPB
            }
            if (0 != p->pm){
                *p->portModeRegisterAddr &= (unsigned long)~(0x1 << p->bit);        /* set Output Mode */
            }
            if (0 != p->pu){
                *p->portPullUpRegisterAddr &= (unsigned long)~(0x1 << p->bit);        /* Disable Pullup Reg */
            }
#if defined(G22_FPB) || defined(G23_FPB)
            if (0 != p->pim){
                *p->portInputModeRegisterAddr &= (unsigned long)~(0x1 << p->bit);    /* set CMOS Input */
            }
#endif // G23_FPB
            *p->portRegisterAddr &= (unsigned long)~(0x1 << p->bit);            /* clear Port */
            break;
        default:
            break;
        }
    }
}

/**********************************************************************************************************************
 * Function Name: pin output
 * Description  : Perform port output
 * Arguments    : pin  - pin number
 *              : pp   - output value
 * Return Value : -
 *********************************************************************************************************************/
// void digitalWrite(uint8_t pin, uint8_t val)
void digitalWrite(pin_size_t pin, PinStatus val)
{
    const PinTableType ** pp;
    PinTableType * p;
    if (pin < NUM_DIGITAL_PINS)
    {
        if(CHECK_OUTPUT_INHIBIT_RL78(pin))
        {
            return;
        }
        pp = &pinTablelist[pin];
        p = (PinTableType *)*pp;
        /* When Output Mode  */
        if (val == LOW) {
            *p->portRegisterAddr &= ~p->mask;       /* Write "0" to Port */
        } else {
            *p->portRegisterAddr |= p->mask;        /* Write "1" to Port */
        }
    }
}

/**********************************************************************************************************************
 * Function Name: pin input
 * Description  : Perform port input
 * Arguments    : pin  - pin number
 * Return Value : input value
 *********************************************************************************************************************/
// int digitalRead(uint8_t pin)
PinStatus digitalRead(pin_size_t pin){
    if (pin < NUM_DIGITAL_PINS) {
        const PinTableType ** pp;
        PinTableType * p;
        pp = &pinTablelist[pin];
        p = (PinTableType *)*pp;
        if (*p->portRegisterAddr & p->mask) {

            return HIGH;
        }
    }
    return LOW;

}

#ifdef __RL78__
/**********************************************************************************************************************
 * Function Name: disable input pin
 * Description  : Prohibits the input of the specified pin.
 * Arguments    : pin   - pin number
 * Return Value : -
 *********************************************************************************************************************/
void DisableDigitalInput(uint8_t pin)
{
#if defined(G23_FPB)
    if (pin < NUM_DIGITAL_PINS) {
        const PinTableType ** pp;
        PinTableType * p;
        pp = &pinTablelist[pin];
        p = (PinTableType *)*pp;
        if (0 != p->pdidis){    /* can be changed */
            *p->portDigInputDisRegisterAddr |= (unsigned long)(0x1 << p->bit);    /* Input disable */
        }
    }
#endif // G23_FPB
}

/**********************************************************************************************************************
 * Function Name: enable input pin
 * Description  : Allows the input of the specified pin.
 * Arguments    : pin   - pin number
 * Return Value : -
 *********************************************************************************************************************/
void EnableDigitalInput(uint8_t pin)
{

    if (pin < NUM_DIGITAL_PINS) {
        const PinTableType ** pp;
        PinTableType * p;
        pp = &pinTablelist[pin];
        p = (PinTableType *)*pp;
#if defined(G23_FPB)
        if (0 != p->pdidis){    /* can be changed */
            *p->portDigInputDisRegisterAddr &= (unsigned long)~(0x1 << p->bit);    /* set Input enable */
        }
#endif // G23_FPB
    }
}
#endif /*__RL78__*/

