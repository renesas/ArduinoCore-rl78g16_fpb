#ifndef _PINS_VARIANT_H_
#define _PINS_VARIANT_H_

#include <stdint.h>
#include <stdlib.h>

#ifndef configCPU_CLOCK_HZ
#define configCPU_CLOCK_HZ         (16000000)  // CPU frequency used for only I2C setting
#endif

#define F_CPU (16 * 1000 * 1000L)

#define FEW_RAM_MODEL 1 

// G23:2 , G22, G16:1, G24:3
#define MICROS_TIMER_DIVIDE_FACTOR ((uint32_t)1) // Reference clock frequency after dividing

#define UART_CHANNEL        0       // UART0(Serial0)
// #define UART1_CHANNEL       1       // UART1(Serial1)
#define UART_TOTAL_NUM      1

/* SPI(CSI) Definition */
#define USE_CSI      (1) // Set to '1' when Use SPI Hardware

#if defined(USE_CSI) && USE_CSI

//  #define CSI_CHANNEL0 (0) // USE CSI00 for SPI
#define CSI_CHANNEL4 (4) // USE CSI20 for SPI
#endif /* defined(USE_CSI) && USE_CSI */

/* IIC Definition */
#define IIC_CHANNEL0 (0)
// #define IIC_CHANNEL1 (1)

#define CHECK_PINMODE_INHIBIT_RL78(p) (  0 )
#define CHECK_OUTPUT_INHIBIT_RL78(p) ((p) == 7 || (p) == 9 || (p) == 10 )

#define PULSE_IN_CH_NUM         (2)

typedef struct {
    void (*open)();
    void (*start)();
    void (*stop)();
    void (*get_width)(uint32_t * const width);
} pulse_in_func;

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/
#define NUM_DIGITAL_PINS           24
#define NUM_ANALOG_INPUTS           1

#define analogInputToDigitalPin(p)  ((p < 1) ? (p) + 23 : -1)

#define digitalPinHasPWM(p)         ((p) == 3 || (p) == 5 || (p) == 6 || (p) == 9 || (p) == 10 || (p) == 11)

#define PIN_WIRE_SDA        (22) // P61
#define PIN_WIRE_SCL        (21) // P60
#define PIN_SPI_SS    (8)
#define PIN_SPI_MOSI  (11)
#define PIN_SPI_MISO  (12)
#define PIN_SPI_SCK   (13)

extern const uint8_t SS;
extern const uint8_t MOSI;
extern const uint8_t MISO;
extern const uint8_t SCK;

extern const uint8_t SDA;
extern const uint8_t SCL;

#define BUILTIN_LED1 16
#define BUILTIN_LED2 18
#define LED_BUILTIN  BUILTIN_LED1

#define LED_ON  LOW
#define LED_OFF HIGH

#define PIN_A0   (23)   /*A0 = ANI4 */

extern const uint8_t A0;

// #define digitalPinToInterrupt(p)  (((p) == 2) ? 0 : (((p) == 3) ? 1 : (((p) == 4) ? 2 : (((p) == 15) ? 3 : (((p) == 17) ? 4 : (((p) == 23) ? 5 : NOT_AN_INTERRUPT))))))
#define digitalPinToInterrupt(p)  (((p) == 0) ?  0 : (((p) == 2) ?  1 : (((p) == 3) ? 2 :  (((p) == 4) ? 3 : (((p) == 15) ? 4 : (((p) == 17) ? 5 : (((p) == 23) ? 6 : NOT_AN_INTERRUPT)))))))

/***************************************************************************/
/*    Macro Definitions                                                    */
/***************************************************************************/
#define ADDR_PORT_REG           0xFFFFFF00
#define ADDR_PORT_MODE_REG      0xFFFFFF20
#define ADDR_PORT_PULL_UP_REG   0xFFFF0030
#define ADDR_PORT_IN_MODE_REG   0xFFFF0040
#define ADDR_PORT_OUT_MODE_REG  0xFFFF0050
#define ADDR_PORT_MODE_CONTROL_REG      0xFFFF0060

#define ANALOG_PIN_0        4       // ANI4 (P05)

/* Port define. */
#define PORT_0              0
#define PORT_1              1
#define PORT_2              2
#define PORT_3              3
#define PORT_4              4
#define PORT_5              5
#define PORT_6              6
#define PORT_7              7
#define PORT_8              8
#define PORT_9              9
#define PORT_10             10
#define PORT_11             11
#define PORT_12             12
#define PORT_13             13
#define PORT_14             14
#define PORT_15             15
#define PORT_16             16
#define PORT_17             17
#define PORT_18             18
#define PORT_19             19

