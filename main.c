#include<stm32f10x.h>

int main(void)
	

{
	//Enable GPIOC (peripheral clock) check RM0041 
	//set bit 4 of RCC_APB2ENR register
	
	RCC ->APB2ENR = 0x10;
	
	
	//set GPIOC pin 8 and 9 as outputs
	
	GPIOC -> CRH = 0x33; //general purpose output pushpull ,, output mode with 50MHz frequency
	
	
	while(1)
	{
		
		GPIOC -> BSRR = 0x300; //LED pins to high
		for(int i =0;i<1000000;i++);  //Delay
		
		GPIOC -> BSRR = 0x3000000;  //LED pins to low
		
		for(int i =0;i<1000000;i++);  //Delay
		
		
		
	}
	
	
	//return 0;
}























