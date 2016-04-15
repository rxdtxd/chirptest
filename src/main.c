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
    uint8_t ret;
    uint8_t data[2];
    uint16_t tmp;
    
//    led_init();
    i2c_init();
    
    // debug
    uart_init();
    stdout = &uart_output;

    while (1) {
	// request read cap reg
	i2c_start(CHIRP_WRITE);
	i2c_write(CHIRP_CAP_REG);
	i2c_stop();

	// not necessary, eh?
	//_delay_us(20);
	
	// 
	ret = i2c_receive(CHIRP_WRITE, data, CHIRP_DATALEN);

	tmp = (uint16_t)data[0]<<8;
	tmp |= (uint16_t)data[1];
	
	printf("i: %u\tret: %u\tdata: %02x %02x (%u)\n",
	       i, ret, data[0], data[1], tmp);
	
	i++;
	_delay_ms(10);
    }

    
    return 0;
}
