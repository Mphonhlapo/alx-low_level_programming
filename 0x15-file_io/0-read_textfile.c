#include "main.h"

/**
 * read_textfile - Read from a text file and print to STDOUT.
 * @filename: Name of the file to read from.
 * @letters: Number of letters to read and print.
 *
 * Return: The actual number of bytes printed, or 0 on failure.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd, bytes_written, total_bytes;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	total_bytes = read(fd, buf, letters);
	bytes_written = write(STDOUT_FILENO, buf, total_bytes);

	free(buf);
	close(fd);
	return (bytes_written);
}
