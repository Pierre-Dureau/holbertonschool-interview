#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - Check if the grid is stable
 * @grid: 3x3 grid
 *
 * Return: True or False
 */
static bool is_stable(int grid[3][3])
{
	size_t i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (false);
		}

	return (true);
}

/**
 * copy_grid - copy the grid to have good transition
 * @grid: 3x3 grid
 * @gridcopy: 3x3 grid
 */
static void copy_grid(int grid[3][3], int gridcopy[3][3])
{
	size_t i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			gridcopy[i][j] = grid[i][j];
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int gridcopy[3][3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	while (!is_stable(grid1))
	{
		copy_grid(grid1, gridcopy);
		printf("=\n");
		print_grid(grid1);

		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				if (gridcopy[i][j] > 3)
				{
					if (i - 1 >= 0)
						grid1[i - 1][j] += 1;
					if (j - 1 >= 0)
						grid1[i][j - 1] += 1;
					if (i + 1 <= 2)
						grid1[i + 1][j] += 1;
					if (j + 1 <= 2)
						grid1[i][j + 1] += 1;
					grid1[i][j] -= 4;
				}
			}
	}
}