/* Port of digital pin define. */
#define DIGITAL_PIN_0       PORT_0  /* P04  */
#define DIGITAL_PIN_1       PORT_0  /* P03  */
#define DIGITAL_PIN_2       PORT_1  /* P11  */
#define DIGITAL_PIN_3       PORT_1  /* P10  */
#define DIGITAL_PIN_4       PORT_1  /* P14  */
#define DIGITAL_PIN_5       PORT_1  /* P16  */
#define DIGITAL_PIN_6       PORT_1  /* P17  */
#define DIGITAL_PIN_7       PORT_4  /* P42  */
#define DIGITAL_PIN_8       PORT_4  /* P43  */
#define DIGITAL_PIN_9       PORT_12 /* P122 */
#define DIGITAL_PIN_10      PORT_12 /* P121 */
#define DIGITAL_PIN_11      PORT_2  /* P21  */
#define DIGITAL_PIN_12      PORT_2  /* P20  */
#define DIGITAL_PIN_13      PORT_4  /* P41  */
#define DIGITAL_PIN_14      PORT_4  /* P40  */
#define DIGITAL_PIN_15      PORT_13 /* P137 */
#define DIGITAL_PIN_16      PORT_1  /* P12  */
#define DIGITAL_PIN_17      PORT_1  /* P13  */
#define DIGITAL_PIN_18      PORT_1  /* P15  */
#define DIGITAL_PIN_19      PORT_0  /* P00  */
#define DIGITAL_PIN_20      PORT_0  /* P01  */
#define DIGITAL_PIN_21      PORT_6  /* P60  */
#define DIGITAL_PIN_22      PORT_6  /* P61  */
#define DIGITAL_PIN_23      PORT_0  /* P05  */

/* Bit Num of digital pin define */
#define DIGITAL_PIN_BIT_0   0x04    /* P04  */
#define DIGITAL_PIN_BIT_1   0x03    /* P03  */
#define DIGITAL_PIN_BIT_2   0x01    /* P11  */
#define DIGITAL_PIN_BIT_3   0x00    /* P10  */
#define DIGITAL_PIN_BIT_4   0x04    /* P14  */
#define DIGITAL_PIN_BIT_5   0x06    /* P16  */
#define DIGITAL_PIN_BIT_6   0x07    /* P17  */
#define DIGITAL_PIN_BIT_7   0x02    /* P42  */
#define DIGITAL_PIN_BIT_8   0x03    /* P43  */
#define DIGITAL_PIN_BIT_9   0x02    /* P122 */
#define DIGITAL_PIN_BIT_10  0x01    /* P121 */
#define DIGITAL_PIN_BIT_11  0x01    /* P21  */
#define DIGITAL_PIN_BIT_12  0x00    /* P20  */
#define DIGITAL_PIN_BIT_13  0x01    /* P41  */
#define DIGITAL_PIN_BIT_14  0x00    /* P40  */
#define DIGITAL_PIN_BIT_15  0x07    /* P137 */
#define DIGITAL_PIN_BIT_16  0x02    /* P12  */
#define DIGITAL_PIN_BIT_17  0x03    /* P13  */
#define DIGITAL_PIN_BIT_18  0x05    /* P15  */
#define DIGITAL_PIN_BIT_19  0x00    /* P00  */
#define DIGITAL_PIN_BIT_20  0x01    /* P01  */
#define DIGITAL_PIN_BIT_21  0x00    /* P60  */
#define DIGITAL_PIN_BIT_22  0x01    /* P61  */
#define DIGITAL_PIN_BIT_23  0x05    /* P05  */

/* Bit mask of digital pin define. */
// only the bit num (not port) 0->01, 1->02, 2->04, 3->08, 4->10, 5->20, 6->40, 7->80
#define DIGITAL_PIN_MASK_0  0x10    /* P04  */
#define DIGITAL_PIN_MASK_1  0x08    /* P03  */
#define DIGITAL_PIN_MASK_2  0x02    /* P11  */
#define DIGITAL_PIN_MASK_3  0x01    /* P10  */
#define DIGITAL_PIN_MASK_4  0x10    /* P14  */
#define DIGITAL_PIN_MASK_5  0x40    /* P16  */
#define DIGITAL_PIN_MASK_6  0x80    /* P17  */
#define DIGITAL_PIN_MASK_7  0x04    /* P42  */
#define DIGITAL_PIN_MASK_8  0x08    /* P43  */
#define DIGITAL_PIN_MASK_9  0x04    /* P122 */
#define DIGITAL_PIN_MASK_10 0x02    /* P121 */
#define DIGITAL_PIN_MASK_11 0x02    /* P21  */
#define DIGITAL_PIN_MASK_12 0x01    /* P20  */
#define DIGITAL_PIN_MASK_13 0x02    /* P41  */
#define DIGITAL_PIN_MASK_14 0x01    /* P40  */
#define DIGITAL_PIN_MASK_15 0x80    /* P137 */
#define DIGITAL_PIN_MASK_16 0x04    /* P12  */
#define DIGITAL_PIN_MASK_17 0x08    /* P13  */
#define DIGITAL_PIN_MASK_18 0x20    /* P15  */
#define DIGITAL_PIN_MASK_19 0x01    /* P00  */
#define DIGITAL_PIN_MASK_20 0x02    /* P01  */
#define DIGITAL_PIN_MASK_21 0x01    /* P60  */
#define DIGITAL_PIN_MASK_22 0x02    /* P61  */
#define DIGITAL_PIN_MASK_23 0x20    /* P05  */

