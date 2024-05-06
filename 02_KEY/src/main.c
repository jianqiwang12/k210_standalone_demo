#include <stdio.h>
#include <unistd.h>
#include <sleep.h>
#include "./KEY/key.h"
#include "./LED/led.h"

int main(void)
{
    uint8_t key;

    led_init();
    key_init();

    while(1)
    {
        key = key_scan(0);

        if(key == 1)
        {
            LEDR(0);
            LEDG(1);
            LEDB(1);
        }
        else
        {
            msleep(10);
        }
    }
}