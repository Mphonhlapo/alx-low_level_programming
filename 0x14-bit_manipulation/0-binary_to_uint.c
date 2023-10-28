#include "main.h"

/**
 * binary_to_uint - function that converts a binary number to an unsigned int.
 * @b: pointer to a string carrying a binary number
 *
 * Return: unsigned int with decimal value of binary number, or 0 if error
 */
unsigned int binary_to_uint(const char *b)
{
	int a;
	unsigned int num;

	num = 0;
	if (!b)
		return (0);
	a = 0;
	while (b[a] != '\0')
	{
		if (b[a] != '0' && b[a] != '1')
			return (0);
		a++;
	}
	a = 0;
	while (b[a] != '\0')
	{
		num <<= 1;
		if (b[a] == '1')
			num += 1;
		a++;
	}
	return (num);
}
