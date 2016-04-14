// pin definitions

#ifndef _PINOUT_H_
#define _PINOUT_H_

#include <avr/io.h>

#define F_CPU 16000000UL

// I2C (defines unused ATM)
#define I2C_DDR      DDRC
#define I2C_PORT     PORTC
#define I2C_SDA_PIN  PORTC4 // A4
#define I2C_SCL_PIN  PORTC5 // A5

/* // leds */
/* #define LED_DDR DDRC */
/* #define LED_DD DDC5 */
/* #define LED_PORT PORTC */
/* #define LEDBASE  PORTC5  // A5 */

/* // TODO: move to iocontrol.h? */
/* #define led_init()   LED_DDR |= _BV(LED_DD) */
/* #define led_on()     LED_PORT &= ~(_BV( LEDBASE )) */
/* #define led_off()    LED_PORT |=   _BV( LEDBASE ) */
/* #define led_toggle() LED_PORT ^=   _BV( LEDBASE ) */

#endif /* _PINOUT_H_ */
