#include "sort.h"


/**
 * merge - Merges two partition during a mergesort.
 * @array: Array to sort
 * @result: Temporary array to store resultsarray
 * @start: Start of split
 * @middle: middle of split
 * @end: End of split
 */
void merge(int *array, int *result, size_t start, size_t middle, size_t end)
{
	size_t i = start, j = middle, k = start;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, middle - start);
	printf("[right]: ");
	print_array(array + middle, end - middle);
	while (i != middle && j != end)
	{
		if (array[i] < array[j])
			result[k++] = array[i++];
		else
			result[k++] = array[j++];
	}
	while (i < middle)
		result[k++] = array[i++];
	while (j < end)
		result[k++] = array[j++];
	for (i = start; i < end; i++)
		array[i] = result[i];
	printf("[Done]: ");
	print_array(array + start, end - start);
}

/**
 * split - Performs merge sort on an array partition
 * @array: Array to sort
 * @result: Temporary array to store results
 * @start: Start of split
 * @end: End of split
 */
void split(int *array, int *result, size_t start, size_t end)
{
	size_t middle;

	if (start >= end - 1)
		return;
	middle = (start + end) / 2;
	split(array, result, start, middle);
	split(array, result, middle, end);
	merge(array, result, start, middle, end);
}

/**
 * merge_sort - Sorts an array using the Merge Sort method
 * @array: Array of integers
 * @size: Size of @array
 */
void merge_sort(int *array, size_t size)
{
	int	*result;
	size_t i;

	if (size < 2)
		return;
	result = malloc(sizeof(*result) * size);
	for (i = 0; i < size; i++)
		result[i] = 0;
	split(array, result, 0, size);
	free(result);
}
