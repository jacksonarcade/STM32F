
//blink the blue and green LED of STM32f1 discovery board value line

#define RCC_APB2ENR (*((unsigned int *) 0x40021018))
#define GPIOC_CRH (*((unsigned int *) 0x40011004))
#define GPIOC_BSRR (*((unsigned int *) 0x40011010))

int main()
{ 
  RCC_APB2ENR = 0x10u;  //Memory location APB2 Peripheral Clock Enable Register     RCC_APB2ENR
  GPIOC_CRH = 0x33u;  //Memory location Port Configuration Register for Px15 -> Px8      GPIOC_CRH
  
  while(1){
  
  GPIOC_BSRR = 0x300u;      //Memory location Port Bit Set/Reset Register GPIOC_BSRR
  for(int i =0;i<1000000;i++);  //Delay         
  GPIOC_BSRR = 0x3000000u;     //Memory location Port Bit Set/Reset Register GPIOC_BSRR
  for(int i =0;i<1000000;i++);  //Delay
  
  
  }
}
