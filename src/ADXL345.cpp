#include "ADXL345.h"
#include <Wire.h>

void ADXL345::init() {
    // Init Wire
    Wire.begin();

    // Set measurement range to +-2g
    Wire.beginTransmission(ADXL345_ADDR);
    Wire.write(0x31);
    Wire.write(0x00);
    Wire.endTransmission();

    // Enable measurement
    Wire.beginTransmission(ADXL345_ADDR);
    Wire.write(0x2D);
    Wire.write(0x08);
    Wire.endTransmission();
}

int* ADXL345::read() {
    static int axis[3];
    int buff[6];

    Wire.beginTransmission(ADXL345_ADDR);
    Wire.write(ADXL345_DATAX0);
    Wire.endTransmission();

    Wire.requestFrom(ADXL345_ADDR, 6);

    for (uint8_t i = 0; i<6; i++) {
        buff[i] = Wire.read();
    }

    // Read 2 bytes for each axis and convert them into 10-bit integer
    axis[0] = ((buff[1] & 0x03) << 8) | buff[0];
    axis[1] = ((buff[3] & 0x03) << 8) | buff[2];
    axis[2] = ((buff[5] & 0x03) << 8) | buff[4];

    for (int i = 0; i<3; i++) {
        if (axis[i] > 511) axis[i] -= 1024;
    }
    
    return axis;
}