/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-05-03   *************************************/
/************* SWC     :   LCD          *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/

/*Lib Layer*/
#include"../../5-LIB/TYPEDEF.h"
#include"../../5-LIB/ERROR_STATE.h"
#define F_CPU 8000000UL
#include<util/delay.h>
/*MCAL*/
#include"../../1-MCAL/DIO/DIO_interface.h"

/*HAL*/
#include"../../2-HAL/LCD/LCD_Private.h"
#include"../../2-HAL/LCD/LCD_Config.h"



ES_t LCD_enu_SendCmnd(u8 Copy_u8_Cmdn){
    #if LCD_U8_MODE == LCD_U8_MODE_8BIT
        /* RS = 0 */
        DIO_enu_SetPinValue(LCD_U8_RS_PORT,LCD_U8_RS_PIN,DIO_U8_LOW);
        /* RW = 0 */
        DIO_enu_SetPinValue(LCD_U8_RW_PORT,LCD_U8_RW_PIN,DIO_U8_LOW);
        /*Write Command*/
        DIO_enu_SetPortValue(LCD_U8_DATA_PORT,Copy_u8_Cmdn);
        /* E = 1 */
        DIO_enu_SetPinValue(LCD_U8_E_PORT,LCD_U8_E_PIN,DIO_U8_HIGH );
        _delay_us(1);
        /* E = 0 */
        DIO_enu_SetPinValue(LCD_U8_E_PORT,LCD_U8_E_PIN,DIO_U8_LOW );
        return SATE_OK;
    #elif LCD_U8_MODE == LCD_U8_MODE_4BIT
    /*Send Command at 4-bit mode*/
        /* RS = 0 */
        DIO_enu_SetPinValue(LCD_U8_RS_PORT,LCD_U8_RS_PIN,DIO_U8_LOW);
        /* RW = 0 */
        DIO_enu_SetPinValue(LCD_U8_RW_PORT,LCD_U8_RW_PIN,DIO_U8_LOW);
        /*Write Command*/
        DIO_enu_SetPortValue(LCD_U8_DATA_PORT,Copy_u8_Cmdn);
        /* E = 1 */
        DIO_enu_SetPinValue(LCD_U8_E_PORT,LCD_U8_E_PIN,DIO_U8_HIGH );
        _delay_us(1);
        /* E = 0 */
        DIO_enu_SetPinValue(LCD_U8_E_PORT,LCD_U8_E_PIN,DIO_U8_LOW );
        /*Write the rest of the cmnd*/
        DIO_enu_SetPortValue(LCD_U8_DATA_PORT,Copy_u8_Cmdn << SHIFT_4BIT);
        /* E = 1 */
        DIO_enu_SetPinValue(LCD_U8_E_PORT,LCD_U8_E_PIN,DIO_U8_HIGH );
        _delay_us(1);
        /* E = 0 */
         DIO_enu_SetPinValue(LCD_U8_E_PORT,LCD_U8_E_PIN,DIO_U8_LOW );
         return SATE_OK;
    #endif
}

ES_t LCD_enu_SendChar(u8 Copy_u8_Char){
    #if LCD_U8_MODE == LCD_U8_MODE_8BIT
    /* RS = 1 */
    DIO_enu_SetPinValue(LCD_U8_RS_PORT,LCD_U8_RS_PIN,DIO_U8_HIGH);
    /* RW = 0 */
    DIO_enu_SetPinValue(LCD_U8_RW_PORT,LCD_U8_RW_PIN,DIO_U8_LOW);
    /*Write Char*/
    DIO_enu_SetPortValue(LCD_U8_DATA_PORT,Copy_u8_Char);
    /* E = 1 */
    DIO_enu_SetPinValue(LCD_U8_E_PORT,LCD_U8_E_PIN,DIO_U8_HIGH );
    _delay_us(1);
    /* E = 0 */
    DIO_enu_SetPinValue(LCD_U8_E_PORT,LCD_U8_E_PIN,DIO_U8_LOW );
    return SATE_OK;
    #elif LCD_U8_MODE == LCD_U8_MODE_4BIT
    /* RS = 1 */
    DIO_enu_SetPinValue(LCD_U8_RS_PORT,LCD_U8_RS_PIN,DIO_U8_HIGH);
    /* RW = 0 */
    DIO_enu_SetPinValue(LCD_U8_RW_PORT,LCD_U8_RW_PIN,DIO_U8_LOW);
    /*Write Char*/
    DIO_enu_SetPortValue(LCD_U8_DATA_PORT,Copy_u8_Char);
    /* E = 1 */
    DIO_enu_SetPinValue(LCD_U8_E_PORT,LCD_U8_E_PIN,DIO_U8_HIGH );
    _delay_us(1);
    /* E = 0 */
    DIO_enu_SetPinValue(LCD_U8_E_PORT,LCD_U8_E_PIN,DIO_U8_LOW );
    /*Write Char*/
    DIO_enu_SetPortValue(LCD_U8_DATA_PORT,Copy_u8_Char << SHIFT_4BIT);
    /* E = 1 */
    DIO_enu_SetPinValue(LCD_U8_E_PORT,LCD_U8_E_PIN,DIO_U8_HIGH );
    _delay_us(1);
    /* E = 0 */
    DIO_enu_SetPinValue(LCD_U8_E_PORT,LCD_U8_E_PIN,DIO_U8_LOW );
    return SATE_OK;
    #endif
}
ES_t LCD_enu_SendString(u8 * Copy_pu8_String){
    for(u8 i ; Copy_pu8_String[i] != '\0' ; i++ ){
        LCD_enu_SendChar(Copy_pu8_String[i]);
    }
    return SATE_OK;
}

