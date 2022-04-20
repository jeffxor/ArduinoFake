#pragma once
#include "ArduinoFake.h"
#include "StreamFake.h"
#include "arduino/SPI.h"

struct SPIClassFake
{
public:
    virtual void begin(int8_t sck=-1, int8_t miso=-1, int8_t mosi=-1, int8_t ss=-1) = 0;
    virtual void end() = 0;

    virtual void setHwCs(bool use) = 0;
    virtual void setBitOrder(uint8_t bitOrder) = 0;
    virtual void setDataMode(uint8_t dataMode) = 0;
    virtual void setFrequency(uint32_t freq) = 0;
    virtual void setClockDivider(uint32_t clockDiv) = 0;
    
    virtual uint32_t getClockDivider() = 0;

    virtual void beginTransaction(SPISettings settings) = 0;
    virtual void endTransaction(void) = 0;
    virtual void transfer(uint8_t * data, uint32_t size) = 0;
    virtual uint8_t transfer(uint8_t data) = 0;
    virtual uint16_t transfer16(uint16_t data) = 0;
    virtual uint32_t transfer32(uint32_t data) = 0;
  
    virtual void transferBytes(const uint8_t * data, uint8_t * out, uint32_t size) = 0;
    virtual void transferBits(uint32_t data, uint32_t * out, uint8_t bits) = 0;

    virtual void write(uint8_t data) = 0;
    virtual void write16(uint16_t data) = 0;
    virtual void write32(uint32_t data) = 0;
    virtual void writeBytes(const uint8_t * data, uint32_t size) = 0;
    virtual void writePixels(const void * data, uint32_t size) = 0;//ili9341 compatible
    virtual void writePattern(const uint8_t * data, uint8_t size, uint32_t repeat) = 0;
};

class SPIClassFakeProxy : public SPIClass {
private:
  SPIClassFake * spiClassFake;

public:
  SPIClassFakeProxy(SPIClassFake *fake) { spiClassFake = fake; }

  SPIClassFake *getSPIClassFake() { return spiClassFake; }
};
