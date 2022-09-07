#include "header.h"
/**
 * exece - function to execute a program
 *
 * @str: a double pointer to a null terminated array
 *       composed to null terminated strings
*/
void exece(char **str)
{
	int pid;

	if (str != NULL)
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(str[0], str, environ) == -1)
			{
				perror("Error: ");
				exit(100);
			}
		}
		else
			wait(NULL);
	}
}
