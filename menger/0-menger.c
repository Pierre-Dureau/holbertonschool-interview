#include "menger.h"

void menger(int level)
{
	int size = pow(3, level), i, j;

	if (level < 0)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			IsEmpty(i, j) ? printf(" ") : printf("#");
		printf("\n");
	}
}

int IsEmpty(int x, int y)
{
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return 1;
		x /= 3;
		y /= 3;
	}
	return 0;
}
