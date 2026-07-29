/***********************************************************************/
/********************  Author: Moaz                    *****************/
/********************  SWC: EXTI1                      *****************/
/********************  LAYER: MCAL                     *****************/
/********************  DATE: 29/07/2026                *****************/
/***********************************************************************/

#ifndef EXTI1_REGISTER_H_
#define EXTI1_REGISTER_H_

/* Registers Addresses */
#define EXTI1_MCUCR    (*(( volatile u8 *)0X55))
#define EXTI1_GICR     (*(( volatile u8 *)0X5B))
#define EXTI1_GIFR     (*(( volatile u8 *)0X5A))

/* MCUCR bits for INT1 */
#define MCUCR_ISC11   3
#define MCUCR_ISC10   2

/* GICR bits for INT1 */
#define GICR_INT1     7

/* GIFR bits for INT1 */
#define GIFR_INTF1    7

#endif