#include "search_algos.h"


void print_array(int *array, size_t start, size_t size)
{
    size_t i;

    printf("Searching in array: ");
    for (i = start; i < size; i++)
        printf("%d,", array[i]);
}

int advanced_binary(int *array, size_t size, int value)
{
    size_t middle = size / 2;

    print_array(array, 0, size);

    while (1)
    {
        if (array[middle] == value)
            return middle;
        else if (array[middle] > value)
            middle += middle / 2;
        else
            middle -= middle /2;

        size /= 2;

        print_array(array, middle, size);
    }
}