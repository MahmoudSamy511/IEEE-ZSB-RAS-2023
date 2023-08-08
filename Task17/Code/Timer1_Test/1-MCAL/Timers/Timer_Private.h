/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-08-08   *************************************/
/************* SWC     :   Timer        *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H
#include"../../5-LIB/TYPEDEF.h"
/*****************************Registers Addresses*********************/
#define TIMSK_REG           *((volatile u8 *)0x59)
#define TIFR_REG            *((volatile u8 *)0x58)
#define TCCR0_REG           *((volatile u8 *)0x53)
#define TCNT0_REG           *((volatile u8 *)0x52)
#define OCR0_REG            *((volatile u8 *)0x5c)
/*****************************Registers Bits*********************/
#define WGM00                  6
#define WGM01                  3
#define COM00                  4
#define COM01                  5
#define TOIE0                  0
#define OCIE0                  1
#define TOV0                   0
#define OCF0                   1
/*****************************Protypes Of ISR Functions*********************/
void __vector_10(void)    __attribute__((signal));
void __vector_11(void)    __attribute__((signal));
/*****************************Options Macros**********************/
#define NORMAL_MODE                     0
#define CTC_MODE                        1

#define F_CPU_CLK                       1
#define CLK_8                           2
#define CLK_64                          3
#define CLK_256                         4
#define CLK_1024                        5
#define EXTERNAL_FALLING_EDGE           6           
#define EXTERNAL_RISING_EDGE            7            

#define RESET_CLK_SOURCE              0XF8
#endif