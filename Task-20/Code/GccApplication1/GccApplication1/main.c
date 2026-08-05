#define F_CPU 16000000UL
#include <util/delay.h>

/* Libraries */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"
#include "ADC_interface.h"

/* HAL */
#include "LCD_interface.h"

int main(void)
{
	
	LCD_voidInit();
	
	ADC_voidInit();
	
	DIO_u8SetPortDirection(DIO_PORT_B, DIO_PORT_OUTPUT);
	
	DIO_u8SetPortValue(DIO_PORT_B, DIO_PORT_LOW);
	
	DIO_u8SetPinDirection(DIO_PORT_A, DIO_PIN_0, DIO_PIN_INPUT);

	u16 local_u16AdcValue = 0;
	u8 local_u8Percentage = 0;
	u8 local_u8NumLedsOn = 0;
	u8 local_u8PortB_Output = 0;

	while(1)
	{
		local_u16AdcValue = ADC_u16getDigitalReading(0);

		local_u8Percentage = (u8)(((u32)local_u16AdcValue * 100) / 1023);

		local_u8NumLedsOn = (local_u8Percentage * 8) / 100;

		local_u8PortB_Output = (1 << local_u8NumLedsOn) - 1;
		DIO_u8SetPortValue(DIO_PORT_B, local_u8PortB_Output);

		
		LCD_u8SendPosition(0, 0);
		LCD_voidSendString("ADC Val: ");
		LCD_writeNumber((u32)local_u16AdcValue);
		LCD_voidSendString("    ");

		LCD_u8SendPosition(0, 1);
		LCD_voidSendString("Percent: ");
		LCD_writeNumber((u32)local_u8Percentage);
		LCD_voidSendString("%   ");

		_delay_ms(100);
	}
	
	return 0;
}