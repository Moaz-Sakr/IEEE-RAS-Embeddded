
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_register.h"

void ADC_voidInit(void)
{
/*  Reference Selection Bits */
SET_BIT(ADC_ADMUX,6);
CLR_BIT(ADC_ADMUX,7);

#if ADC_DATA == DATA_8
/* ADC Left Adjust Result */
SET_BIT(ADC_ADMUX,5);
#elif ADC_DATA == DATA_10
/* ADC Right Adjust Result */
CLR_BIT(ADC_ADMUX,5);
#else
#error "please set ada data bits"
#endif
/*ADC Prescaler Selections   /16 */
SET_BIT(ADC_ADCSRA,0);
SET_BIT(ADC_ADCSRA,1);
SET_BIT(ADC_ADCSRA,2);

/*ADC Enable*/
SET_BIT(ADC_ADCSRA,7);
}
u16 ADC_u16getDigitalReading(u8 copy_u8ChannelID)
{
	/*Analog Channel */
	ADC_ADMUX &= 0b11100000;
	ADC_ADMUX |= copy_u8ChannelID ;
	
	/*ADC Start Conversion*/
	SET_BIT(ADC_ADCSRA,6);
	
	
	/*Busy waiting ADC Interrupt Flag*/
	while(GET_BIT(ADC_ADCSRA,4) == 0);
	
	/*Clear flag*/
	SET_BIT(ADC_ADCSRA,4);
	

	#if ADC_DATA == DATA_8
	/*Read 8 bits*/
	return ADC_ADCH;
	
	#elif ADC_DATA == DATA_10
	/*Read 10 bits*/
	return ADC_10_DATA;
	
	#else
	#error "please set ada data bits"
	#endif
	
}
