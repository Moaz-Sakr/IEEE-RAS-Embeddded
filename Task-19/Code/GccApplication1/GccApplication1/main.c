/***********************************************************************/
/********************  Author: Moaz                    *****************/
/********************  SWC: MAIN APP                   *****************/
/********************  DATE: 29/07/2026                *****************/
/***********************************************************************/

#define F_CPU 16000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

// MCAL Inclusions
#include "DIO_interface.h"
#include "EXTI0.h"
#include "EXTI1.h"
#include "GIE_interface.h"

// HAL Inclusions
#include "LCD_interface.h"

// Extern the 7-segment cathode array from SSD_program.c
extern u8 SSD_Cathode[10];

volatile u8 counter = 1;

/* ==================================================================== */
/* ======================== Callback Functions ======================== */
/* ==================================================================== */

// Callback for INT0: Toggles the LED
void APP_ToggleLED(void)
{
	// Toggle LED on Port A, Pin 0
	DIO_u8TogglePinValue(DIO_PORT_A, DIO_PIN_0);
}

// Callback for INT1: Resets the 7-segment counter to 1
void APP_ResetCounter(void)
{
	counter = 1;
}

/* ==================================================================== */
/* =========================== Main Program =========================== */
/* ==================================================================== */

int main(void)
{
	/* 1. Initialization & Direction Setup */
	
	// Set LED Pin as Output (PORT A, PIN 0)
	DIO_u8SetPinDirection(DIO_PORT_A, DIO_PIN_0, DIO_PIN_OUTPUT);
	
	// Set 7-Segment Port as Output (PORT B)
	DIO_u8SetPortDirection(DIO_PORT_B, DIO_PORT_OUTPUT);
	
	// Set INT0 (PD2) and INT1 (PD3) Pins as Input
	DIO_u8SetPinDirection(DIO_PORT_D, DIO_PIN_2, DIO_PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PORT_D, DIO_PIN_3, DIO_PIN_INPUT);
	
	// Enable Internal Pull-up resistors for INT0 and INT1
	DIO_u8SetPinValue(DIO_PORT_D, DIO_PIN_2, DIO_PIN_HIGH);
	DIO_u8SetPinValue(DIO_PORT_D, DIO_PIN_3, DIO_PIN_HIGH);

	/* 2. Initialize LCD */
	// LCD_voidInit() handles its own pin directions internally based on LCD_config.h
	LCD_voidInit();

	/* 3. Set Callbacks for Interrupts */
	EXTI0_u8SetCallBack(APP_ToggleLED);
	EXTI1_u8SetCallBack(APP_ResetCounter);

	/* 4. Enable External Interrupts (Falling Edge Trigger) */
	EXTI0_u8Enable(EXTI_SENSE_CTRL_FALLING_EDGE);
	EXTI1_u8Enable(EXTI_SENSE_CTRL_FALLING_EDGE);

	/* 5. Enable Global Interrupts */
	GIE_Enable();

	/* 6. Application Super Loop */
	while(1)
	{
		// A. Display current counter value on 7-Segment (PORT B)
		DIO_u8SetPortValue(DIO_PORT_B, SSD_Cathode[counter]);
		
		// B. Display current counter value on LCD
		LCD_voidSendCommand(LCD_CLEAR); // Clear screen[cite: 21]
		LCD_voidSendString("Counter: ");
		LCD_writeNumber(counter);       // Write the updated counter[cite: 21]

		// Wait for 1 second (Since Timers are forbidden)
		_delay_ms(1000);

		// Increment counter safely
		counter++;
		if(counter > 9)
		{
			counter = 1;
		}
	}
	return 0;
}