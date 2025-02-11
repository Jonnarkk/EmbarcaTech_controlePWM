# EmbarcaTech_controlePWM

## Descrição
Este projeto consiste na utilização do PWM (Pulse Width Modulation) para controlar o movimento de um servomotor, além de manipular a intensidade do LED RGB presente
na placa BigDogLab.

## Estrutura do Código
O código está organizado em funções principais de configuração e ajuste do PWM:

- `void pwm_inicial_setup()`: Inicializa o PWM para o servomotor de modo modularizado.
- `void pwm_led_setup()`: Inicializa o PWM para o LED de modo modularizado.
- `gpio_set_function(gpio, GPIO_FUNC_PWM)`: Configura o pino desejado para agir sob PWM.
- `pwm_gpio_to_slice_num(gpio)`: Obtém o canal PWM da GPIO desejada.
- `pwm_set_clkdiv(slice, 38.0)`: Configura o divisor de clock para o slice especificado.
- `pwm_set_wrap(slice, WRAP)`: Configura o valor do wrap. 
- `pwm_set_enabled(slice, true)`: Habilita o PWM no slice especificado.

## Matemática envolvida

## Link com o vídeo explicativo

## Desenvolvedor
Guilherme Miller Gama Cardoso
