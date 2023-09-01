#include "main.h"

/**
 * get_bit - Get the bit at a specific index in a number.
 * @n: The number to search.
 * @index: The index of the bit (0 for least significant bit).
 *
 * Return: The bit value (1 or 0) at the specified index,-1 if out of range.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	/* Check if the index is within the valid range (0 to 63). */
	if (index > 63)
		return (-1);

	/* Right-shift 'n' by 'index' and extract the bit value using a bitmask. */
	bit_val = (n >> index) & 1;

	return (bit_val);
}
