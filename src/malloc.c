#include "ft_malloc.h"
#include "utils.h"

t_zone *g_zones = NULL;
pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;

void *malloc(size_t size)
{
	pthread_mutex_lock(&g_mutex);
	if (size == 0)
		return (NULL);
	size = align(size);
	t_block *ptr = get_block(size);
	if (!ptr)
		return (NULL);
	// log_malloc(GET_DATA(ptr), size);
	pthread_mutex_unlock(&g_mutex);
	return GET_DATA(ptr);
}

void *realloc(void *ptr, size_t size)
{
	pthread_mutex_lock(&g_mutex);
	if (!chk_ptr(NULL, ptr))
		return NULL;
	t_block *block = __realloc(ptr, size);
	if (!block)
		return (NULL);
	// log_realloc(GET_DATA(block), ptr, size);
	pthread_mutex_unlock(&g_mutex);
	return GET_DATA(block);
}

void *calloc(size_t nmemb, size_t size)
{
	pthread_mutex_lock(&g_mutex);
	size_t total = nmemb * size;
	if (total == 0)
		return (NULL);
	size = align(total);
	t_block *block = get_block(size);
	if (!block)
		return (NULL);
	ft_memset(GET_DATA(block), 0, total);
	// log_calloc(GET_DATA(block), nmemb, size);
	pthread_mutex_unlock(&g_mutex);
	return GET_DATA(block);
}

void free(void *ptr)
{
	pthread_mutex_lock(&g_mutex);
	if (!ptr)
		return;
	return_block(ptr);
	// log_free(ptr);
	pthread_mutex_unlock(&g_mutex);
}
