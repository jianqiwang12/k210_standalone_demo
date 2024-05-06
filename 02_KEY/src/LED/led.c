#include "led.h"
#include "fpioa.h"
#include "gpio.h"

void led_init(void)
{
    gpio_init();

    fpioa_set_function(PIN_LED_G, FUNC_LEDG);
    fpioa_set_function(PIN_LED_R, FUNC_LEDR);
    fpioa_set_function(PIN_LED_B, FUNC_LEDB);

    gpio_set_drive_mode(LEDG_GPIONUM, GPIO_DM_OUTPUT);
    gpio_set_drive_mode(LEDR_GPIONUM, GPIO_DM_OUTPUT);
    gpio_set_drive_mode(LEDB_GPIONUM, GPIO_DM_OUTPUT);

    gpio_set_pin(LEDG_GPIONUM, GPIO_PV_HIGH);
    gpio_set_pin(LEDR_GPIONUM, GPIO_PV_HIGH);
    gpio_set_pin(LEDB_GPIONUM, GPIO_PV_HIGH);
}