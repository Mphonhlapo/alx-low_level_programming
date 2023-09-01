#include "main.h"

/**
 * clear_bit - Clears the value of a specific bit to 0.
 * @n: A pointer to the number to be modified.
 * @index: The index of the bit to clear (0 for least significant bit).
 *
 * Return: 1 for success, -1 for failure (if the index is out of range).
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	/* Clear the bit at the specified index to 0 using a bitmask. */
	*n = (~(1UL << index) & *n);
	return (1);
}
