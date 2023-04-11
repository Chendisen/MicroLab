#include "gpio.h"
#include "uart.h"
#include <stdio.h>
#include <newlib.h>

ssize_t _write(int fd, const void *buf, size_t count){
    char * letter = (char *)(buf);
    for(int i = 0; i < count; i++){
        uart_send(*letter);
        letter++;
        }
    return count;
}

ssize_t _read(int fd, void *buf, size_t count){
    char *str = (char *)(buf);
    char letter;
    do {
        letter = uart_read();
    } while(letter == '\0');
    *str = letter;
    return 1;
}

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
            iprintf("The average grade in TTK%d was in %d and %d: %c\n\r",4235,2019,2018,'C');
        }

        /*int var0 = 0;
        scanf("%d", &var0);

        int var1 = 0;
        scanf("%d", &var1);

        iprintf("The product of %d and %d is %d", var0, var1, var0*var1);*/

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

