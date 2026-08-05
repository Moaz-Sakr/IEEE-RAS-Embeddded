/***********************************************************************/
/***********************************************************************/
/********************  Author: Eman Assem      *************************/
/********************  SWC: ADC                *************************/
/********************  LAYER: MCAL             *************************/
/********************  VERSION: 1.0            *************************/
/********************  DATE:          *************************/
/***********************************************************************/
/***********************************************************************/

#ifndef _ACD_INTERFACE_H_
#define _ACD_INTERFACE_H_

#define ADC_CHANNEL_ID_0      0
#define ADC_CHANNEL_ID_1      1
#define ADC_CHANNEL_ID_2      2
#define ADC_CHANNEL_ID_3      3
#define ADC_CHANNEL_ID_4      4
#define ADC_CHANNEL_ID_5      5
#define ADC_CHANNEL_ID_6      6
#define ADC_CHANNEL_ID_7      7


void ADC_voidInit(void);
u16 ADC_u16getDigitalReading(u8 copy_u8ChannelID);



#endif