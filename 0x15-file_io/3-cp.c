#include "main.h"

/**
 * create_buffer - Allocates memory for a buffer of 1024 bytes.
 * @file: The name of the file the buffer is associated with.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't allocate memory for %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes a file.
 * @fd: The file descriptor of the file to be closed.
 */
void close_file(int fd)
{
	int close_status;

	close_status = close(fd);
	if (close_status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of one file to another.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If the source file cannot be read - exit code 98.
 * If the target file cannot be created or written to - exit code 99.
 * If any file cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int source_fd, target_fd, read_bytes, write_bytes;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	source_fd = open(argv[1], O_RDONLY);
	read_bytes = read(source_fd, buffer, 1024);
	target_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do
	{
		if (source_fd == -1 || read_bytes == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		write_bytes = write(target_fd, buffer, read_bytes);
		if (target_fd == -1 || write_bytes == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		read_bytes = read(source_fd, buffer, 1024);
		target_fd = open(argv[2], O_WRONLY | O_APPEND);
	} while (read_bytes > 0);

	free(buffer);
	close_file(source_fd);
	close_file(target_fd);

	return (0);
}
