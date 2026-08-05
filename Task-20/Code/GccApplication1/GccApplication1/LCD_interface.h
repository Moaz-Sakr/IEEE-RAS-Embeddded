


#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_

#define LCD_CLEAR   1
#define LCD_RETURN_HOME   2


void LCD_voidSendData(u8 copy_u8Data);
void LCD_voidSendCommand(u8 copy_u8Command);
void LCD_voidInit(void);
void LCD_voidSendString(const char *string);
u8 LCD_u8SendPosition(u8 col_pos,u8 row_pos);

void LCD_writeNumber(u32 number);

#endif