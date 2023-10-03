#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: Pointer to the name of the file.
 * @text_content: String to be added to the end of the file.
 *
 * Return: On success, returns 1. On failure, returns -1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, write_status, content_length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (content_length = 0; text_content[content_length];)
			content_length++;
	}

	/* Open the file in write-only mode and append mode */
	file_descriptor = open(filename, O_WRONLY | O_APPEND);
	if (file_descriptor == -1)
		return (-1);

	/* Write the content to the file */
	write_status = write(file_descriptor, text_content, content_length);
	if (write_status == -1)
	{
		close(file_descriptor);
		return (-1);
	}

	/* Close the file */
	close(file_descriptor);

	return (1);
}
