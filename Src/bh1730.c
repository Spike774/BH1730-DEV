#include "bh1730.h"



static void BH1730_WriteReg(uint8_t addr, uint8_t value) {
    // uint8_t ret;
    uint8_t buf[2];
    // buf[0] = addr;
    buf[0] = addr | BH1730_CMD;
    buf[1] = value;
    HAL_I2C_Master_Transmit(&hi2c2, BH1730_ADDR , buf, 2, HAL_I2C_STATE_TIMEOUT);
    // ret = HAL_I2C_Master_Transmit(&hi2c2, BH1730_ADDR , buf, 2, HAL_I2C_STATE_TIMEOUT);
    // OLED_ShowNum(0, 0, ret, 8, 12, 1);
    // OLED_ShowNum(0, 32, 101, 3, 12, 1);
    // OLED_Refresh();
    // HAL_Delay(1000);
    // OLED_Clear();
}


static uint8_t BH1730_ReadReg(uint8_t addr) {
    // uint8_t ret;
    uint8_t value = 0;    
    addr = addr | BH1730_CMD;
    HAL_I2C_Master_Transmit(&hi2c2, BH1730_ADDR, &addr, 1, HAL_I2C_STATE_TIMEOUT);     
    // ret = HAL_I2C_Master_Transmit(&hi2c2, BH1730_ADDR, &addr, 1, HAL_I2C_STATE_TIMEOUT);     
    // HAL_I2C_Master_Transmit(&hi2c2, BH1730_ADDR, addr, 1, HAL_I2C_STATE_TIMEOUT);    
    // OLED_ShowNum(0, 16, ret, 8, 12, 1);
    // OLED_ShowNum(0, 32, 102, 3, 12, 1);
    // OLED_Refresh();
    // HAL_Delay(1000);
    // OLED_Clear(); 
    HAL_I2C_Master_Receive(&hi2c2, BH1730_ADDR, &value, 1, HAL_I2C_STATE_TIMEOUT);
    // ret = HAL_I2C_Master_Receive(&hi2c2, BH1730_ADDR, &value, 1, HAL_I2C_STATE_TIMEOUT);
    // OLED_ShowNum(0, 16, ret, 8, 12, 1);
    // OLED_ShowNum(0, 32, 103, 3, 12, 1);
    // OLED_Refresh();
    // HAL_Delay(1000);
    // OLED_Clear();    
    // OLED_ShowNum(0, 16, value, 8, 12, 1);
    // OLED_ShowNum(0, 32, 104, 3, 12, 1);
    // OLED_Refresh();
    // HAL_Delay(1000);
    // OLED_Clear();
    return value;
}


void BH1730_init(void){
  BH1730_WriteReg(BH1730_CMD_SPECIAL | BH1730_CMD_SPECIAL_SOFT_RESET, (1<<7)); 
}

/**
 *  Set gain of the internal ADC
 * 
 */
void setGain(uint8_t gain){
  if(gain == GAIN_X1){
    BH1730_WriteReg(BH1730_REG_GAIN, BH1730_GAIN_X1_MODE); 
  }else if(gain == GAIN_X2){
    BH1730_WriteReg(BH1730_REG_GAIN, BH1730_GAIN_X2_MODE); 
  }else if(gain == GAIN_X64){
    BH1730_WriteReg(BH1730_REG_GAIN, BH1730_GAIN_X64_MODE); 
  }
  else{
    BH1730_WriteReg(BH1730_REG_GAIN, BH1730_GAIN_X128_MODE); 
  }
//   // else if(gain == GAIN_X128){
//   //   BH1730_WriteReg(BH1730_REG_GAIN, BH1730_GAIN_X128_MODE); 
//   // }
//   // else {
//   // #if BH1730_DEBUG == 1
//   //   Serial.println("Gain invalid");
//   // #endif
//   //   return;
//   // }
//   // BH1730_GAIN gain = gain;
}

/**
 * Read lux level from sensor.
 * Returns -1 if read is timed out
 * 
 */
