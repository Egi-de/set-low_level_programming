#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * f1 - derives key index 0 from the username length
 * @len: length of the username
 * Return: index into the charset
 */
int f1(int len)
{
	return ((len ^ 0x3b) & 0x3f);
}

/**
 * f2 - derives key index 1 from the sum of username chars
 * @name: the username
 * @len: length of the username
 * Return: index into the charset
 */
int f2(char *name, int len)
{
	int sum = 0, i;

	for (i = 0; i < len; i++)
		sum += (signed char)name[i];
	return ((sum ^ 0x4f) & 0x3f);
}

/**
 * f3 - derives key index 2 from the product of username chars
 * @name: the username
 * @len: length of the username
 * Return: index into the charset
 */
int f3(char *name, int len)
{
	int prod = 1, i;

	for (i = 0; i < len; i++)
		prod *= (signed char)name[i];
	return ((prod ^ 0x55) & 0x3f);
}

/**
 * f4 - derives key index 3 from the max username char, via rand()
 * @name: the username
 * @len: length of the username
 * Return: index into the charset
 */
int f4(char *name, int len)
{
	int max = (signed char)name[0], i;

	for (i = 0; i < len; i++)
		if ((signed char)name[i] > max)
			max = (signed char)name[i];
	max ^= 0xe;
	srand(max);
	return (rand() & 0x3f);
}

/**
 * f5 - derives key index 4 from the sum of squares of username chars
 * @name: the username
 * @len: length of the username
 * Return: index into the charset
 */
int f5(char *name, int len)
{
	int sum = 0, i;

	for (i = 0; i < len; i++)
		sum += (signed char)name[i] * (signed char)name[i];
	return ((sum ^ 0xef) & 0x3f);
}

/**
 * f6 - derives key index 5 by burning through the rand() sequence
 * @c: ASCII code of the first username character
 * Return: index into the charset
 */
int f6(int c)
{
	int r = 0, i;

	for (i = 0; c > i; i++)
		r = rand();
	return ((r ^ 0xe5) & 0x3f);
}

/**
 * main - generates a valid crackme5 key for a given username
 * @argc: argument count
 * @argv: argument vector, argv[1] is the username
 * Return: 0 on success, 1 on usage error
 */
int main(int argc, char **argv)
{
	const char charset[] =
		"A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char key[7];
	int len;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s username\n", argv[0]);
		return (1);
	}
	len = strlen(argv[1]);
	key[0] = charset[f1(len)];
	key[1] = charset[f2(argv[1], len)];
	key[2] = charset[f3(argv[1], len)];
	key[3] = charset[f4(argv[1], len)];
	key[4] = charset[f5(argv[1], len)];
	key[5] = charset[f6((signed char)argv[1][0])];
	key[6] = '\0';
	printf("%s\n", key);
	return (0);
}
