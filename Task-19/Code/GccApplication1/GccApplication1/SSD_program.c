
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SSD_config.h"
#include "SSD_interface.h"
#include "SSD_private.h"

u8 SSD_Cathode [10] = {
	0b00111111, //0
	0b00000110,
	0b01011011,
	0b01001111,
	0b01100110,
	0b01101101,
	0b01111101,
	0b00000111,
	0b01111111,
	0b01101111  //9
};

void SSD_Display_1_Number(u8 number);

void SSD_Display_2_Numbers(u8 number)
{
CLR_BIT(SSD_EN_PORT,SSD_EN1); // EN SSD1
SET_BIT(SSD_EN_PORT,SSD_EN2); // DISABLE SSD2
SSD1_PORT=SSD_Cathode[number/10];
_delay_ms(80);
SET_BIT(SSD_EN_PORT,SSD_EN1); // DISABLE SSD1
CLR_BIT(SSD_EN_PORT,SSD_EN2); // EN SSD2
SSD2_PORT=SSD_Cathode[number%10];
_delay_ms(60);

}