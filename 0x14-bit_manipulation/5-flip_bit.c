#include "main.h"

/**
 * flip_bits - Counts the number of bits that need to change
 *             to get from one number to another.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits that need to change.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int exclusive = n ^ m;
	int countbit = 0;
	int bit_index = 0;

	while (bit_index < 64)
	{
		if (exclusive & (1UL << bit_index))
			countbit++;
		bit_index++;
	}

	return (countbit);
}
