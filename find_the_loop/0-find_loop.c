#include "lists.h"



listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	if (!head || !head->next)
		return (NULL);

	slow = head;
	fast = head->next;

	while (slow && fast)
	{
		if (slow == fast)
			return (slow);

		slow = slow->next;
		fast = fast->next->next;
	}

	return (NULL);
}
