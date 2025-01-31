#pragma once

#include "api/HardwareSerial.h"

#ifdef SERIAL_BUFFER_SIZE
#undef SERIAL_BUFFER_SIZE
#endif

#if defined(FEW_RAM_MODEL) && (FEW_RAM_MODEL == 1)
#define SERIAL_BUFFER_SIZE  32
#else
#define SERIAL_BUFFER_SIZE  256
#endif

class HardwareUart : public arduino::HardwareSerial
{
  public:
    HardwareUart(uint8_t rxen);
    /*API*/
    void begin(unsigned long baud) override ;
    void begin(unsigned long baud, uint16_t config) override ;
    void begin(unsigned long baud, int rx_buf, int tx_buf);
    void begin(unsigned long baud, uint16_t config, int rx_buf, int tx_buf);
    void end() override ;
    virtual int available(void) override;
    virtual int peek(void) override;
    virtual int read(void) override ;
    virtual void flush(void) override;
    virtual size_t write(uint8_t c) override;
    inline size_t write(unsigned long n) { return write((uint8_t)n); }
    inline size_t write(long n) { return write((uint8_t)n); }
    inline size_t write(unsigned int n) { return write((uint8_t)n); }
    inline size_t write(int n) { return write((uint8_t)n); }
    using Print::write; /* pull in write(str) and write(buf, size) from Print */
    int availableForWrite(void) override;
    int availableForRead(void);
    void store_char(unsigned char c);
    void setReceiveCallback(void (*userFunc)(void));
    void setTransmitCallback(void (*userFunc)(void));
    void load_char(void);
    void store_char(void);
    operator bool() override ;

  private:
    volatile int _rx_buffer_head;
    volatile int _rx_buffer_tail;
    volatile int _tx_buffer_head;
    volatile int _tx_buffer_tail;
    volatile int _rx_buf_size;
    volatile int _tx_buf_size;
    unsigned char *_rx_buffer;
    unsigned char *_tx_buffer;

#if defined(FEW_RAM_MODEL) && (FEW_RAM_MODEL == 1)
    unsigned char base_rx_buffer[SERIAL_BUFFER_SIZE];
    unsigned char base_tx_buffer[SERIAL_BUFFER_SIZE];
#endif //

    uint8_t receive_buffer;
    uint8_t _urt_channel;
    bool transmitting;

    size_t UART_Send(uint8_t c);
    /* size_t UART_Send(const uint8_t *buffer, size_t size); */

    void Set_SerialPort(uint8_t txd_pin,uint8_t rxd_pin);

    /* Add 2021.02.09 */
    void Set_Baudrate(unsigned long baurate);
    void Set_Config(uint16_t config);
};

extern HardwareUart Serial;
extern HardwareUart Serial1;
extern HardwareUart Serial2;
