
//old MPU6050_Read_Accel 

HAL_StatusTypeDef MPU6050_Read_Accel(I2C_HandleTypeDef *hi2c, MPU6050_Data_t *data)
{
  uint8_t accel_data[6];
  int16_t Raw_Accel_X, Raw_Accel_Y,Raw_Accel_Z;
  
 HAL_StatusTypeDef status= HAL_I2C_Mem_Read(hi2c,MPU6050_ADDR,ACCEL_XOUT_H_REG,1,accel_data,6,100);
 if(status==HAL_OK)
 {
  Raw_Accel_X=(int16_t)(accel_data[0]<<8 | accel_data[1]);
  Raw_Accel_Y=(int16_t)(accel_data[2]<<8 | accel_data[3]);
  Raw_Accel_Z=(int16_t)(accel_data[4]<<8 | accel_data[5]);
  
  data->Accel_X = (float)Raw_Accel_X/ACCEL_SCALE_2G - Accel_X_Offset;
  data->Accel_Y = (float)Raw_Accel_Y/ACCEL_SCALE_2G - Accel_Y_Offset;
  data->Accel_Z = (float)Raw_Accel_Z/ACCEL_SCALE_2G - Accel_Z_Offset;
  
  data->roll=atan2f(data->Accel_Y,data->Accel_Z)*(57.29578f);                                                                 //   roll = atan2(ay, az) * 180.0 / PI;
  data->pitch=atan2f(-data->Accel_X,sqrtf(data->Accel_Y*data->Accel_Y +data->Accel_Z*data->Accel_Z))*(57.29578f);            // pitch = atan2(-ax, sqrt(ay * ay + az * az)) * 180.0 / PI;
 }
  return status;
}
