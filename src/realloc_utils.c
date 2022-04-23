#include "ft_malloc.h"
#include "utils.h"

static t_block *get_new_block(size_t size, t_block *old)
{
	void *new_block = get_block(size);

	if (!new_block)
		return (NULL);
	ft_memcpy(GET_DATA(new_block), GET_DATA(old), old->size);
	return (new_block);
}

static t_block *__realloc_new_blk(void *ptr, size_t size)
{
	t_block *block = GET_BLOCK(ptr);
	t_block *new_block = resize_block(block, size);

	if (!new_block)
	{
		free(ptr);
		return (get_new_block(size, block));
	}
	return (new_block);
}

t_block *__realloc(void *ptr, size_t size)
{
	if (!ptr)
		return (get_block(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	size = align(size);
	t_block *block = GET_BLOCK(ptr);
	if (block->size >= size)
		return (ptr);
	return (__realloc_new_blk(ptr, size));
}
