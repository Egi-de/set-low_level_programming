#include <stdlib.h>
#include "main.h"

/**
 * _calloc - allocates memory for an array, set to zero
 * @nmemb: number of elements
 * @size: size of each element
 * Return: pointer to the allocated memory, or NULL on failure
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int total, i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	total = nmemb * size;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < total; i++)
		ptr[i] = 0;

	return (ptr);
}
