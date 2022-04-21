#include "zones.h"

void free_zone(t_zone *zone)
{
	if (!IS_ZONE_EMPTY(zone))
		return;
	remove_zone(zone);
	munmap(zone, zone->size);
}
