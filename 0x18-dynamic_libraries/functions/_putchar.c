#include <unistd.h>
/**
 * _putchar - writes to stdout
 *
 * Return: On success 1
 * On error, -1 is returned, and error is set
 */

int _putchar(char c)
{
	return(write(1, &c, 1));
}

