// main.c
// arduino+chirpsensor

#include "pinout.h"

#include <stdbool.h>
#include <util/delay.h>

#include "i2c.h"
#include "iocontrol.h"
/* #include "uart.h" // debug terminal */


int main (void) {    
    led_init();
    i2c_init();

    /* // debug */
    /* uart_init(); */
    /* stdout = &uart_output; */

    return 0;
}
