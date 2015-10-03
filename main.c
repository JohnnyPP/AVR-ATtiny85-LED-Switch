/*
 * main.c
 *
 *  Created on: Oct 3, 2015
 *      Author: JohnnyP
 */

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB |= 1 << PINB3;
	DDRB &= (1 << PINB4);
	PORTB |= 1 << PINB4;

	while(1)
	{
		PORTB ^= 1 << PINB3;

		if(bit_is_clear(PINB, 4))
		{
			_delay_ms(100);
		}
		else
		{
			_delay_ms(500);
		}
	}
}
