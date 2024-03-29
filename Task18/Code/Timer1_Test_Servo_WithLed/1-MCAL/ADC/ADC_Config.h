/****************************************************************************/
/************* Name    :   Mahmoud Samy *************************************/
/************* Date    :   2023-07-31   *************************************/
/************* SWC     :    ADC         *************************************/
/************* Version :    1.0         *************************************/
/****************************************************************************/
#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H
/*Options For Referance Voltage :
                                1-AREF 
                                2-AVCC
                                3-INTERNAL_VOLTAGE_REF
*/

/*Options For ADC Coversion Mode :
                                1-START_CONVERSION 
                                2-FREE_RUNNING_MODE
                                3-EXTERNAL_INTERRUPT
*/

/*Options For ADC Presentation Mode :
                                1-RIGHT_ADJUST
                                2-LEFT_ADJUST
*/

/*Options For ADC Clock(Division Factor) :
                                1-DIV_BY_2
                                2-DIV_BY_4
                                3-DIV_BY_8
                                4-DIV_BY_16
                                5-DIV_BY_32
                                6-DIV_BY_64
                                7-DIV_BY_128
*/

/******************Choose Referance Voltage**********************/
#define ADC_REF_VOLTAGE                     AVCC               
/******************Choose Conversion Mode**********************/
#define ADC_CONVERSION_MODE                 START_CONVERSION               
/******************Choose Presentation Mode**********************/
#define ADC_PRESENTATION_MODE               RIGHT_ADJUST               
/******************Choose Division Factor**********************/
#define ADC_DIVISION_FACTOR                 DIV_BY_128               
/******************Choose MAX Timout Value**********************/
#define ADC_U32_TIMEOUT_MAX_VALUE           50000





#endif