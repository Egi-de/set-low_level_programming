#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char charset[] =
	"A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

/**
 * char_stats - computes sum, product, sum of squares, and max of chars
 * @name: the username
 * @len: length of the username
 * @sum: output - sum of chars
 * @prod: output - product of chars
 * @sq: output - sum of squares of chars
 * @max: output - max char value
 */
void char_stats(char *name, int len, int *sum, int *prod, int *sq, int *max)
{
	int i;

	*sum = 0;
	*prod = 1;
	*sq = 0;
	*max = (signed char)name[0];
	for (i = 0; i < len; i++)
	{
		*sum += (signed char)name[i];
		*prod *= (signed char)name[i];
		*sq += (signed char)name[i] * (signed char)name[i];
		if ((signed char)name[i] > *max)
			*max = (signed char)name[i];
	}
}

/**
 * burn_rand - advances the rand() sequence c times
 * @c: number of times to call rand()
 * Return: the last value returned by rand()
 */
int burn_rand(int c)
{
	int r = 0, i;

	for (i = 0; c > i; i++)
		r = rand();
	return (r);
}

/**
 * main - generates a valid crackme5 key for a given username
 * @argc: argument count
 * @argv: argument vector, argv[1] is the username
 * Return: 0 on success, 1 on usage error
 */
int main(int argc, char **argv)
{
	char *name;
	char key[7];
	int len, sum, prod, sq, max;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s username\n", argv[0]);
		return (1);
	}
	name = argv[1];
	len = strlen(name);
	char_stats(name, len, &sum, &prod, &sq, &max);

	key[0] = charset[(len ^ 0x3b) & 0x3f];
	key[1] = charset[(sum ^ 0x4f) & 0x3f];
	key[2] = charset[(prod ^ 0x55) & 0x3f];
	srand(max ^ 0xe);
	key[3] = charset[rand() & 0x3f];
	key[4] = charset[(sq ^ 0xef) & 0x3f];
	key[5] = charset[(burn_rand((signed char)name[0]) ^ 0xe5) & 0x3f];
	key[6] = '\0';

	printf("%s", key);
	return (0);
}
