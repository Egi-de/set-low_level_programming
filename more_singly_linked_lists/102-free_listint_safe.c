#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list, even if it has a loop
 * @h: pointer to pointer to head of list
 * Return: size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *slow, *fast, *entry, *tmp;
	size_t count;
	int has_loop;

	if (h == NULL || *h == NULL)
		return (0);

	slow = *h;
	fast = *h;
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
		slow = *h;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		entry = slow;
	}

	count = 0;
	slow = *h;
	while (slow != NULL)
	{
		tmp = slow->next;
		count++;
		free(slow);
		if (entry != NULL && slow == entry && count > 1)
			break;
		slow = tmp;
	}

	*h = NULL;
	return (count);
}
