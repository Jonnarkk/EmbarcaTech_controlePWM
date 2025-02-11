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
Os valores utilizados neste código foram, em sua maioria, escolhidos através do uso de fórmulas matemáticas
trabalhadas na aula síncrona e materiais complementares. 

- **Frequência**: A frequência de 50Hz foi achada com a fórmula:
<p align = "center">   
<img src="https://github.com/user-attachments/assets/09eeb442-d57d-4ce8-b0d3-54699e6eee6c" width="234" height="74" />
<p>

- **WRAP**: O valor do wrap escolhido foi de 65535, o valor padrão, já que o wrap tem limite de 16 bis (0-65535).

- **DIV_CLOCK**: O valor do divisor de clock foi encontrado com a fórmula usada na frequência, porém com uma manipulação algébrica:
<p align = "center">   
<img src="https://github.com/user-attachments/assets/d350d6b4-efdd-4bb9-a5fc-e84370f2d533" width="164" height="59" />
<p>
Como neste projeto somente foi utilizado a parte inteira do divisor de clock, a fração do divisor fracionário é anulada. Com a substituição dos valores, encontramos um valor aproximado de 38, que foi implementado no código.

- **Valores dos ângulos e STEP**: Os valores das funções `pwm_set_gpio_level` foram extraídos das seguintes fórmulas:
<p align = "center">   
<img src="https://github.com/user-attachments/assets/38a257ec-6bff-408a-a113-788071555851" width="97" height="46" />
<p>
e também  
<p align = "center">   
<img src="https://github.com/user-attachments/assets/d21b5d72-3c24-4fdf-b3e1-10457b464c37" width="180" height="55" />
<p>
dando como resultado 7864 (180°), 4817 (90°), 1638 (0°) e 17 (STEP de 5 µs).

## Link com o vídeo explicativo

## Desenvolvedor
Guilherme Miller Gama Cardoso
