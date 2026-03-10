#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: the string to search
 * @accept: the accepted bytes
 * Return: number of bytes in s that consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count;
	int i;
	int found;

	count = 0;
	while (s[count] != '\0')
	{
		found = 0;
		i = 0;
		while (accept[i] != '\0')
		{
			if (s[count] == accept[i])
			{
				found = 1;
				break;
			}
			i++;
		}
		if (!found)
			return (count);
		count++;
	}
	return (count);
}
