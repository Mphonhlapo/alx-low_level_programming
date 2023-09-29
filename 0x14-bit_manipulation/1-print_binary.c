#include "main.h"

/**
 * print_binary - prints the binary equivalent of a decimal number
 * @decimal_number: number to print in binary
 */
void print_binary(unsigned long int decimal_number)
{
	int bit_position = 63; /* Start from the most significant bit */
	int bit_count = 0;     /* Count the number of printed bits */

	/* Iterate through each bit */
	while (bit_position >= 0)
	{
		/* Get the current bit by shifting and using bitwise AND */
		unsigned long int current_bit = decimal_number >> bit_position;

		if (current_bit & 1)
		{
			_putchar('1'); /* Print '1' if the bit is set */
			bit_count++;
		}
		else if (bit_count)
			_putchar('0'); /*Print '0' if the bit is not set (and after any set bits)*/

			bit_position--; /* Move to the next bit towards the least significant end */
	}

		if (!bit_count)
		_putchar('0'); /* If no bits were set, print '0' */
}
