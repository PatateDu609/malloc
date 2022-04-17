#include "zones.h"

void split_block(t_zone *zone, t_block *block, size_t old)
{
	t_block *new_block = NEXT_BLOCK(block);
	(void)zone;

	if ((void *)new_block < (void *)zone + zone->size &&
		old - block->size > sizeof(t_block))
	{
		new_block->size = old - block->size - sizeof(t_block);
		new_block->free = 1;
	}
	else
		block->size = old;
}
