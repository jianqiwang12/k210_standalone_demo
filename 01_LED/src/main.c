#include <stdio.h>
#include <unistd.h>
#include "./LED/led.h"
#include "gpio.h"
#include "fpioa.h"

int main(void)
{
    led_init();

    while(1)
    {
        LEDG(0);
        LEDR(1);
        LEDB(1);
        sleep(1);

        LEDG(1);
        LEDR(0);
        LEDB(1);
        sleep(1);

        LEDG(1);
        LEDR(1);
        LEDB(0);
        sleep(1);
    }
}