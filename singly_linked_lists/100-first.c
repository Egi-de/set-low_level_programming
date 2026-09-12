#include <stdio.h>

/**
 * _first - prints a message before main() runs
 */
__attribute__((constructor))
static void _first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
