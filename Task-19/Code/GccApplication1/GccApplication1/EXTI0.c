/***********************************************************************/
/********************  Author: Moaz                    *****************/
/********************  SWC: EXTI0                      *****************/
/********************  LAYER: MCAL                     *****************/
/********************  DATE: 29/07/2026                *****************/
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_STATE.h"

#include "EXTI0_REGISTER.h"
#include "EXTI0.h"

static volatile void (*global_ptr_to_int0)(void)=NULL;

u8 EXTI0_u8Enable(u8 copy_u8SenseCTRL)
{
	u8 Local_u8error_state=OK;
	SET_BIT(EXTI0_GICR, GICR_INT0);
	
	switch (copy_u8SenseCTRL)
	{
		case EXTI_SENSE_CTRL_LOW_LEVEL :
		CLR_BIT(EXTI0_MCUCR, MCUCR_ISC00);
		CLR_BIT(EXTI0_MCUCR, MCUCR_ISC01);
		break;
		case EXTI_SENSE_CTRL_ON_CHANGE :
		SET_BIT(EXTI0_MCUCR, MCUCR_ISC00);
		CLR_BIT(EXTI0_MCUCR, MCUCR_ISC01);
		break;
		case EXTI_SENSE_CTRL_FALLING_EDGE :
		CLR_BIT(EXTI0_MCUCR, MCUCR_ISC00);
		SET_BIT(EXTI0_MCUCR, MCUCR_ISC01);
		break;
		case EXTI_SENSE_CTRL_RISING_EDGE:
		SET_BIT(EXTI0_MCUCR, MCUCR_ISC00);
		SET_BIT(EXTI0_MCUCR, MCUCR_ISC01);
		break;
		default: Local_u8error_state = NOK; break;
	}
	return Local_u8error_state;
}

u8 EXTI0_u8Disable(void)
{
	CLR_BIT(EXTI0_GICR, GICR_INT0);
	return OK;
}

u8 EXTI0_u8SetCallBack(void (*copy_ptr_to_function)(void))
{
	if(copy_ptr_to_function != NULL)
	{
		global_ptr_to_int0 = copy_ptr_to_function;
		return OK;
	}
	else
	{
		return NOK;
	}
}

// ISR(INT0_vect)
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if (global_ptr_to_int0 != NULL)
	global_ptr_to_int0();
}