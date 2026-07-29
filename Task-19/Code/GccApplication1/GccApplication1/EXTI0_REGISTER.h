/***********************************************************************/
/********************  Author: Moaz                    *****************/
/********************  SWC: EXTI0                      *****************/
/********************  LAYER: MCAL                     *****************/
/********************  DATE: 29/07/2026                *****************/
/***********************************************************************/

#ifndef EXTI0_REGISTER_H_
#define EXTI0_REGISTER_H_

/* Registers Addresses */
#define EXTI0_MCUCR    (*(( volatile u8 *)0X55))
#define EXTI0_GICR     (*(( volatile u8 *)0X5B))
#define EXTI0_GIFR     (*(( volatile u8 *)0X5A))

/* MCUCR bits for INT0 */
#define MCUCR_ISC01   1
#define MCUCR_ISC00   0

/* GICR bits for INT0 */
#define GICR_INT0     6

/* GIFR bits for INT0 */
#define GIFR_INTF0    6

#endif