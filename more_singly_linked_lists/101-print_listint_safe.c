#include <stdio.h>
#include "lists.h"

/**
 * find_loop_entry - finds the entry node of a loop in a listint_t list
 * @head: pointer to head of list
 * Return: pointer to entry node, or NULL if no loop
 */
const listint_t *find_loop_entry(const listint_t *head)
{
	const listint_t *slow, *fast;

	slow = head;
	fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (slow);
		}
	}
	return (NULL);
}

/**
 * print_listint_safe - prints a listint_t list, even if it has a loop
 * @head: pointer to head node
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *entry, *node;
	size_t count;
	int seen_entry;

	entry = find_loop_entry(head);
	count = 0;
	seen_entry = 0;
	node = head;

	while (node != NULL)
	{
		if (entry != NULL && node == entry && seen_entry)
		{
			printf("-> [%p] %d\n", (void *)entry, entry->n);
			break;
		}
		printf("[%p] %d\n", (void *)node, node->n);
		count++;
		if (entry != NULL && node == entry)
			seen_entry = 1;
		node = node->next;
	}

	return (count);
}
