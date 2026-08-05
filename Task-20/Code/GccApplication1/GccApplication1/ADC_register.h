
#ifndef _ACD_REGISTER_H_
#define _ACD_REGISTER_H_


#define ADC_ADMUX     (*((volatile u8*)0X27))
#define ADC_ADCSRA    (*((volatile u8*)0X26))
#define ADC_ADCH      (*((volatile u8*)0X25))
#define ADC_ADCL      (*((volatile u8*)0X24))
#define ADC_10_DATA      (*((volatile u16*)0X24))



#endif