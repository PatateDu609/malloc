#include "ft_malloc.h"
#include "utils.h"

static t_block *get_new_block(size_t size, t_block *old)
{
	t_block *new_block = malloc(size);

	if (!new_block)
		return (NULL);
	ft_memcpy(new_block, old, old->size);
	return (new_block);
}

t_block *__realloc(t_block *block, size_t size)
{
	t_block *new_block = resize_block(block, size);

	if (!new_block)
		return (get_new_block(size, block));
	return (new_block);
}
