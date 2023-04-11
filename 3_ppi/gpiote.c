#include "gpiote.h"

void gpiote_init() {
    GPIOTE->CONFIG[0] = ((1) | (14 << 8) | (2 << 16) | (0 << 20));
    GPIOTE->CONFIG[1] = ((3) | (28 << 8) | (3 << 16) | (1 << 20));
    GPIOTE->CONFIG[2] = ((3) | (11 << 8) | (3 << 16) | (1 << 20));
    GPIOTE->CONFIG[3] = ((3) | (31 << 8) | (3 << 16) | (1 << 20));
    GPIOTE->CONFIG[4] = ((3) | (5 << 8) | (1 << 13) | (3 << 16) | (1 << 20));
    GPIOTE->CONFIG[5] = ((3) | (30 << 8) | (3 << 16) | (1 << 20));
}