
#include "main.h"

/**
 * create_textfile - Generates a new file and writes content to it.
 * @file_name: A pointer to the name of the file to be created.
 * @content: A pointer to the string to be written to the file.
 *
 * Return: If the function fails - -1.
 *         Otherwise - 1.
 */
int create_textfile(const char *file_name, char *content)
{
	int file_desc, write_status, content_len = 0;

	if (file_name == NULL)
		return (-1);

	if (content != NULL)
	{
		for (content_len = 0; content[content_len];)
			content_len++;
	}

	file_desc = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0600);
	write_status = write(file_desc, content, content_len);

	if (file_desc == -1 || write_status == -1)
		return (-1);

	close(file_desc);

	return (1);
}
