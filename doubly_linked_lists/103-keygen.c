#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	char *name;
	char key[7];
	int len, i, sum, prod, sq, max, r;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s username\n", argv[0]);
		return (1);
	}
	name = argv[1];
	len = strlen(name);

	key[0] = charset[(len ^ 0x3b) & 0x3f];

	for (sum = 0, i = 0; i < len; i++)
		sum += (signed char)name[i];
	key[1] = charset[(sum ^ 0x4f) & 0x3f];

	for (prod = 1, i = 0; i < len; i++)
		prod *= (signed char)name[i];
	key[2] = charset[(prod ^ 0x55) & 0x3f];

	for (max = (signed char)name[0], i = 0; i < len; i++)
		if ((signed char)name[i] > max)
			max = (signed char)name[i];
	srand(max ^ 0xe);
	key[3] = charset[rand() & 0x3f];

	for (sq = 0, i = 0; i < len; i++)
		sq += (signed char)name[i] * (signed char)name[i];
	key[4] = charset[(sq ^ 0xef) & 0x3f];

	for (r = 0, i = 0; (signed char)name[0] > i; i++)
		r = rand();
	key[5] = charset[(r ^ 0xe5) & 0x3f];

	key[6] = '\0';
	printf("%s", key);
	return (0);
}
