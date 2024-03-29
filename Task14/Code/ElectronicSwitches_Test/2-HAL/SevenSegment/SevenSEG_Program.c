/********************************************************************************/
/************* Name    :   Mahmoud Samy     *************************************/
/************* Date    :   2023-07-08       *************************************/
/************* SWC     :   Senven Segment   *************************************/
/************* Version :   1.0              *************************************/
/********************************************************************************/
/*********LIB************/
#include"../../5-LIB/ERROR_STATE.h"
#include"../../5-LIB/TYPEDEF.h"
/*********MCAL***********/
#include"../../1-MCAL/DIO/DIO_interface.h"
/*********HAL***********/
#include"SevenSEG_Config.h"
#include"SevenSEG_Private.h"

u8 SevenSeg_au8_Numbers[10] = {0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,
                              0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};
u8 SevenSeg_au8_Pins[7] = {PIN_U8_A,PIN_U8_B,PIN_U8_C,PIN_U8_D,PIN_U8_E,PIN_U8_F,PIN_U8_G};   
ES_t sevenSeg_enu_displayNum(u8 Copy_u8_Num)
{
    u8 Local_u8_errorState = STATE_OK;
    if(Copy_u8_Num>= 0 && Copy_u8_Num<=9){
        DIO_enu_SetPortDirection(SEVEN_SEGMENT_U8_PORT,DIO_U8_OUTPUT);
        for (u8 Local_u8_iterator = 0; Local_u8_iterator < 7; Local_u8_iterator++)
        {
           DIO_enu_SetPinValue(SEVEN_SEGMENT_U8_PORT,SevenSeg_au8_Pins[Local_u8_iterator],(SevenSeg_au8_Numbers[Copy_u8_Num]>>Local_u8_iterator) & MASK_BIT);
        }

    }else{
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}