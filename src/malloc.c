#include "ft_malloc.h"

t_zone *g_zones = NULL;

void *malloc(size_t size)
{
	write(1, "malloc(", 7);
	log_nb(size, 10);
	write(1, ") - ", 4);
	if (size == 0)
		return (NULL);
	size = align(size);
	t_block *ptr = get_block(size);
	if (!ptr)
		return (NULL);
	log_nb((unsigned long)GET_DATA(ptr), 16);
	write(1, "\n", 1);
	return GET_DATA(ptr);
}

void *realloc(void *ptr, size_t size)
{
	write(1, "realloc\n", 8);
	(void)ptr;
	(void)size;
	return NULL;
}

void free(void *ptr)
{
	write(1, "free(", 5);
	log_nb((unsigned long)ptr, 16);
	write(1, ")\n", 2);
	if (!ptr)
		return;
	return_block(ptr);
}
