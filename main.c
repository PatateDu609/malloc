#include <stdio.h>
#include "ft_malloc.h"

void show(char *str)
{
	static int b = 0;
	if (b)
		write(1, "\n", 1);

	write(1, str, strlen(str));
	write(1, " show_alloc_mem\n", 17);
	show_alloc_mem();

	b = 1;
}

int main()
{
	alloc_zone(10);
	show("Initial");

	reserve_block(g_zones, 1);
	show("First");
	reserve_block(g_zones, 265);
	show("Second");
	reserve_block(g_zones, 2644);
	show("Third");
	reserve_block(g_zones, 1000);
	show("Fourth");
	reserve_block(g_zones, 98);
	show("Fifth");

	munmap(g_zones, g_zones->size);
	return (0);
}
