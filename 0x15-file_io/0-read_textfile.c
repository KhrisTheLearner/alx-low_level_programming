#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints its content to STDOUT.
 * @filename: Name of the text file to be read
 * @letters: Number of letters to be read from the file
 * Return: bytes_written - Actual number of bytes read and printed
 *         0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t file_descriptor;
	ssize_t bytes_written;
	ssize_t total_read;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	total_read = read(file_descriptor, buffer, letters);
	bytes_written = write(STDOUT_FILENO, buffer, total_read);

	free(buffer);
	close(file_descriptor);
	return (bytes_written);
}
