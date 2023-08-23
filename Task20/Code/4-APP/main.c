#include"../1-MCAL/UART/UART_Interface.h"
#include"../1-MCAL/DIO/DIO_interface.h"
int main(){
	DIO_enu_SetPinDirection(DIO_U8_PORTD, DIO_U8_PIN0, DIO_U8_INPUT);
	DIO_enu_SetPinDirection(DIO_U8_PORTD, DIO_U8_PIN1, DIO_U8_OUTPUT);
	DIO_enu_SetPinDirection(DIO_U8_PORTC, DIO_U8_PIN0, DIO_U8_OUTPUT);
	DIO_enu_SetPinDirection(DIO_U8_PORTC, DIO_U8_PIN1, DIO_U8_OUTPUT);
	DIO_enu_SetPinDirection(DIO_U8_PORTC, DIO_U8_PIN2, DIO_U8_OUTPUT);
	UART_enu_Init();
	while(1){
		static u8 rFlag = 0 ,gFlag=0, bFlag =0;
		u8 Data =0 ;
		UART_enu_recieveChar(&Data);
		switch(Data){
		case 'R':
			if(!rFlag){
				UART_enu_sendString("\rLED RED ON\n");
				rFlag = 1;
				Data = 0;
			}
			else{
				UART_enu_sendString("\rLED RED OFF\n");
				rFlag = 0;
			}
			DIO_enu_ToggPin(DIO_U8_PORTC, DIO_U8_PIN0);
			break;
		case 'G':
			if(!gFlag){
				UART_enu_sendString("\rLED GREEN ON\n");
				gFlag = 1;
			}
			else{
				UART_enu_sendString("\rLED GREEN OFF\n");
				gFlag = 0;
			}
			DIO_enu_ToggPin(DIO_U8_PORTC, DIO_U8_PIN1);
			break;
		case 'B':
			if(!bFlag){
				UART_enu_sendString("\rLED BLUE ON\n");
				bFlag = 1;
			}
			else{
				UART_enu_sendString("\rLED BLUE OFF\n");
				bFlag =0;
			}
			DIO_enu_ToggPin(DIO_U8_PORTC, DIO_U8_PIN2);
			break;
		}
	}
	return 0;
}
