# Projeto: Controle de Servomotor com RP2040

Este projeto implementa um sistema de controle de um servomotor utilizando o microcontrolador RP2040. O sistema ajusta a posição do braço do servomotor para ângulos específicos e realiza uma movimentação periódica suave entre os ângulos de 0 e 180 graus.

## Requisitos

Este projeto envolve a configuração do módulo PWM para controlar a posição do servomotor, definindo ciclos ativos específicos para ajustar o ângulo do braço do servomotor. A movimentação do braço é feita de forma suave, com incrementos de ciclo ativo de ±5µs e um atraso de ajuste de 10ms.

## Compilação e Execução

1. Clone o repositório do projeto.
2. Configure o ambiente de desenvolvimento do Raspberry Pi Pico.
3. Compile o código usando o CMake.
4. Carregue o binário no Raspberry Pi Pico ou simule usando o simulador Wokwi.

## Estrutura do Código

### Função **pwm_setup**
A função **pwm_setup** é responsável por configurar o módulo PWM no pino GPIO 22. Ela define o divisor de clock, o valor de wrap e habilita o PWM no slice correspondente.

### Função **main**
A função **main** inicializa o sistema padrão de I/O, configura o módulo PWM e ajusta o ciclo ativo do PWM para diferentes valores, aguardando 5 segundos em cada posição. Em seguida, entra em um loop infinito onde movimenta o braço do servomotor suavemente entre os ângulos de 0 e 180 graus.

### Movimentação Suave do Servomotor
Para realizar a movimentação suave do braço do servomotor, o código ajusta o ciclo ativo do PWM em incrementos de ±5µs com um atraso de ajuste de 10ms. Isso garante que a movimentação do braço seja gradual e precisa.

### Link para o vídeo de explicação
https://youtu.be/wdP8S_vaVVg