#include "main.h"

/**
 * flip_bits - Counts the number of bits to change between two numbers.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits that need to be changed to get from n to m.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		current = exclusive >> i;
		if (current & 1)
			count++;
	}

	return (count);
}
