#include "main.h"
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
