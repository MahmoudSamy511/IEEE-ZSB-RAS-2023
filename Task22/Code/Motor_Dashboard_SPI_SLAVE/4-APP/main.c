//LIB Layer
#include"../5-LIB/TYPEDEF.h"
//MCAL
#include"../1-MCAL/SPI/SPI_Interface.h"
//HAL Layer
#include"../2-HAL/DC_Motor/DC_Motor_Interface.h"
#include"../2-HAL/Stepper_Motor/Stepper_Motor_Interface.h"
#include"../2-HAL/Servo_Motor/Servo_Interface.h"

int main(void){
	u8 Angle = 0 , Data = 0;
	SPI_enu_Init();
	DC_Motor_enu_Init(1, 1);
	STEP_Motor_enu_Init();
	Servo_enu_Init(0,1);
	while(1){

		SPI_enu_Transceive(10, &Data);
		if('1'== Data){
			SPI_enu_Transceive(10, &Data);
			switch(Data){
			case '1':
				DC_Motor_enu_Rotate(MOTOR1, CW);
				DC_Motor_enu_Rotate(MOTOR2, CW);
			break;
			case '2':
				DC_Motor_enu_Rotate(MOTOR1, CCW);
				DC_Motor_enu_Rotate(MOTOR2, CCW);
			break;
			}
		}else if ('2'== Data){
			SPI_enu_Transceive(10, &Data);
			switch(Data){
			case '1':
				SPI_enu_Transceive(10, &Angle);
				STEP_Motor_enu_Rotate(CW, Angle);
				break;
			case '2':
				SPI_enu_Transceive(10, &Angle);
				STEP_Motor_enu_Rotate(CW, Angle);
				break;
			}
		}else if ('3'== Data){
			SPI_enu_Transceive(10, &Angle);
			Servo_enu_SetAngle(MOTOR_2, Angle);
		}else if('4'== Data){
			DC_Motor_enu_Stop(MOTOR1);
			DC_Motor_enu_Stop(MOTOR2);
			STEP_Motor_enu_Stop();
			Servo_enu_SetAngle(MOTOR_2,0);
		}
	}
	return 0;
}


