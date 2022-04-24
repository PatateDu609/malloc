#include "zones.h"

static t_block *select_block(t_block *block, t_zone *zone, size_t size)
{
	size_t s = 0;

	while (IS_INSIDE_ZONE(zone, block))
	{
		s += block->size + sizeof(t_block);
		if (block->free && block->size >= size)
			return (block);
		block = NEXT_BLOCK(block);
	}
	return (NULL);
}

t_block *reserve_block(t_zone *zone, size_t size)
{
	t_block *block = GET_FIRST_BLOCK(zone);
	if (IS_LARGE(size))
	{
		block->size = zone->size - sizeof(t_zone) - sizeof(t_block);
		block->free = 0;
		return (block);
	}
	if (block->size)
		block = select_block(block, zone, size);
	if (!block || zone->size < size + sizeof(t_block))
		return (NULL);
	size_t old = block->size;

	block->size = size;
	block->free = 0;

	if (block->size < old)
		split_block(zone, block, old);

	return (block);
}
