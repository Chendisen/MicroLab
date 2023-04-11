#include "gpio.h"

void gpio_init() {
    GPIO0->PIN_CNF[14] = 0x0; // button A

    GPIO0->PIN_CNF[21] = 1; //Row 1
	GPIO0->PIN_CNF[22] = 1; //Row 2
	GPIO0->PIN_CNF[15] = 1; //Row 3
	GPIO0->PIN_CNF[24] = 1; //Row 4
	GPIO0->PIN_CNF[19] = 1; //Row 5

    GPIO0->OUTSET = (1<<21);
    GPIO0->OUTSET = (1<<22);
    GPIO0->OUTSET = (1<<15);
    GPIO0->OUTSET = (1<<24);
    GPIO0->OUTSET = (1<<19);

    GPIO0->PIN_CNF[28] = 1;
    GPIO0->PIN_CNF[11] = 1;
    GPIO0->PIN_CNF[31] = 1;
    GPIO1->PIN_CNF[5] = 1;
    GPIO0->PIN_CNF[30] = 1;

    GPIO0->OUTCLR = ((1 << 28) | (1 << 11) | (1 << 31) | (1 << 30));
    GPIO1->OUTCLR = (1 << 5);
}