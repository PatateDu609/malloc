#include <stdio.h>
#include "ft_malloc.h"

void show(char *str)
{
	static int b = 0;
	if (b)
		write(1, "\n", 1);

	write(1, str, strlen(str));
	show_alloc_mem();

	b = 1;
}

int main()
{
	write(1, "Large malloc\n", 13);
	void *ptr = malloc(1000000);
	show("malloc\n");
	free(ptr);
	show("free\n");

	write(1, "\nSmall malloc\n", 14);
	ptr = malloc(5000);
	show("malloc\n");
	free(ptr);
	show("free\n");

	write(1, "\nTiny malloc\n", 14);
	ptr = malloc(500);
	show("malloc\n");
	free(ptr);
	show("free\n");
	return (0);
}
