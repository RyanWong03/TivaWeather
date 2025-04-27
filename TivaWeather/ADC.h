#ifndef DEFS_H_
#define DEFS_H_

#define RCGCADC     0x400FE638
#define ADC_BASE    0x40038000
#define ADCSSFIFO3  0xA8

void configure_PLL();
void adc_module_init(int module_id);
void adc_sequencer_init(int module_id, int sequencer_id, int trigger_event, int input_source, int sample_control);

#endif /* DEFS_H_ */
