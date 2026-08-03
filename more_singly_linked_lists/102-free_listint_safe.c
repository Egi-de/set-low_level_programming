#include <stdlib.h>
#include "lists.h"

/**
 * find_loop_entry2 - finds the entry node of a loop in a listint_t list
 * @head: pointer to head of list
 * Return: pointer to entry node, or NULL if no loop
 */
static listint_t *find_loop_entry2(listint_t *head)
{
	listint_t *slow, *fast;

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
 * free_listint_safe - frees a listint_t list, even if it has a loop
 * @h: pointer to pointer to head of list
 * Return: size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *entry, *node, *tmp;
	size_t count;
	int seen_entry;

	if (h == NULL || *h == NULL)
		return (0);

	entry = find_loop_entry2(*h);
	count = 0;
	seen_entry = 0;
	node = *h;

	while (node != NULL)
	{
		if (entry != NULL && node == entry && seen_entry)
			break;

		tmp = node->next;
		if (entry != NULL && node == entry)
			seen_entry = 1;
		free(node);
		count++;
		node = tmp;
	}

	*h = NULL;
	return (count);
}
