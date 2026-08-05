



#ifndef _LCD_PRIVATE_H_
#define _LCD_PRIVATE_H_


#define EIGHT_MODE  1
#define FOUR_MODE   2

static void send_4bits(u8 data_bits);
static void send_enable_pulse(void);
#endif