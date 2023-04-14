#include "main.h"
#include <stdlib.h>

/**
 * print_textfile - Read a text file and output its content to STDOUT.
 * @file_path: Path of the file to be read
 * @num_chars: Maximum number of characters to be read from the file
 * Return: actual_written - Actual number of bytes read and printed
 *         0 when the function fails or file_path is NULL.
 */
ssize_t print_textfile(const char *file_path, size_t num_chars)
{
	char *buffer;
	ssize_t file_desc;
	ssize_t actual_written;
	ssize_t total_read;

	file_desc = open(file_path, O_RDONLY);
	if (file_desc == -1)
		return (0);
	buffer = malloc(sizeof(char) * num_chars);
	total_read = read(file_desc, buffer, num_chars);
	actual_written = write(STDOUT_FILENO, buffer, total_read);

	free(buffer);
	close(file_desc);
	return (actual_written);
}
