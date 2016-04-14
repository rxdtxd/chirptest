// main.c
// chirptest

#include "pinout.h"

#include <stdbool.h>
#include <util/delay.h>
#include <util/twi.h>   // i2c

//#include "i2c.h"
#include "iocontrol.h"
#include "uart.h" // debug terminal


int main (void) {
    uint8_t i = 0;
    
    led_init();
//    i2c_init();
    
    // debug
    uart_init();
    stdout = &uart_output;

    while (1) {
	printf("i: %u\n", i);
	i++;
	_delay_ms(1.0);
    }
    
    return 0;
}
