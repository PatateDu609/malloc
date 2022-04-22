#include "zones.h"

t_zone *get_zone(t_block *block)
{
	t_zone *zone;

	zone = g_zones;
	while (zone)
	{
		if (IS_INSIDE_ZONE(zone, block))
			return (zone);
		zone = zone->next;
	}
	return (NULL);
}

t_block *get_previous_block(t_zone *zone, t_block *block)
{
	t_block *tmp;
	t_block *prev;

	tmp = GET_FIRST_BLOCK(zone);
	prev = NULL;
	while (tmp != block)
	{
		prev = tmp;
		tmp = NEXT_BLOCK(tmp);
	}
	return (prev);
}

static void defragmentate(t_zone *zone, t_block *block)
{
	t_block *prev = get_previous_block(zone, block);
	t_block *next = NEXT_BLOCK(block);

	if (IS_INSIDE_ZONE(zone, next) && next->free)
		block->size += next->size + sizeof(t_block);
	if (prev && prev->free)
		prev->size += block->size + sizeof(t_block);
}

void return_block(void *data)
{
	t_block *block = data - sizeof(t_block);
	block->free = 1;

	t_zone *zone = get_zone(block);
	if (!zone)
		return;
	defragmentate(zone, block);
	if (IS_ZONE_EMPTY(zone))
		free_zone(zone);
}
