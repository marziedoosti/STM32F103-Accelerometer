
#include "MPU6050.h"
#include <math.h>

static float Accel_X_Offset = 0, Accel_Y_Offset = 0, Accel_Z_Offset = 0;

HAL_StatusTypeDef MPU6050_Init(I2C_HandleTypeDef *hi2c)
{
  uint8_t check,data;
  //Check device ID ---WHO_AM_I
  HAL_I2C_Mem_Read(hi2c,MPU6050_ADDR,WHO_AM_I_REG,1,&check,1,100);
  
  if(check==0x68) //if the device is present
  {
    //sleep mod=0 ---> device is awake
    data=0x00;
    HAL_I2C_Mem_Write(hi2c, MPU6050_ADDR, PWR_MGMT_1_REG, 1, &data, 1, 100);
    
    //Set DATA_RATE of 1kHz by writing SMPLRT_DIV reg
    data=0x00;
    HAL_I2C_Mem_Write(hi2c, MPU6050_ADDR, SMPLRT_DIV_REG, 1, &data, 1, 100);
    
    //Set the Digital Low Path Filter by writing CONFIG reg
    data=0x03;
    HAL_I2C_Mem_Write(hi2c, MPU6050_ADDR, CONFIG_REG, 1, &data, 1, 100);
    
    //Set the full scale range for accelerometer and gyroscope ---> -+2g ,-+250
    data=0x00;
    HAL_I2C_Mem_Write(hi2c, MPU6050_ADDR, ACCEL_CONFIG_REG, 1, &data, 1, 100);
    HAL_I2C_Mem_Write(hi2c, MPU6050_ADDR, GYRO_CONFIG_REG, 1, &data, 1, 100);
    return HAL_OK;
  }
  else
  {
    return HAL_ERROR;
  }
}

HAL_StatusTypeDef MPU6050_Read_Raw(I2C_HandleTypeDef *hi2c, int16_t *raw_x,int16_t *raw_y,int16_t *raw_z)
{
  uint8_t accel_raw[6];
  HAL_I2C_Mem_Read(hi2c,MPU6050_ADDR,ACCEL_XOUT_H_REG,1,accel_raw,6,100);
  *raw_x=(int16_t)(accel_raw[0]<<8 | accel_raw[1]);
  *raw_y=(int16_t)(accel_raw[2]<<8 | accel_raw[3]);
  *raw_z=(int16_t)(accel_raw[4]<<8 | accel_raw[5]);
  
  return HAL_OK;
}

HAL_StatusTypeDef MPU6050_Calibrate(I2C_HandleTypeDef *hi2c)
{
    float sum_x = 0, sum_y = 0, sum_z = 0;
    int16_t  rx,ry,rz;
    int samples = 100;
    
    for(int i = 0; i < samples; i++)
    {
        if(MPU6050_Read_Raw(hi2c,&rx,&ry,&rz) == HAL_OK)
        {
            sum_x += rx;
            sum_y += ry;
            sum_z += rz;
        }
        HAL_Delay(5);
    }
    
   //Finding offset in 100 sample 
   //In flat situation   Accel_X=0,  Accel_Y=0,  Accel_Z=1g (16384.0)
    Accel_X_Offset = sum_x /(float) samples;
    Accel_Y_Offset = sum_y /(float) samples;
    Accel_Z_Offset = (sum_z /(float) samples) - ACCEL_SCALE_2G; 

    return HAL_OK;
}

HAL_StatusTypeDef MPU6050_Read_Accel(I2C_HandleTypeDef *hi2c, MPU6050_Data_t *data)
{
  int16_t rx, ry, rz;
  
 HAL_StatusTypeDef status=  MPU6050_Read_Raw(hi2c, &rx,&ry, &rz);
 if(status==HAL_OK)
 {
  float raw_x_calibrated = (float)rx - Accel_X_Offset;
  float raw_y_calibrated = (float)ry - Accel_Y_Offset;
  float raw_z_calibrated = (float)rz - Accel_Z_Offset;
  
  data->Accel_X = raw_x_calibrated/ACCEL_SCALE_2G ;
  data->Accel_Y = raw_y_calibrated/ACCEL_SCALE_2G ;
  data->Accel_Z = raw_z_calibrated/ACCEL_SCALE_2G ;
  
  data->roll=atan2f(data->Accel_Y,data->Accel_Z)*(57.29578f);                                                                 //   roll = atan2(ay, az) * 180.0 / PI;
  data->pitch=atan2f(-data->Accel_X,sqrtf(data->Accel_Y*data->Accel_Y +data->Accel_Z*data->Accel_Z))*(57.29578f);            // pitch = atan2(-ax, sqrt(ay * ay + az * az)) * 180.0 / PI;
 }
  return status;
}

void MPU6050_Angle (MPU6050_Data_t *data)
{
  data->roll=atan2f(data->Accel_Y,data->Accel_Z)*(57.29578f);                                                                 //   roll = atan2(ay, az) * 180.0 / PI;
  data->pitch=atan2f(-data->Accel_X,sqrtf(data->Accel_Y*data->Accel_Y +data->Accel_Z*data->Accel_Z))*(57.29578f);            // pitch = atan2(-ax, sqrt(ay * ay + az * az)) * 180.0 / PI;
}

