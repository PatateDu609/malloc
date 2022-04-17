#include "zones.h"

t_block *reserve_block(t_zone *zone, size_t size)
{
	t_block *block = GET_FIRST_BLOCK(zone);
	if (!zone->used)
	{
		zone->used = 1;

		block->size = size;
		block->free = 0;
	}
	return (block);
}
