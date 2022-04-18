#include "zones.h"

void show_alloc_mem(void)
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

		if (!block->size)
			write(1, "No block in this zone\n", 23);
		while (IS_INSIDE_ZONE(zone, block))
		{
			log_blk(block);
			if (!block->free)
				s += block->size;
			block = NEXT_BLOCK(block);
		}
		write(1, "Remaining size: ", 16);
		log_nb(zone->size - s - sizeof(t_zone), 10);
		write(1, "\n", 1);
		zone = zone->next;
	}
}
