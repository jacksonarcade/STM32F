#include<stm32f10x.h>

int main(void)
	

{
	int button;
	
	//Enable GPIOC (peripheral clock) check RM0041 
	//set bit 4 of RCC_APB2ENR register
	
	
	
	RCC ->APB2ENR |= 0x10 | 0x04;
	
	//Enable GPIOA bit2
	
	
	//set GPIOC pin 8 and 9 as outputs
	
	GPIOC -> CRH = 0x33; //general purpose output pushpull ,, output mode with 50MHz frequency
	
	//set GPIOA pin 0 as input
	GPIOA ->CRL = 0x04;
	
	
	
	while(1)
	{
		//read the button
	
	  button = (GPIOA->IDR & 0x1);
		
		if(button == 1)
		{
		
		GPIOC -> BSRR = 0x300; //LED pins to high
			
		}
		//for(int i =0;i<1000000;i++);  //Delay
		else
		{
		GPIOC -> BSRR = 0x3000000;  //LED pins to low
		}
		//for(int i =0;i<1000000;i++);  //Delay
			
	}
	
	
	//return 0;
}

