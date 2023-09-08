#include "main.h"

/**
* append_text_to_file - Appends text to the end of a file.
* @filename: A pointer to the name of the file.
* @text_content: The string to add to the end of the file.
*
* Return: If the function fails or filename is NULL - returns -1.
*         If file does not exist or user lacks write permissions - returns -1.
*         Otherwise - returns 1 on success.
*/
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, write_result, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	file_descriptor = open(filename, O_WRONLY | O_APPEND);
	write_result = write(file_descriptor, text_content, len);

	if (file_descriptor == -1 || write_result == -1)
		return (-1);

	close(file_descriptor);

	return (1);
}
