#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: pointer to the string
 * Return: pointer to the modified string
 */
char *leet(char *s)
{
	int i;
	int j;
	char plain[] = "aAeEoOtTlL";
	char leet_code[] = "4433007711";

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (plain[j] != '\0')
		{
			if (s[i] == plain[j])
				s[i] = leet_code[j];
			j++;
		}
		i++;
	}
	return (s);
}
