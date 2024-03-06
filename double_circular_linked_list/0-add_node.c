#include "list.h"


/**
 * create_node - Create a new node
 *
 * @str: string
 *
 * Return: The new node or NULL
 */
List *create_node(char *str)
{
	List *new = NULL;

	if (!*str)
		return (NULL);

	new = malloc(sizeof(List));

	if (!new)
		return (NULL);

	new->prev = NULL;
	new->next = NULL;
	new->str = strdup(str);

	return (new->str ? new : NULL);
}

/**
 * add_node_end - Add a node at the end of the list
 *
 * @list: Double linked list
 * @str: string
 *
 * Return: The new node or NULL
 */
List *add_node_end(List **list, char *str)
{
	List *new = NULL, *head = *list;

	new = create_node(str);
	if (!new)
		return (NULL);

	if (!*list)
	{
		new->next = new;
		new->prev = new;
		*list = new;
	}
	else
	{
		new->prev = head->prev;
		new->next = head;
		head->prev->next = new;
		head->prev = new;
	}
	return (new);
}


/**
 * add_node_begin - Add a node at the beginning of the list
 *
 * @list: Double linked list
 * @str: string
 *
 * Return: The new node or NULL
 */
List *add_node_begin(List **list, char *str)
{
	List *new = NULL, *head = *list;

	new = create_node(str);
	if (!new)
		return (NULL);

	if (!*list)
	{
		new->next = new;
		new->prev = new;
	}
	else
	{
		new->next = head;
		new->prev = head->prev;
		head->prev->next = new;
		head->prev = new;
	}
	*list = new;
	return (new);
}
