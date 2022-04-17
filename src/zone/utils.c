#include "zones.h"

size_t get_zone_size(size_t size)
{
	if (IS_TINY(size))
		return (TINY_ZONE);
	else if (IS_SMALL(size))
		return (SMALL_ZONE);
	else
		return (size);
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
