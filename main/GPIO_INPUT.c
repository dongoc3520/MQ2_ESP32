#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
//#include "led_strip.h"
#include "sdkconfig.h"
#include "driver/gpio.h"

// uint64_t pin_bit_mask;        /*!< GPIO pin: set with bit mask, each bit maps to a GPIO */
// gpio_mode_t mode;             /*!< GPIO mode: set input/output mode                     */
// gpio_pullup_t pull_up_en;     /*!< GPIO pull-up                                         */
// gpio_pulldown_t pull_down_en; /*!< GPIO pull-down                                       */
// gpio_int_type_t intr_type;    /*!< GPIO interrupt type                                  */
void app_main(void)
{
    gpio_config_t GPIO_config = {};
    GPIO_config.pin_bit_mask = (1 << 23);
    GPIO_config.mode = GPIO_MODE_OUTPUT;
    GPIO_config.pull_up_en = GPIO_PULLDOWN_DISABLE;
    GPIO_config.pull_down_en = GPIO_PULLDOWN_DISABLE;
    GPIO_config.intr_type = GPIO_INTR_DISABLE;
    gpio_config(&GPIO_config);
    GPIO_config.pin_bit_mask = (1 << 22);
    GPIO_config.mode = GPIO_MODE_INPUT;
    GPIO_config.pull_up_en = GPIO_PULLDOWN_ENABLE;
    gpio_config(&GPIO_config);
    while (1)
    {
        if ( gpio_get_level(22) == 0)
        {
            gpio_set_level(23,1);
        }
        else{
            gpio_set_level(23, 0);
        }
    }
}
