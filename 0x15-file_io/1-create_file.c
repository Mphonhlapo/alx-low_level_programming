#include "main.h"

/*
 *create_file - Function to create a file and write content to it.
 *@filename: The name of the file to be created.
 *@text_content: The content to be written to the file.
 *Return: Returns 1 on success, and -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int num_letters;
	int result;

	/* Check if the filename is NULL. */
	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	/* Check if the file couldn't be opened. */
	if (fd == -1)
		return (-1);

	/* If text_content is NULL, set it as an empty string. */
	if (!text_content)
		text_content = "";

	/* Count the number of letters in the text_content. */
	for (num_letters = 0; text_content[num_letters]; num_letters++)
		;

	/* Write the text_content to the file. */
	result = write(fd, text_content, num_letters);

	/* Check if the write operation failed. */
	if (result == -1)
		return (-1);

	/* Close the file. */
	close(fd);

	/* Return 1 to indicate success. */
	return (1);
}
