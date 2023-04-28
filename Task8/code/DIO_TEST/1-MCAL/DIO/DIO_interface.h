/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-04-27   *************************************/
/************* SWC     :   DIO          *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#include"../../5-LIB/TYPEDEF.h"

/*Macros for PORTS*/
#define DIO_U8_PORTA     0
#define DIO_U8_PORTB     1
#define DIO_U8_PORTC     2
#define DIO_U8_PORTD     3

/*Macros for PINS*/
#define DIO_U8_PIN0      0
#define DIO_U8_PIN1      1
#define DIO_U8_PIN2      2
#define DIO_U8_PIN3      3
#define DIO_U8_PIN4      4
#define DIO_U8_PIN5      5
#define DIO_U8_PIN6      6
#define DIO_U8_PIN7      7

/*Macros for Pin Direction*/
#define DIO_U8_INPUT     0
#define DIO_U8_OUTPUT    1

/*Macros for Pin Value*/
#define DIO_U8_LOW       0
#define DIO_U8_HIGH      1

/*Functions Prototypes*/
void DIO_void_Init           (void);

u8 DIO_u8_SetPinDirection    (u8 Copy_u8_PortId, u8 Copy_u8_PinId,u8 Copy_u8_PinDirection);

u8 DIO_u8_SetPinValue        (u8 Copy_u8_PortId, u8 Copy_u8_PinId,u8 Copy_u8_PinValue);

u8 DIO_u8_GetPinValue        (u8 Copy_u8_PortId, u8 Copy_u8_PinId,u8 * Copy_pu8_ReturnPinValue);

u8 DIO_u8_SetPortDirection   (u8 Copy_u8_PortId, u8 Copy_u8_PortDirection);

u8 DIO_u8_SetPortValue       (u8 Copy_u8_PortId, u8 Copy_u8_PortValue);

u8 DIO_u8_GetPortValue       (u8 Copy_u8_PortId, u8 * Copy_u8_ReturnPortValue);


#endif