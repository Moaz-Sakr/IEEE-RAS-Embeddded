

#ifndef _DIO_REGISTER_H_
#define _DIO_REGISTER_H_


#define REG_PORTA     (*((volatile   u8 * )0X3B))
#define REG_DDRA      (*((volatile   u8 * )0X3A))
#define REG_PINA      (*((volatile   u8 * )0X39))


#define REG_PORTB     (*((volatile   u8 * )0X38))
#define REG_DDRB      (*((volatile   u8 * )0X37))
#define REG_PINB      (*((volatile   u8 * )0X36))


#define REG_PORTC     (*((volatile   u8 * )0X35))
#define REG_DDRC      (*((volatile   u8 * )0X34))
#define REG_PINC      (*((volatile   u8 * )0X33))


#define REG_PORTD     (*((volatile   u8 * )0X32))
#define REG_DDRD      (*((volatile   u8 * )0X31))
#define REG_PIND      (*((volatile   u8 * )0X30))


#endif  //_DIO_REGISTER_H_