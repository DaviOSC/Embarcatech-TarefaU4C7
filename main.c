#include <stdio.h> //biblioteca padrão da linguagem C
#include "pico/stdlib.h" //subconjunto central de bibliotecas do SDK Pico
#include "hardware/pwm.h" //biblioteca para controlar o hardware de PWM

#define PWM_PIN 22 
const uint16_t WRAP_PERIOD = 20000; //valor máximo do contador - WRAP
const float PWM_DIVISER = 125.0; //divisor do clock para o PWM

//função para configurar o módulo PWM
void pwm_setup()
{
    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM); //habilitar o pino GPIO como PWM

    uint slice = pwm_gpio_to_slice_num(PWM_PIN); //obter o canal PWM da GPIO

    pwm_set_clkdiv(slice, PWM_DIVISER); //define o divisor de clock do PWM

    pwm_set_wrap(slice, WRAP_PERIOD); //definir o valor de wrap

    pwm_set_enabled(slice, true); //habilita o pwm no slice correspondente
}

//função principal
int main()
{
    stdio_init_all(); //inicializa o sistema padrão de I/O
    pwm_setup(); //configura o módulo PWM

    pwm_set_gpio_level(PWM_PIN, 2400); // definir o ciclo de trabalho (duty cycle) do pwm para 2.400µs
    sleep_ms(5000); //esperar 5 segundos

    pwm_set_gpio_level(PWM_PIN, 1470); // definir o ciclo de trabalho (duty cycle) do pwm para 1.470µs
    sleep_ms(5000); //esperar 5 segundos

    pwm_set_gpio_level(PWM_PIN, 500); // definir o ciclo de trabalho (duty cycle) do pwm para 500µs
    sleep_ms(5000); //esperar 5 segundos

    uint16_t duty_cycle = 500; // ciclo inicial de 500µs (0 graus)
    int increment = 5; // incremento de 5µs

    while (true)
    {
        // Movimenta de 0 graus (500µs) para 180 graus (2400µs)
        while (duty_cycle <= 2400)
        {
            pwm_set_gpio_level(PWM_PIN, duty_cycle);
            duty_cycle += increment;
            sleep_ms(10); // atraso de ajuste de 10ms
        }

        // Movimenta de 180 graus (2400µs) para 0 graus (500µs)
        while (duty_cycle >= 500)
        {
            pwm_set_gpio_level(PWM_PIN, duty_cycle);
            duty_cycle -= increment;
            sleep_ms(10); // atraso de ajuste de 10ms
        }
    }
}
