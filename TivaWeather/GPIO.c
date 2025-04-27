#include "main.h"

void gpio_port_init(int port)
{
    //Enable clock to GPIO Port.
    HWREG(RCGCGPIO) |= port;
}

//Red -> PK4
//Green -> PK5
//Blue -> PM0
void RGB_LED_init()
{
    gpio_port_init(PORTK | PORTM);
    HWREG(GPIOPORTK + GPIODIR) |= (1 << 4) | (1 << 5); // Set PK4 and PK5 as output
    HWREG(GPIOPORTM + GPIODIR) |= (1 << 0); // Set PM0 as output
    HWREG(GPIOPORTK + GPIODEN) |= (1 << 4) | (1 << 5); // Enable digital function for PK4 and PK5
    HWREG(GPIOPORTM + GPIODEN) |= (1 << 0); // Enable digital function for PM0
}

void illuminate_RGB_LED(int color)
{
    // Turn off all LEDs
    HWREG(GPIOPORTK + GPIODATA) &= ~((1 << 4) | (1 << 5)); // Turn off PK4 and PK5
    HWREG(GPIOPORTM + GPIODATA) &= ~(1 << 0); // Turn off PM0

    // Illuminate the selected color
    switch (color)
    {
        case 0: // Red
            HWREG(GPIOPORTK + GPIODATA) |= (1 << 4); // Turn on PK4 (Red)
            break;
        case 1: // Green
            HWREG(GPIOPORTK + GPIODATA) |= (1 << 5); // Turn on PK5 (Green)
            break;
        case 2: // Blue
            HWREG(GPIOPORTM + GPIODATA) |= (1 << 0); // Turn on PM0 (Blue)
            break;
        default:
            break; // Invalid color, do nothing
    }
}