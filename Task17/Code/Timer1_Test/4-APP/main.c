#include"../1-MCAL/DIO/DIO_interface.h"
#include"../1-MCAL/Timers/Timer_Interface.h"
#include"../1-MCAL/GI/GI_Interface.h"
#include"../2-HAL/LCD/LCD_Interface.h"
void toggleLed(void);
int main(){
	LCD_enu_Init();
	GI_enu_Enable();
	DIO_enu_SetPinDirection(DIO_U8_PORTC, DIO_U8_PIN1, DIO_U8_OUTPUT);
	DIO_enu_SetPinValue(DIO_U8_PORTB, DIO_U8_PIN0, DIO_U8_HIGH);
	Timers_enu_Timer0SetCallBack(&toggleLed,CTC_MODE);
	Timers_enu_Timer0Init();
	LCD_enu_SendString("Counter: ");
	while(1);
	return 0;
}
void toggleLed(void){
	static u8 counter = 0,ledState = 0;
	LCD_enu_SetCursor(0, 9);
	LCD_enu_SendNum(++counter);
	if(ledState == 0){
		DIO_enu_SetPinValue(DIO_U8_PORTC, DIO_U8_PIN1, DIO_U8_HIGH);
		ledState = 1;
	}else{
		DIO_enu_SetPinValue(DIO_U8_PORTC, DIO_U8_PIN1, DIO_U8_LOW);
		ledState = 0;
	}
}
