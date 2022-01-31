#include "stm32l4xx.h"


int main()
{
  
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;          //Connect GPIO A to System Clock
  GPIOA->MODER &= ~GPIO_MODER_MODE5;            //Clear Moder 5
  GPIOA->MODER |= GPIO_MODER_MODE5_0;            //set up PA5 as Digital output 
  
  
  //Activate clock ouput
  GPIOA->MODER &= ~GPIO_MODER_MODE8;            //Clear Moder 8
  GPIOA->MODER |= GPIO_MODER_MODE8_1;            //set up PA8 as alternate function mode
  
  //Select and activate MCO in Clock CFGR 
  RCC->CFGR &= ~RCC_CFGR_MCOSEL;        //Clear mask
  RCC->CFGR |= RCC_CFGR_MCOSEL_0;       //SYSCLK system clock selected  
  
  
  
  while(1)
  {
    uint32_t counter = 50000;
    while(--counter);
    GPIOA->ODR ^= GPIO_ODR_OD5;
  }
  
  //return 0;
}
