#include "zones.h"

t_block *get_block(size_t size)
{
	t_zone *zone;
	t_block *block;
	size_t target = get_zone_size(size);

	zone = g_zones;
	while (zone)
	{
		if (zone->size == target)
		{
			block = reserve_block(zone, size);
			if (block)
				return (block);
		}
		zone = zone->next;
	}
	return (reserve_block(alloc_zone(size), size));
}
