// main.c
// chirptest

#include "pinout.h"

#include <stdbool.h>
#include <util/delay.h>

#include "I2C-master-lib/i2c_master.h"
#include "iocontrol.h"
#include "uart.h" // debug terminal

// http://wemakethings.net/chirp/
#define CHIRP_ADDR    0x20

// i2c 7-bit addressing shit
#define CHIRP_WRITE   (CHIRP_ADDR<<1)
#define CHIRP_READ    (CHIRP_ADDR<<1)&1

#define CHIRP_CAP_REG 0
#define CHIRP_DATALEN 2


int main (void) {
    uint8_t i = 0;
    uint8_t data[2];
    
//    led_init();
    i2c_init();
    
    // debug
    uart_init();
    stdout = &uart_output;

    while (1) {
	printf("debug start\n");
	i2c_start(CHIRP_WRITE);
	i2c_write(CHIRP_CAP_REG);
	i2c_stop();
	printf("debug stopped\n");
	
	printf("debug receive\n");
	i2c_receive(CHIRP_ADDR, data, CHIRP_DATALEN);
	
	printf("i: %u; data[0]: %u; data[1]: %u\n", i, data[0], data[1]);
	
	i++;
//	_delay_ms(1.0);
    }

    
    return 0;
}
