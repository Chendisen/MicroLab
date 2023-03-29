#include "gpio.h"
#include "uart.h"


int main(void)
{
    gpio_init();
    uart_init();
    char letter;
    int sleep;

    while(1){
        if(ubit_button_press_a()){
            gpio_lights_on();
            letter = 'A';
            uart_send(letter);
        }
        if(ubit_button_press_b()){
            gpio_lights_off();
            letter = 'B';
            uart_send(letter);
        }

        sleep = 10000;
		while(--sleep);
    }


    return 0;
}

