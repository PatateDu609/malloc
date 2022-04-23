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
	void *ptr, *ptr1, *ptr2;

	ptr = malloc(16);
	show("Malloc(16)");
	ptr1 = calloc(1, 288);
	show("calloc(1, 288)");
	ptr2 = malloc(32);
	show("malloc(32)");
	show_alloc_mem_ex();
	
	free(ptr);
	show("free(ptr)");

	free(ptr1);
	show("free(ptr1)");
	
	free(ptr2);
	show("free(ptr2)");

	return (0);
}
