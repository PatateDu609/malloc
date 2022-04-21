#include "utils.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *p = (unsigned char *)dst;
	const unsigned char *q = (const unsigned char *)src;

	while (n--)
		*p++ = *q++;
	return (dst);
}
