
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_STATE.h"


#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_register.h"

/**DIO_u8SetPinDirection(DIO_PORT_B,32,DIO_PIN_OUTPUT);**/
u8 DIO_u8SetPinDirection(u8 copy_u8Port,u8 copy_u8Pin, u8 copy_u8PinDirection)
{
	u8 local_u8Error_state=OK;
	
	if(copy_u8Pin >= DIO_PIN_0   &&  copy_u8Pin <= DIO_PIN_7 )
	{
		switch(copy_u8PinDirection)
		{
			case DIO_PIN_INPUT:
			switch(copy_u8Port)
			{
				case DIO_PORT_A: CLR_BIT(REG_DDRA,copy_u8Pin); break;
				case DIO_PORT_B: CLR_BIT(REG_DDRB,copy_u8Pin); break;
				case DIO_PORT_C: CLR_BIT(REG_DDRC,copy_u8Pin); break;
				case DIO_PORT_D: CLR_BIT(REG_DDRD,copy_u8Pin); break;
				default:  local_u8Error_state = NOK;
			}
			break;
			case DIO_PIN_OUTPUT:
			switch(copy_u8Port)
			{
				case DIO_PORT_A: SET_BIT(REG_DDRA,copy_u8Pin); break;
				case DIO_PORT_B: SET_BIT(REG_DDRB,copy_u8Pin); break;
				case DIO_PORT_C: SET_BIT(REG_DDRC,copy_u8Pin); break;
				case DIO_PORT_D: SET_BIT(REG_DDRD,copy_u8Pin); break;
				default:  local_u8Error_state = NOK;
			}
			break;
			default:  local_u8Error_state = NOK;
		}
	}
	else
	{
		local_u8Error_state = NOK;
	}
	
	return local_u8Error_state;
	
	/*
	if (copy_u8Port == DIO_PORT_A)
	{
	if(copy_u8Pin >= DIO_PIN_0   &&  copy_u8Pin <= DIO_PIN_7 )
	{
	if(copy_u8PinDirection == DIO_PIN_INPUT)
	{
	CLR_BIT(REG_DDRA,copy_u8Pin);
	}
	else if(copy_u8PinDirection == DIO_PIN_OUTPUT)
	{
	SET_BIT(REG_DDRA,copy_u8Pin);
	}
	else
	{
	local_u8Error_state = NOK;
	}
	}
	else
	{
	local_u8Error_state = NOK;
	}
	}
	else if (copy_u8Port == DIO_PORT_B)
	{
	if(copy_u8Pin >= DIO_PIN_0   &&  copy_u8Pin <= DIO_PIN_7 )
	{
	if(copy_u8PinDirection == DIO_PIN_INPUT)
	{
	CLR_BIT(REG_DDRB,copy_u8Pin);
	}
	else if(copy_u8PinDirection == DIO_PIN_OUTPUT)
	{
	SET_BIT(REG_DDRB,copy_u8Pin);
	}
	else
	{
	local_u8Error_state = NOK;
	}
	}
	else
	{
	local_u8Error_state = NOK;
	}
	}
	else if (copy_u8Port == DIO_PORT_C)
	{
	if(copy_u8Pin >= DIO_PIN_0   &&  copy_u8Pin <= DIO_PIN_7 )
	{
	if(copy_u8PinDirection == DIO_PIN_INPUT)
	{
	CLR_BIT(REG_DDRC,copy_u8Pin);
	}
	else if(copy_u8PinDirection == DIO_PIN_OUTPUT)
	{
	SET_BIT(REG_DDRC,copy_u8Pin);
	}
	else
	{
	local_u8Error_state = NOK;
	}
	}
	else
	{
	local_u8Error_state = NOK;
	}
	}
	else if (copy_u8Port == DIO_PORT_D)
	{
	if(copy_u8Pin >= DIO_PIN_0   &&  copy_u8Pin <= DIO_PIN_7 )
	{
	if(copy_u8PinDirection == DIO_PIN_INPUT)
	{
	CLR_BIT(REG_DDRD,copy_u8Pin);
	}
	else if(copy_u8PinDirection == DIO_PIN_OUTPUT)
	{
	SET_BIT(REG_DDRD,copy_u8Pin);
	}
	else
	{
	local_u8Error_state = NOK;
	}
	}
	else
	{
	local_u8Error_state = NOK;
	}
	}
	else
	{
	local_u8Error_state = NOK;
	}
	*/
	return local_u8Error_state;
}
u8 DIO_u8SetPinValue(u8 copy_u8Port,u8 copy_u8Pin, u8 copy_u8PinValue)
{

	u8 local_u8Error_state=OK;
	
	if(copy_u8Pin >= DIO_PIN_0   &&  copy_u8Pin <= DIO_PIN_7 )
	{
		switch(copy_u8PinValue)
		{
			case DIO_PIN_LOW:
			switch(copy_u8Port)
			{
				case DIO_PORT_A: CLR_BIT(REG_PORTA,copy_u8Pin); break;
				case DIO_PORT_B: CLR_BIT(REG_PORTB,copy_u8Pin); break;
				case DIO_PORT_C: CLR_BIT(REG_PORTC,copy_u8Pin); break;
				case DIO_PORT_D: CLR_BIT(REG_PORTD,copy_u8Pin); break;
				default:  local_u8Error_state = NOK;
			}
			break;
			case DIO_PIN_HIGH:
			switch(copy_u8Port)
			{
				case DIO_PORT_A: SET_BIT(REG_PORTA,copy_u8Pin); break;
				case DIO_PORT_B: SET_BIT(REG_PORTB,copy_u8Pin); break;
				case DIO_PORT_C: SET_BIT(REG_PORTC,copy_u8Pin); break;
				case DIO_PORT_D: SET_BIT(REG_PORTD,copy_u8Pin); break;
				default:  local_u8Error_state = NOK;
			}
			break;
			default:  local_u8Error_state = NOK;
		}
	}
	else
	{
		local_u8Error_state = NOK;
	}
	
	return local_u8Error_state;

}
u8 DIO_u8GetPinValue(u8 copy_u8Port,u8 copy_u8Pin, u8 *copy_Pu8ReadValue)
{

	u8 local_u8Error_state=OK;
	
	if(copy_u8Pin >= DIO_PIN_0   &&  copy_u8Pin <= DIO_PIN_7 )
	{
		
			switch(copy_u8Port)
			{
				case DIO_PORT_A: *copy_Pu8ReadValue=GET_BIT(REG_PINA,copy_u8Pin); break;
				case DIO_PORT_B: *copy_Pu8ReadValue=GET_BIT(REG_PINB,copy_u8Pin); break;
				case DIO_PORT_C: *copy_Pu8ReadValue=GET_BIT(REG_PINC,copy_u8Pin); break;
				case DIO_PORT_D: *copy_Pu8ReadValue=GET_BIT(REG_PIND,copy_u8Pin); break;
				default:  local_u8Error_state = NOK;
			}
	}
	else
	{
		local_u8Error_state = NOK;
	}
	
	return local_u8Error_state;


}