/*  PMC  */
#define DIGITAL_PIN_PMC_0   0x10    /* P04  */
#define DIGITAL_PIN_PMC_1   0x08    /* P03  */
#define DIGITAL_PIN_PMC_2   0x00    /* P11  */
#define DIGITAL_PIN_PMC_3   0x00    /* P10  */
#define DIGITAL_PIN_PMC_4   0x00    /* P14  */
#define DIGITAL_PIN_PMC_5   0x00    /* P16  */
#define DIGITAL_PIN_PMC_6   0x00    /* P17  */
#define DIGITAL_PIN_PMC_7   0x00    /* P42  */
#define DIGITAL_PIN_PMC_8   0x00    /* P43  */
#define DIGITAL_PIN_PMC_9   0x00    /* P122 */
#define DIGITAL_PIN_PMC_10  0x00    /* P121 */
#define DIGITAL_PIN_PMC_11  0x02    /* P21  */
#define DIGITAL_PIN_PMC_12  0x01    /* P20  */
#define DIGITAL_PIN_PMC_13  0x00    /* P41  */
#define DIGITAL_PIN_PMC_14  0x00    /* P40  */
#define DIGITAL_PIN_PMC_15  0x00    /* P137 */
#define DIGITAL_PIN_PMC_16  0x00    /* P12  */
#define DIGITAL_PIN_PMC_17  0x00    /* P13  */
#define DIGITAL_PIN_PMC_18  0x00    /* P15  */
#define DIGITAL_PIN_PMC_19  0x00    /* P00  */
#define DIGITAL_PIN_PMC_20  0x02    /* P01  */
#define DIGITAL_PIN_PMC_21  0x00    /* P60  */
#define DIGITAL_PIN_PMC_22  0x00    /* P61  */
#define DIGITAL_PIN_PMC_23  0x20    /* P05  */

/* Define Digital Pin PM */
// used for (if (0 != p->pm){)
#define DIGITAL_PIN_PM_0    0x10    /* P04  */
#define DIGITAL_PIN_PM_1    0x08    /* P03  */
#define DIGITAL_PIN_PM_2    0x02    /* P11  */
#define DIGITAL_PIN_PM_3    0x01    /* P10  */
#define DIGITAL_PIN_PM_4    0x10    /* P14  */
#define DIGITAL_PIN_PM_5    0x40    /* P16  */
#define DIGITAL_PIN_PM_6    0x80    /* P17  */
#define DIGITAL_PIN_PM_7    0x04    /* P42  */
#define DIGITAL_PIN_PM_8    0x08    /* P43  */
#define DIGITAL_PIN_PM_9    0x04    /* P122 */
#define DIGITAL_PIN_PM_10   0x02    /* P121 */
#define DIGITAL_PIN_PM_11   0x02    /* P21  */
#define DIGITAL_PIN_PM_12   0x01    /* P20  */
#define DIGITAL_PIN_PM_13   0x02    /* P41  */
#define DIGITAL_PIN_PM_14   0x01    /* P40  */
#define DIGITAL_PIN_PM_15   0x00    /* P137 */
#define DIGITAL_PIN_PM_16   0x04    /* P12  */
#define DIGITAL_PIN_PM_17   0x08    /* P13  */
#define DIGITAL_PIN_PM_18   0x20    /* P15  */
#define DIGITAL_PIN_PM_19   0x01    /* P00  */
#define DIGITAL_PIN_PM_20   0x02    /* P01  */
#define DIGITAL_PIN_PM_21   0x01    /* P60  */
#define DIGITAL_PIN_PM_22   0x02    /* P61  */
#define DIGITAL_PIN_PM_23   0x20    /* P05  */

