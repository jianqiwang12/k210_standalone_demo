/*********************
 * 定时器定时1s
 * 间隔1s输出 “one second OK!”
*********************/


#include <stdio.h>
#include <timer.h>
#include <plic.h>
#include <sysctl.h>

int timer_callback(void *ctx)
{
    printf("one second OK!\n");

    return 0;
}

int main(void)
{
    /*********************
     * 中断设置步骤：
     * 1. 初始化中断
     * 2. 使能系统中断
    *********************/
    // 1. 中断初始化
    plic_init();
    // 2. 使能系统中断
    sysctl_enable_irq();

    /*********************
     * 定时器设置步骤：
     * 1. 初始化定时器
     * 2. 设置定时器间隔
     * 3. 设置定时器中断回调
     * 4. 使能定时器
    *********************/
    // 1. 定时器初始化
    timer_init(TIMER_DEVICE_0);
    // 2. 定时器中断间隔1s
    timer_set_interval(TIMER_DEVICE_0, TIMER_CHANNEL_0, 1e9);
    // 3. 定时器中断回调
    timer_irq_register(TIMER_DEVICE_0, TIMER_CHANNEL_0, 0, 1, timer_callback, NULL);
    // 4. 使能定时器
    timer_set_enable(TIMER_DEVICE_0, TIMER_CHANNEL_0, 1);

    while(1);

}