/***********************************************************************/
/********************  Author: Moaz                    *****************/
/********************  SWC: EXTI1                      *****************/
/********************  LAYER: MCAL                     *****************/
/********************  DATE: 29/07/2026                *****************/
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_STATE.h"

#include "EXTI1_REGISTER.h"
#include "EXTI1.h"

static volatile void (*global_ptr_to_int1)(void)=NULL;

u8 EXTI1_u8Enable(u8 copy_u8SenseCTRL)
{
	u8 Local_u8error_state=OK;
	SET_BIT(EXTI1_GICR, GICR_INT1);
	
	switch (copy_u8SenseCTRL)
	{
		case EXTI_SENSE_CTRL_LOW_LEVEL :
		CLR_BIT(EXTI1_MCUCR, MCUCR_ISC10);
		CLR_BIT(EXTI1_MCUCR, MCUCR_ISC11);
		break;
		case EXTI_SENSE_CTRL_ON_CHANGE :
		SET_BIT(EXTI1_MCUCR, MCUCR_ISC10);
		CLR_BIT(EXTI1_MCUCR, MCUCR_ISC11);
		break;
		case EXTI_SENSE_CTRL_FALLING_EDGE :
		CLR_BIT(EXTI1_MCUCR, MCUCR_ISC10);
		SET_BIT(EXTI1_MCUCR, MCUCR_ISC11);
		break;
		case EXTI_SENSE_CTRL_RISING_EDGE:
		SET_BIT(EXTI1_MCUCR, MCUCR_ISC10);
		SET_BIT(EXTI1_MCUCR, MCUCR_ISC11);
		break;
		default: Local_u8error_state = NOK; break;
	}
	return Local_u8error_state;
}

u8 EXTI1_u8Disable(void)
{
	CLR_BIT(EXTI1_GICR, GICR_INT1);
	return OK;
}

u8 EXTI1_u8SetCallBack(void (*copy_ptr_to_function)(void))
{
	if(copy_ptr_to_function != NULL)
	{
		global_ptr_to_int1 = copy_ptr_to_function;
		return OK;
	}
	else
	{
		return NOK;
	}
}

// ISR(INT1_vect)
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if (global_ptr_to_int1 != NULL)
	global_ptr_to_int1();
}