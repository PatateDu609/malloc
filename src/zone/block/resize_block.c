#include "zones.h"

static t_block *resize_back(t_block *prev, t_block *block, size_t size)
{

	prev->size += sizeof(t_block) + block->size;
	prev->free = 0;

	return (prev->size >= size ? prev : NULL);
}

t_block *resize_block(t_block *block, size_t size)
{
	t_zone *zone = get_zone(block);
	if (!zone)
		return NULL;
	t_block *next = NEXT_BLOCK(block);
	if (IS_INSIDE_ZONE(zone, next) && next->free)
	{
		block->size += next->size + sizeof(t_block);
		next->free = 0;
	}
	if (block->size >= size)
		return block;
	t_block *prev = get_previous_block(zone, block);
	if (prev && prev->free)
		return resize_back(prev, block, size);
	return NULL;
}
