#include "zones.h"

static void show_ex(t_block *block)
{
	if (block->free)
	{
		write(1, "The block is free...\n", 21);
		return ;
	}
	void *ptr = GET_DATA(block);
	
	for (size_t i = 0; i < block->size; ptr++, i++)
	{
		unsigned char data = *(unsigned char *)ptr;
		log_nb(data, -16);
		write(1, ((i + 1) % 64 ? " " : "\n"), 1);
	}
	write(1, "\n", 1);
}

static void __show_mem(int ex)
{
	t_zone *zone = g_zones;

	if (!zone)
	{
		write(1, "No zone allocated\n", 19);
		return;
	}
	while (zone)
	{
		log_zone(zone);
		t_block *block = GET_FIRST_BLOCK(zone);
		size_t s = 0;

		while (IS_INSIDE_ZONE(zone, block))
		{
			log_blk(block);
			if (ex)
				show_ex(block);
			if (!block->free)
				s += block->size + sizeof(t_block);
			block = NEXT_BLOCK(block);
		}
		if (zone->type != LARGE)
			s -= sizeof(t_block);
		write(1, "Remaining size: ", 16);
		log_nb(zone->size - s - sizeof(t_zone), 10);
		write(1, "\n", 1);
		zone = zone->next;
	}
}

static void show_mem(int ex)
{
	pthread_mutex_lock(&g_mutex);
	__show_mem(ex);
	pthread_mutex_unlock(&g_mutex);
}

void show_alloc_mem(void)
{
    show_mem(0);
}


void show_alloc_mem_ex()
{
    show_mem(1);
}