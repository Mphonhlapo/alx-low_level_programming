#include "main.h"

/**
 * create_file - Creates a file and writes text content to it.
 * @filename:   Pointer to the name of the file to create.
 * @text_content:   Pointer to the string to write to the file.
 *
 * Return: On success, returns 1. On failure, returns -1.
 */
int create_file(const char *filename, char *text_content)
{
    int file_descriptor, write_status, content_length = 0;

    if (filename == NULL)
        return (-1);

    if (text_content != NULL)
    {
        for (content_length = 0; text_content[content_length];)
            content_length++;
    }

    /* Create the file with read-write permissions for the owner */
    file_descriptor = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
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
