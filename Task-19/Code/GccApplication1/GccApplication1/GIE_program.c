#include "STD_TYPES.h"
#include "ERR_STATE.h"
#include "BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_private.h"
#include "GIE_register.h"


void GIE_Enable(void)
{
	
	SET_BIT(GIE_SREG,SREG_I);

}
void GIE_Disable(void)
{
	
	CLR_BIT(GIE_SREG,SREG_I);
	
}

