/************************
按下按键后，LED亮，串口输出“LED ON”；
松开按键后，LED灭，串口输出“LED OFF”。
*************************/

#include <stdio.h>
#include <unistd.h>
#include "fpioa.h"
#include "gpiohs.h"
#include "sysctl.h"

#define PIN_LED 14
#define PIN_KEY 16

#define GPIO_LED 3
#define GPIO_KEY 2

uint32_t irq_flag;
uint32_t g_count;

int irq_gpiohs2(void* ctx)
{
    // 获取按键状态
    // 0为按下, 1为断开
    irq_flag = gpiohs_get_pin(GPIO_KEY);
    if(irq_flag){
        printf("LED OFF\n");
    }
    else{
        printf("LED ON\n");
    }

    if (!irq_flag)
        gpiohs_set_pin(GPIO_LED, GPIO_PV_LOW);
    else
        gpiohs_set_pin(GPIO_LED, GPIO_PV_HIGH);
    return 0;
}

int main(void)
{
    // 初始化外部终端
    plic_init();

    // 使能系统终端
    sysctl_enable_irq();

    fpioa_set_function(PIN_LED, FUNC_GPIOHS3);
    gpiohs_set_drive_mode(GPIO_LED, GPIO_DM_OUTPUT);
    gpio_pin_value_t value = GPIO_PV_HIGH;
    gpiohs_set_pin(GPIO_LED, value);

    fpioa_set_function(PIN_KEY, FUNC_GPIOHS2);
    gpiohs_set_drive_mode(GPIO_KEY, GPIO_DM_INPUT_PULL_UP);
    gpiohs_set_pin_edge(GPIO_KEY, GPIO_PE_BOTH);

    gpiohs_irq_register(GPIO_KEY, 1, irq_gpiohs2, &g_count);

    while (1);
}