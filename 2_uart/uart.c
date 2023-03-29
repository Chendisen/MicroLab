#include "uart.h"
#include "gpio.h"


void uart_init()
{
    // Configure UART
    GPIO0->PIN_CNF[6] = 0; // Configure RX as Input
    GPIO1->PIN_CNF[8] = 1; // Configure TX as output

    // Tell the pin positions to the uart.
    UART->PSEL_TXD = 0x6;         
    UART->PSEL_RXD = 0x28;  

    // Correct Baudrate
    UART->BAUDRATE = 0x00275000;

    // Disconnect RTS and CTS
    UART->PSEL_RTS = (0x1 << 31);
    UART->PSEL_CTS = (0x1 << 31);

    // Turn on the UART Module
    UART->ENABLE = 0x4;

    // Start UART Receiver
    UART->TASKS_STARTRX = 0x1;
}


void uart_send(char letter)
{
    UART->TASKS_STARTTX = 0x1;
    
    UART->TXD = letter;
    while(!UART->EVENTS_TXDRDY){
    }
    UART->EVENTS_TXDRDY = 0x0;
    UART->TASKS_STOPTX = 0x1;
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