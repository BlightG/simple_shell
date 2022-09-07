#include "header.h"

/**
 * free_grid - frees a 2d area with height of "height"
 *
 * @grid: 2d array
 *
*/

void free_grid(char **grid)
{
	int i;

	if (grid != NULL)
	{
		for (i = 0 ; grid[i] != NULL ; i++)
			free(grid[i]);
		free(grid);
	}
}
