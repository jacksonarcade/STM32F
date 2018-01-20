#include "stm32f10x.h"

int main(void)
	
{
	
	RCC->APB2ENR |= (1<<4);		//initialize the clk for GPIOC
	
	//Configure Pin 8 and Pin9 output with 50MHz
	GPIOC -> CRH |= ((1<<0) | (1<<1) | (1<<4) |(1<<5) );
	
	
	GPIOC -> CRH &= ~((1<<2) | (1<<3) | (1<<6) | (1<<7)); //general purpose output
	
	
	
	
	
	while(1)
		
	{
		GPIOC -> BSRR = ((1<<8)|(1<<9));
		for(int i=0;i<5000000;i++);
		GPIOC -> BSRR = (1<<(16+8)) | (1<<(16+9));
		for(int i=0;i<5000000;i++);
		
	}
	
	
	
}

