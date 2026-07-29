

#ifndef _LCD_CONFIG_H_
#define _LCD_CONFIG_H_

/*
EIGHT_MODE
FOUR_MODE

*/
#define LCD_MODE  FOUR_MODE

#define LCD_CTRL_PORT           DIO_PORT_C

#define LCD_CTRL_RS_PIN         DIO_PIN_5
#define LCD_CTRL_E_PIN          DIO_PIN_7

#define LCD_DATA_PORT           DIO_PORT_D



#if LCD_MODE == FOUR_MODE
#define LCD_DATA_PIN_D4             DIO_PIN_4
#define LCD_DATA_PIN_D5             DIO_PIN_5
#define LCD_DATA_PIN_D6             DIO_PIN_6
#define LCD_DATA_PIN_D7             DIO_PIN_7
#endif




#endif