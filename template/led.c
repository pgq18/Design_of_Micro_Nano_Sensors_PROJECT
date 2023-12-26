#include "stm32f4xx.h"                  // Device header
#include "led.h"

void LED_Config(void){
	
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);

}

void LED_ON(void){

	GPIO_ResetBits(GPIOA, GPIO_Pin_1);
	
}

void LED_OFF(void){

	GPIO_SetBits(GPIOA, GPIO_Pin_1);
	
}