ES_t LCD_enu_SendNum(u32 Copy_u32_Num){
    u8 Local_u8_Reminder ;
    u8 Local_u8_ReverseNum = 0;
    while(Copy_u32_Num != 0){
        Local_u8_Reminder = Copy_u32_Num % 10;
        Local_u8_ReverseNum = Local_u8_ReverseNum * 10 + Local_u8_Reminder;
        Copy_u32_Num /= 10;
    }
    while(Local_u8_ReverseNum != 0){
        LCD_enu_SendChar((Local_u8_ReverseNum % 10)+'0');
        Local_u8_ReverseNum /= 10;
    }
    return SATE_OK;

}
ES_t LCD_enu_SetCursor(u8 Copy_u8_LineNum,u8 Copy_u8_Location){
    if(Copy_u8_Location<=39){
    switch (Copy_u8_LineNum)
    {
    case LINE1:LCD_enu_SendCmnd(ADDRESS_OF_LINE1 + Copy_u8_Location);break;
    case LINE2:LCD_enu_SendCmnd(ADDRESS_OF_LINE2 + Copy_u8_Location);break;
    default:return SATE_NOT_OK;break;
    }
    }
    else{
        return SATE_NOT_OK;
    }
    return SATE_OK;
}
ES_t LCD_enu_Init(void){
    #if LCD_U8_MODE == LCD_U8_MODE_8BIT
    /*Function Set Command*/
    _delay_ms(35);
    LCD_enu_SendCmnd(FUN_SET_8BIT_2LINES_5X7);
    _delay_us(40);
    /*Display On/Off Control*/
    LCD_enu_SendCmnd(DIS_ON_CURSOR_ON_BLINKING);
    _delay_us(40);
    /*Display Clear*/
    LCD_enu_SendCmnd(DISPLAY_CLEAR);
    _delay_ms(2);
    /*Entry Mode Set*/
    LCD_enu_SendCmnd(ENTRY_MOOD);
     return SATE_OK;
    #elif LCD_U8_MODE == LCD_U8_MODE_4BIT
    _delay_ms(35);
    /*Function Set Command*/
    LCD_enu_SendCmnd(0x20);
    LCD_enu_SendCmnd(0x20);
    LCD_enu_SendCmnd(0x80);
    _delay_us(40);
    /*Display On/Off Control*/
    LCD_enu_SendCmnd(0x00);
    LCD_enu_SendCmnd(0x50);
    _delay_us(40);
    /*Display Clear*/
    LCD_enu_SendCmnd(0x00);
    LCD_enu_SendCmnd(0x10);
    _delay_ms(2);
    /*Entry Mode Set*/
    LCD_enu_SendCmnd(0x00);
    LCD_enu_SendCmnd(0x60);
    return SATE_OK;
    #endif
}
ES_t LCD_enu_Clear(void){
	LCD_enu_SendCmnd(DISPLAY_CLEAR);
	 _delay_ms(2);
	return SATE_OK;
}
ES_t LCD_enu_CreateCustomChar(u8 Copy_u8_Location, u8 *Copy_pu8_CharArray)
{
    if (Copy_pu8_CharArray != NULL && Copy_u8_Location < MAX_CHARACTERS)
    {
        LCD_enu_SendCmnd(ADDRESS_OF_CGRAM + (Copy_u8_Location * MAX_CHARACTERS));
        for (u8 Local_u8_Counter = 0; Local_u8_Counter < MAX_CHARACTERS; Local_u8_Counter++)
        {
            LCD_enu_SendChar(Copy_pu8_CharArray[Local_u8_Counter]);
        }
        LCD_enu_SetCursor(0,0);
        return SATE_OK;
    }
    else
        {
        return SATE_NOT_OK;
        }
}