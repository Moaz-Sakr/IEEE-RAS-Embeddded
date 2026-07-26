#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

#include "MD_config.h"
#include "MD_interface.h"

void MD_vInit(void)
{
	DIO_u8SetPinDirection(MOTOR_PORT, RM_DIR_PIN, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(MOTOR_PORT, RM_EN_PIN,  DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(MOTOR_PORT, LM_DIR_PIN, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(MOTOR_PORT, LM_EN_PIN,  DIO_PIN_OUTPUT);
	
	MD_vStop();
}

void MD_vStop(void)
{
	DIO_u8SetPinValue(MOTOR_PORT, RM_EN_PIN, DIO_PIN_LOW);
	DIO_u8SetPinValue(MOTOR_PORT, LM_EN_PIN, DIO_PIN_LOW);
}

void MD_vForward(void)
{
	DIO_u8SetPinValue(MOTOR_PORT, RM_DIR_PIN, DIO_PIN_LOW);
	DIO_u8SetPinValue(MOTOR_PORT, LM_DIR_PIN, DIO_PIN_LOW);
	
	DIO_u8SetPinValue(MOTOR_PORT, RM_EN_PIN, DIO_PIN_HIGH);
	DIO_u8SetPinValue(MOTOR_PORT, LM_EN_PIN, DIO_PIN_HIGH);
}

void MD_vBackward(void)
{
	DIO_u8SetPinValue(MOTOR_PORT, RM_DIR_PIN, DIO_PIN_HIGH);
	DIO_u8SetPinValue(MOTOR_PORT, LM_DIR_PIN, DIO_PIN_HIGH);
	
	DIO_u8SetPinValue(MOTOR_PORT, RM_EN_PIN, DIO_PIN_HIGH);
	DIO_u8SetPinValue(MOTOR_PORT, LM_EN_PIN, DIO_PIN_HIGH);
}

void MD_vTurnRight(void)
{
	DIO_u8SetPinValue(MOTOR_PORT, LM_DIR_PIN, DIO_PIN_LOW);
	DIO_u8SetPinValue(MOTOR_PORT, LM_EN_PIN, DIO_PIN_HIGH);
	
	DIO_u8SetPinValue(MOTOR_PORT, RM_DIR_PIN, DIO_PIN_HIGH);
	DIO_u8SetPinValue(MOTOR_PORT, RM_EN_PIN, DIO_PIN_HIGH);
}

void MD_vTurnLeft(void)
{
	DIO_u8SetPinValue(MOTOR_PORT, RM_DIR_PIN, DIO_PIN_LOW);
	DIO_u8SetPinValue(MOTOR_PORT, RM_EN_PIN, DIO_PIN_HIGH);
	
	DIO_u8SetPinValue(MOTOR_PORT, LM_DIR_PIN, DIO_PIN_HIGH);
	DIO_u8SetPinValue(MOTOR_PORT, LM_EN_PIN, DIO_PIN_HIGH);
}