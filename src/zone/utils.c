#include "zones.h"

size_t get_zone_size(size_t size)
{
	if (IS_TINY(size))
		return (TINY_ZONE);
	else if (IS_SMALL(size))
		return (SMALL_ZONE);
	else
		return (size + sizeof(t_zone) + sizeof(t_block));
}

void append_zone(t_zone *zone)
{
	t_zone *tmp = g_zones;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = zone;
	zone->prev = tmp;
	zone->next = NULL;
}

void remove_zone(t_zone *zone)
{
	if (zone->prev)
		zone->prev->next = zone->next;
	if (zone->next)
		zone->next->prev = zone->prev;
	if (zone == g_zones)
		g_zones = zone->next;
}

size_t align(size_t size)
{
	return ((size + (ALIGNMENT - 1)) & ~(ALIGNMENT - 1));
}
