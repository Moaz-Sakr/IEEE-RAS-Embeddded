#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "MD_interface.h"

#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	MD_vInit();
	
	u8 i;
	for(i = DIO_PIN_0; i <= DIO_PIN_4; i++)
	{
		DIO_u8SetPinDirection(DIO_PORT_A, i, DIO_PIN_INPUT);
		DIO_u8SetPinValue(DIO_PORT_A, i, DIO_PIN_HIGH);
	}
	
	u8 Local_u8FwdBtn   = DIO_PIN_HIGH;
	u8 Local_u8BwdBtn   = DIO_PIN_HIGH;
	u8 Local_u8RightBtn = DIO_PIN_HIGH;
	u8 Local_u8LeftBtn  = DIO_PIN_HIGH;
	u8 Local_u8StopBtn  = DIO_PIN_HIGH;

	while(1)
	{
		DIO_u8GetPinValue(DIO_PORT_A, DIO_PIN_0, &Local_u8FwdBtn);
		DIO_u8GetPinValue(DIO_PORT_A, DIO_PIN_1, &Local_u8BwdBtn);
		DIO_u8GetPinValue(DIO_PORT_A, DIO_PIN_2, &Local_u8RightBtn);
		DIO_u8GetPinValue(DIO_PORT_A, DIO_PIN_3, &Local_u8LeftBtn);
		DIO_u8GetPinValue(DIO_PORT_A, DIO_PIN_4, &Local_u8StopBtn);
		

		u8 Local_u8PressedCount = 0;
		if(Local_u8FwdBtn == DIO_PIN_LOW)   Local_u8PressedCount++;
		if(Local_u8BwdBtn == DIO_PIN_LOW)   Local_u8PressedCount++;
		if(Local_u8RightBtn == DIO_PIN_LOW) Local_u8PressedCount++;
		if(Local_u8LeftBtn == DIO_PIN_LOW)  Local_u8PressedCount++;


		if(Local_u8StopBtn == DIO_PIN_LOW)
		{
			MD_vStop();
		}

		else if(Local_u8PressedCount > 1)
		{
			MD_vStop();
		}

		else if(Local_u8FwdBtn == DIO_PIN_LOW)
		{
			MD_vForward();
		}
		else if(Local_u8BwdBtn == DIO_PIN_LOW)
		{
			MD_vBackward();
		}
		else if(Local_u8RightBtn == DIO_PIN_LOW)
		{
			MD_vTurnRight();
		}
		else if(Local_u8LeftBtn == DIO_PIN_LOW)
		{
			MD_vTurnLeft();
		}

		else
		{
			MD_vStop();
		}
		
		_delay_ms(50);
	}
	
	return 0;
}