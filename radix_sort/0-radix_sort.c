#include "sort.h"


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
	int *new_array, i = 0, j = 0, k = 0, u = 1, check = 1;

	if (size < 2)
		return;

	new_array = malloc(size * sizeof(int));
	if (!new_array)
		return;
	copy_array(new_array, array, size);

	for (u = 1; check == 1; u *= 10, k = 0)
	{
		check = 0;
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < (int)size; j++)
			{
				if (array[j] / u > 0 && (array[j] / u) % 10 == i)
				{
					new_array[k] = array[j];
					k++;
					check = 1;
				}
			}
		}
		if (check == 1)
		{
			print_array(new_array, size);
			copy_array(array, new_array, size);
		}

	}
}
