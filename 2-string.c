#include "header.h"
/**
 * checkconact - checks strings and counts delimiter
 *
 * @str: string to be counted
 * @delimcount: number of delimiters
 * @core: pointer to main program flag
 *
 * Return: retuns 1 if sucess and 0 if failure
*/
int checkconact(char *str, int *delimcount, int *core)
{
	int i;

	if (str == NULL || str[0] == '\n')
		return (0);
	if (strcmp(str, "exit\n") == 0)
	{
		*core = 0;
		free(str);
		return (0);
	}
	*delimcount = 1;
	for (i = 0 ; str[i] != '\0' ; i++)
	{
		if (str[i] == 32 && str[i - 1] != 32)
			*delimcount = *delimcount + 1;
	}
	str[strlen(str) - 1] = '\0';
	if (*delimcount < 0)
		return (0);
	return (1);
}
/**
 * conact - parses input from the buffer
 *
 * @str: pointer to shell input buffer
 * @core: pointer to main function flag
 *
 * Return: a mulidimentional array or NULL if failure
*/
char **conact(char *str, int *core)
{
	int i, delimcount;
	char *piece;
	char **conact;

	if (checkconact(str, &delimcount, core) == 0)
		return (NULL);
	conact = malloc(sizeof(char *) * (delimcount + 2));
	if (conact == NULL)
	{
		free(conact);
		perror("Error:");
		return (NULL);
	}
	i = 0;
	piece = strtok(str, " ");
	while (piece != NULL)
	{
		conact[i] = malloc(sizeof(char) * strlen(piece));
		if (conact[i] == NULL)
		{
			perror("Error:");
			free_grid(conact);
			return (NULL);
		}
		if (i == 0 && str[0] != '/')
		{
			strcpy(conact[i], "/bin/");
			strcat(conact[i], piece);
		}
		else
			conact[i] = piece;
		piece = strtok(NULL, " ");
		i++;
	}
	conact[i] = "\n";
	conact[i] = '\0';
	return (conact);
}
