#include <stdio.h>
#include "ft_malloc.h"

void show(char *str)
{
	static int b = 0;
	if (b)
		write(1, "\n", 1);

	write(1, str, strlen(str));
	write(1, "\n", 1);
	show_alloc_mem();

	b = 1;
}

int main()
{
	while (1);
	return (0);
}
