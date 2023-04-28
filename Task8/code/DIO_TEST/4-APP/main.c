#include"../1-MCAL/DIO/DIO_interface.h"
int main(){
	DIO_void_Init();
	/*Pins Directions*/
	DIO_u8_SetPinDirection(DIO_U8_PORTC,DIO_U8_PIN0,DIO_U8_OUTPUT);
	DIO_u8_SetPinDirection(DIO_U8_PORTD,DIO_U8_PIN4,DIO_U8_OUTPUT);
	DIO_u8_SetPinDirection(DIO_U8_PORTA,DIO_U8_PIN5,DIO_U8_OUTPUT);
	DIO_u8_SetPinDirection(DIO_U8_PORTB,DIO_U8_PIN3,DIO_U8_OUTPUT);
	DIO_u8_SetPinDirection(DIO_U8_PORTA,DIO_U8_PIN0,DIO_U8_INPUT);
	DIO_u8_SetPinDirection(DIO_U8_PORTB,DIO_U8_PIN1,DIO_U8_INPUT);
	/*Switch Read*/
	u8 switchRead1;
	u8 switchRead2;
	while(1){
		/*Set Pin Values*/
		DIO_u8_SetPinValue(DIO_U8_PORTC,DIO_U8_PIN0,DIO_U8_HIGH);
		DIO_u8_SetPinValue(DIO_U8_PORTD,DIO_U8_PIN4,DIO_U8_HIGH);
		/*Get Pin Values*/
		DIO_u8_GetPinValue(DIO_U8_PORTA,DIO_U8_PIN0,&switchRead1);
		DIO_u8_GetPinValue(DIO_U8_PORTB,DIO_U8_PIN1,&switchRead2);
		/*Check Switch1 is pressed or not*/
		if(switchRead1 == DIO_U8_HIGH){
			/*TURN ON LED*/
			DIO_u8_SetPinValue(DIO_U8_PORTA,DIO_U8_PIN5,DIO_U8_HIGH);
		}
		else{
			/*TURN OFF LED*/
			DIO_u8_SetPinValue(DIO_U8_PORTA,DIO_U8_PIN5,DIO_U8_LOW);
		}
		/*Check Switch2 is pressed or not*/
		if(switchRead2 == DIO_U8_HIGH){
			/*TURN ON LED*/
				DIO_u8_SetPinValue(DIO_U8_PORTB,DIO_U8_PIN3,DIO_U8_HIGH);

		}
		else{
			/*TURN OFF LED*/
				DIO_u8_SetPinValue(DIO_U8_PORTB,DIO_U8_PIN3,DIO_U8_LOW);
		}
	}
return 0;
}
