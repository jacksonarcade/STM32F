#include "stm32f10x.h"

int main()
{

	
	//initiate the clock for GPIO C
	RCC->APB2ENR |= (1<<4);   
	
	//configure pin 8 on GPIO C
	
	GPIOC->CRH |= (	(1<<0) | (1<<1));  //output 50MHz
	
	//configure pin9 on GPIO C
	GPIOC->CRH |= (	(1<<4) | (1<<5));  //output 50MHz
	
	GPIOC->CRH &= ~( (1<<2) | (1<<3));
	GPIOC->CRH &= ~( (1<<6) | (1<<7));   //GPIO output

	while(1)
	{
		for (int i = 0; i<=5000000; i++)
	{
		GPIOC->BSRR = (1<<9);		//set pin 9 to high
		GPIOC->BSRR = (1<<(8+16));		//SET pin 8 to low
	}
		for (int i = 0; i<=5000000; i++)
		
	{
	  GPIOC->BSRR = 1<<(9+16);   //set pin 9 to low
		GPIOC->BSRR = 1<<(8);	//set pin 8 to high
	}
	}
	
	
	
	
return 0;	
}






