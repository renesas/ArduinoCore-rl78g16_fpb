#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

extern "C" {
    uint32_t R_BSP_GetFclkFreqHz(void);
    void Set_Char_Serial_from_buf(uint8_t chn);
}

#include "Arduino.h"

extern "C" {
    #include "pintable.h"
    extern const PinTableType * pinTablelist[NUM_DIGITAL_PINS];
    #include "pins_variant.h"
}

extern "C" {
#if ( UART_CHANNEL == 0 )
    #include "Config_UART0.h"
#endif /* ( UART_CHANNEL == 0 ) */
#if ( UART1_CHANNEL == 1 )
    #include "Config_UART1.h"
#endif /* ( UART1_CHANNEL == 1 ) */

#if ( UART2_CHANNEL == 2 )
    #include "Config_UART2.h"
#endif /* ( UART2_CHANNEL == 2 ) */

};

#include "HardwareUart.h"


void serialEventRun(void)
{

}

fInterruptFunc_t uart_receive_callback_table[UART_TOTAL_NUM] __attribute__((weak));
fInterruptFunc_t uart_transmit_callback_table[UART_TOTAL_NUM] __attribute__((weak));

// Constructors ////////////////////////////////////////////////////////////////

/**********************************************************************************************************************
 * Function Name: HardwareUart::HardwareUart
 * Description  : Constructor
 * Arguments    : rxen - UART channel
 * Return Value : void
 *********************************************************************************************************************/
HardwareUart::HardwareUart(uint8_t rxen)
{
    _urt_channel   = rxen;
    _rx_buffer_head = 0;
    _rx_buffer_tail = 0;
    _tx_buffer_head = 0;
    _tx_buffer_tail = 0;
    _rx_buf_size    = 0;
    _tx_buf_size    = 0;
    _rx_buffer      = 0;
    _tx_buffer      = 0;
    transmitting    = 0;
    receive_buffer  = 0;
}

// Public Methods //////////////////////////////////////////////////////////////

/**********************************************************************************************************************
 * Function Name: HardwareUart::begin
 * Description  : Initialize and configure the serial port.
 * Arguments    : baud   - baud rate
 *              :          { 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 31250, 38400, 57600, 115200 }
 * Return Value : void
 *********************************************************************************************************************/
void HardwareUart::begin(unsigned long baud)
{
    begin(baud, SERIAL_8N1);
}

/**********************************************************************************************************************
 * Function Name: HardwareUart::begin
 * Description  : Initialize and configure the serial port.
 * Arguments    : baud   - baud rate
 *              :          { 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 31250, 38400, 57600, 115200 }
 *              : config - serial port setting
 *               :         SERIAL_{ 8, 7 }{ N, E }{ 1, 2 }
 * Return Value : void
 *********************************************************************************************************************/
void HardwareUart::begin(unsigned long baud, uint16_t config){
    begin(baud, config, SERIAL_BUFFER_SIZE, SERIAL_BUFFER_SIZE);
}

/**********************************************************************************************************************
 * Function Name: HardwareUart::begin
 * Description  : Initialize and configure the serial port.
 * Arguments    : baud   - baud rate
 *              :          { 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 31250, 38400, 57600, 115200 }
 *              : rx_buf - receive  buffer size
 *              : tx_buf - transmit buffer size
 * Return Value : void
 *********************************************************************************************************************/
void HardwareUart::begin(unsigned long baud, int rx_buf, int tx_buf){
    begin(baud, SERIAL_8N1, rx_buf, tx_buf);
}

/**********************************************************************************************************************
 * Function Name: HardwareUart::begin
 * Description  : Initialize and configure the serial port.
 * Arguments    : baud   - baud rate
 *              :          { 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 31250, 38400, 57600, 115200 }
 *              : config - serial port setting
 *               :         SERIAL_{ 8, 7 }{ N, E }{ 1, 2 }
 *              : rx_buf - receive  buffer size
 *              : tx_buf - transmit buffer size
 * Return Value : void
 *********************************************************************************************************************/
