#ifndef UART_H_
#define UART_H_

#define UART0FR     0x4000C018
#define UART0DR     0x4000C000
#define RCGCUART    0x400FE618

#define UARTCTL     0x30
#define UARTIBRD    0x24
#define UARTFBRD    0x28
#define UARTCC      0xFC8
#define UARTLCRH    0x2C
#define UART0       0x1
#define UARTIM      0x38
#define UARTICR     0x44

void UART0_init();
void output_character(char character);
void output_string(char* string);
void UART0_interrupt_init();
char simple_read_character();
void UART0_Handler();

#endif /* UART_H_ */
