#ifndef LCD_H_
#define LCD_H_

#define RCGCSSI 0x400FE61C
#define SSI3    0x4000B000

#define SSICR0  0x000
#define SSICR1  0x004
#define SSIDR   0x008
#define SSISR   0x00C
#define SSICPSR 0x010
#define SSICC   0xFC8

#define LCD_DISPLAY_OFF 0x28

void LCD_init();
void unlatch_CS_LCD();
void latch_CS_LCD();
void poll_tx_buffer();
void poll_transmission_complete();
void send_LCD_command(int command);

#endif /* LCD_H_ */
