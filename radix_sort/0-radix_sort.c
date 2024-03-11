#include "sort.h"


/**
 * get_max - get maximum number of unit in the array
 *
 * @array: The array
 * @size: Size of the array
 *
 * Return: number of unit
*/
int get_max(int *array, size_t size)
{
	int max = 0, i = 0, nb = 0;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	while (max)
	{
		max /= 10;
		nb++;
	}

	return (nb);
}


/**
 * copy_array - Copy an array
 *
 * @new_array: The array
 * @array: The array copied
 * @size: Size of the array
 */
void copy_array(int *new_array, int *array, size_t size)
{
	int i;

	for (i = 0; i < (int)size; i++)
		new_array[i] = array[i];
}


/**
 * radix_sort - Radix sort algorithm
 *
 * @array: The array to sort
 * @size: Number of elements in @array
*/
void radix_sort(int *array, size_t size)
{
	int *new_array, i = 0, j = 0, k = 0, u = 1, nb = 0;

	if (size < 2)
		return;

	new_array = malloc(size * sizeof(int));
	if (!new_array)
		return;
	copy_array(new_array, array, size);
	nb = get_max(array, size);

	for (u = 1; nb > 0; u *= 10, k = 0, nb--)
	{
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < (int)size; j++)
			{
				if ((array[j] / u) % 10 == i)
				{
					new_array[k] = array[j];
					k++;
				}
			}
		}
		copy_array(array, new_array, size);
		print_array(array, size);
	}
	free(new_array);
}
