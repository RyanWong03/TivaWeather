#include "main.h"

/*
 * Initializes the LM45 Temperature sensor on the Alice Edubase Board. It is connected to PE5 & uses AIN8.
 * */
void TempSensorInit()
{
    gpio_port_init(PORTE);

    //Set GPIO Port E Pin 5 to use AFSEL.
    HWREG(GPIOPORTE + GPIOAFSEL) |= (1 << 5);

    //Set GPIO Port E Pin 5 to be analog.
    HWREG(GPIOPORTE + GPIODEN) &= ~(1 << 5);

    //Set GPIO Port E Pin 5 to select GPIO analog mode.
    HWREG(GPIOPORTE + GPIOAMSEL) |= (1 << 5);

    adc_module_init(0);
    configure_PLL();

    //Page 1073 of the datasheet has more information on these arguments.
    adc_sequencer_init(0, 3, (0xF << 12), 8, 2);
}
