
#include "lcd.h"

////////////////////GARD Academy//////////////////////
//////////////Coding by Hamid Najafi/////////////

void lcd_cmd_4bit(unsigned char cmd){
  HAL_Delay(T);
  
  HAL_GPIO_WritePin(CTRL_PORT_E,E_PIN_NUMBER,GPIO_PIN_SET);  
  HAL_GPIO_WritePin(CTRL_PORT_RS,RS_PIN_NUMBER,GPIO_PIN_RESET);
  
  HAL_GPIO_WritePin(DATA_PORT_D4,D4_PIN_NUMBER,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(DATA_PORT_D5,D5_PIN_NUMBER,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(DATA_PORT_D6,D6_PIN_NUMBER,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(DATA_PORT_D7,D7_PIN_NUMBER,GPIO_PIN_RESET);
  
  if(cmd & 0x01)
     HAL_GPIO_WritePin(DATA_PORT_D4,D4_PIN_NUMBER,GPIO_PIN_SET);
  if(cmd & 0x02)
     HAL_GPIO_WritePin(DATA_PORT_D5,D5_PIN_NUMBER,GPIO_PIN_SET);
  if(cmd & 0x04)
     HAL_GPIO_WritePin(DATA_PORT_D6,D6_PIN_NUMBER,GPIO_PIN_SET);
  if(cmd & 0x08)
     HAL_GPIO_WritePin(DATA_PORT_D7,D7_PIN_NUMBER,GPIO_PIN_SET);
  
  HAL_GPIO_WritePin(CTRL_PORT_E,E_PIN_NUMBER,GPIO_PIN_RESET);
}

void lcd_preinit(void){
  lcd_cmd_4bit(0x03); 
  HAL_Delay(6);
  
  lcd_cmd_4bit(0x03); 
  HAL_Delay(1);
  
  lcd_cmd_4bit(0x03);   
  HAL_Delay(1);
  
  lcd_cmd_4bit(0x02); 
  HAL_Delay(1);
}

void send_command(unsigned char data)
{
  HAL_Delay(T);
  HAL_GPIO_WritePin(CTRL_PORT_E,E_PIN_NUMBER,GPIO_PIN_SET);
  
  HAL_GPIO_WritePin(CTRL_PORT_RS,RS_PIN_NUMBER,GPIO_PIN_RESET);
  
  HAL_GPIO_WritePin(DATA_PORT_D4,D4_PIN_NUMBER,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(DATA_PORT_D5,D5_PIN_NUMBER,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(DATA_PORT_D6,D6_PIN_NUMBER,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(DATA_PORT_D7,D7_PIN_NUMBER,GPIO_PIN_RESET);
  
  if(data & 0x10)
     HAL_GPIO_WritePin(DATA_PORT_D4,D4_PIN_NUMBER,GPIO_PIN_SET);
  if(data & 0x20)
     HAL_GPIO_WritePin(DATA_PORT_D5,D5_PIN_NUMBER,GPIO_PIN_SET);
  if(data & 0x40)
     HAL_GPIO_WritePin(DATA_PORT_D6,D6_PIN_NUMBER,GPIO_PIN_SET);
  if(data & 0x80)
     HAL_GPIO_WritePin(DATA_PORT_D7,D7_PIN_NUMBER,GPIO_PIN_SET);
  
  HAL_GPIO_WritePin(CTRL_PORT_E,E_PIN_NUMBER,GPIO_PIN_RESET);
  
  HAL_GPIO_WritePin(CTRL_PORT_E,E_PIN_NUMBER,GPIO_PIN_SET);
  
  
  HAL_GPIO_WritePin(DATA_PORT_D4,D4_PIN_NUMBER,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(DATA_PORT_D5,D5_PIN_NUMBER,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(DATA_PORT_D6,D6_PIN_NUMBER,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(DATA_PORT_D7,D7_PIN_NUMBER,GPIO_PIN_RESET);
  
  if(data & 0x01)
     HAL_GPIO_WritePin(DATA_PORT_D4,D4_PIN_NUMBER,GPIO_PIN_SET);
  if(data & 0x02)
     HAL_GPIO_WritePin(DATA_PORT_D5,D5_PIN_NUMBER,GPIO_PIN_SET);
  if(data & 0x04)
     HAL_GPIO_WritePin(DATA_PORT_D6,D6_PIN_NUMBER,GPIO_PIN_SET);
  if(data & 0x08)
     HAL_GPIO_WritePin(DATA_PORT_D7,D7_PIN_NUMBER,GPIO_PIN_SET);
   
  HAL_GPIO_WritePin(CTRL_PORT_E,E_PIN_NUMBER,GPIO_PIN_RESET);
}

void lcd_putchar(char data)
{
  HAL_Delay(T);
  HAL_GPIO_WritePin(CTRL_PORT_E,E_PIN_NUMBER,GPIO_PIN_SET);
  HAL_GPIO_WritePin(CTRL_PORT_RS,RS_PIN_NUMBER,GPIO_PIN_SET);
  
  HAL_GPIO_WritePin(DATA_PORT_D4,D4_PIN_NUMBER,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(DATA_PORT_D5,D5_PIN_NUMBER,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(DATA_PORT_D6,D6_PIN_NUMBER,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(DATA_PORT_D7,D7_PIN_NUMBER,GPIO_PIN_RESET);
  
  if(data & 0x10)
     HAL_GPIO_WritePin(DATA_PORT_D4,D4_PIN_NUMBER,GPIO_PIN_SET);
  if(data & 0x20)
     HAL_GPIO_WritePin(DATA_PORT_D5,D5_PIN_NUMBER,GPIO_PIN_SET);
  if(data & 0x40)
     HAL_GPIO_WritePin(DATA_PORT_D6,D6_PIN_NUMBER,GPIO_PIN_SET);
  if(data & 0x80)
     HAL_GPIO_WritePin(DATA_PORT_D7,D7_PIN_NUMBER,GPIO_PIN_SET);
   
  HAL_GPIO_WritePin(CTRL_PORT_E,E_PIN_NUMBER,GPIO_PIN_RESET);
  
  HAL_GPIO_WritePin(CTRL_PORT_E,E_PIN_NUMBER,GPIO_PIN_SET);  
  
  HAL_GPIO_WritePin(DATA_PORT_D4,D4_PIN_NUMBER,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(DATA_PORT_D5,D5_PIN_NUMBER,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(DATA_PORT_D6,D6_PIN_NUMBER,GPIO_PIN_RESET);
  HAL_GPIO_WritePin(DATA_PORT_D7,D7_PIN_NUMBER,GPIO_PIN_RESET);
  
  if(data & 0x01)
     HAL_GPIO_WritePin(DATA_PORT_D4,D4_PIN_NUMBER,GPIO_PIN_SET);
  if(data & 0x02)
     HAL_GPIO_WritePin(DATA_PORT_D5,D5_PIN_NUMBER,GPIO_PIN_SET);
  if(data & 0x04)
     HAL_GPIO_WritePin(DATA_PORT_D6,D6_PIN_NUMBER,GPIO_PIN_SET);
  if(data & 0x08)
     HAL_GPIO_WritePin(DATA_PORT_D7,D7_PIN_NUMBER,GPIO_PIN_SET);
 
  HAL_GPIO_WritePin(CTRL_PORT_E,E_PIN_NUMBER,GPIO_PIN_RESET);
}

void lcd_init(void)
{
  HAL_Delay(20*T);
  lcd_preinit();
  send_command(0x28);
  send_command(0x08);
  send_command(0x0C);
  send_command(0x06);
  
}

void lcd_puts(char *str)
{
  HAL_Delay(T);
  while(*str)
  {
    lcd_putchar(*str);
    str++;
  }
}

void lcd_gotoxy(unsigned char x, unsigned char y)
{
  HAL_Delay(T); 
    switch(y){
    case 0:
      send_command( 0x80 + x );
    break;
    case 1:
      send_command( 0xC0 + x );
      break;
    case 2:
      send_command( 0x94 + x );
      break;
    case 3:
      send_command( 0xD4 + x );
  }
}

void lcd_clear(void)
{
  HAL_Delay(T);
  send_command(0x01);
  send_command(0x02);
}




