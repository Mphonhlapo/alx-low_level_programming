#include "main.h"

/**
 * set_bit - sets a bit at a specified index to 1
 * @decimal_number: pointer to the number to modify
 * @bit_index: index of the bit to set to 1
 *
 * Return: 1 for success, -1 for failure
 */
int set_bit(unsigned long int *decimal_number, unsigned int bit_index)
{
	if (bit_index > 63)
		return (-1); /* Invalid bit index */

	*decimal_number = ((1UL << bit_index) | *decimal_number);
	return (1); /* Bit successfully set to 1 */
}