void HardwareUart::begin(unsigned long baud, uint16_t config, int rx_buf, int tx_buf)
{
    /* Initialize Unit */
    /* begin executed. end call */
    if ((0 != _rx_buffer) || (0 != _tx_buffer))
    {
        return;
    }
    if ((1 == rx_buf) || (1 == tx_buf))
    {
        return;
    }
#if defined(FEW_RAM_MODEL) && (FEW_RAM_MODEL == 1)
    _rx_buffer = base_rx_buffer;
    _tx_buffer = base_tx_buffer;
#else
    _rx_buffer = (uint8_t *)malloc((size_t)(rx_buf * (int)sizeof(uint8_t)));
    if (0 == _rx_buffer)
    {
        _rx_buf_size = 0;
        _tx_buf_size = 0;
        return;
    }
    _tx_buffer = (uint8_t *)malloc((size_t)(tx_buf * (int)sizeof(uint8_t)));
    if (0 == _tx_buffer)
    {
        free((uint8_t *)_rx_buffer);
        _rx_buffer = 0;
        _rx_buf_size = 0;
        _tx_buf_size = 0;
        return;
    }
#endif

    _rx_buf_size = rx_buf;
    _tx_buf_size = tx_buf;
    _rx_buffer_head = 0;
    _rx_buffer_tail = 0;
    _tx_buffer_head = 0;
    _tx_buffer_tail = 0;

    switch (_urt_channel)
    {
        case 0:
#if defined(UART_CHANNEL) && (UART_CHANNEL==0)
            R_Config_UART0_Create();
            Set_Baudrate(baud);
            Set_SerialPort(SERIAL_TXD0,SERIAL_RXD0);
            Set_Config(config);
            R_Config_UART0_Start();
            R_Config_UART0_Receive((uint8_t * const)&receive_buffer,1);
#endif /* defined(UART_CHANNEL) && UART_CHANNEL==0 */
            break;
        case 1:
#if (UART1_CHANNEL==1)
            R_Config_UART1_Create();
            Set_Baudrate(baud);
            Set_SerialPort(SERIAL_TXD1,SERIAL_RXD1);
            Set_Config(config);
            R_Config_UART1_Start();
            R_Config_UART1_Receive((uint8_t * const)&receive_buffer,1);
#endif /* UART1_CHANNEL==1 */
            break;
        case 2:
#if (UART2_CHANNEL==2)
            R_Config_UART2_Create();
            Set_Baudrate(baud);
            Set_SerialPort(SERIAL_TXD2,SERIAL_RXD2);
            Set_Config(config);
            R_Config_UART2_Start();
            R_Config_UART2_Receive((uint8_t * const)&receive_buffer,1);
#endif /* UART2_CHANNEL==2 */
            break;
        default :
            /* Do nothing */
            break;
    }
}

/**********************************************************************************************************************
 * Function Name: HardwareUart::end
 * Description  : Terminate the serial port processing.
 * Arguments    : -
 * Return Value : void
 *********************************************************************************************************************/
void HardwareUart::end()
{
    switch (_urt_channel)
    {
    case 0:
#if defined(UART_CHANNEL) && (UART_CHANNEL == 0 )
        R_Config_UART0_Stop();
#endif /* defined(UART_CHANNEL) && (UART_CHANNEL == 0 ) */
        break;
    case 1:
#if (UART1_CHANNEL == 1 )
        R_Config_UART1_Stop();
#endif /* (UART1_CHANNEL == 1 ) */
        break;
    case 2:
#if (UART2_CHANNEL == 2 )
        R_Config_UART2_Stop();
#endif /* (UART2_CHANNEL == 2 ) */
        break;
    default :
            /* Do nothing */
        break;
        }
#if defined(FEW_RAM_MODEL) && (FEW_RAM_MODEL == 1)
    _rx_buffer = 0;
    _tx_buffer = 0;
#else
    if(_rx_buffer!= 0)
    {
        free((uint8_t *)_rx_buffer);
        _rx_buffer = 0;
    }
    if(_tx_buffer!= 0)
    {
        free((uint8_t *)_tx_buffer);
        _tx_buffer = 0;
    }
#endif
    _rx_buffer_head = 0;
    _rx_buffer_tail = 0;
    _tx_buffer_head = 0;
    _tx_buffer_tail = 0;
    _rx_buf_size = 0;
    _tx_buf_size = 0;
}

/**********************************************************************************************************************
 * Function Name: HardwareUart::available
 * Description  : Get the number of readable data bytes of received data.
 * Arguments    : -
 * Return Value : size of readable data
 *********************************************************************************************************************/
int HardwareUart::available(void)
{
    int head = 0;
    int tail = 0;
    noInterrupts();
    head = _rx_buffer_head;
    tail = _rx_buffer_tail;
    interrupts();
    if (head >= tail) return head - tail;
    return (_rx_buf_size - tail + head );
}

