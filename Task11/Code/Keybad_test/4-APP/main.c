#include"../5-LIB/TYPEDEF.h"
#include"../1-MCAL/DIO/DIO_interface.h"
#include"../2-HAL/LCD/LCD_Interface.h"
#include"../2-HAL/Keybad/Keybad_Interface.h"
#include<util/delay.h>
#define F_CPU 16000000UL

/* Set your own password */
#define PasswordLength      5
#define Password          "51120"

int main(void){
	DIO_enu_Init();
	LCD_enu_Init();
	u8 savedPass[] = Password , pass[PasswordLength], Index=0, checkCounter = 0;
	u8 flag = 0;
	LCD_enu_SendString("Hello, User :)");
	_delay_ms(20);
	LCD_enu_Clear();
	LCD_enu_SendString("Enter Password:");
	LCD_enu_SetCursor(1, 0);
	DIO_enu_SetPinValue(DIO_U8_PORTC, DIO_U8_PIN5, DIO_U8_HIGH);
	_delay_ms(60);
	DIO_enu_SetPinValue(DIO_U8_PORTC, DIO_U8_PIN5, DIO_U8_LOW);
	while(1){
		u8 key=0;
		Keypad_enu_getKey(&key);
		if(key != KEYPAD_U8_NO_KEY_PRESSED){
			LCD_enu_SendChar('*');
			//Turn on Buzzer While Entering password
			DIO_enu_SetPinValue(DIO_U8_PORTC, DIO_U8_PIN5, DIO_U8_HIGH);
				_delay_ms(1);
			DIO_enu_SetPinValue(DIO_U8_PORTC, DIO_U8_PIN5, DIO_U8_LOW);
			pass[Index] = key;
			Index++;
			checkCounter++;
		}
		if(checkCounter == PasswordLength){
			for(int j =0 ;j<PasswordLength ; j++){
				if(pass[j] != savedPass[j]){
					flag = 1;
					break;
				}
			}
			if (flag){
				Index =0;
				checkCounter =0;
				flag = 0;
				LCD_enu_Clear();
				LCD_enu_SendString("Wrong Password");
				//Turn on Red Led
				DIO_enu_SetPinValue(DIO_U8_PORTC, DIO_U8_PIN0, DIO_U8_HIGH);
				_delay_ms(20);
				LCD_enu_Clear();
				LCD_enu_SendString("Enter Password:");
				LCD_enu_SetCursor(1, 0);

			}else{
				LCD_enu_Clear();
				LCD_enu_SendString("Welcome :)");
				LCD_enu_SetCursor(1, 0);
				LCD_enu_SendString("Have a nice day");
				//Turn on Green Led and Toggle Relay
				DIO_enu_SetPinValue(DIO_U8_PORTC, DIO_U8_PIN0, DIO_U8_LOW);
				DIO_enu_SetPinValue(DIO_U8_PORTC, DIO_U8_PIN1, DIO_U8_HIGH);
				DIO_enu_SetPinValue(DIO_U8_PORTC, DIO_U8_PIN4, DIO_U8_HIGH);
				_delay_ms(100);
			}
		}

	}
	return 0;
}
