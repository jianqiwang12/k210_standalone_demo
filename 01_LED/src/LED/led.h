#ifndef __LED_H
#define __LED_H

#include <stdio.h>
#include "gpio.h"

/*****************************HARDWARE-PIN*********************************/
/* 硬件IO口，与原理图对应 */
#define PIN_LED_G             (12)
#define PIN_LED_R             (13)
#define PIN_LED_B             (14)

/*****************************SOFTWARE-GPIO********************************/
/* 软件GPIO口，与程序对应 */
#define LEDG_GPIONUM          (0)
#define LEDR_GPIONUM          (1)
#define LEDB_GPIONUM          (2)

/*****************************FUNC-GPIO************************************/
/* GPIO口的功能，绑定到硬件IO口 */
#define FUNC_LEDG             (FUNC_GPIO0 + LEDG_GPIONUM)
#define FUNC_LEDR             (FUNC_GPIO0 + LEDR_GPIONUM)
#define FUNC_LEDB             (FUNC_GPIO0 + LEDB_GPIONUM)

/* IO操作 */
/* x=1时输出高电平，x=0时输出低电平 */
#define LEDG(x)                 do { (x) ?                                     \
                                    gpio_set_pin(LEDG_GPIONUM, GPIO_PV_HIGH):  \
                                    gpio_set_pin(LEDG_GPIONUM, GPIO_PV_LOW);   \
                                } while (0)
#define LEDR(x)                 do { (x) ?                                     \
                                    gpio_set_pin(LEDR_GPIONUM, GPIO_PV_HIGH):  \
                                    gpio_set_pin(LEDR_GPIONUM, GPIO_PV_LOW);   \
                                } while (0)
#define LEDB(x)                 do { (x) ?                                     \
                                    gpio_set_pin(LEDB_GPIONUM, GPIO_PV_HIGH):  \
                                    gpio_set_pin(LEDB_GPIONUM, GPIO_PV_LOW);   \
                                } while (0)


/* 函数声明 */
void led_init(void);     /* 初始化LED */

#endif