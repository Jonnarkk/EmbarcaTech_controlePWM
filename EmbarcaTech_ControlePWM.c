#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVOMOTORPWM_PIN 22
#define WRAP 65535

void pwm_inicial_setup(){
    gpio_set_function(SERVOMOTORPWM_PIN, GPIO_FUNC_PWM);

    uint slice = pwm_gpio_to_slice_num(SERVOMOTORPWM_PIN);
    pwm_config config = pwm_get_default_config();

    pwm_config_set_clkdiv(&config, 38.0);

    pwm_config_set_wrap(&config, WRAP);

    pwm_init(slice, &config, true);
}

int main(){
    uint16_t angulo = 1638, up_down = 1, step = 17, M_angulo = 7864, m_angulo = 1638;

    stdio_init_all();
    pwm_inicial_setup();

    pwm_set_gpio_level(SERVOMOTORPWM_PIN, 7864);
    printf("180 graus\n");
    sleep_ms(5000);
    pwm_set_gpio_level(SERVOMOTORPWM_PIN, 4817);
    printf("90 graus\n");
    sleep_ms(5000);
    pwm_set_gpio_level(SERVOMOTORPWM_PIN, 1638);
    printf("0 graus\n");
    sleep_ms(5000);

    while (true) {
        pwm_set_gpio_level(SERVOMOTORPWM_PIN, angulo);
        if(up_down){
            printf("Incrementando angulo: %d\n", angulo);
            angulo += step;
            if(angulo >= M_angulo)
                up_down = 0;
        }
        else{
            printf("Decrementando angulo: %d\n", angulo);
            angulo -= step;
            if(angulo <= m_angulo)
                up_down = 1;
        }
        sleep_ms(10);
    }

    return 0;
}
