
#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

 #define DIO_PORT_A         0
 #define DIO_PORT_B         1
 #define DIO_PORT_C         2
 #define DIO_PORT_D         3
 
 #define DIO_PIN_0          0
 #define DIO_PIN_1          1
 #define DIO_PIN_2          2
 #define DIO_PIN_3          3
 #define DIO_PIN_4          4
 #define DIO_PIN_5          5
 #define DIO_PIN_6          6
 #define DIO_PIN_7          7
 
 #define DIO_PIN_INPUT      0
 #define DIO_PIN_OUTPUT     1

 #define DIO_PIN_LOW        0
 #define DIO_PIN_HIGH       1

  #define DIO_PORT_INPUT      0
  #define DIO_PORT_OUTPUT     0XFF
			  
  #define DIO_PORT_LOW        0
  #define DIO_PORT_HIGH       0XFF
  
  
/*return:  error state function with bad behavior return NOK else return OK */
u8 DIO_u8SetPinDirection(u8 copy_u8Port,u8 copy_u8Pin, u8 copy_u8PinDirection);
u8 DIO_u8SetPinValue(u8 copy_u8Port,u8 copy_u8Pin, u8 copy_u8PinValue);
u8 DIO_u8GetPinValue(u8 copy_u8Port,u8 copy_u8Pin, u8 *copy_Pu8ReadValue);
u8 DIO_u8TogglePinValue(u8 copy_u8Port,u8 copy_u8Pin);


u8 DIO_u8SetPortDirection(u8 copy_u8Port, u8 copy_u8PortDirection);
u8 DIO_u8SetPortValue(u8 copy_u8Port, u8 copy_u8PortValue);
u8 DIO_u8GetPortValue(u8 copy_u8Port, u8 *copy_Pu8ReadValue);
u8 DIO_u8TogglePortValue(u8 copy_u8Port);


#endif  //#define _DIO_INTERFACE_H_
