/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-08-31   *************************************/
/************* SWC     :   SPI          *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include"../../5-LIB/TYPEDEF.h"
#include"../../5-LIB/ERROR_STATE.h"

ES_t SPI_enu_Init(void);
ES_t SPI_enu_Transceive(u8 Copy_u8_Data ,u8 *Copy_u8_recievedData);
ES_t SPI_enu_Disable(void);


#endif
