#include <stdio.h>
#include <unistd.h>
#include "fpioa.h"
#include "gpio.h"

int main(void)
{
    fpioa_set_function(12, FUNC_GPIO3);

    gpio_init();
    gpio_set_drive_mode(3, GPIO_DM_OUTPUT);
    gpio_pin_value_t value = GPIO_PV_HIGH;
    gpio_set_pin(3, value);
    while (1)
    {
        sleep(1);
        gpio_set_pin(3, value = !value);
    }
    return 0;
}