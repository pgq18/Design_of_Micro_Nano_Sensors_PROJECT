# include "wheel.h"
#include <stdio.h>  // 用于文件操作
#include <stdlib.h> // 用于内存操作
#include <string.h>  // 用于字符串操作
#include <float.h>   // 用于浮点数操作


void initialize_wheel(wheel *cfg){

cfg ->speed = 0;

cfg ->acc = 0;

cfg ->PWM = 0;

cfg -> time = 0;

}

void speed_adjustment(wheel *cfg, float speed ,float acc ){

cfg ->acc = acc;
cfg ->speed = speed -acc;

}

void time_reset(wheel *cfg){

    if (cfg ->time >=10000)
    {
       cfg ->time = 0;
    }


}

void speed_to_PWM(wheel *cfg,float speed){




}
