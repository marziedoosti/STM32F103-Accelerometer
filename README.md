STM32 Digital Level

Overview

A digital level project developed using the STM32F103C8T6 microcontroller, MPU6050 motion sensor, and SSD1306 OLED display.

Hardware

- STM32F103C8T6 microcontroller
- MPU6050 accelerometer and gyroscope
- SSD1306 OLED display

Communication

- I2C communication with the MPU6050 sensor
- I2C communication with the SSD1306 OLED display

Features

- Motion sensor interfacing
- Real-time orientation measurement
- OLED display output
- Digital level functionality

Development Tools

- IAR Embedded Workbench
- STM32CubeMX
- C programming language

Project Structure

- "Core/" — Application source code
- "Drivers/" — Peripheral and device drivers
- "EWARM/" — IAR project files
- "Accel_proj.ioc" — STM32CubeMX configuration

Getting Started

1. Open the IAR project file located in the "EWARM/" directory.
2. Build the project.
3. Connect the MPU6050 and SSD1306 OLED to the STM32F103C8T6 using I2C.
4. Flash the firmware to the microcontroller.

License

<img width="711" height="711" alt="oled1" src="https://github.com/user-attachments/assets/00df5de9-fd6f-4319-8eb9-cdf86c5fa45a" />


