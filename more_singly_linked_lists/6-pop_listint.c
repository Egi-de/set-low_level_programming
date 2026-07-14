#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - deletes head node and returns its data
 * @head: pointer to pointer to the head of the list
 * Return: head node's data, or 0 if list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int n;

	if (*head == NULL)
		return (0);
	n = (*head)->n;
	tmp = (*head)->next;
	free(*head);
	*head = tmp;
	return (n);
}