/* Define Digital Pin PU */
#define DIGITAL_PIN_PU_0    0x10    /* P04  */
#define DIGITAL_PIN_PU_1    0x08    /* P03  */
#define DIGITAL_PIN_PU_2    0x02    /* P11  */
#define DIGITAL_PIN_PU_3    0x01    /* P10  */
#define DIGITAL_PIN_PU_4    0x10    /* P14  */
#define DIGITAL_PIN_PU_5    0x40    /* P16  */
#define DIGITAL_PIN_PU_6    0x80    /* P17  */
#define DIGITAL_PIN_PU_7    0x04    /* P42  */
#define DIGITAL_PIN_PU_8    0x08    /* P43  */
#define DIGITAL_PIN_PU_9    0x04    /* P122 */
#define DIGITAL_PIN_PU_10   0x02    /* P121 */
#define DIGITAL_PIN_PU_11   0x02    /* P21  */
#define DIGITAL_PIN_PU_12   0x01    /* P20  */
#define DIGITAL_PIN_PU_13   0x02    /* P41  */
#define DIGITAL_PIN_PU_14   0x01    /* P40  */
#define DIGITAL_PIN_PU_15   0x00    /* P137 */
#define DIGITAL_PIN_PU_16   0x04    /* P12  */
#define DIGITAL_PIN_PU_17   0x08    /* P13  */
#define DIGITAL_PIN_PU_18   0x20    /* P15  */
#define DIGITAL_PIN_PU_19   0x01    /* P00  */
#define DIGITAL_PIN_PU_20   0x02    /* P01  */
#define DIGITAL_PIN_PU_21   0x00    /* P60  */
#define DIGITAL_PIN_PU_22   0x00    /* P61  */
#define DIGITAL_PIN_PU_23   0x20    /* P05  */

/* Define Digital Pin PIM */

/* Define Digital Pin POM */
#define DIGITAL_PIN_POM_0   0x10    /* P04  */
#define DIGITAL_PIN_POM_1   0x08    /* P03  */
#define DIGITAL_PIN_POM_2   0x00    /* P11  */
#define DIGITAL_PIN_POM_3   0x00    /* P10  */
#define DIGITAL_PIN_POM_4   0x10    /* P14  */
#define DIGITAL_PIN_POM_5   0x40    /* P16  */
#define DIGITAL_PIN_POM_6   0x80    /* P17  */
#define DIGITAL_PIN_POM_7   0x00    /* P42  */
#define DIGITAL_PIN_POM_8   0x00    /* P43  */
#define DIGITAL_PIN_POM_9   0x00    /* P122 */
#define DIGITAL_PIN_POM_10  0x00    /* P121 */
#define DIGITAL_PIN_POM_11  0x00    /* P21  */
#define DIGITAL_PIN_POM_12  0x01    /* P20  */
#define DIGITAL_PIN_POM_13  0x02    /* P41  */
#define DIGITAL_PIN_POM_14  0x00    /* P40  */
#define DIGITAL_PIN_POM_15  0x00    /* P137 */
#define DIGITAL_PIN_POM_16  0x00    /* P12  */
#define DIGITAL_PIN_POM_17  0x00    /* P13  */
#define DIGITAL_PIN_POM_18  0x00    /* P15  */
#define DIGITAL_PIN_POM_19  0x01    /* P00  */
#define DIGITAL_PIN_POM_20  0x02    /* P01  */
#define DIGITAL_PIN_POM_21  0x00    /* P60  */
#define DIGITAL_PIN_POM_22  0x00    /* P61  */
#define DIGITAL_PIN_POM_23  0x20    /* P05  */

#define PWM_PIN_3           3       // TO3 (pulseIn)
#define PWM_PIN_6           6       // TO4 (pulseIn)

#define TONE_PIN_11         11      // TO0
#define TONE_PIN_3          3       // TO3
#define TONE_PIN_6          6       // TO4

/* Define Serial Port Number */
#define SERIAL_TXD0         19 // P00
#define SERIAL_RXD0         20 // P01

#if (UART1_CHANNEL==1)
#define SERIAL_TXD1         0  // P04
#define SERIAL_RXD1         1  // P03
#endif /* UART1_CHANNEL==1 */

/* Define Serial Port Number */

#if defined(UART_CHANNEL)
#define IS_PIN_SERIAL0(p)        ((p) == PIN_SERIAL0_RX || (p) == PIN_SERIAL0_TX )
#else
#define IS_PIN_SERIAL0(p)        (0)
#endif

#if defined(UART1_CHANNEL)
#define IS_PIN_SERIAL1(p)        ((p) == PIN_SERIAL1_RX || (p) == PIN_SERIAL1_TX)
#else
#define IS_PIN_SERIAL1(p)        (0)
#endif

#endif // #variant
