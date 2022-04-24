#include "zones.h"
#include "utils.h"

static u_int8_t is_last_of_type(t_zone *zone)
{
	t_zone *z = g_zones;

	if (zone->type == LARGE)
		return 0;
	while (z)
	{
		if (zone != z && z->type == zone->type)
			return 0;
		z = z->next;
	}
	return 1;
}

void free_zone(t_zone *zone)
{
	if (!IS_ZONE_EMPTY(zone) || is_last_of_type(zone))
		return;
	remove_zone(zone);
	munmap(zone, zone->size);
}