uint32_t BH1730_GetLux() {
    
  // set accuracy, default GAIN_X1
  uint8_t gain = GAIN_X1;

  // set Gain
  // setGain(gain);

  // Start one time measurement
  BH1730_WriteReg(BH1730_REG_CONTROL, BH1730_REG_CONTROL_POWER | BH1730_REG_CONTROL_ADC_EN | BH1730_REG_CONTROL_ONE_TIME);
  // uint8_t buf[2];
  // buf[0] = (uint8_t) 0x80;
  // buf[1] = (uint8_t) 0x0C;
  // HAL_I2C_Master_Transmit(&hi2c2, 0x52, buf, 2, HAL_I2C_STATE_TIMEOUT);  
  // HAL_Delay(10);

  // uint8_t value = 0; 
  // HAL_I2C_Master_Transmit(&hi2c2, 0x52, ((uint8_t)0x14), 1, HAL_I2C_STATE_TIMEOUT);  
  // HAL_I2C_Master_Transmit(&hi2c2, 0x52, 0x14, 1, HAL_I2C_STATE_TIMEOUT);  
  // HAL_I2C_Master_Receive(&hi2c2, 0x52, &value, 1, HAL_I2C_STATE_TIMEOUT);
  // BH1730_ReadReg(BH1730_REG_DATA0_LOW);
  // OLED_ShowNum(0, 16, value, 8, 12, 1);
  // OLED_ShowNum(0, 32, 105, 3, 12, 1);
  // OLED_Refresh();
  // HAL_Delay(1000);
  // OLED_Clear(); 

  // Wait for ADC data is valid

  // while(((read8(BH1730_REG_CONTROL) & BH1730_REG_CONTROL_ADC_VALID) == 0) && ++ret < BH1730_RET_TIMEOUT){
  // HAL_Delay(10);
  //   // delay(10);
  // }

  // if(ret == BH1730_RET_TIMEOUT){
  // #if BH1730_DEBUG == 1
  //   Serial.println("Read timed out");
  // #endif
  //   return -1;
  // }

  // Read real light and IR light from registers  
  // uint32_t result;
  uint8_t data0_lb, data0_mb, data1_lb, data1_mb;
  data0_lb = BH1730_ReadReg(BH1730_REG_DATA0_LOW);
  data0_mb = BH1730_ReadReg(BH1730_REG_DATA0_HIGH);
  data1_lb = BH1730_ReadReg(BH1730_REG_DATA1_LOW); 
  data1_mb = BH1730_ReadReg(BH1730_REG_DATA1_HIGH); 

  // OLED_ShowNum(0, 0, data0_lb, 8, 12, 1);
  // OLED_Refresh();
  // HAL_Delay(1000);
  // OLED_Clear();
  // Calculate lux based on formula in datasheet.
  uint16_t data0, data1;
  data0 = (data0_mb << 8 ) + data0_lb;
  data1 = (data1_mb << 8 ) + data1_lb;
  // OLED_ShowNum(0, 0, data0, 9, 12, 1);
  // OLED_ShowNum(0, 22, data1, 9, 12, 1);
  // OLED_Refresh();
  // HAL_Delay(1000);
  // OLED_Clear();

  if(data0 == 0)return 0;
  
  uint32_t lx = 0;
  uint32_t div = data1/data0;


  if(div < 0.26) {
      lx = ((1.29 * data0) - (2.733 * data1)) / gain * 102.6 / BH1730_ITIME_MS;
  }else if(div < 0.55) {
      lx = ((0.795 * data0) - (0.859 * data1)) / gain * 102.6 / BH1730_ITIME_MS;
  }else if(div < 1.09) {
      lx = ((0.51 * data0) - (0.345 * data1)) / gain * 102.6 / BH1730_ITIME_MS;
  }else if(div < 2.13) {
      lx = ((0.276 * data0) - (0.13 * data1)) / gain * 102.6 / BH1730_ITIME_MS;
  }

  return lx;
}