#include <stdio.h>
#include <stdbool.h>
#include "sandpiles.h"
/**
 * my_print_grid - func to print grid
 * @grid : grid to print
 * Return: none
 */
static void my_print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
			{
				printf(" ");
			}
			printf("%d", grid[i][j]);
		}
	printf("\n");
	}
}
/**
 * my_check_grid - function to check grid
 * @grid : grid to check
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
bool my_check_grid(int grid[3][3])
{
	int i, j;

	for (i = 1; i < 3; i++)
	{
		for (j = 1; j < 3; j++)
		{
			if (j)
			{
				if (grid[i][j] != grid[i][j - 1])
					return (false);
			}
		}
	}
	return (true);
}
/**
 * sum_grids - function to summarize grids
 * @grid1 : grid to check
 * @grid2 : secnd grid
 * Return : none
 */
void sum_grids(int grid1[3][3], int grid2[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
}
/**
 * topple - function to topple grid
 * @grid : grid to topple
 * Return : none
 */
void topple(int grid[3][3])
{
	int toppling = 1;
	int temp[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	while (toppling)
	{
		toppling = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (grid[i][j] > 3)
				{
					toppling = 1;
					grid[i][j] -= 4;
					if (i > 0)
						temp[i - 1][j]++;
					if (i < 2)
						temp[i + 1][j]++;
					if (j > 0)
						temp[i][j - 1]++;
					if (j < 2)
						temp[i][j + 1]++;
				}
			}
		}
		if (toppling)
		{
			printf("=\n");
			my_print_grid(grid);
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				grid[i][j] += temp[i][j];
				temp[i][j] = 0;
			}
		}
	}
}
/**
 * sandpiles_sum - function to check grid
 * @grid1 : grid to check
 * @grid2 : 2nd grid
 * Return : none
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum_grids(grid1, grid2);
	if (my_check_grid(grid1) == false)
	{
		printf("=\n");
		my_print_grid(grid1);
	}
	topple(grid1);
}

