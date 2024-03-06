#include <stdbool.h>
#include "nrf.h"
#include "nrf_drv_gpiote.h"
#include "boards.h"

#define PIN_IN BSP_BUTTON_0
#define PIN_OUT BSP_LED_1


void in_pin_handler(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action)
{
    nrf_drv_gpiote_out_toggle(PIN_OUT);
}

static void gpio_init(void)
{

    nrf_drv_gpiote_init();

    nrf_drv_gpiote_out_config_t out_config = GPIOTE_CONFIG_OUT_SIMPLE(true);
    nrf_drv_gpiote_out_init(PIN_OUT, &out_config);
    nrf_drv_gpiote_in_config_t in_config = GPIOTE_CONFIG_IN_SENSE_TOGGLE(true);
    in_config.pull = NRF_GPIO_PIN_PULLUP;

    nrf_drv_gpiote_in_init(PIN_IN, &in_config, in_pin_handler);
    nrf_drv_gpiote_in_event_enable(PIN_IN, true);
}


int main(void)
{
    gpio_init();

    while (true)
    {
        // Do nothing.
    }
}