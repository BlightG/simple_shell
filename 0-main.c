#include "header.h"
/**
 * main - entry point for shell
 *
 * Return: Always 0 on sucess
*/
int main(void)
{
	int core, isatty_num;
	size_t buffersize;
	ssize_t nread;
	char *buffer;
	char **ddbuffer;

	buffersize = 1024;
	buffer = malloc(sizeof(char) * buffersize);
	if (buffer == NULL)
	{
		free(buffer);
		return (1);
	}
	core = 1;
	while (core)
	{
		fflush(stdin);
		clear(buffer);
		isatty_num = isatty(0);
		if (isatty_num == 1)
			write(1, "#", 2);
		nread = getline(&buffer, &buffersize, stdin);
		if (nread == -1)
			break;
		ddbuffer = conact(buffer, &core);
		exece(ddbuffer);
	}
	return (0);
}
