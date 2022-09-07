#include "header.h"
/**
 * main - entry point for shell
 *
 * Return: Always 0 on sucess
*/
int main(void)
{
	int core;
	size_t buffersize;
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
		write(1, "#", 2);
		getline(&buffer, &buffersize, stdin);
		if (buffer == NULL)
		{
			free_grid(ddbuffer);
			perror("Error: ");
			break;
		}
		ddbuffer = conact(buffer, &core);
		exece(ddbuffer);
		/*free_grid(ddbuffer);*/
	}
	return (0);
}
