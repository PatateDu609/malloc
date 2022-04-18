#include "zones.h"

static void init_zone(t_zone *zone)
{
	t_block *block = GET_FIRST_BLOCK(zone);
	block->size = zone->size - sizeof(t_zone);
	block->free = 1;
}

t_zone *alloc_zone(size_t size)
{
	size_t zone_size = get_zone_size(size);
	void *zone = mmap(NULL, zone_size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

	if (zone == MAP_FAILED)
		return (NULL);

	memset(zone, 0, zone_size);
	t_zone *zone_struct = (t_zone *)zone;
	zone_struct->size = zone_size;

	init_zone(zone_struct);

	if (!g_zones)
		g_zones = zone_struct;
	else
		append_zone(zone_struct);
	return (zone_struct);
}
