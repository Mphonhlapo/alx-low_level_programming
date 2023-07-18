#include <stdio.h>
/**
 * main - Entry point
 * Description - 'Printing lower and upper case latters'
 * Return: Always 0
 */

int main(void)
{
	int n = 97;
	int m = 65;

	while (n < 123)
	{
		putchar(n);
	}
	while (m < 91)
	{
		putchar(m);
	}
	putchar('\n');
	return(0);
