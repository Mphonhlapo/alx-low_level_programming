#include <stdio.h>
/*
 * Main - Entry point of aprogram
 *
 * This function is the starting point of the program's execution.
 * It prints the sizes of various data types and returns 0 to indicate successful execution
 * on the computer it is compiled and run on.
 *
 * Return: 0 (Successful)
 */
int main(void)
{
printf("Size of a char: %1d byte(s)\n", (unsigned long) sizeof(char));
printf("Size of an int: %1d byte(s)\n", (unsigned long) sizeof(int));
printf("Size of a long int: %1d"
	       	"byte(s)\n", (unsigned long) sizeof(long int));
printf("Size of a long long int: %1d byte(s)\n", (unsigned long) sizeof(long long int));
printf("Size of a float: %1d byte(s)\n", (unsigned long) sizeof(float));
return (0);
}
