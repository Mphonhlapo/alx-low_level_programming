#include "main.h"

/*
 * append_text_to_file- Appends text to the end of a file.
 * @filename: The name of the target file.
 * @text_content: The content to be added.
 *
 * Return: Returns 1 if the file exists. Returns -1 if the file does not exist
 * or if the operation fails.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int num_letters;
	int result;

	/* Check if the filename is NULL. */
	if (!filename)
		return (-1);

	/* Open the file for writing, and append to it. */
	fd = open(filename, O_WRONLY | O_APPEND);

	/* Check if the file couldn't be opened. */
	if (fd == -1)
		return (-1);

	/* If text_content is not NULL, write its contents to the file. */
	if (text_content)
	{
		num_letters = 0;

		/* Calculate the number of letters in text_content using a while loop. */
		while (text_content[num_letters])
		{
			num_letters++;
		}

		result = write(fd, text_content, num_letters);

		/* Check if the write operation failed. */
		if (result == -1)
			return (-1);
	}

	/* Close the file. */
	close(fd);

	/* Return 1 to indicate success. */
	return (1);
}
