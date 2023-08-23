#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * @brief
 *
 * @param head
 * @param number
 * @return listint_t*
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
    listint_t *current;

    current = *head;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = number;
    new->next = NULL;

    if (*head == NULL)
        *head = new;
    else
    {
        while (current->next != NULL && current->next->n > new->n)
            current = current->next;
		new->next = current->next;
        current->next = new;
    }

    return (new);
}
