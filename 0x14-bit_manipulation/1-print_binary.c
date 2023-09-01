#include "main.h"

/*
 * print_binary - Prints the binary representation of a decimal number.
 * @n: The decimal number to be printed in binary.
 */
void print_binary(unsigned long int n)
{
	int i = 63, count = 0;
	unsigned long int current;

	/* Skip leading zeros. */
	while (i >= 0 && !((n >> i) & 1))
	{
		i--;
	}

	/* Iterate through each bit from the most significant to least significant. */
	while (i >= 0)
	{
		current = (n >> i) & 1;

		/* Print the current bit. */
		_putchar(current ? '1' : '0');
		count++;

		i--;
	}

	/* If the number is 0, print a single '0'. */
	if (!count)
		_putchar('0');
}