/**********************************************************************************************************************
 * Function Name: HardwareUart::peek
 * Description  : Read received data by 1 byte and do not change the buffer position.
 * Arguments    : -
 * Return Value : -1    - no read data
 *              : other - read data
 *********************************************************************************************************************/
int HardwareUart::peek(void)
{
    if (_rx_buffer_head == _rx_buffer_tail)
    {
        return -1;
    }
    else
    {
        return _rx_buffer[_rx_buffer_tail];
    }
}

/**********************************************************************************************************************
 * Function Name: HardwareUart::read
 * Description  : Read received data by 1 byte and advance the buffer position by 1 byte.
 * Arguments    : -
 * Return Value : -1    - no read data
 *              : other - read data
 *********************************************************************************************************************/
int HardwareUart::read(void)
{
    /* if the head isn't ahead of the tail, we don't have any characters */
    noInterrupts();
    if (_rx_buffer_head == _rx_buffer_tail)
    {
        interrupts();
        return -1;
    }
    unsigned char c = _rx_buffer[_rx_buffer_tail];
    _rx_buffer_tail = (_rx_buffer_tail + 1) % _rx_buf_size;
    interrupts();

    return c;
}

/**********************************************************************************************************************
 * Function Name: HardwareUart::flush
 * Description  : Wait for all data transmission in the transmission buffer to be completed.
 * Arguments    : -
 * Return Value : void
 *********************************************************************************************************************/
void HardwareUart::flush()
{
  /* buffer is none */


    if (0 == _tx_buf_size || 0 == _tx_buffer)
    {
        return;
    }
    if (_urt_channel == 0)
    {
#if defined(UART_CHANNEL) && ( UART_CHANNEL == 0 )
    	while (SSR00 & (_0040_SAU_UNDER_EXECUTE | _0020_SAU_VALID_STORED))
        {  /* check TSF00 and BFF00 */
            ;
        }
#endif /* defined(UART_CHANNEL) && ( UART_CHANNEL == 0 ) */
    }
    else if (_urt_channel == 1)
    {
#if ( UART1_CHANNEL == 1 )
    	while (SSR02 & (_0040_SAU_UNDER_EXECUTE | _0020_SAU_VALID_STORED))
        {  /* check TSF02 and BFF02 */
            ;
        }
#endif /* ( UART1_CHANNEL == 1 ) */
    }
    else if (_urt_channel == 2)
    {
#if ( UART2_CHANNEL == 2 )
    	while (SSR10 & (_0040_SAU_UNDER_EXECUTE | _0020_SAU_VALID_STORED))
        {  /* check TSF10 and BFF10 */
            ;
        }
#endif /* ( UART2_CHANNEL == 2 ) */
    }
    while(_tx_buf_size-1!=availableForWrite())
    {
        NOP();
    }
}

/**********************************************************************************************************************
 * Function Name: HardwareUart::UART_Send
 * Description  : Transmit data to the target serial port (actual implementation of write operation).
 * Arguments    : c - transmission data
 * Return Value : -1    - write failed with the transmission buffer overflow
 *              : other - written data size
 *********************************************************************************************************************/
