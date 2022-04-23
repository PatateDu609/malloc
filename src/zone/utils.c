#include "zones.h"

size_t get_zone_size(t_zone_type type, size_t size)
{
	switch (type)
	{
	case TINY:
		return (TINY_ZONE + sizeof(t_zone));
	case SMALL:
		return (SMALL_ZONE + sizeof(t_zone));
	case LARGE:
		return (size + sizeof(t_zone) + sizeof(t_block));
	default:
		return (0);
	}
}

t_zone_type get_zone_type(size_t size)
{
	if (size <= N)
		return (TINY);
	if (size <= M)
		return (SMALL);
	return (LARGE);
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
