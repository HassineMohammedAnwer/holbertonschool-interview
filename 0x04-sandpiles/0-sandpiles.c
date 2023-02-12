#include <stdio.h>
#include <stdbool.h>
#include "sandpiles.h"

static void my_print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
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
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, toppling = 1, temp[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	}
	if (my_check_grid(grid1) == false)
		my_print_grid(grid1);
	while (toppling)
	{
		toppling = 0;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					toppling = 1;
					grid1[i][j] -= 4;
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
			my_print_grid(grid1);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				grid1[i][j] += temp[i][j];
				temp[i][j] = 0;
			}
		}
	}
}
