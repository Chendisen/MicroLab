#include "uart.h"
#include "gpio.h"


void uart_init()
{
    // Configure UART
    GPIO0->PIN_CNF[6] = 1; // Configure RX as Input
    GPIO1->PIN_CNF[8] = 0; // Configure TX as output

    // Tell the pin positions to the uart.
    UART->PSEL_RXD = 6;  
    UART->PSEL_TXD = 40;         


    // Correct Baudrate
    UART->BAUDRATE = 0x00275000;

    // Disconnect RTS and CTS
    UART->PSEL_RTS = (1 << 31);
    UART->PSEL_CTS = (1 << 31);

    // Turn on the UART Module
    UART->ENABLE = 4;

    // Start UART Receiver
    UART->TASKS_STARTRX = 1;
}


void uart_send(char letter)
{
    UART->TASKS_STARTTX = 1;
    
    while(!UART->EVENTS_TXDRDY){
        continue;
    }
    UART->TXD = letter;
    UART->TASKS_STOPTX = 1;
}

char uart_read()
{
    UART->TASKS_STARTRX = 1;

    if(UART->EVENTS_RXDRDY){
        UART->EVENTS_RXDRDY = 0;
        char letter = (char)UART->RXD;
        return letter;
    }

    return '\0';
}