size_t HardwareUart::UART_Send(uint8_t c)
{
    MD_STATUS err = MD_OK;
    int i;
    uint8_t isp;
    size_t ret = 0;

    /* buffer is none */
    if (0 == _tx_buf_size)
    {
        return ret;
    }
    isp = (uint8_t)GET_PSW_ISP();
    noInterrupts();
    if(_tx_buffer_tail == _tx_buffer_head)
    {
        /* Unsent */
        //int head = (_tx_buffer_head + 1);
        i = (_tx_buffer_head + 1) % _tx_buf_size;
        _tx_buffer[_tx_buffer_head] = c;
        _tx_buffer_head = i;
        interrupts();
        switch (_urt_channel)
        {
            case 0:
#if defined(UART_CHANNEL) && ( UART_CHANNEL == 0 )
                if((SSR00 & _0020_SAU_VALID_STORED) != 0)/*BFF00*/
                {
                    return 0;
                }
                err = R_Config_UART0_Send((uint8_t * const)&c,1);
#endif /* defined(UART_CHANNEL) && ( UART_CHANNEL == 0 ) */
                break;
            case 1:
#if ( UART1_CHANNEL == 1 )
                if((SSR02 & _0020_SAU_VALID_STORED) != 0)/*BFF02*/
                {
                    return 0;
                }
                err = R_Config_UART1_Send((uint8_t * const)&c,1);
#endif /* ( UART1_CHANNEL == 1 ) */
                break;
            case 2:
#if ( UART2_CHANNEL == 2 )
                if((SSR10 & _0020_SAU_VALID_STORED) != 0)/*BFF10*/
                {
                    return 0;
                }
                err = R_Config_UART2_Send((uint8_t * const)&c,1);
#endif /* ( UART2_CHANNEL == 2 ) */
                break;
        default :
            /* Do nothing */
                break;
        }
    }
    else
    {
        /* only buffer copy during transmission process */
        i = (_tx_buffer_head + 1) % _tx_buf_size;
        if(i == _tx_buffer_tail)
        {
            /* buffer over */
            if(ISP_LEVEL_3 == isp)
            {
                /* When called from main program(setup() or loop() */
                interrupts();
                while(i == _tx_buffer_tail)
                {
                    ;
                }
                noInterrupts();
            }
            else
            {
                /* When called from interuupt function (ex. callback routine for periodic processing */
                switch (_urt_channel)
                {
                    case 0:
        #if defined(UART_CHANNEL) && ( UART_CHANNEL == 0 )
                        while (SSR00 & (_0040_SAU_UNDER_EXECUTE | _0020_SAU_VALID_STORED))
                        {  /* check TSF00 and BFF00 */
                            ;
                        }
                        STIF0 = 0;
        #endif /* defined(UART_CHANNEL) && ( UART_CHANNEL == 0 ) */
                        break;
                    case 1:
        #if ( UART1_CHANNEL == 1 )
                        while (SSR02 & (_0040_SAU_UNDER_EXECUTE | _0020_SAU_VALID_STORED))
                        {  /* check TSF02 and BFF02 */
                            ;
                        }
                        STIF1 = 0;
        #endif /* ( UART1_CHANNEL == 1 ) */
                        break;
                    case 2:
        #if ( UART2_CHANNEL == 2 )
                        while (SSR10 & (_0040_SAU_UNDER_EXECUTE | _0020_SAU_VALID_STORED))
                        {  /* check TSF10 and BFF10 */
                            ;
                        }
                        STIF2 = 0;
        #endif /* ( UART2_CHANNEL == 2 ) */
                        break;
                    case 3:
                        break;
                }
                Set_Char_Serial_from_buf(_urt_channel);
                if(0 != uart_transmit_callback_table[_urt_channel])
                {
                    (*uart_transmit_callback_table[_urt_channel])();
                }
            }
        }
        _tx_buffer[_tx_buffer_head] = c;
        _tx_buffer_head = i;
        interrupts();
    }
    if(err == MD_OK){
        return 1;
    }
    return ret;
}

/**********************************************************************************************************************
 * Function Name: HardwareUart::write
 * Description  : Transmit data to the target serial port.
 * Arguments    : c - transmission data
 * Return Value : -1    - write failed with the transmission buffer overflow
 *              : other - written data size
 *********************************************************************************************************************/

size_t HardwareUart::write(uint8_t c)
{
    size_t err = 0;
    err = UART_Send(c);
    return err;
}


/**********************************************************************************************************************
 * Function Name: HardwareUart::availableForWrite
 * Description  : Get the number of available transmit buffer space for write.
 * Arguments    : -
 * Return Value : size of transmit buffer free space
 *********************************************************************************************************************/
int HardwareUart::availableForWrite(void)
{
    int head = 0;
    int tail = 0;
    noInterrupts();
    head = _tx_buffer_head;
    tail = _tx_buffer_tail;
    interrupts();
    if (head >= tail) return _tx_buf_size - 1 - head + tail;
    return (tail - head - 1);
}

/**********************************************************************************************************************
 * Function Name: HardwareUart::availableForRead
 * Description  : Get the number of available receive buffer space for read.
 * Arguments    : -
 * Return Value : size of receive buffer free space
 *********************************************************************************************************************/
int HardwareUart::availableForRead(void)
{
    int head = 0;
    int tail = 0;
    noInterrupts();
    head = _rx_buffer_head;
    tail = _rx_buffer_tail;
    interrupts();
    if (head >= tail) return _rx_buf_size - 1 - head + tail;
    return (tail - head - 1);
}

HardwareUart::operator bool() {
    return true;
}

/* Load Send data from Send Buffer & Start New Send Function */
/**********************************************************************************************************************
 * Function Name: HardwareUart::load_char
 * Description  : Extract 1 byte from the transmit buffer and send it.
 *              : Called from the transmission complete interrupt handler.
 *              : Unavailable for the other purpose.
 * Arguments    :  -
 * Return Value :  -
 *********************************************************************************************************************/
