#include "main.h"

/**
 * _pow - Calculates the result of base raised to the power.
 * @base: The base.
 * @power: The power.
 *
 * Return: The result of base^power.
 */
unsigned long int _pow(unsigned int base, unsigned int power)
{
	unsigned long int num;
	unsigned int a;

	num = 1;
	for (a = 1; a <= power; a++)
		num *= base;
	return (num);
}

/**
 * print_binary - Prints a number in binary notation.
 * @n: The number to print in binary.
 *
 * Return: Void (no return value).
 */
void print_binary(unsigned long int n)
{
	unsigned long int divisor, check;
	char flag;

	flag = 0;
	divisor = _pow(2, sizeof(unsigned long int) * 8 - 1);
	for (; divisor != 0; divisor >>= 1)
	{
		check = n & divisor;
		if (check == divisor)
		{
			flag = 1;
			_putchar('1');
		}
		else if (flag == 1 || divisor == 1)
		{
			_putchar('0');
		}
	}
}
