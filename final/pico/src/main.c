#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"
#include "hardware/pwm.h"

#define PWM_PIN 2

int main(void)
{
    stdio_init_all();

    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(PWM_PIN);

    pwm_set_wrap(slice_num, 80);
    pwm_set_chan_level(slice_num, PWM_CHAN_A, 40);
    pwm_set_clkdiv(slice_num, 256.f);
    pwm_set_enabled(slice_num, true);

    while(1)
    {
        tight_loop_contents();
    }
}
