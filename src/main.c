/*  Author  : Fatma                          */
/*  Date    : 29 October 2021                */
/*  version : V1                             */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"
#include "DIO_Interface.h"
#include "OS_interface.h"
#include "OS_interface.h"

void LED1(void);
void LED2(void);
void LED3(void);


void main(void)
{
	/* RCC Initialize */
	MRCC_voidInitSysClock();

	/* GPIOA Enable Clock */
	MRCC_voidEnableClock(APB2 , IOPA);

	/* A0 OUTPUT_SPEED_2MHZ_PP*/
	MGPIO_voidSetPinDirection( GPIOA , PIN0 , OUTPUT_SPEED_2MHZ_PP );
	/* A1 OUTPUT_SPEED_2MHZ_PP*/
	MGPIO_voidSetPinDirection( GPIOA , PIN1 , OUTPUT_SPEED_2MHZ_PP );
	/* A2 OUTPUT_SPEED_2MHZ_PP*/
	MGPIO_voidSetPinDirection( GPIOA , PIN2 , OUTPUT_SPEED_2MHZ_PP );

    /* Create task1 with id=0; periodicity =1000; first delay=0 */
	SOS_voidCreateTask(0,1000,LED1, 0);
	/* Create task2 with id=1; periodicity =2000; first delay=1 */
	SOS_voidCreateTask(1,2000,LED2, 1);
	/* Create task3 with id=2; periodicity =3000; first delay=2 */
	SOS_voidCreateTask(2,3000,LED3, 2);

	//start system
	SOS_voidStart();


	while(1)
	{

	}
}

void LED1(void)
{
	/* toggle local_pin each call*/
	static u8 Local_Pin1=0;
	TOG_BIT(Local_Pin1,0);

	/*set value of local_pin to pin0 */
	MGPIO_voidSetPinValue( GPIOA , PIN0 , Local_Pin1 );
}

void LED2(void)
{
	/* toggle local_pin each call*/
	static u8 Local_Pin2=0;
	TOG_BIT(Local_Pin2,0);

	/*set value of local_pin to pin1 */
	MGPIO_voidSetPinValue(GPIOA , PIN1 , Local_Pin2 );
}

void LED3(void)
{
	/* toggle local_pin each call*/
	static u8 Local_Pin3=0;
	TOG_BIT(Local_Pin3,0);

	/*set value of local_pin to pin2 */
	MGPIO_voidSetPinValue(GPIOA , PIN2 , Local_Pin3 );
}