void HardwareUart::load_char(void){
    int i = (_tx_buffer_tail + 1) % _tx_buf_size;
    _tx_buffer_tail = i;
    if (i != _tx_buffer_head) {
        uint8_t send_buffer  = _tx_buffer[i];
        switch (_urt_channel)
        {
        case 0:
#if defined(UART_CHANNEL) && (UART_CHANNEL == 0)
            R_Config_UART0_Send((uint8_t * const)&send_buffer,1);
#endif /* defined(UART_CHANNEL) && (UART_CHANNEL == 0) */
            break;
        case 1:
#if (UART1_CHANNEL == 1)
            R_Config_UART1_Send((uint8_t * const)&send_buffer,1);
#endif /* (UART1_CHANNEL == 1) */
            break;
        case 2:
#if (UART2_CHANNEL == 2)
            R_Config_UART2_Send((uint8_t * const)&send_buffer,1);
#endif /* (UART2_CHANNEL == 2) */
            break;
        default :
            /* Do nothing */
            break;
        }
    }
}


/* Store Received data to Receive Buffer & Start New Receive Function */
/**********************************************************************************************************************
 * Function Name: HardwareUart::store_char
 * Description  : Store 1 byte of the last received data in the receive buffer
 *              : and continue the receive process for the following bytes.
 *              : Called from the receive complete interrupt handler.
 *              : Unavailable for the other purpose.
 * Arguments    : -
 * Return Value : -
 *********************************************************************************************************************/
void HardwareUart::store_char(void){
    store_char(receive_buffer);
    receive_buffer = 0;
    switch (_urt_channel)
    {
    case 0:
    #if defined(UART_CHANNEL) && (UART_CHANNEL == 0)
        R_Config_UART0_Receive((uint8_t * const)&receive_buffer,1);
    #endif /* defined(UART_CHANNEL) && (UART_CHANNEL == 0) */
        break;
    case 1:
    #if (UART1_CHANNEL == 1)
        R_Config_UART1_Receive((uint8_t * const)&receive_buffer,1);
    #endif /* (UART1_CHANNEL == 1) */
        break;
    case 2:
    #if (UART2_CHANNEL == 2)
        R_Config_UART2_Receive((uint8_t * const)&receive_buffer,1);
    #endif /* (UART2_CHANNEL == 2) */
        break;
    default :
            /* Do nothing */
        break;
    }
}

/**********************************************************************************************************************
 * Function Name: HardwareUart::store_char
 * Description  : Store 1 byte of the last received data in the receive buffer
 *              : and continue the receive process for the following bytes.
 *              : Make sure to disable interrupts before calling this from outside of the interrupt handler.
 * Arguments    : c - byte to store
 * Return Value : -
 *********************************************************************************************************************/
void HardwareUart::store_char(unsigned char c){
    int i = (_rx_buffer_head + 1) % _rx_buf_size;
    if (i != _rx_buffer_tail)
    {
        _rx_buffer[_rx_buffer_head] = c;
        _rx_buffer_head = i;
    }
}

/* Add for RL78/G23 */
/**********************************************************************************************************************
 * Function Name: HardwareUart::Set_Baudrate
 * Description  : Set baud rate for the serial port.
 * Arguments    : baudrate - baud rate
 *              :            { 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 31250, 38400, 57600, 115200 }
 * Return Value : void
 *********************************************************************************************************************/
