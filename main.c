/*
 * main.c
 *
 *  Created on: Oct 3, 2015
 *      Author: JohnnyP
 *      https://newbiehack.com/MicrocontrollerAddingabutton.aspx
 */

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	_SFR_IO8(0x17) |= 1 << PINB3;										// DDRB Set pin 3 to output
	(*(volatile uint8_t *)((0x17) + 0x20)) &= ~(1 << PINB4);			// DDRB Set pin 4 to input
	(*(volatile uint8_t *)((0x18) + 0x20)) |= 1 << PINB4;				// PORTB Set pin 4 to high

	while(1)
	{
		// _SFR_IO8(0x18) and
		// (*(volatile uint8_t *)((0x18) + 0x20)) and
		// (*(volatile unsigned char *)((0x18) + 0x20)) are equivalent
		(*(volatile unsigned char *)((0x18) + 0x20)) ^= 1 << PINB3;			// Toggle pin 3 (LED)

		// Test whether bit PINB4 in IO register PINB is clear (Low).
		// This will return TRUE if the bit is clear, and a FALSE if the bit is set (High).
		if(bit_is_clear(PINB, PINB4))
		{
			_delay_ms(100);		// While the button is pressed (Button short-circuits PINB4 to the ground)
		}
		else
		{
			_delay_ms(500);		// While the button is not pressed (PINB4 is set high)
		}
	}
}
