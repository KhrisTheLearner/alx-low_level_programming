#include <stdio.h>
#include "main.h"

/**
 * _putchar - writes the character c stdout
 * @c:The character to print
 *
 * Return: On succes 1.
 * On erroe, -1 is returned and error is set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
