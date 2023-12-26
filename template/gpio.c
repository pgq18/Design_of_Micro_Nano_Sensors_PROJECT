#include "stm32f4xx.h"                  // Device header
#include "gpio.h"

void GPIO_Config(uint32_t RCC_AHB1Periph, uint32_t GPIO_Pin){
	
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_TypeDef* GPIOx;
	
	switch(RCC_AHB1Periph){
		case RCC_AHB1Periph_GPIOA:
			GPIOx = GPIOA;
			break;
		case RCC_AHB1Periph_GPIOB:
			GPIOx = GPIOB;
			break;
		case RCC_AHB1Periph_GPIOC:
			GPIOx = GPIOC;
			break;
		case RCC_AHB1Periph_GPIOD:
			GPIOx = GPIOD;
			break;
		case RCC_AHB1Periph_GPIOE:
			GPIOx = GPIOE;
			break;
		default:
			break;
	}
		
	GPIO_Init(GPIOx, &GPIO_InitStructure);
	
}

void GPIO_Config_PWM(uint32_t RCC_AHB1Periph, uint32_t GPIO_Pin){
	
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_TypeDef* GPIOx;
	
	switch(RCC_AHB1Periph){
		case RCC_AHB1Periph_GPIOA:
			GPIOx = GPIOA;
			break;
		case RCC_AHB1Periph_GPIOB:
			GPIOx = GPIOB;
			break;
		case RCC_AHB1Periph_GPIOC:
			GPIOx = GPIOC;
			break;
		case RCC_AHB1Periph_GPIOD:
			GPIOx = GPIOD;
			break;
		case RCC_AHB1Periph_GPIOE:
			GPIOx = GPIOE;
			break;
		default:
			break;
	}
		
	GPIO_Init(GPIOx, &GPIO_InitStructure);
	
}
