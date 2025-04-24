#ifndef GPIO_H_
#define GPIO_H_

#define RCGCGPIO    0x400FE608

#define GPIOPORTA   0x40058000
#define GPIOPORTE   0x4005C000
#define GPIOPORTK   0x40061000
#define GPIOPORTP   0x40065000
#define GPIOPORTQ   0x40066000

#define GPIODATA    0x3FC
#define GPIODIR     0x400
#define GPIOAFSEL   0x420
#define GPIODEN     0x51C
#define GPIOAMSEL   0x528
#define GPIOPCTL    0x52C

#define PORTA       0x1
#define PORTE       0x10
#define PORTK       0x200
#define PORTP       0x2000
#define PORTQ       0x4000

void gpio_port_init(int port);

#endif /* GPIO_H_ */
