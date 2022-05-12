/*
开发板上LED间隔1s闪烁
*/

#include <stdio.h>
#include <unistd.h>
#include "fpioa.h"
#include "gpio.h"

int main(void)
{
<<<<<<< HEAD:k210_standalone-sdk_led/src/main.c
    // FPIOA允许用户将255个内部功能映射到芯片外围的48个自由IO上
    // 设置管脚复用功能
    // MaixDock上IO12是LED_B, IO13是LED_G, IO14是LED_R
    // 将GPIO Pin 3映射到IO12的管脚上
    fpioa_set_function(12, FUNC_GPIO1);
=======
    fpioa_set_function(13, FUNC_GPIO3);
>>>>>>> aab52988ff67a26c87c2148e27c95d4d9c45f24d:led_blink/src/main.c

    // 初始化GPIO
    gpio_init();

    // 设置GPIO驱动模式
    // GPIO_DM_OUTPUT 输入
    gpio_set_drive_mode(1, GPIO_DM_OUTPUT);

    // GPIO值
    gpio_pin_value_t value = GPIO_PV_HIGH;

    // 设置GPIO管脚值
    gpio_set_pin(1, value);

    while (1)
    {
        sleep(1);
        gpio_set_pin(1, value = !value);
    }

    return 0;
}