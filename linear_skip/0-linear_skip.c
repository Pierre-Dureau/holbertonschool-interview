#include "search.h"

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *save = list, *temp;

	if (!list)
		return (NULL);

	for(list = list->express; list; list = list->express, save = save->express)
	{
		printf("Value checked at index [%lld] = [%d]\n", list->index, list->n);
		if (list->n > value)
			break;
	}

	if (list)
		printf("Value found between indexes [%lld] and [%lld]\n", save->index, list->index);
	else
	{
		for (temp = save; temp->next; temp = temp->next);
		printf("Value found between indexes [%lld] and [%lld]\n", save->index, temp->index);
	}

	for (; save && save != list; save = save->next)
	{
		printf("Value checked at index [%lld] = [%d]\n", save->index, save->n);
		if (save->n == value)
			return (save);
	}
	return (NULL);
}
