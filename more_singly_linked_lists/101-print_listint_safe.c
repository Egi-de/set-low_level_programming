#include <stdio.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t list, even if it has a loop
 * @head: pointer to head node
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow, *fast, *entry;
	size_t count;
	int has_loop;

	slow = head;
	fast = head;
	has_loop = 0;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			has_loop = 1;
			break;
		}
	}

	entry = NULL;
	if (has_loop)
	{
		slow = head;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		entry = slow;
	}

	count = 0;
	slow = head;
	while (slow != NULL)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		count++;
		if (entry != NULL && slow == entry && count > 1)
		{
			printf("-> [%p] %d\n", (void *)entry, entry->n);
			break;
		}
		slow = slow->next;
	}

	return (count);
}
