#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Defines
#define SERVOMOTORPWM_PIN 22 // Pino do servomotor
#define BLUE_PIN 12 // Pino do LED azul
#define WRAP 65535 // Valor padrão do contador 16 bits
#define MAIOR_ANGULO 7864 // Limite superior do servomotor
#define MENOR_ANGULO 1638 // Limite inferior do servomotor
#define STEP 17 // Passo do incremento ou decremento do ângulo

// Função para inicialização do PWM - f_pwm = 50Hz, T_pwm = 20ms
void pwm_inicial_setup(){
    gpio_set_function(SERVOMOTORPWM_PIN, GPIO_FUNC_PWM); //Configura o pino 22 para funcionar como PWM

    uint slice = pwm_gpio_to_slice_num(SERVOMOTORPWM_PIN); // Salva o slice do pino 22 na variável slice
    pwm_config config = pwm_get_default_config(); // Salvando configuração padrão do PWM na variável config

    pwm_config_set_clkdiv(&config, 38.0); // Configurando o divisor de clock para 38.0 - Nâo utilizei parte fracionária

    pwm_config_set_wrap(&config, WRAP); // Configurando WRAP para 65535

    pwm_init(slice, &config, true); // Inicializando o PWM
}

// Função para inicialização do LED como sinal PWM
void pwm_led_setup(){
    gpio_set_function(BLUE_PIN, GPIO_FUNC_PWM); // Habilita o pino GPIO como PWM

    uint slice = pwm_gpio_to_slice_num(BLUE_PIN); // Obtém o canal PWM da GPIO

    pwm_set_clkdiv(slice, 38.0); // Define o divisor de clock do PWM

    pwm_set_wrap(slice, WRAP); // Define o valor de wrap

    pwm_set_enabled(slice, true); // Habilita o pwm no slice correspondente

}

int main(){
    uint16_t angulo = 1638; // Variável para fazer a movimentação suave do servomotor
    uint8_t up_down = 1; // Variável de controle para inverter rotação do servomotor

    stdio_init_all();
    pwm_inicial_setup();
    pwm_led_setup();

    pwm_set_gpio_level(SERVOMOTORPWM_PIN, 7864); // Ajuste do servo motor para 180°
    pwm_set_gpio_level(BLUE_PIN, 7864); // Ajuste do servo motor para 180°
    printf("180 graus\n");
    sleep_ms(5000);
    pwm_set_gpio_level(SERVOMOTORPWM_PIN, 4817); // Ajuste do servo motor para 90°
    pwm_set_gpio_level(BLUE_PIN, 4817); // Ajuste do servo motor para 90°
    printf("90 graus\n");
    sleep_ms(5000);
    pwm_set_gpio_level(SERVOMOTORPWM_PIN, 1638); // Ajuste do servo motor para 0°
    pwm_set_gpio_level(BLUE_PIN, 1638); // Ajuste do servo motor para 0°
    printf("0 graus\n");
    sleep_ms(5000);

    while (true) {
        pwm_set_gpio_level(SERVOMOTORPWM_PIN, angulo); // Função para alterar o ciclo ativo do período
        pwm_set_gpio_level(BLUE_PIN, angulo); // Função para alterar o ciclo ativo do período
        
        if(up_down){
            printf("Incrementando angulo: %d\n", angulo);
            angulo += STEP;
            if(angulo >= MAIOR_ANGULO) // Verificando se atingiu o limite máximo da angulação
                up_down = 0;
        }
        else{
            printf("Decrementando angulo: %d\n", angulo);
            angulo -= STEP;
            if(angulo <= MENOR_ANGULO) // Verificando se atingiu o limite mínimo da angulação
                up_down = 1;
        }
        sleep_ms(10);
    }

    return 0;
}
