/*
 * main.c
 *
 *  Created on: May 6, 2023
 *      Author: Mahmoud Samy1
 */
#include"../1-MCAL/DIO/DIO_interface.h"
#include"../2-HAL/LCD/LCD_Interface.h"
#include"../5-LIB/TYPEDEF.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void){
DIO_enu_Init();
LCD_enu_Init();
u8 Heart[8] ={0x00,0x00,0x0a,0x1f,0x1f,0x0e,0x04,0x00};
LCD_enu_CreateCustomChar(LCD_U8_CHAR0,Heart);
u8 Alien[8] ={0b00011111,0b00010101,0b00011111,0b00011111,0b00001110,0b00001010,0b00011011,0b00000000};
LCD_enu_CreateCustomChar(LCD_U8_CHAR1,Alien);
u8 Sound[8] = {0b00000001,0b00000011,0b00000101,0b00001001,0b00001001,0b00001011,0b00011011,0b00011000};
LCD_enu_CreateCustomChar(LCD_U8_CHAR2,Sound);
u8 Lock[8] = {0b00001110,0b00010001,0b00010001,0b00011111,0b00011011,0b00011011,0b00011111,0b00000000};
LCD_enu_CreateCustomChar(LCD_U8_CHAR3,Lock);
int counter = 0;
u8 switch1_read,switch2_read,switch3_read,switch4_read;
LCD_enu_SendString(" Hi ,There :)");
_delay_ms(100);
LCD_enu_Clear();
while(1){
	DIO_enu_GetPinValue(DIO_U8_PORTA, DIO_U8_PIN0, &switch1_read);
	DIO_enu_GetPinValue(DIO_U8_PORTA, DIO_U8_PIN1, &switch2_read);
	DIO_enu_GetPinValue(DIO_U8_PORTA, DIO_U8_PIN5, &switch3_read);
	DIO_enu_GetPinValue(DIO_U8_PORTA, DIO_U8_PIN6, &switch4_read);
	_delay_ms(25);
	if(switch1_read){
		counter++;
		LCD_enu_SendChar(0);
	}else if(switch2_read){
		counter++;
		LCD_enu_SendChar(1);
	}else if(switch3_read){
		counter++;
		LCD_enu_SendChar(2);
	}
	else if(switch4_read){
		counter++;
		LCD_enu_SendChar(3);
		}
	/*check for end of line1*/
	if(counter == 17)
		LCD_enu_SetCursor(1,0);
	/*check for end of screen*/
	else if(counter == 34)
		LCD_enu_Clear();
}


	return 0;
}

