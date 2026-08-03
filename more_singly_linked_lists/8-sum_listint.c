#include "lists.h"

/**
 * sum_listint - sums all data in a listint_t list
 * @head: pointer to head of list
 * Return: sum of all node values, 0 if empty
 */
int sum_listint(listint_t *head)
{
	int sum;

	sum = 0;
	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
