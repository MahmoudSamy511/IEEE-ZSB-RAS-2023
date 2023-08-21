#include"../1-MCAL/DIO/DIO_interface.h"
#include"../1-MCAL/EXTI/EXTI_Interface.h"
#include"../1-MCAL/Timers/Timer_Interface.h"
#include"../1-MCAL/GI/GI_Interface.h"
#include"../2-HAL/LCD/LCD_Interface.h"
#include"../5-LIB/TYPEDEF.h"
void ICU_SW(void);
static volatile u16 Period_Ticks =0;
static volatile u16 ON_Ticks =0;
int main(){
	LCD_enu_Init();
	DIO_enu_SetPinDirection(DIO_U8_PORTB, DIO_U8_PIN3,DIO_U8_OUTPUT);
	Timers_enu_Timer0SetCompareValue(64);
	Timers_enu_Init(TIMER0, FAST_PWM_NON_INVERTING, CLK_8);
	Timers_enu_Init(TIMER1, NORMAL_MODE, CLK_8);
	EXTI_enu_setCallBack(&ICU_SW, EXTI0);
	EXTI_enu_Enable(EXTI0, RISING_EDGE);
	GI_enu_Enable();
	while(1){
		while((Period_Ticks==0) && (ON_Ticks==0));
			LCD_enu_SetCursor(0,0);
			LCD_enu_SendString("Time Period");
			LCD_enu_SetCursor(0, 12);
			LCD_enu_SendNum((Period_Ticks*8)/16);
			LCD_enu_SetCursor(1,0);
			LCD_enu_SendString("ON Period");
			LCD_enu_SetCursor(1, 10);
			LCD_enu_SendNum((ON_Ticks*8)/16);
			break;
	}
	return 0;
}
void ICU_SW(void){
	static volatile u8 counter =0;
	counter++;
	if(counter==1){ //First Rising Edge
		//Timer starts Counting
		Timers_enu_SetTimerValue(TIMER1,0);
	}else if (counter==2){ //Second Rising Edge
		Timers_enu_GetTimerValue(TIMER1,&Period_Ticks);
		//change trigger to falling edge
		EXTI_enu_setSenseControl(EXTI0,FALLING_EDGE);
	}else if (counter==3){
		//falling edge to get on time
		Timers_enu_GetTimerValue(TIMER1,&ON_Ticks);
		ON_Ticks -= Period_Ticks;
		EXTI_enu_Disable(EXTI0);
	}
}
