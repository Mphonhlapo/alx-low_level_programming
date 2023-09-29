#include "main.h"

/**
 * clear_bit - sets the value of a specified bit to 0
 * @num_ptr: pointer to the number to modify
 * @bit_index: index of the bit to clear
 *
 * Return: 1 for success, -1 for failure
 */
int clear_bit(unsigned long int *num_ptr, unsigned int bit_index)
{
	if (bit_index > 63)
		return (-1); /* Invalid bit index */

	unsigned long int bitmask = 1UL << bit_index;

	while (bitmask > 0 && bit_index <= 63)
	{
		*num_ptr = (~bitmask) & *num_ptr;
		bitmask >>= 1;
		bit_index++;
	}
	return (1); /* Bit successfully cleared to 0 */
}
