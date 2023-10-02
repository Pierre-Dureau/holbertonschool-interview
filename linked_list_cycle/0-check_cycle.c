#include "lists.h"

/**
 * check_cycle - Checks if a singly linked list has a cycle in it
 *
 * @list: pointer to head of list
 * Return: 1 if there is a cycle, 0 if not
 */
int check_cycle(listint_t *list)
{
	listint_t *slow = list, *fast = list->next;

	while (slow != fast && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	if (slow == fast)
		return (1);
	return (0);
}
