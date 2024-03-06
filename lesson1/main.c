#include <stdint.h>
#include "nrf_delay.h"
#include "nrf_gpio.h"

#define LED_PIN 23

int main(void) {
    // Инициализация GPIO
    nrf_gpio_cfg_output(LED_PIN);

    while (1) {
        // Включение светодиода
        nrf_gpio_pin_set(LED_PIN);
        nrf_delay_ms(500);

        // Выключение светодиода
        nrf_gpio_pin_clear(LED_PIN);
        nrf_delay_ms(500);
    }
}
