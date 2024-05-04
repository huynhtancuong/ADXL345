# ADXL345 Library

This is a library for the ADXL345 accelerometer sensor. It provides a simple interface to read measurements from the sensor within the range of ±2g.

## Installation

To use this library, follow these steps:

### Arduino IDE
1. Download the library files from the [GitHub repository](https://github.com/huynhtancuong/ADXL345.git).
2. Copy the library files to your Arduino libraries directory.
3. Restart the Arduino IDE.

### PlatformIO
1. Open your PlatformIO project.
2. Add the following line to your `platformio.ini` file:
    ```
    lib_deps =
         huynhtancuong/ADXL345
    ```
3. Save the `platformio.ini` file.
4. Build and upload your project.


## Usage

To use the ADXL345 library, include the library header file in your sketch:

```cpp
#include <Arduino.h>
#include "ADXL345.h"

ADXL345 accel_sensor;

void setup(void) 
{
  // Init ADXL345
  accel_sensor.init();

  Serial.begin(9600);
}


void loop(void) 
{
    int* accelReading = accel_sensor.read();
    
    int LSB_x = accel_sensor.get_LSB_x(accelReading);
    int LSB_y = accel_sensor.get_LSB_y(accelReading);
    int LSB_z = accel_sensor.get_LSB_z(accelReading);

    float G_x = accel_sensor.get_G_y(accelReading);
    float G_y = accel_sensor.get_G_x(accelReading);
    float G_z = -accel_sensor.get_G_z(accelReading);

    float accel_x = accel_sensor.get_SI_x(accelReading);
    float accel_y = accel_sensor.get_SI_y(accelReading);
    float accel_z = accel_sensor.get_SI_z(accelReading);

    Serial.printf("LSB: x=%5d y=%5d z=%5d \t ", LSB_x, LSB_y, LSB_z);
    Serial.printf("G: x=%10.3f y=%10.3f z=%10.3f \t", G_x, G_y, G_z);
    Serial.printf("SI Units: x=%.3f m/s^2, y=%.3f m/s^2, z=%.3f m/s^2\n", accel_x, accel_y, accel_z);

    delay(100);
}
```

