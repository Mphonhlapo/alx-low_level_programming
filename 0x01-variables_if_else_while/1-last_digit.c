#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main - Entry point
 * Description: assigns random numbers
 * Return: always 0
 */
int main(void)
{
	int n;
	int ld;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	ld = n % 10;
	if (ld > 5)
	{
		printf("if the last digit of %d is %d and is greater than 5", n, ld);
	}
	else if (ld == 0)
	{
		printf("if the last digit of %d is %d and is 0", n, ld);
	}
	else
	{
		printf("if the last digit of %d is %d and less than 0 and not 0", n, ld);
	}
	return (0);
}
