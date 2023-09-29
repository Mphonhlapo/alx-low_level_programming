#include "main.h"

/**
 * clear_bit - sets the value of a specified bit to 0
 * @decimal_number: pointer to the number to modify
 * @bit_index: index of the bit to clear
 *
 * Return: 1 for success, -1 for failure
 */
int clear_bit(unsigned long int *decimal_number, unsigned int bit_index)
{
	if (bit_index > 63)
		return (-1); /* Invalid bit index */

	*decimal_number = (~(1UL << bit_index) & *decimal_number);
	return (1); /* Bit successfully cleared to 0 */
}
