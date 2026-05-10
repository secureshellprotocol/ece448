#include <stdint.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"
#include "hardware/pwm.h"

#define PWM_PIN_H 2
#define PWM_PIN_L 3
#define PWM_WRAP 11773 // this was experimentally determined to be 6KHz
#define DUTY_CYCLE 0.5
#define DEADTIME_PERCENT 0.1 // 10%

int main(void)
{
    stdio_init_all();

    gpio_set_function(PWM_PIN_H, GPIO_FUNC_PWM);
    gpio_set_function(PWM_PIN_L, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(PWM_PIN_H);

    pwm_set_wrap(slice_num, PWM_WRAP);
    pwm_set_output_polarity(slice_num, false, true); // set output
    pwm_set_phase_correct(slice_num, true);

    uint16_t deadtime = (uint16_t)(PWM_WRAP * DEADTIME_PERCENT);
    
    uint16_t level_h = PWM_WRAP * (DUTY_CYCLE - DEADTIME_PERCENT);
    uint16_t level_l = PWM_WRAP * (1 - (DUTY_CYCLE - DEADTIME_PERCENT));

    pwm_set_chan_level(slice_num, PWM_CHAN_A, level_h);
    pwm_set_chan_level(slice_num, PWM_CHAN_B, level_l);
    pwm_set_clkdiv(slice_num, 1.0f);
    pwm_set_enabled(slice_num, true);

    while(1)
    {
        tight_loop_contents();
    }
}
