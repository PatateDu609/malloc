#include "zones.h"

t_block *get_block(size_t size)
{
	t_zone *zone;
	t_block *block;
	t_zone_type type = get_zone_type(size);

	zone = g_zones;
	while (zone)
	{
		if (zone->type == type && type != LARGE)
		{
			block = reserve_block(zone, size);
			if (block)
				return (block);
		}
		zone = zone->next;
	}
	return (reserve_block(alloc_zone(size), size));
}