void HardwareUart::Set_Baudrate(unsigned long baudrate)
{
    uint32_t fclk_frequency;
    uint32_t  peri_clk    ;
    uint8_t  sdr     ;
    uint16_t tmp_sdr ;
    uint8_t  prs = 0U;
    fclk_frequency = R_BSP_GetFclkFreqHz();

    peri_clk    = (fclk_frequency) ; /* SPSmk0\[3:0] = 0x0 */

    tmp_sdr = (uint16_t)(((peri_clk/baudrate) >> 1) -1) ;
    while(0x007F<tmp_sdr)
    {
        prs++;
        peri_clk = (peri_clk >> 1);
        tmp_sdr  = (uint16_t)(((peri_clk/baudrate) >> 1) -1) ;
    }

    sdr     = (uint8_t)(tmp_sdr & 0x007F) ;

    switch (_urt_channel)
    {
        case 0:
#if defined(UART_CHANNEL) && ( UART_CHANNEL == 0 )
            SPS0 &= (_00F0_SAU_CK00_CLEAR) ;
            SPS0 |=  prs ;
            SDR00 = ((uint16_t)sdr) << 9 ;
            SDR01 = ((uint16_t)sdr) << 9 ;
#endif /* defined(UART_CHANNEL) && ( UART_CHANNEL == 0 ) */
            break;
        case 1:
#if ( UART1_CHANNEL == 1 )
            SPS0 &= (_000F_SAU_CK01_CLEAR) ;
            SPS0 |= ((uint16_t)prs << 4);
            SDR02 = ((uint16_t)sdr) << 9 ;
            SDR03 = ((uint16_t)sdr) << 9 ;
#endif /* ( UART1_CHANNEL == 1 ) */
            break;
        case 2:
#if ( UART2_CHANNEL == 2 )
            SPS1 &= (_00F0_SAU_CK00_CLEAR) ;
            SPS1 |= prs ;
            SDR10 = ((uint16_t)sdr) << 9 ;
            SDR11 = ((uint16_t)sdr) << 9 ;
#endif /* ( UART2_CHANNEL == 2 ) */
            break;
        default :
            /* Do nothing */
            break;
    }
}

#ifdef __RL78__
/**********************************************************************************************************************
 * Function Name: HardwareUart::Set_Config
 * Description  : Set the serial data length, parity, and stop bit.
 * Arguments    : config - serial port setting
 *               :         SERIAL_{ 8, 7 }{ N, E }{ 1, 2 }
 * Return Value : void
 *********************************************************************************************************************/
void HardwareUart::Set_Config(uint16_t config )
{
    uint16_t converted_config = 0;

    switch(config)
    {
        case SERIAL_7N1:
        case SERIAL_8N1:
        case SERIAL_7N2:
        case SERIAL_8N2:
        case SERIAL_7E1:
        case SERIAL_8E1:
        case SERIAL_7E2:
        case SERIAL_8E2:
        case SERIAL_7O1:
        case SERIAL_8O1:
        case SERIAL_7O2:
        case SERIAL_8O2:
            /* Do nothing */
            break;
        default:
            config = SERIAL_8N1;
            break;
    }
    if(SERIAL_DATA_7 == (SERIAL_DATA_MASK & config))
    {
        converted_config |= _0002_SAU_LENGTH_7;
    }
    else
    {
        /* All other settings are treated as SERIAL_DATA_8(default). */
        converted_config |= _0003_SAU_LENGTH_8;
    }

    if(SERIAL_STOP_BIT_2 == (SERIAL_STOP_BIT_MASK & config))
    {
        converted_config |= _0020_SAU_STOP_2;
    }
    else
    {
        /* All other settings are treated as SERIAL_STOP_BIT_1(default). */
        converted_config |= _0010_SAU_STOP_1;
    }

    if(SERIAL_PARITY_EVEN == (SERIAL_PARITY_MASK & config))
    {
        converted_config |= _0200_SAU_PARITY_EVEN;
    }
    else if(SERIAL_PARITY_ODD == (SERIAL_PARITY_MASK & config))
    {
        converted_config |= _0300_SAU_PARITY_ODD;
    }
    else
    {
        /* All other settings are treated as SERIAL_PARITY_NONE(default). */
        converted_config |= _0000_SAU_PARITY_NONE;
    }

    switch (_urt_channel)
    {
        /* Rewriting prohibited when SEmn = 1 / Set_Config is called between R_Config_UART0_Create () and R_Config_UART0_Start (), so SEmn = 0*/
        case 0:
        {
        /* SCR00 16bit*/
#if defined(UART_CHANNEL) && ( UART_CHANNEL == 0 )
        unsigned short SCR00data=_8000_SAU_TRANSMISSION |_0000_SAU_INTSRE_MASK |_0004_SAU_SCRMN_INITIALVALUE |_0080_SAU_LSB | converted_config;
        /* When sending, _0000_SAU_INTSRE_MASK :EOCmn = 0*/
        unsigned short SCR01data=_4000_SAU_RECEPTION |_0400_SAU_INTSRE_ENABLE |_0004_SAU_SCRMN_INITIALVALUE |_0080_SAU_LSB | converted_config;
        /* _0400_SAU_INTSRE_ENABLE: EOCmn = 1 Allow the occurrence of the error interrupt INTSREx */

        /* SLCmn1: 0 SLCmn0: 1 when receiving XXXXXXXXXX01XXXX*/
        SCR01data &= ~(_0020_SAU_STOP_2);
        SCR01data |= _0010_SAU_STOP_1;

        SCR00 = SCR00data;
        SCR01 = SCR01data;
#endif /* defined(UART_CHANNEL) && ( UART_CHANNEL == 0 ) */
        }
        break;

        case 1:
        {
#if ( UART1_CHANNEL == 1 )
        unsigned short SCR02data=_8000_SAU_TRANSMISSION| _0000_SAU_INTSRE_MASK |_0004_SAU_SCRMN_INITIALVALUE |_0080_SAU_LSB |converted_config;
        unsigned short SCR03data=_4000_SAU_RECEPTION| _0400_SAU_INTSRE_ENABLE |_0004_SAU_SCRMN_INITIALVALUE |_0080_SAU_LSB |converted_config;
        /* SLCmn1: 0 SLCmn0: 1 when receiving XXXXXXXXXX01XXXX*/
        SCR03data &= ~(_0020_SAU_STOP_2);
        SCR03data |= _0010_SAU_STOP_1;

        SCR02 = SCR02data;
        SCR03 = SCR03data;
#endif /* ( UART1_CHANNEL == 1 ) */
        }
        break;
        case 2:
        {
#if ( UART2_CHANNEL == 2 )
            unsigned short SCR10data=_8000_SAU_TRANSMISSION| _0000_SAU_INTSRE_MASK |_0004_SAU_SCRMN_INITIALVALUE |_0080_SAU_LSB |converted_config;
            unsigned short SCR11data=_4000_SAU_RECEPTION| _0400_SAU_INTSRE_ENABLE |_0004_SAU_SCRMN_INITIALVALUE |_0080_SAU_LSB |converted_config;
            /* SLCmn1: 0 SLCmn0: 1 when receiving XXXXXXXXXX01XXXX*/
            SCR11data &= ~(_0020_SAU_STOP_2);
            SCR11data |= _0010_SAU_STOP_1;
            SCR10 = SCR10data;
            SCR11 = SCR11data;
#endif /* ( UART2_CHANNEL == 2 ) */
        }
        break;
        default :
            /* Do nothing */
        {

        }
        break;
    }
}
/**********************************************************************************************************************
 End of function Set_Config
 *********************************************************************************************************************/
