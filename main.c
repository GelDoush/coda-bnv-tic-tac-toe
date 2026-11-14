#include <stdlib.h>
#include <stdio.h>
#include "tic-tac-toe.h"

int main()
{
    char ** grid = malloc(4 * sizeof(*grid)); 
	grid[3] = NULL;
	grid[0] = malloc(4 * sizeof(char));
	grid[1] = malloc(4 * sizeof(char));
	grid[2] = malloc(4 * sizeof(char));

	game(grid);

	int i = 0;
	while(grid[i] != NULL)
	{
		free(grid[i]);
		i = i + 1;
	}

	free(grid);
	exit(0);
}