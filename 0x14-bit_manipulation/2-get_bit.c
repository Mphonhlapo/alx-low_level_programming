#include "main.h"

/**
 * get_bit - returns the value of a bit at a specified index in a number
 * @decimal_number: number to search
 * @bit_index: index of the bit to retrieve
 *
 * Return: value of the bit at the specified index
 */
int get_bit(unsigned long int decimal_number, unsigned int bit_index)
{
	int bit_value;

	if (bit_index > 63)
		return (-1); /* Invalid bit index */

	bit_value = (decimal_number >> bit_index) & 1;

	return (bit_value);
}
