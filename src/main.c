// main.c
// chirptest

#include "pinout.h"

#include <stdbool.h>
#include <util/delay.h>

#include "i2cmaster/i2cmaster.h"
#include "iocontrol.h"
#include "uart.h" // debug terminal

// http://wemakethings.net/chirp/
#define CHIRP_ADDR    (0x20<<1)

// i2c 7-bit addressing shit
#define CHIRP_WRITE   (CHIRP_ADDR+I2C_WRITE)
#define CHIRP_READ    (CHIRP_ADDR+I2C_READ)

#define CHIRP_CAP_REG 0
//#define CHIRP_DATALEN 2


int main (void) {
    uint8_t i = 0;
    uint8_t data[2];
    
//    led_init();
    i2c_init();
    TWSR |= 0x11; // i2c clock 64 times slower
    
    // debug
    uart_init();
    stdout = &uart_output;

    while (1) {
	printf("start %x", CHIRP_WRITE);
	while(!i2c_start(CHIRP_WRITE)) {
	    printf(".");
	    _delay_ms(1);
	}
	printf("\n");

	printf("write %x", CHIRP_CAP_REG);
	i2c_write(CHIRP_CAP_REG);
	printf("\n");

	printf("stop");
	i2c_stop();
	printf("\n");
	
	printf("start %x", CHIRP_WRITE);
	while(!i2c_start(CHIRP_WRITE)) {
	    printf(".");
	    _delay_ms(1);
	}
	printf("\n");

	printf("write %x", CHIRP_CAP_REG);
	i2c_write(CHIRP_CAP_REG);
	printf("\n");

	printf("repstart %x", CHIRP_READ);
	while(!i2c_rep_start(CHIRP_READ)) {
	    printf(".");
	    _delay_ms(1);
	}
	printf("\n");
	
	printf("readack");
	data[0] = i2c_readAck();
	printf("\n");
	
	printf("readnak");
	data[1] = i2c_readNak();
	printf("\n");

	printf("stop");
	i2c_stop();
	printf("\n");
	
	printf(">>> i: %u; data[0]: %u; data[1]: %u\n",
	       i, data[0], data[1]);
	
	i++;
//	_delay_ms(1.0);
    }

    
    return 0;
}
