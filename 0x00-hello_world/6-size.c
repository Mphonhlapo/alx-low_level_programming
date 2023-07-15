#include <stdio.h>
/*
 * main -A C program that prints the size of various types on the computer it is compiled and run on.
 * return: 0
 */
int main(void)
{
printf("Size of a char: %1d byte(s)\n", (unsigned long) sizeof(char));
printf("Size of an int: %1d byte(s)\n", (unsigned long) sizeof(int));
printf("Size of a long int: %1d byte(s)\n", (unsigned long) sizeof(long int));
printf("Size of a long long int: %1d byte(s)\n", (unsigned long) sizeof(long long int));
printf("Size of a float: %1d byte(s)\n", (unsigned long) sizeof(float));
return (0);
}
