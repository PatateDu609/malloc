#include "zones.h"

static t_block *get_block(t_block *block, t_zone *zone, size_t size)
{
	while (block->size)
	{
		if (block->free && block->size >= size)
			return (block);
		block = NEXT_BLOCK(block);
	}
	if ((void *)block < (void *)zone + zone->size)
		return (block);
	return (NULL);
}

t_block *reserve_block(t_zone *zone, size_t size)
{
	t_block *block = GET_FIRST_BLOCK(zone);
	if (block->size)
		block = get_block(block, zone, size);
	size_t old = block->size;

	block->free = 0;
	block->size = size;

	if (block->size < old)
		split_block(zone, block, old);

	return (block);
}
