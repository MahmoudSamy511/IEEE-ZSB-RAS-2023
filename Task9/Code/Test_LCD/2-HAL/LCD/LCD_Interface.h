/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-05-03   *************************************/
/************* SWC     :   LCD          *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H
#include"../../5-LIB/TYPEDEF.h"
#include"../../5-LIB/ERROR_STATE.h"



ES_t LCD_enu_Init(void);

ES_t LCD_enu_SendCmnd(u8 Copy_u8_Cmdn);

ES_t LCD_enu_SendChar(u8 Copy_u8_Char);

ES_t LCD_enu_SendString(u8 * Copy_u8_String);

ES_t LCD_enu_SendNum(u8 * Copy_u8_String);

ES_t LCD_enu_SetCursor(u8 Copy_u8_LineNum,u8 Copy_u8_Location);

ES_t LCD_enu_Clear(void);




#endif
