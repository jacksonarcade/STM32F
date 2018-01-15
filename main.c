#include "stm32f10x.h"


int main()
	
{
	//RCC - Reset and Clock Control
//APB2 - peripheral clock enable register
//Enable GPIOA and GPIOC pins *See 6.3.7 reference manual pg.91
// 0x14 in binary = 00010100 = [0001][0100] = [IOPF IOPE IOPD IOPC IOPB IOPA Res. AFIO]
RCC ->APB2ENR |= 0x10 | 0x04;
 
//CRH - Port Configuration Register High *pins 8-15
//Set Pin 8 to general purpose output *7.2.2 in reference manual pg. 112
GPIOC ->CRH = 0x01;
 
//CRL - Port Configuration Register Low *pins 0-7
//*on STM32F100RB User button is connected to PA0
//Set Pin A0 to floating input *7.2.1 in reference manual
GPIOA ->CRL = 0x04; //00000100
 
//run forever
while (1)
{
//Read the button
//IDR - Input Data Register
//if pin 0 is HIGH
if((GPIOA ->IDR & 0x1) == 1)
{
    //set Pin 8 HIGH
    //BSRR - Bit Set/Reset
    GPIOC ->BSRR = 1<<8;
}else
{
    //set Pin 8 LOW (Reset)
    GPIOC ->BSRR = 1<<24;
}
}
	
	
}
