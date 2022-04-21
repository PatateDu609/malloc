#include "zones.h"
#include "ft_malloc.h"

void split_block(t_zone *zone, t_block *block, size_t old)
{
	t_block *new_block = NEXT_BLOCK(block);
	size_t new_size = old - block->size - sizeof(t_block);

	if (IS_INSIDE_ZONE(zone, new_block) && new_size >= sizeof(t_block))
	{
		new_block->size = new_size;
		new_block->free = 1;
	}
	else
		block->size = old;
}
