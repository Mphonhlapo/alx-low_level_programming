#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: On success, 1. On failure, -1.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;
	int result = 1; /* Default return value is success */

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fd == -1)
		return (-1); /* open failed */

	if (text_content != NULL)
	{
		w = write(fd, text_content, len);
		if (w == -1)
			result = -1; /* write failed */
	}

	close(fd);

	return (result);
}
