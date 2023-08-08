/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-08-08   *************************************/
/************* SWC     :   Timer        *************************************/
/************* Version :   1.0          *************************************/
/****************************************************************************/
#include"../../5-LIB/TYPEDEF.h"
#include"../../5-LIB/ERROR_STATE.h"
#include"../../5-LIB/BIT_MATH.h"

#include"Timer_Private.h"
#include"Timer_Config.h"
/*Global Pointer To Function */
static  void(*Timers_pf_Timer0[2])(void) = {NULL};
ES_t Timers_enu_Timer0Init(void){
/*************** Timer 0 Mode ****************/
    #if TIMER0_MODE == NORMAL_MODE
        CLR_BIT(TCCR0_REG,WGM00);
        CLR_BIT(TCCR0_REG,WGM01);
        //Enable OverFlow Interrupt
        SET_BIT(TIMSK_REG,TOIE0);
        //PreLoad Value
        TCNT0_REG = TIMER0_PRELOAD_VALUE;
    #elif TIMER0_MODE == CTC_MODE
        CLR_BIT(TCCR0_REG,WGM00);
        SET_BIT(TCCR0_REG,WGM01);
        //Enable CTC Interrupt
        SET_BIT(TIMSK_REG,OCIE0);
        //Set Compare match unit Register Value
        OCR0_REG = TIMER0_OCR_VALUE;
    #endif
    /***************Set PreScaler Value ****************/
    TCCR0_REG |= TIMER0_PRESCALER;
}
ES_t Timers_enu_Timer0SetCallBack(void(*Copy_pf)(void),u8 Copy_u8_Mode){
    u8 Local_u8_errorState = STATE_OK;
    if(Copy_pf != NULL && Copy_u8_Mode<2 ){
        Timers_pf_Timer0[Copy_u8_Mode] = Copy_pf;
    }else{
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}
ES_t Timers_enu_TimerSetCLKSource(u8 Copy_u8_CLK_Source){
    u8 Local_u8_errorState = STATE_OK;
    if(Copy_u8_CLK_Source < 8){
        //Clear Old Value of Prescaler
        TCCR0_REG &= RESET_CLK_SOURCE;
        TCCR0_REG |= TIMER0_PRESCALER;
    }else{
        Local_u8_errorState = STATE_NOT_OK;
    }
    return Local_u8_errorState;
}
void __vector_10(void){
    #if (TIMER0_PRESCALER == EXTERNAL_FALLING_EDGE) || (TIMER0_PRESCALER == EXTERNAL_RISING_EDGE)
    if(Timers_pf_Timer0[CTC_MODE] != NULL)
        Timers_pf_Timer0[CTC_MODE]();
    #else
    static u16 Local_u16_CounterCTC = 0;
    Local_u16_CounterCTC++;
    if(Local_u16_CounterCTC == 20000){
        Local_u16_CounterCTC = 0;
    if(Timers_pf_Timer0[CTC_MODE] != NULL)
        Timers_pf_Timer0[CTC_MODE]();
    }
    #endif
}
void __vector_11(void){
    #if (TIMER0_PRESCALER == EXTERNAL_FALLING_EDGE) || (TIMER0_PRESCALER == EXTERNAL_RISING_EDGE)
        if(Timers_pf_Timer0[NORMAL_MODE] != NULL)
            Timers_pf_Timer0[NORMAL_MODE]();
    #else
    static u16 Local_u16_CounterOVF = 0;
    Local_u16_CounterOVF++;
    if(Local_u16_CounterOVF == 7813){
        /*clear overflow counter*/
        Local_u16_CounterOVF = 0;
        /*update preload Value*/
        TCNT0_REG = TIMER0_PRELOAD_VALUE;
        /*calling App function*/
        if(Timers_pf_Timer0[NORMAL_MODE] != NULL)
            Timers_pf_Timer0[NORMAL_MODE]();
    }
    #endif
    
}



