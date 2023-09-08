#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: On failure or if filename is NULL, return -1.
 *         If file does not exist or user lacks write permissions, return -1.
 *         Otherwise, return 1 upon successful append.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o, w, len = 0;
	int result = 1; /* Default return value is success */

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len]; len++)
			; /* Calculate the length using a for loop */
	}

	o = open(filename, O_WRONLY | O_APPEND);
	if (o == -1)
		return (-1); /* open failed */

	if (text_content != NULL)
	{
		for (int i = 0; i < len; i++)
		{
			w = write(o, &text_content[i], 1);
			if (w == -1)
			{
				result = -1; /* write failed */
				break;
			}
		}
	}

	close(o);

	return (result);
}
