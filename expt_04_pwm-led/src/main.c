/*********************
LED实现呼吸灯效果
*********************/


#include <stdio.h>
#include <syslog.h>
#include <timer.h>
#include <pwm.h>
#include <plic.h>
#include <sysctl.h>
#include <fpioa.h>

#define PIN_LED 14


int timer_callback(void *ctx)
{
    static double cnt = 0.01;
    static int flag = 0;

    pwm_set_frequency(PWM_DEVICE_1, PWM_CHANNEL_0, 200000, cnt);

    if(flag){
        cnt -= 0.01;
    }
    else{
        cnt += 0.01;
    }    

    if(cnt > 1.0)
    {
        cnt = 1.0;
        flag = 1;
    }
    else if (cnt < 0.0)
    {
        cnt = 0.0;
        flag = 0;
    }

    return 0;
}

int main(void)
{
    // 设置IO14为PWM的输出管脚
    fpioa_set_function(PIN_LED, FUNC_TIMER1_TOGGLE1);

    /************************
     * 中断设置步骤:
     * 1. 初始化中断
     * 2. 使能系统中断
    ************************/
    // 1. 中断初始化
    plic_init();
    // 2. 使能系统中断
    sysctl_enable_irq();

    /************************
     * 定时器设置步骤:
     * 1. 初始化定时器
     * 2. 设置定时器间隔
     * 3. 设置定时器中断回调
     * 4. 使能定时器
    ************************/
    // 定时器初始化
    timer_init(TIMER_DEVICE_0);
    // 定时器中断间隔10ms
    timer_set_interval(TIMER_DEVICE_0, TIMER_CHANNEL_0, 1e7);
    // 定时器中断回调
    timer_irq_register(TIMER_DEVICE_0, TIMER_CHANNEL_0, 0, 1, timer_callback, NULL);
    // 使能定时器
    timer_set_enable(TIMER_DEVICE_0, TIMER_CHANNEL_0, 1);

    /************************
     * PWM设置步骤:
     * 1. 初始化PWM
     * 2. 设置PWM频率, 占空比
     * 3. 使能PWM
    ************************/
    // 1. PWM初始化
    pwm_init(PWM_DEVICE_1);
    // 2. PWM频率200kHz
    pwm_set_frequency(PWM_DEVICE_1, PWM_CHANNEL_0, 200000, 0.5);
    // 3. 使能PWM
    pwm_set_enable(PWM_DEVICE_1, PWM_CHANNEL_0, 1);

    while(1);
}