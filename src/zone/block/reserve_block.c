#include "zones.h"

static t_block *get_block(t_block *block, t_zone *zone, size_t size)
{
	size_t s = 0;

	while (block->size && IS_INSIDE_ZONE(zone, block))
	{
		s += block->size;

		if (block->free && block->size >= size)
			return (block);
		block = NEXT_BLOCK(block);
	}
	if (size + sizeof(t_block) <= zone->size - s - sizeof(t_zone))
		return (block);
	return (NULL);
}

t_block *reserve_block(t_zone *zone, size_t size)
{
	t_block *block = GET_FIRST_BLOCK(zone);
	if (block->size)
		block = get_block(block, zone, size);
	if (!block || zone->size < size + sizeof(t_block))
		return (NULL);
	size_t old = block->size;

	block->free = 0;
	block->size = size;

	if (block->size < old)
		split_block(zone, block, old);

	return (block);
}
