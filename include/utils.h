#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

size_t align(size_t size);

size_t ft_max(size_t a, size_t b);
size_t ft_min(size_t a, size_t b);
void *ft_memset(void *s, int c, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);

#endif
