#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: Pointer to the name of the file.
 * @text_content: String to be appended to the end of the file.
 *
 * Return: If the function fails or filename is NULL - -1.
 *         If the file does not exist or the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int open_fd, write_res, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	open_fd = open(filename, O_WRONLY | O_APPEND);
	write_res = write(open_fd, text_content, length);

	if (open_fd == -1 || write_res == -1)
		return (-1);

	close(open_fd);

	return (1);
}
