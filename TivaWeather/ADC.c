//Custom includes
#include "main.h"

void configure_PLL()
{
    //Powerup the PLL
    (*((volatile uint32_t *)(0x400FE160))) |= (1 << 23);

    //Wait for PLL to be locked.
    while(*((volatile uint32_t*)(0x400FE168)) != 1) {}

    //Disable the PLL.
    (*((volatile uint32_t *)(0x400FE160))) &= ~(1 << 23);
}

void adc_module_init(int module_id)
{
    //Enable the ADC clock using the RCGCADC register
    (*((volatile uint32_t *)(RCGCADC))) |= (1 << module_id);
}

void adc_sequencer_init(int module_id, int sequencer_id, int trigger_event, int input_source, int sample_control)
{
    uint32_t adc_addr = ADC_BASE + (0x1000 * module_id);

    //Disable the sequencer
    (*((volatile uint32_t *)(adc_addr))) &= ~(1 << sequencer_id);

    //Set sequencer triggering event.
    (*((volatile uint32_t *)(adc_addr + 0x014))) |= trigger_event;

    //Select input source.
    if(input_source > 15) (*((volatile uint32_t *)(0x400390B8))) |= 1;
    (*((volatile uint32_t *)(adc_addr + 0x080))) = input_source;

    //Configure sample control bits. Setting END bit is important.
    (*((volatile uint32_t *)(adc_addr + 0x084))) |= sample_control;

    //Configuration done. Enable SS3.
    (*((volatile uint32_t *)(adc_addr))) |= (1 << sequencer_id);
}
