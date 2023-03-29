#include "gpio.h"
#include "uart.h"
#include <stdio.h>


int main()
{
    gpio_init();
    uart_init();
    int sleep;
    int light_status = 0;

    while(1){
        if(ubit_button_press_a()){
            uart_send('A');
        }
        if(ubit_button_press_b()){
            uart_send('B');
        }

        if(uart_read() != '\0')
        {
            if(light_status == 1)
            {
                gpio_lights_off();
                light_status = 0;
            }
            else if(light_status == 0)
            {
                gpio_lights_on();
                light_status = 1;
            } 
        }

        sleep = 10000;
		while(--sleep);
    }


    return 0;
}

