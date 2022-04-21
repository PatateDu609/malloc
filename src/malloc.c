#include "ft_malloc.h"

t_zone *g_zones = NULL;

void *malloc(size_t size)
{
	size = align(size);
	t_block *ptr = get_block(size);
	if (!ptr)
		return (NULL);
	return GET_DATA(ptr);
}

void *realloc(void *ptr, size_t size)
{
	(void)ptr;
	(void)size;
	return NULL;
}

void free(void *ptr)
{
	(void)ptr;
}
