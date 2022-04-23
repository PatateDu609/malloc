#include "zones.h"
#include "utils.h"

// static t_block *resize_back(t_block *prev, t_block *block, size_t size)
// {

// 	prev->size += sizeof(t_block) + block->size;
// 	prev->free = 0;

// 	return (prev->size >= size ? prev : NULL);
// }

static void ft_special_merge_block(t_block *block, t_block *next, size_t size)
{
	size_t min = ft_min(size - block->size, next->size + sizeof(t_block));
	size_t old = next->size;

	if (min == next->size)
		return;
	else
	{
		t_block *new_block;

		block->size = size;
		block->free = 0;
		new_block = NEXT_BLOCK(block);
		new_block->size = old - min;
		new_block->free = 1;
		return;
	}
}

t_block *resize_block(t_block *block, size_t size)
{
	t_zone *zone = get_zone(block);
	if (!zone)
		return NULL;
	t_block *next = NEXT_BLOCK(block);
	if (IS_INSIDE_ZONE(zone, next) && next->free)
		ft_special_merge_block(block, next, size);
	if (block->size >= size)
		return block;
	// t_block *prev = get_previous_block(zone, block);
	// if (prev && prev->free)
	// 	return resize_back(prev, block, size);
	return NULL;
}
