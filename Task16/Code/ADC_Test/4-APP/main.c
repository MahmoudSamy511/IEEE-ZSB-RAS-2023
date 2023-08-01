//MCAL
#include"../1-MCAL/DIO/DIO_interface.h"
#include"../1-MCAL/ADC/ADC_Interface.h"
#include"../1-MCAL/GI/GI_Interface.h"
//HAL
#include"../2-HAL/LCD/LCD_Interface.h"
//LIB
#include"../5-LIB/TYPEDEF.h"

#include<util/delay.h>
#define F_CPU 16000000UL

void clearUnusedDigits(u16 value , u8 Row){
	u8 start , end = 15, y=0;
	for(u32 i= 10 ;i<1000000;i *=10){
		if(value < i){
			for(start =10+y ; start<= end ; start++){
				LCD_enu_SetCursor(Row, start);
				LCD_enu_SendChar(' ');
			}
			break;
		}
		y++;
	}
}
int main(){
	LCD_enu_Init();
	ADC_enu_Init();
	LCD_enu_SendString("Hi, User :)");
	_delay_ms(1000);
	LCD_enu_Clear();
	LCD_enu_SendString("Volt(mv):");
	LCD_enu_SetCursor(1,0);
	LCD_enu_SendString("LDR(Ohm):");
	while(1){
		static u16 digitalValue = 0;
		u16 voltage = 0;
		u32 Resistance = 0;
		ADC_enu_GetDigitalValueSynchNonBlocking(ADC_U8_CHANNEL0, &digitalValue);
		voltage = (digitalValue * 5000UL)/1023;
		Resistance =((10000*1023UL)/digitalValue) - 10000;
		clearUnusedDigits(voltage,0);
		clearUnusedDigits(Resistance,1);
		LCD_enu_SetCursor(0, 9);
		LCD_enu_SendNum(voltage);
		LCD_enu_SetCursor(1, 9);
		LCD_enu_SendNum(Resistance);
	}
	return 0;
}


