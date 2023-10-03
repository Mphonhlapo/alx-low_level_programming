#include "main.h"

/**
 * read_textfile - Read a text file and print its content to STDOUT.
 * @filename: Text file to be read.
 * @letters: Number of letters to be read.
 *
 * Return: The actual number of bytes read and printed, or -1 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
	{
		fprintf(stderr, "Filename is NULL.\n");
		return -1; /*indicates failure */
	}

	int fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Unable to open file");
		return -1; /* indicates failure */
	}

	char *buf = (char *)malloc(sizeof(char) * letters);
	if (buf == NULL)
	{
		perror("Memory allocation failed");
		close(fd);
		return -1; /*indicates failure */
	}

	ssize_t bytes_read = read(fd, buf, letters);
	if (bytes_read == -1)
	{
		perror("Read failed");
		free(buf);
		close(fd);
		return -1; /* Indicates failure */
	}

	ssize_t bytes_written = write(STDOUT_FILENO, buf, bytes_read);
	if (bytes_written == -1)
	{
		perror("Write failed");
		free(buf);
		close(fd);
		return -1; /*indicates failure */
	}
i
	free(buf);
	close(fd);
	return bytes_written;
}
