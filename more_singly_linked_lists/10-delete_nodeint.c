#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - deletes node at given index of a listint_t list
 * @head: pointer to pointer to head of list
 * @index: index of node to delete (0-based)
 * Return: 1 if succeeded, -1 if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *tmp;
	listint_t *prev;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	tmp = *head;

	if (index == 0)
	{
		*head = tmp->next;
		free(tmp);
		return (1);
	}

	prev = NULL;
	i = 0;
	while (tmp != NULL && i < index)
	{
		prev = tmp;
		tmp = tmp->next;
		i++;
	}
	if (tmp == NULL)
		return (-1);

	prev->next = tmp->next;
	free(tmp);
	return (1);
}
