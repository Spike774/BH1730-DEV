## BH1730 drive for STM32 

- STM32F030C8T6
- HAL lib & I2C
- MXcube config

BH1730 is a wide range ambient light sensor spare for MAX44009 which has been discontinued for a while.

BH1730 is about 1/4 cost of MAX44009 at Q4 2021.

The max lux of BH1730 is 100k lux less than the 188k of MAX44009.

This drive is generally translated from the BH1730 Arduino C++ lib.

OLED is a 0.5 inch 80x48 14pin monitor, driven by CH1115 compatible with SSD1306.

Reference:
https://github.com/jancoow/BH1730-Library

Electric Scheme:
https://oshwhub.com/nonsproject/bh1730-dev

Sensor info:
https://www.rohm.com/products/sensors-mems/ambient-light-sensor-ics/digital-16bit-serial-output/bh1730fvc-product#productDetail