#include "main.h"

/*
 * error_file - Checks if files can be opened and handles errors.
 * @file_from: File descriptor for the source file.
 * @file_to: File descriptor for the destination file.
 * @argv: The arguments vector.
 * Return: No explicit return, but it handles errors and exits if necessary.
 */
void error_file(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}
