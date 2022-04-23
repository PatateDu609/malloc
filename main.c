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
	ptr = malloc(16);
	ptr = malloc(96);
	ptr = calloc(6, 48);
	ptr = calloc(6, 864);
	free(ptr);
	ptr = malloc(480);
	ptr12 = malloc(4096);
	ptr10 = malloc(1616);
	ptr1 = calloc(44, 48);
	ptr2 = calloc(39, 160);
	ptr3 = calloc(414, 3312);
	ptr3 = realloc(ptr1, 46);
	ptr4 = realloc(ptr2, 156);
	ptr3 = realloc(ptr3, 3904);
	ptr4 = malloc(944);
	ptr5 = calloc(76, 608);
	free(ptr12);
	free(ptr);
	ptr = malloc(16);
	free(ptr);

	return (0);
}
