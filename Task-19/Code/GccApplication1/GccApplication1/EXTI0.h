/***********************************************************************/
/********************  Author: Moaz                    *****************/
/********************  SWC: EXTI0                      *****************/
/********************  LAYER: MCAL                     *****************/
/********************  DATE: 29/07/2026                *****************/
/***********************************************************************/

#ifndef EXTI0_H_
#define EXTI0_H_

#define EXTI_SENSE_CTRL_LOW_LEVEL     0
#define EXTI_SENSE_CTRL_ON_CHANGE     1
#define EXTI_SENSE_CTRL_FALLING_EDGE  2
#define EXTI_SENSE_CTRL_RISING_EDGE   3

u8 EXTI0_u8Enable(u8 copy_u8SenseCTRL);
u8 EXTI0_u8Disable(void);
u8 EXTI0_u8SetCallBack(void (*copy_ptr_to_function)(void));

#endif