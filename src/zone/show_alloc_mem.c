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
		if (zone->used)
		{
			t_block *block = GET_FIRST_BLOCK(zone);

			while (block)
			{
				log_blk(block);
				block = NEXT_BLOCK(block);
			}
		}
		else
			write(1, "No block in this zone\n", 23);
		zone = zone->next;
	}
}
