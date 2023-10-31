#ifndef __MAIN_H__
#define __MAIN_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


/* Function to read a specified number of letters from a text file */
ssize_t read_textfile(const char *filename, size_t letters);

/* Function to create a file with the given text content */
int create_file(const char *filename, char *text_content);

/* Function to append text content to an existing file */
int append_text_to_file(const char *filename, char *text_content);

#endif
