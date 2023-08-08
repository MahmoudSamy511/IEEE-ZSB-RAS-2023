/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-08-08   *************************************/
/************* SWC     :   Timer        *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H
/********************************************/
/*Options For Mode:
                    1- NORMAL_MODE
                    2- CTC_MODE
*/
/*Options For PreScaler:
                    1- F_CPU_CLK
                    2- CLK_8
                    3- CLK_64
                    4- CLK_256
                    5- CLK_1024
                    6- EXTERNAL_FALLING_EDGE
                    7- EXTERNAL_RISING_EDGE
*/
/**********************Choose Timer Mode*************/
#define TIMER0_MODE             CTC_MODE
/**********************Choose Prescaler*************/
#define TIMER0_PRESCALER        EXTERNAL_RISING_EDGE
/**********************Choose Prescaler*************/
#define TIMER0_PRELOAD_VALUE        128    
#define TIMER0_OCR_VALUE            0 



#endif
