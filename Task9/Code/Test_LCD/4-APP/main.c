#include"../5-LIB/TYPEDEF.h"
#include"../1-MCAL/DIO/DIO_interface.h"
#include"../2-HAL/LCD/LCD_Interface.h"
int main(void){


	DIO_enu_Init();
	LCD_enu_Init();
	LCD_enu_SetCursor(0, 0);
	LCD_enu_SendString("IEEE-ZSB-RAS ");
	LCD_enu_SendNum(2023);
	LCD_enu_SetCursor(1, 2);
	LCD_enu_SendString("Mahmoud Samy");



	while(1);



	return 0;
}
