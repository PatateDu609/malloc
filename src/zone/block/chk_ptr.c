#include "zones.h"

static t_zone *get_zone_from_data(void *ptr)
{
    t_zone *zone = g_zones;

    while (zone)
    {
        if (IS_INSIDE_ZONE(zone, ptr))
            return zone;
        zone = zone->next;
    }
    return NULL;
}

u_int8_t chk_ptr(t_zone *zone, void *ptr)
{
    if (!ptr)
        return 0;
    if (zone == NULL)
        zone = get_zone_from_data(ptr);
    if (!zone)
        return 0;
    t_block *block = GET_BLOCK(ptr);
    t_block *first = GET_FIRST_BLOCK(zone);
    while (IS_INSIDE_ZONE(zone, first))
    {
        if (first == block)
            return 1;
        first = NEXT_BLOCK(first);
    }
    return 0;
}