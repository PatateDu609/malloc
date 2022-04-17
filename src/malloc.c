#include "ft_malloc.h"

t_zone *g_zones = NULL;

void *malloc(size_t size)
{
	(void)size;
	return NULL;
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
