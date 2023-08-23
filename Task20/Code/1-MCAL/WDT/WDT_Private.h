/********************************************************************************/
/************* Name    :   Mahmoud Samy     *************************************/
/************* Date    :   2023-08-17       *************************************/
/************* SWC     :   Watch Dog Timer  *************************************/
/************* Version :   1.0              *************************************/
/********************************************************************************/
#ifndef WDT_PRIVATE_H
#define WDT_PRIVATE_H

#include"../../5-LIB/TYPEDEF.h"
/**************Register Address*****************/
#define WDT_WDTCR_REG       *((volatile u8*)0x41)
/**************Register Bits*****************/
#define WDE                 3
#define WDTOE               4

#endif