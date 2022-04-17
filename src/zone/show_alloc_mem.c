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

		if (!block->size)
			write(1, "No block in this zone\n", 23);
		while (block->size)
		{
			log_blk(block);
			block = NEXT_BLOCK(block);
		}
		zone = zone->next;
	}
}
