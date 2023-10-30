#include "slide_line.h"

/**
 * @brief
 *
 * @param line
 * @param size
 * @param direction
 * @return int
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_RIGHT)
		return (slide_right(line, size));
	else
		return (slide_left(line, size));
}

int slide_right(int *line, size_t size)
{
	size_t i = 0;
	int place = 0, first = 1;

	for (i = 0; i < size; i++)
	{
		if (line[i] == 0)
			continue;

		if (first == 1)
		{
			place = i;
			first = 0;
		}
		else
		{
			if (line[place] == line[i])
			{
				line[i] *= 2;
				line[place] = 0;
				first = 1;
			}
			else
				place = i;
		}
	}
	return (reorder(line, size, SLIDE_RIGHT));
}

int slide_left(int *line, size_t size)
{
	size_t i = 0;
	int place = 0, first = 1;

	for (i = size - 1;; i--)
	{
		if (line[i] == 0)
			continue;

		if (first == 1)
		{
			place = i;
			first = 0;
		}
		else
		{
			if (line[place] == line[i])
			{
				line[i] *= 2;
				line[place] = 0;
				first = 1;
			}
			else
				place = i;
		}
		if (i == 0)
			break;
	}
	return (reorder(line, size, SLIDE_LEFT));
}

int reorder(int *line, size_t size, int direction)
{
	size_t i, j;
	int count_place = 0;

	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < size; i++)
		{
			if (line[i] == 0)
				count_place++;
			else if (line[i] != 0 && count_place > 0)
			{
				for (j = 0; j < size; j++)
				{
					if (line[j] == 0)
					{
						line[j] = line[i];
						line[i] = 0;
						count_place--;
						break;
					}
				}
			}
		}
	}
	else
	{
		for (i = size - 1;; i--)
		{
			if (line[i] == 0)
				count_place++;
			else if (line[i] != 0 && count_place > 0)
			{
				for (j = size - 1; j > 0; j--)
				{
					if (line[j] == 0)
					{
						line[j] = line[i];
						line[i] = 0;
						count_place--;
						break;
					}
				}
			}
			if (i == 0)
				break;
		}
	}

	return (1);
}
