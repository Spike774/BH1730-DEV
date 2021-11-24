#ifndef __BH1730_H
#define __BH1730_H

#include "i2c.h"
#include "oled.h"


#define BH1730_DEBUG 0

#define BH1730_ADDR_S                 (uint8_t)0x29
#define BH1730_ADDR                   (BH1730_ADDR_S << 1)
// #define BH1730_ADDR                   BH1730_ADDR_S

#define BH1730_PART_NUMBER 0x7

#define BH1730_CMD 0x80
#define BH1730_CMD_SPECIAL 0x60
#define BH1730_CMD_SPECIAL_SOFT_RESET 0x4

#define BH1730_REG_CONTROL 0x00
#define BH1730_REG_GAIN 0x7
#define BH1730_REG_TIMING 0x01
#define BH1730_REG_PART_ID 0x12
#define BH1730_REG_DATA0_LOW  0x14
#define BH1730_REG_DATA0_HIGH 0x15
#define BH1730_REG_DATA1_LOW 0x16
#define BH1730_REG_DATA1_HIGH 0x17

#define BH1730_REG_CONTROL_POWER 0x1
#define BH1730_REG_CONTROL_ADC_EN 0x2
#define BH1730_REG_CONTROL_ONE_TIME 0x8
#define BH1730_REG_CONTROL_ADC_VALID 0x10

#define BH1730_GAIN_X1_MODE 0x00
#define BH1730_GAIN_X2_MODE 0x01
#define BH1730_GAIN_X64_MODE 0x02
#define BH1730_GAIN_X128_MODE 0x03

#define BH1730_RET_TIMEOUT 50

#define BH1730_ITIME 218
#define BH1730_T_INT 2.8
#define BH1730_ITIME_MS ((BH1730_T_INT/1000.0) * 964.0 * (256.0 - BH1730_ITIME))

#define BH1730_GAIN_SET 0x00

#define GAIN_X1         1
#define GAIN_X2         2
#define GAIN_X64        64
#define GAIN_X128       128


// #define BH1730_CMD_MAGIC 0x80
// #define BH1730_CMD_SETADDR 0x0
// #define BH1730_CMD_SPECCMD 0x60

// #define BH1730_SPECCMD_INTRESET 0x1
// #define BH1730_SPECCMD_STOPMEAS 0x2
// #define BH1730_SPECCMD_STARTMEAS 0x3
// #define BH1730_SPECCMD_RESET 0x4

// #define BH1730_ADDR_CONTROL 0x00
// #define BH1730_ADDR_TIMING 0x01
// #define BH1730_ADDR_INTERRUPT 0x02
// #define BH1730_ADDR_THLLOW 0x03
// #define BH1730_ADDR_THLHIGH 0x04
// #define BH1730_ADDR_THHLOW 0x05
// #define BH1730_ADDR_THHIGH 0x06
// #define BH1730_ADDR_GAIN 0x07
// #define BH1730_ADDR_ID 0x12
// #define BH1730_ADDR_DATA0LOW 0x14
// #define BH1730_ADDR_DATA0HIGH 0x15
// #define BH1730_ADDR_DATA1LOW 0x16
// #define BH1730_ADDR_DATA1HIGH 0x17


// #define BH1730_CTL_ADC_INTR 0x20
// #define BH1730_CTL_ADC_VALID 0x10
// #define BH1730_CTL_ONE_TIME 0x08
// #define BH1730_CTL_DATA_SEL 0x04
// #define BH1730_CTL_ADC_EN 0x02
// #define BH1730_CTL_POWER 0x01

// BH1730();
// uint8_t begin(void);                            //bool
// void setGain(BH1730_GAIN gain);
uint32_t BH1730_GetLux(void);


// uint8_t read8(uint8_t addr);
// uint16_t read16(uint8_t addr);
// void write8(uint8_t addr, uint8_t data);
// uint8_t read8(uint8_t a);
// uint16_t read16(uint8_t a);
// void write8(uint8_t a, uint8_t d);

#endif