u8 DIO_u8TogglePinValue(u8 copy_u8Port,u8 copy_u8Pin)
{
u8 local_u8Error_state=OK;

if(copy_u8Pin >= DIO_PIN_0   &&  copy_u8Pin <= DIO_PIN_7 )
{
	
	switch(copy_u8Port)
	{
		case DIO_PORT_A: TOG_BIT(REG_PORTA,copy_u8Pin); break;
		case DIO_PORT_B: TOG_BIT(REG_PORTB,copy_u8Pin); break;
		case DIO_PORT_C: TOG_BIT(REG_PORTC,copy_u8Pin); break;
		case DIO_PORT_D: TOG_BIT(REG_PORTD,copy_u8Pin); break;
		default:  local_u8Error_state = NOK;
	}
}
else
{
	local_u8Error_state = NOK;
}

return local_u8Error_state;

}
u8 DIO_u8SetPortDirection(u8 copy_u8Port, u8 copy_u8PortDirection)
{
	u8 local_u8Error_state=OK;

			switch(copy_u8Port)
			{
				case DIO_PORT_A:  REG_DDRA= copy_u8PortDirection; break;
				case DIO_PORT_B:  REG_DDRB= copy_u8PortDirection; break;
				case DIO_PORT_C:  REG_DDRC= copy_u8PortDirection; break;
				case DIO_PORT_D:  REG_DDRD= copy_u8PortDirection;break;
				default:  local_u8Error_state = NOK;
			}
			
	return local_u8Error_state;
}
u8 DIO_u8SetPortValue(u8 copy_u8Port, u8 copy_u8PortValue)
{
	u8 local_u8Error_state=OK;

	switch(copy_u8Port)
	{
		case DIO_PORT_A:  REG_PORTA= copy_u8PortValue; break;
		case DIO_PORT_B:  REG_PORTB= copy_u8PortValue; break;
		case DIO_PORT_C:  REG_PORTC= copy_u8PortValue; break;
		case DIO_PORT_D:  REG_PORTD= copy_u8PortValue;break;
		default:  local_u8Error_state = NOK;
	}
	
	return local_u8Error_state;
}
u8 DIO_u8GetPortValue(u8 copy_u8Port, u8 *copy_Pu8ReadValue);
u8 DIO_u8TogglePortValue(u8 copy_u8Port);