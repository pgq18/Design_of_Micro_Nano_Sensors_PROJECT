#include "stm32f4xx.h"  
#include <stdio.h>  // 用于文件操作
#include <stdlib.h> // 用于内存操作
#include <string.h>  // 用于字符串操作
#include <float.h>   // 用于浮点数操作
#include <stdint.h>

typedef struct  {

int32_t PWM;
float speed;
float acc;
int time;



} wheel;

void initialize_wheel(wheel *cfg);

void speed_adjustment(wheel *cfg, float speed,  float acc );

void time_reset(wheel *cfg);

void speed_to_PWM(wheel *cfg,float speed);
