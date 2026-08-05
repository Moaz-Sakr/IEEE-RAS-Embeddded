
#define F_CPU 16000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_STATE.h"

#include "DIO_interface.h"

#include "LCD_config.h"
#include "LCD_private.h"
#include "LCD_interface.h"

static void send_4bits(u8 data_bits)
{
	DIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_D4,GET_BIT(data_bits,4));
	DIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_D5,GET_BIT(data_bits,5));
	DIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_D6,GET_BIT(data_bits,6));
	DIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_D7,GET_BIT(data_bits,7));
}

static void send_enable_pulse(void)
{
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_CTRL_E_PIN,DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_CTRL_E_PIN,DIO_PIN_LOW);


}

void LCD_voidSendData(u8 copy_u8Data)
{
	/*CTRL PINS*/
	/*1- RS: data = 1    command = 0 */
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_CTRL_RS_PIN,DIO_PIN_HIGH);
	/*2- RW: read = 1 write = 0 */
	
	#if LCD_MODE == EIGHT_MODE
	
	/*3- Send Data :  8 bit of data  */
	DIO_u8SetPortValue(LCD_DATA_PORT,copy_u8Data);
	/*4- Send Enable pules   HIGH then delay  " to send data " then LOW*/
	send_enable_pulse();
	
	#elif LCD_MODE == FOUR_MODE
	
	send_4bits(copy_u8Data);
	send_enable_pulse();
	send_4bits(copy_u8Data<<4);
	send_enable_pulse();
	

	#else
	#error "please enter lcd mode"
	#endif

}

void LCD_voidSendCommand(u8 copy_u8Command)
{
	
	/*CTRL PINS*/
	/*1- RS: data = 1    command = 0 */
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_CTRL_RS_PIN,DIO_PIN_LOW);
	/*2- RW: read = 1 write = 0 */
	#if LCD_MODE == EIGHT_MODE

	/*3- Send Data :  8 bit of data  */
	DIO_u8SetPortValue(LCD_DATA_PORT,copy_u8Command);
	/*4- Send Enable pules   HIGH then delay  " to send data " then LOW*/
	send_enable_pulse();

	#elif LCD_MODE == FOUR_MODE

	send_4bits(copy_u8Command);
	send_enable_pulse();
	send_4bits(copy_u8Command<<4);
	send_enable_pulse();
	

	#else
	#error "please enter lcd mode"
	#endif

}
void LCD_voidInit(void)
{
	
	/* LCD*/
	/* RS B1: OUTPUT*/
	DIO_u8SetPinDirection(LCD_CTRL_PORT,LCD_CTRL_RS_PIN,DIO_PIN_OUTPUT);
	
	/* E  B2: OUTPUT*/
	DIO_u8SetPinDirection(LCD_CTRL_PORT,LCD_CTRL_E_PIN,DIO_PIN_OUTPUT);
	
	/* 1- Wait for more than 30 ms */
	_delay_ms(40);
	
	#if LCD_MODE == EIGHT_MODE


	DIO_u8SetPortDirection(LCD_DATA_PORT,DIO_PORT_DIR_OUTPUT);
	





	/* 2- Function set  0b0011NFXX  (N = 1) 2-LINES    , (F = 1) 5*11    */
	LCD_voidSendCommand(0b00111100);

	
	#elif LCD_MODE == FOUR_MODE

	/* DATA C0->C7 : OUTPUT*/
	//
	DIO_u8SetPinDirection(LCD_DATA_PORT,LCD_DATA_PIN_D4,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_DATA_PORT,LCD_DATA_PIN_D5,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_DATA_PORT,LCD_DATA_PIN_D6,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_DATA_PORT,LCD_DATA_PIN_D7,DIO_PIN_OUTPUT);



	/* 2- Function set  0b0011NFXX  (N = 1) 2-LINES    , (F = 1) 5*11    */

	send_4bits(0b00100000);
	send_enable_pulse();
	send_4bits(0b00100000);
	send_enable_pulse();
	send_4bits(0b11000000);
	send_enable_pulse();



	#else
	#error "please enter lcd mode"
	#endif
	
	/* 3- Display on/ off  0b00001DCB   Display=1 0n    cursor = 1 on    blink = 0 0FF*/
	LCD_voidSendCommand(0b00001110);
	
	/* 4- Display Clear */
	LCD_voidSendCommand(1);
	
	/* 5-Entry mode */
	LCD_voidSendCommand(0b00000110);

	
}
void LCD_voidSendString(const char *string)
{
	while(*string != '\0')
	LCD_voidSendData(*string++);
}


u8 LCD_u8SendPosition(u8 col_pos,u8 row_pos)
{
	u8 local_err_state=OK;
	u8 DDRAM_address=0;
	switch(row_pos)
	{
		case 0 : DDRAM_address=col_pos;        LCD_voidSendCommand(128+DDRAM_address);   break;
		case 1 : DDRAM_address=col_pos+0x40;   LCD_voidSendCommand(128+DDRAM_address); break;
		default: local_err_state=NOK; break;
	}


	return local_err_state;
}
void LCD_writeNumber(u32 number)
{
	u32 local_reversed=1;

	if(number==0)
	{
		LCD_voidSendData('0');
	}
	else
	{
		//Reverse Number
		while (number != 0)
		{
			local_reversed=local_reversed*10 + (number%10);
			number/=10;
		}
		
		do
		{
			LCD_voidSendData((local_reversed % 10) + '0');
			local_reversed/=10;
		}
		while(local_reversed != 1);
	}
}
