#include "header.h"
/**
 * clear - a function to clear the buffer
 *
 * @str: a pointer to the shell buffer
*/
void clear(char *str)
{
	int length;

	if (str == NULL)
		exit(98);
	for (length = 0 ; str[length] != '\0' ; length++)
	{
		str[length] = 0;
	}
}
