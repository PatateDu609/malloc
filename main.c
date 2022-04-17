#include <stdio.h>
#include "ft_malloc.h"

void show(char *str)
{
	static int b = 0;

	write(1, str, strlen(str));
	write(1, " show_alloc_mem\n", 17);
	show_alloc_mem();

	if (b)
		write(1, "\n", 1);
	b = 1;
}

int main()
{
	alloc_zone(1024);
	reserve_block(g_zones, 1024);
	reserve_block(g_zones, 55);
	reserve_block(g_zones, 55);
	reserve_block(g_zones, 5587);
	reserve_block(g_zones, 100);

	GET_FIRST_BLOCK(g_zones)->free = 1;
	NEXT_BLOCK(NEXT_BLOCK(GET_FIRST_BLOCK(g_zones)))->free = 1;

	show("First");

	reserve_block(g_zones, 980);
	show("Second");
	reserve_block(g_zones, 65);
	show("Third");
	reserve_block(g_zones, 28);
	show("Fourth");
	reserve_block(g_zones, 20);
	show("Fifth");
	reserve_block(g_zones, 15);
	show("Sixth");
	reserve_block(g_zones, 12);
	show("Seventh");

	GET_FIRST_BLOCK(g_zones)->free = 1;
	show("Eighth");

	reserve_block(g_zones, 10);
	show("Ninth");

	munmap(g_zones, g_zones->size);
	return (0);
}
