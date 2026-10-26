
#ifndef MPU6050_H
#define MPU6050_H

#include "stm32f1xx_hal.h"



//MPU6050 Address for i2c -----0x68<<1
#define MPU6050_ADDR     0xD0

#define WHO_AM_I_REG      0x75
#define PWR_MGMT_1_REG    0x6B
#define SMPLRT_DIV_REG    0x19
#define CONFIG_REG        0x1A
#define GYRO_CONFIG_REG   0x1B
#define ACCEL_CONFIG_REG  0x1C
#define ACCEL_XOUT_H_REG  0x3B

#define ACCEL_SCALE_2G    16384.0f

typedef struct{
  float Accel_X;
  float Accel_Y;
  float Accel_Z;
  float roll;
  float pitch;
}MPU6050_Data_t;

HAL_StatusTypeDef MPU6050_Init(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef MPU6050_Calibrate(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef MPU6050_Read_Raw(I2C_HandleTypeDef *hi2c, int16_t *raw_x,int16_t *raw_y,int16_t *raw_z);
HAL_StatusTypeDef MPU6050_Read_Accel(I2C_HandleTypeDef *hi2c, MPU6050_Data_t *data);
void MPU6050_Angle (MPU6050_Data_t *data);
#endif