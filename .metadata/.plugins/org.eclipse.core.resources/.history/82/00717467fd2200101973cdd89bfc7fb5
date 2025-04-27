#include "main.h"

/**
 * main.c
 */
int main(void)
{
    TempSensorInit();
    UART0_init();

    while(1){
        volatile uint32_t* ADC_reading = (volatile uint32_t*)(ADC_BASE + ADCSSFIFO3);
        float voltage = (*ADC_reading * 3.3) / 4096;
        int celsius_temp = voltage * 100;   //Truncate fractional port for simplicity.
        char string[5];
        char* stringcpy = string;
        int2string(string, celsius_temp);

        char *info = "\nTemperature in Celsius: ";
        output_string(info);
        output_string(stringcpy);

        int a = 0;
        for(a = 0; a < 5000000; a++){}
    }
	return 0;
}