#endif /* __RL78__ */

/**********************************************************************************************************************
 * Function Name: HardwareUart::Set_SerialPort
 * Description  : Set serial port pins for the target port.
 * Arguments    : txd_pin - transmit pin no.
 *              : rxd_pin - receive  pin no.
 * Return Value : void
 *********************************************************************************************************************/
void HardwareUart::Set_SerialPort(uint8_t txd_pin,uint8_t rxd_pin)
{
    const PinTableType ** pp;
    PinTableType * p;

    /* Set RxD pin */
    //getPinTable(rxd_pin,p);
    pp = &pinTablelist[rxd_pin];
    p = (PinTableType *)*pp;
    /* Set PM Register for Input */
    *p->portModeRegisterAddr |=  (unsigned long)(0x1 << p->bit);

#if defined(G22_FPB) || defined(G23_FPB)
    /* Set PMCA Register */
    if (0!=p->pmca)
    {
        *p->portModeControlARegisterAddr &= (unsigned long)~(p->pmca);
    }
#endif // defined(G22_FPB) || defined(G23_FPB)

    /* Set PMCT Register */
#if defined(G22_FPB) || defined(G23_FPB)
    if (0!=p->pmct)
    {
        *p->portModeControlTRegisterAddr &= (unsigned long)~(p->pmct);
    }
#endif // defined(G22_FPB) || defined(G23_FPB)

    /* Set PMCE Register for Output */
#if defined(G23_FPB)
    if (0!=p->pmce)
    {
        *p->portModeControlERegisterAddr &= (unsigned long)~(p->pmce);
    }
#endif // G23_FPB
    /* Set CCDE Register for Digital InOut */
#if defined(G23_FPB)
    if (0!=p->ccde)
    {
        CCDE &= (uint8_t)~(p->ccde);
    }
#endif // G23_FPB
#if defined(G16_FPB)
    if (0!=p->pmc)
    {
        *p->portModeControlRegisterAddr &= (unsigned long)~(p->pmc);
    }
#endif // defined(G16_FPB)

    /* Set TxD pin */
    //getPinTable(txd_pin,p);
    pp = &pinTablelist[txd_pin];
    p = (PinTableType *)*pp;
    /* Set PMCE Register t */
#if defined(G23_FPB)
    if (0!=p->pmce)
    {
        *p->portModeControlERegisterAddr &= (unsigned long)~(p->pmce);
    }
#endif // G23_FPB

    /* Set P Register for Set "H" Output Port*/
    *p->portRegisterAddr |= (unsigned long)(0x1 << p->bit);

    /* Set PM Register for Output */
    *p->portModeRegisterAddr &= (unsigned long)~(0x1 << p->bit);

    /* Set PMCA Register */
#if defined(G22_FPB) || defined(G23_FPB)
    if (0!=p->pmca)
    {
        *p->portModeControlARegisterAddr &= (unsigned long)~(p->pmca);
    }
#endif // defined(G22_FPB) || defined(G23_FPB)

    /* Set PMCT Register */
#if defined(G22_FPB) || defined(G23_FPB)
    if (0!=p->pmct)
    {
        *p->portModeControlTRegisterAddr &= (unsigned long)~(p->pmct);
    }
#endif // defined(G22_FPB) || defined(G23_FPB)

    /* Set PMCE Register t */
#if defined(G23_FPB)
    if (0!=p->pmce)
    {
        *p->portModeControlERegisterAddr &= (unsigned long)~(p->pmce);
    }
#endif // G23_FPB
    /* Set CCDE Register for Digital InOut */
#if defined(G23_FPB)
    if (0!=p->ccde)
    {
        CCDE &= (uint8_t)~(p->ccde);
    }
#endif // G23_FPB

#if defined(G16_FPB)
    if (0!=p->pmc)
    {
        *p->portModeControlRegisterAddr &= (unsigned long)~(p->pmc);
    }
#endif // G16_FPB
}

