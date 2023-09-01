#include "main.h"

/**
 * set_bit - Sets a specific bit at an index to 1.
 * @n: A pointer to the number to be modified.
 * @index: The index of the bit to set to 1 (0 for least significant bit).
 *
 * Return: 1 for success, -1 for failure (if the index is out of range).
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	/* Set the bit at the specified index to 1 using a bitmask. */
	*n = ((1UL << index) | *n);
	return (1);
}
