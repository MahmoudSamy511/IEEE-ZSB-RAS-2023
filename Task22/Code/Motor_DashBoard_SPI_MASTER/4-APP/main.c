//LIB Layer
#include"../5-LIB/TYPEDEF.h"
//MCAL
#include"../1-MCAL/Timers/Timer_Interface.h"
#include"../1-MCAL/DIO/DIO_interface.h"
#include"../1-MCAL/SPI/SPI_Interface.h"
//HAL Layer
#include"../2-HAL/LCD/LCD_Interface.h"
#include"../2-HAL/Keypad/Keypad_Interface.h"

#define delay				500 //ms
/* ********************Set your own password************* */
#define PasswordLength      5
#define Password          "51120"

u8 key=0,order = 0, Index=0, checkCounter = 0,homeFlag = 0,inputFlag = 0;
u8 savedPass[] = Password, pass[PasswordLength];
u8 dummy = 0;
void displayOptionsPage(){
	LCD_enu_Clear();
	LCD_enu_SendString("1-DC    3-Servo");
	LCD_enu_SetCursor(1, 0);
	LCD_enu_SendString("2-Stepper 4-Stop");
}
void takeUserOption(u8 *option){
	while(1){
		Keypad_enu_getKey(option);
		if(*option == '1' || *option == '2' || *option == '3' || *option == '4')break;
	}
}
void displayRotationOptions(){
	LCD_enu_Clear();
	LCD_enu_SendString("1-Rotate CW ");
	LCD_enu_SetCursor(1, 0);
	LCD_enu_SendString("2-Rotate CCW");
}
void getPassword(void){
	Keypad_enu_getKey(&key);
	if(key != KEYPAD_U8_NO_KEY_PRESSED){
		LCD_enu_SendChar('*');
		pass[Index] = key;
		Index++;
		checkCounter++;
	}
	if(checkCounter == PasswordLength){
		for(int j =0 ;j<PasswordLength ; j++){
			if(pass[j] != savedPass[j]){
				inputFlag = 1;
				break;
			}
		}
		if(inputFlag){
			Index =0;
			checkCounter =0;
			inputFlag = 0;
			LCD_enu_Clear();
			LCD_enu_SendString("Wrong Password");
			LCD_enu_SetCursor(1, 0);
			LCD_enu_SendString("Try Again!");
			Timers_enu_delay_ms(delay);
			LCD_enu_Clear();
			LCD_enu_SendString("Enter Password:");
			LCD_enu_SetCursor(1, 0);
		}else{
			//To display this message only once
			if(!homeFlag){
				LCD_enu_Clear();
				LCD_enu_SendString("Welcome :)");
				LCD_enu_SetCursor(1, 0);
				LCD_enu_SendString("Choose Motor ..");
				homeFlag = 1;
				Timers_enu_delay_ms(delay);
			}
			displayOptionsPage();
			takeUserOption(&order);
		}
	}
}
void DCMotor(){
	displayRotationOptions();
	takeUserOption(&order);
	// Rotate DC Motors CW
	if(order == '1'){SPI_enu_Transceive(order, &dummy);}
	// Rotate DC Motors CCW
	else if (order == '2'){SPI_enu_Transceive(order, &dummy);}
}
void servoMotor(){
	LCD_enu_Clear();
	LCD_enu_SendString("Enter Angle:");
	u8 servoMotorAngle= 0;
	// Display and Storing Angle
	Keypad_enu_getKey(&key);
	while(key != '='){
		Keypad_enu_getKey(&key);
		if((key != KEYPAD_U8_NO_KEY_PRESSED)&&(key != '=')){
			LCD_enu_SendChar(key);
			servoMotorAngle = (servoMotorAngle*10)+(key -'0');
		}
	}
	SPI_enu_Transceive(servoMotorAngle, &dummy);
}

void stepperMotor(){
	// Take Stepper Motor Angle
	LCD_enu_Clear();
	LCD_enu_SendString("Enter Angle:");
	u16 stepperMotorAngle=0;
	// Display and Storing Angle
	Keypad_enu_getKey(&key);
	while(key != '='){
		Keypad_enu_getKey(&key);
		if((key != KEYPAD_U8_NO_KEY_PRESSED)&&((key != '='))){
			LCD_enu_SendChar(key);
			stepperMotorAngle = (stepperMotorAngle*10)+(key -'0');
		}
	}
		displayRotationOptions();
		takeUserOption(&order);
		// Rotate Stepper Motor CW With Entered Angle
		if(order == '1'){
			SPI_enu_Transceive(order, &dummy);
			SPI_enu_Transceive(stepperMotorAngle, &dummy);
		}
		// Rotate Stepper Motor CCW With Entered Angle
		else if (order == '2'){
			SPI_enu_Transceive(order, &dummy);
			SPI_enu_Transceive(stepperMotorAngle, &dummy);
		}
}
int main(void){
	SPI_enu_Init();
	DIO_enu_SetPinDirection(DIO_U8_PORTB, DIO_U8_PIN4, DIO_U8_OUTPUT);
	DIO_enu_SetPinValue(DIO_U8_PORTB, DIO_U8_PIN4, DIO_U8_LOW);
	Keypad_enu_Init();
	LCD_enu_Init();
	Timers_enu_Init(TIMER0, NORMAL_MODE, CLK_8);
	LCD_enu_SendString("Hello, User :)");
	Timers_enu_delay_ms(delay);
	LCD_enu_Clear();
	LCD_enu_SendString("Enter Password:");
	LCD_enu_SetCursor(1, 0);
	while(1){
		getPassword();
		if(order == '1'){
			SPI_enu_Transceive(order, &dummy);
			DCMotor();
		}
		else if(order == '2'){
			SPI_enu_Transceive(order, &dummy);
			stepperMotor();
		}
		else if(order == '3'){
			SPI_enu_Transceive(order, &dummy);
			servoMotor();
		}
		else if (order == '4'){
			SPI_enu_Transceive(order, &dummy);
			LCD_enu_Clear();
			LCD_enu_SendString("Stopping Motors");
			Timers_enu_delay_ms(delay);
		}
	}
	return 0;
}