void HardwareUart::setReceiveCallback(void (*userFunc)(void))
{
    uart_receive_callback_table[_urt_channel] = userFunc;
}

void HardwareUart::setTransmitCallback(void (*userFunc)(void))
{
    uart_transmit_callback_table[_urt_channel] = userFunc;
}

extern "C" {
/**********************************************************************************************************************
 * Function Name: Set_Char_Serial_to_buf
 * Description  : Store the received data in the buffer.
 *              : Called from the receive interrupt handler.
 * Arguments    : chn - UART channel
 * Return Value : void
 *********************************************************************************************************************/
void Set_Char_Serial_to_buf(uint8_t chn)
{
    switch (chn)
    {
        case 0:
#if defined(UART_CHANNEL) && (UART_CHANNEL == 0)
            Serial.store_char();
#endif /* defined(UART_CHANNEL) && (UART_CHANNEL == 0) */
            break;
        case 1:
#if (UART1_CHANNEL == 1)
            Serial1.store_char();
#endif /* (UART1_CHANNEL == 1) */
            break;
        case 2:
#if (UART2_CHANNEL == 2)
            Serial2.store_char();
#endif /* (UART2_CHANNEL == 2) */
            break;
        default :
            /* Do nothing */
            break;
    }
}

/**********************************************************************************************************************
 * Function Name: Set_Char_Serial_from_buf
 * Description  : Load write data from the buffer.
 * Arguments    : chn  - UART_CHANNEL
 * Return Value : void         -
 *********************************************************************************************************************/

void Set_Char_Serial_from_buf(uint8_t chn)
{
    switch (chn)
    {
        case 0:
#if defined(UART_CHANNEL) && (UART_CHANNEL == 0)
            Serial.load_char();
#endif /* defined(UART_CHANNEL) && (UART_CHANNEL == 0) */
            break;
        case 1:
#if (UART1_CHANNEL == 1)
            Serial1.load_char();
#endif /* (UART1_CHANNEL == 1) */
            break;
        case 2:
#if (UART2_CHANNEL == 2)
            Serial2.load_char();
#endif /* (UART2_CHANNEL == 2) */
            break;
        default :
            /* Do nothing */
            break;
    }
}

}

// Preinstantiate Objects //////////////////////////////////////////////////////

#if defined(UART_CHANNEL) && ( UART_CHANNEL == 0 )
    HardwareUart Serial(0);
#endif /* defined(UART_CHANNEL) && ( UART_CHANNEL == 0 ) */
#if ( UART1_CHANNEL == 1 )
    HardwareUart Serial1(1);
#endif /* ( UART1_CHANNEL == 1 ) */
#if ( UART2_CHANNEL == 2 )
    HardwareUart Serial2(2);
#endif /* ( UART2_CHANNEL == 2 ) */


