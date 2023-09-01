#include <stdlib.h>
#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number, or 0 if an error occurs
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int dec_val = 0;

	if (!b)
		return (0);

	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);
		dec_val = (dec_val << 1) | (*b++ - '0');
	}

	return (dec_val);
}

/**
 * my_malloc - Allocate memory using malloc
 * @size: Size of memory to allocate
 *
 * Return: Pointer to allocated memory, or NULL on failure
 */
void *my_malloc(size_t size)
{
	return (malloc(size));
}

/**
 * my_free - Free memory allocated with malloc
 * @ptr: Pointer to memory to free
 */
void my_free(void *ptr)
{
	free(ptr);
}

/**
 * my_exit - Exit the program with a specified status code
 * @status: The status code to return
 */
void my_exit(int status)
{
	exit(status);
}
