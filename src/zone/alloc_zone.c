#include "zones.h"
#include "utils.h"

static void init_zone(t_zone *zone)
{
	t_block *block = GET_FIRST_BLOCK(zone);
	block->size = zone->size - sizeof(t_zone);
	block->free = 1;
}

t_zone *alloc_zone(size_t size)
{
	t_zone_type type = get_zone_type(size);
	size_t zone_size = get_zone_size(type, size);
	void *zone = mmap(NULL, zone_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

	if (zone == MAP_FAILED)
		return (NULL);

	t_zone *zone_struct = (t_zone *)zone;
	zone_struct->size = zone_size;
	zone_struct->type = type;

	init_zone(zone_struct);

	if (!g_zones)
		g_zones = zone_struct;
	else
		append_zone(zone_struct);
	return (zone_struct);
}
