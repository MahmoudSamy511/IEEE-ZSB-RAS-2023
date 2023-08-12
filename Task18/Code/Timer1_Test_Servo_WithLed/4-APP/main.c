/*************MCAL*********/
#include"../1-MCAL/DIO/DIO_interface.h"
#include"../1-MCAL/Timers/Timer_Interface.h"
#include"../1-MCAL/ADC/ADC_Interface.h"

#define MAX_ANGLE   		180UL
#define MAX_BRIGHTNESS   	255UL

int main(){
	DIO_enu_SetPinDirection(DIO_U8_PORTB, DIO_U8_PIN3, DIO_U8_OUTPUT);
	DIO_enu_SetPinDirection(DIO_U8_PORTD, DIO_U8_PIN5, DIO_U8_OUTPUT);
	Timers_enu_Timer0Init();
	Timers_enu_Timer1Init();
	ADC_enu_Init();
	while(1){
		u16 digitalValue0 = 0,digitalValue1=0;
		u8 ledBrightness =0,servoAngle =0;
		ADC_enu_GetDigitalValueSynchNonBlocking(ADC_U8_CHANNEL0, &digitalValue0);
		ADC_enu_GetDigitalValueSynchNonBlocking(ADC_U8_CHANNEL1, &digitalValue1);
		ledBrightness = (digitalValue0*MAX_BRIGHTNESS)/1023;
		servoAngle =(digitalValue1*MAX_ANGLE)/1023;
		Timers_enu_Timer0SetCompareMatchValue(ledBrightness);
		Timers_enu_SetServoAngle(servoAngle);
	}
	return 0;
}

