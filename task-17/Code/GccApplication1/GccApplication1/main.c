// main.c
#define F_CPU 16000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SSD_interface.h"

int main(void) {
	
	DIO_u8SetPinDirection(DIO_PORT_C, DIO_PIN_0, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORT_C, DIO_PIN_1, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORT_C, DIO_PIN_2, DIO_PIN_OUTPUT);
	
	DIO_u8SetPortDirection(DIO_PORT_A, DIO_PORT_OUTPUT);
	
	DIO_u8SetPinDirection(DIO_PORT_B, DIO_PIN_1, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORT_B, DIO_PIN_2, DIO_PIN_OUTPUT);
	
	while(1) {
		
		DIO_u8SetPinValue(DIO_PORT_C, DIO_PIN_2, DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORT_C, DIO_PIN_1, DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORT_C, DIO_PIN_0, DIO_PIN_HIGH);
		for(s8 t = 15; t > 0; t--) {
			for(u8 i = 0; i < 50; i++) {
				SSD_Display_2_Numbers(t);
			}
		}
		
		DIO_u8SetPinValue(DIO_PORT_C, DIO_PIN_2, DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORT_C, DIO_PIN_1, DIO_PIN_HIGH);
		DIO_u8SetPinValue(DIO_PORT_C, DIO_PIN_0, DIO_PIN_LOW);
		for(s8 t = 5; t > 0; t--) {
			for(u8 i = 0; i < 50; i++) {
				SSD_Display_2_Numbers(t);
			}
		}
		
		DIO_u8SetPinValue(DIO_PORT_C, DIO_PIN_2, DIO_PIN_HIGH);
		DIO_u8SetPinValue(DIO_PORT_C, DIO_PIN_1, DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORT_C, DIO_PIN_0, DIO_PIN_LOW);
		for(s8 t = 10; t > 0; t--) {
			for(u8 i = 0; i < 50; i++) {
				SSD_Display_2_Numbers(t);
			}
		}
	}
	return 0;
}