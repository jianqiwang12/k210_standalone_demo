#include "key.h"
#include "sleep.h"
#include "fpioa.h"

void key_init(void)
{
    fpioa_set_function(PIN_KEY, FUNC_KEY);
    
    gpiohs_set_drive_mode(KEY_GPIONUM, GPIO_DM_INPUT_PULL_UP);  //输入上拉
}

/**
 * @brief       按键扫描函数
 * @note        
 * @param       mode:0 / 1, 具体含义如下:
 *   @arg       0,  不支持连续按(当按键按下不放时, 只有第一次调用会返回键值,
 *                  必须松开以后, 再次按下才会返回其他键值)
 *   @arg       1,  支持连续按(当按键按下不放时, 每次调用该函数都会返回键值)
 * @retval      键值, 定义如下:
 *              KEY_PRES, 1, KEY按下
 */
uint8_t key_scan(uint8_t mode)
{
    static uint8_t key_up = 1;  //按键松开标志
    uint8_t keyval = 0;

    if(mode) key_up = 1;   //支持连按

    if(key_up && KEY == 0)    //按键松开标志为1，且按键按下
    {
        msleep(50); //去抖动
        key_up = 0;

        if(KEY == 0) keyval = KEY_PRES;
    }
    else if(KEY == 1)   //没有按键按下，按键松开标志为0
    {
        key_up = 0;
    }
    
    return keyval;  //返回按键值

}