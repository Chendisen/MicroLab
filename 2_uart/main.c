#include "uart.h"
#include "gpio.h"

int main(void)
{
    gpio_init();
    uart_init();
    char letter;
    while(1){
        if(ubit_button_press_a()){
            letter = 'A';
            uart_send(letter);
        }
        if(ubit_button_press_b()){
            letter = 'B';
            uart_send(letter);
        }
    }


    return 0;
}

