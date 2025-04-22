#include "main.h"

void gpio_port_init(int port)
{
    //Enable clock to GPIO Port.
    (*((volatile uint32_t *)(RCGCGPIO))) |= port;
}
