#ifndef __KEY_H
#define __KEY_H
#include <stdio.h>
#include "gpiohs.h"

/******************************************************************************************/
/* 硬件IO口，与原理图对应 */
#define PIN_KEY              (16)
/*****************************SOFTWARE-GPIO********************************/
/* 软件GPIO口，与程序对应 */
#define KEY_GPIONUM           (0)
/*****************************FUNC-GPIO************************************/
/* GPIO口的功能，绑定到硬件IO口 */
#define FUNC_KEY              (FUNC_GPIOHS0 + KEY_GPIONUM)
/******************************************************************************************/

#define KEY         gpiohs_get_pin(KEY_GPIONUM)      /* 读取KEY引脚 */

#define KEY_PRES    1              /* KEY按下 */

void key_init(void);                /* 按键初始化函数 */
uint8_t key_scan(uint8_t mode);     /* 按键扫描函数 */

#endif