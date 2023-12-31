#include "stm32f4xx.h"                  // Device header
#include "gpio.h"
#include "car_speed.h"
#include "delay.h"

int car_speed;

void PWM_Config(void){
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	GPIO_Config_PWM(RCC_AHB1Periph_GPIOA, GPIO_Pin_15);  // PWM ch1
	GPIO_Config_PWM(RCC_AHB1Periph_GPIOA, GPIO_Pin_2);  // PWM ch3
	GPIO_Config_PWM(RCC_AHB1Periph_GPIOA, GPIO_Pin_3);  // PWM ch4
	GPIO_Config_PWM(RCC_AHB1Periph_GPIOB, GPIO_Pin_3); // PWM ch2
	
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource15, GPIO_AF_TIM2);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_TIM2);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_TIM2);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource3, GPIO_AF_TIM2);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Prescaler = 36-1;     
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;       
  TIM_TimeBaseStructure.TIM_Period = 100-1;            
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;     
  TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	
	TIM_OCInitTypeDef TIMOC1_Initstruture;
	TIM_OCStructInit(&TIMOC1_Initstruture);
	TIMOC1_Initstruture.TIM_OCMode=TIM_OCMode_PWM1;
	TIMOC1_Initstruture.TIM_OCPolarity=TIM_OCNPolarity_High;
	TIMOC1_Initstruture.TIM_OutputState= TIM_OutputState_Enable;
	TIMOC1_Initstruture.TIM_Pulse=0;
	TIM_OC1Init(TIM2,&TIMOC1_Initstruture);
	TIM_OC2Init(TIM2,&TIMOC1_Initstruture);
	TIM_OC3Init(TIM2,&TIMOC1_Initstruture);
	TIM_OC4Init(TIM2,&TIMOC1_Initstruture);
	
	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);
	TIM_ARRPreloadConfig(TIM2, ENABLE);
	
	TIM_Cmd(TIM2,ENABLE);
	
	// 1
	GPIO_Config(RCC_AHB1Periph_GPIOE, GPIO_Pin_4);
	GPIO_Config(RCC_AHB1Periph_GPIOE, GPIO_Pin_6);
	
	// 2
	GPIO_Config(RCC_AHB1Periph_GPIOA, GPIO_Pin_7);
	GPIO_Config(RCC_AHB1Periph_GPIOA, GPIO_Pin_5);
	
	// 3
	GPIO_Config(RCC_AHB1Periph_GPIOC, GPIO_Pin_0);
	GPIO_Config(RCC_AHB1Periph_GPIOC, GPIO_Pin_2);
	
	// 4
	GPIO_Config(RCC_AHB1Periph_GPIOA, GPIO_Pin_6); 
	GPIO_Config(RCC_AHB1Periph_GPIOA, GPIO_Pin_4); 
	
}

void Speed_Set1(int32_t speed){
	if (speed >= 0) {
		GPIO_ResetBits(GPIOE, GPIO_Pin_4);
		//GPIO_SetBits(GPIOE, GPIO_Pin_4);
		//GPIO_ResetBits(GPIOE, GPIO_Pin_6);
		GPIO_SetBits(GPIOE, GPIO_Pin_6);
		TIM_SetCompare4(TIM2, speed);
	}
	else {
		//GPIO_ResetBits(GPIOE, GPIO_Pin_4);
		GPIO_SetBits(GPIOE, GPIO_Pin_4);
		GPIO_ResetBits(GPIOE, GPIO_Pin_6);
		//GPIO_SetBits(GPIOE, GPIO_Pin_6);
		TIM_SetCompare4(TIM2, -speed);
	}
}

void Speed_Set2(int32_t speed){
	if (speed >= 0) {
		GPIO_ResetBits(GPIOA, GPIO_Pin_7);
		//GPIO_SetBits(GPIOA, GPIO_Pin_7);
		//GPIO_ResetBits(GPIOA, GPIO_Pin_5);
		GPIO_SetBits(GPIOA, GPIO_Pin_5);
		TIM_SetCompare3(TIM2, speed);
	}
	else {
		//GPIO_ResetBits(GPIOA, GPIO_Pin_7);
		GPIO_SetBits(GPIOA, GPIO_Pin_7);
		GPIO_ResetBits(GPIOA, GPIO_Pin_5);
		//GPIO_SetBits(GPIOA, GPIO_Pin_5);
		TIM_SetCompare3(TIM2, -speed);
	}
}

