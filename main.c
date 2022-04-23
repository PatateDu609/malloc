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
	void *ptr, *ptr1, *ptr2, *ptr3, *ptr4, *ptr5, *ptr12, *ptr10;

	ptr = malloc(16);
	ptr = calloc(1, 288);
	ptr = malloc(32);
	show_alloc_mem_ex();

	return (0);
}
