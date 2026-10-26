
#ifndef _LCD_H
#define _LCD_H

////////////////////GARD Academy//////////////////////
//////////////Coding by Hamid Najafi/////////////

#include "stm32f1xx_hal.h"

#define T  1  

#define DATA_PORT_D4   GPIOA
#define DATA_PORT_D5   GPIOA
#define DATA_PORT_D6   GPIOA
#define DATA_PORT_D7   GPIOA
#define D4_PIN_NUMBER  GPIO_PIN_2
#define D5_PIN_NUMBER  GPIO_PIN_3
#define D6_PIN_NUMBER  GPIO_PIN_4
#define D7_PIN_NUMBER  GPIO_PIN_5

#define CTRL_PORT_RS   GPIOA
#define CTRL_PORT_E    GPIOA
#define RS_PIN_NUMBER  GPIO_PIN_0
#define E_PIN_NUMBER   GPIO_PIN_1
////****Connect RW Pin from LCD to GND****////

void lcd_init(void);
void lcd_clear(void);
void lcd_gotoxy(unsigned char x, unsigned char y);
void lcd_putchar(char data);
void lcd_puts(char *str);


#endif