void Speed_Set3(int32_t speed){
	if (speed >= 0) {
		GPIO_ResetBits(GPIOC, GPIO_Pin_0);
		//GPIO_SetBits(GPIOC, GPIO_Pin_0);
		//GPIO_ResetBits(GPIOC, GPIO_Pin_2);
		GPIO_SetBits(GPIOC, GPIO_Pin_2);
		TIM_SetCompare2(TIM2, speed);
	}
	else {
		//GPIO_ResetBits(GPIOC, GPIO_Pin_0);
		GPIO_SetBits(GPIOC, GPIO_Pin_0);
		GPIO_ResetBits(GPIOC, GPIO_Pin_2);
		//GPIO_SetBits(GPIOC, GPIO_Pin_2);
		TIM_SetCompare2(TIM2, -speed);
	}
}

void Speed_Set4(int32_t speed){
	if (speed >= 0) {
		GPIO_ResetBits(GPIOA, GPIO_Pin_6);
		//GPIO_SetBits(GPIOA, GPIO_Pin_6);
		//GPIO_ResetBits(GPIOA, GPIO_Pin_4);
		GPIO_SetBits(GPIOA, GPIO_Pin_4);
		TIM_SetCompare1(TIM2, speed);
	}
	else {
		//GPIO_ResetBits(GPIOA, GPIO_Pin_6);
		GPIO_SetBits(GPIOA, GPIO_Pin_6);
		GPIO_ResetBits(GPIOA, GPIO_Pin_4);
		//GPIO_SetBits(GPIOA, GPIO_Pin_4);
		TIM_SetCompare1(TIM2, -speed);
	}
}

void Speed_Stop_to_Start(void) {
	Speed_Set1(70);
	Speed_Set2(70);
	Speed_Set3(70);
	Speed_Set4(70);
	car_speed = 1;
}

void Speed_Start(void) {
	Speed_Set1(58);
	Speed_Set2(58);
	Speed_Set3(58);
	Speed_Set4(58);
	car_speed = 0;
}

void Speed_Stop(void) {
	Speed_Set1(0);
	Speed_Set2(0);
	Speed_Set3(0);
	Speed_Set4(0);
	car_speed = -1;
}

void Speed_Down(void) {
	if(1){
//		Speed_Set1(70);
//		Speed_Set2(70);
//		Speed_Set3(70);
//		Speed_Set4(70);
//		delay_ms(150);
		Speed_Set1(58);
		Speed_Set2(58);
		Speed_Set3(58);
		Speed_Set4(58);
	}
	car_speed = 0;
}

void Speed_Up(void) {
	if(1){
		Speed_Set1(70);
		Speed_Set2(70);
		Speed_Set3(70);
		Speed_Set4(70);
	}
	car_speed = 1;
	
}

void Turn_Left(void) {
	if(car_speed == -1){
		return;
	}
	else if(car_speed == 1){
		Speed_Down();
	}
	Speed_Set1(65);
	Speed_Set2(90);
	Speed_Set3(65);
	Speed_Set4(90);
	delay_ms(500); // turn left
	Speed_Set1(58);
	Speed_Set2(58);
	Speed_Set3(58);
	Speed_Set4(58);
	car_speed = 0;
}

void Turn_Right(void) {
	if(car_speed == -1){
		return;
	}
	else if(car_speed == 1){
		Speed_Down();
	}
	Speed_Set1(90);
	Speed_Set2(65);
	Speed_Set3(90);
	Speed_Set4(65);
	delay_ms(500); // turn right
	Speed_Set1(58);
	Speed_Set2(58);
	Speed_Set3(58);
	Speed_Set4(58);
	car_speed = 0;
}
