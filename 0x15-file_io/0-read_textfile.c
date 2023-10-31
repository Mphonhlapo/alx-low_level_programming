#include "main.h"

/*
 * read_textfile - reads a text file and prints the letters
 * @filename: The name of the file to read.
 * @letters: The number of letters to be printed.
 *
 * Return: The number of letters actually printed. If it fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t nrd, nwr;
	char *buf;

	/* Check if the filename is NULL. */
	if (!filename)
		return (0);

	/* Open the file for reading. */
	fd = open(filename, O_RDONLY);

	/* Check if the file could not be opened. */
	if (fd == -1)
		return (0);

	/* Allocate memory for the buffer to read the file. */
	buf = malloc(sizeof(char) * (letters));
	if (!buf)
		return (0);

	/* Read from the file into the buffer. */
	nrd = read(fd, buf, letters);

	/* Write the contents of the buffer to standard output. */
	nwr = write(STDOUT_FILENO, buf, nrd);

	/* Close the file and free the buffer. */
	close(fd);
	free(buf);

	return (nwr);
}
