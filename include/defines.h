#ifndef DEFINES_H
#define DEFINES_H

#include <unistd.h>
#include <stddef.h>
#include <stdalign.h>

#define ALIGNMENT alignof(max_align_t)

#define N 1024
#define M 8192

#define TINY_ZONE ((size_t)getpagesize() * 25)
#define SMALL_ZONE ((size_t)getpagesize() * 200)

#define IS_TINY(size) (1 <= size && size <= N)
#define IS_SMALL(size) (N < size && size <= M)
#define IS_LARGE(size) (!IS_TINY(size) && !IS_SMALL(size))

#define GET_FIRST_BLOCK(zone) ((t_block *)((void *)zone + sizeof(t_zone)))
#define GET_DATA(block) ((void *)block + sizeof(t_block))
#define GET_BLOCK(ptr) ((t_block *)((void *)ptr - sizeof(t_block)))

#define NEXT_BLOCK(block) ((t_block *)((void *)block + sizeof(t_block) + block->size))

#define IS_INSIDE_ZONE(zone, block) (zone && (void *)zone < (void *)block && \
									 (void *)block < (void *)zone + zone->size)

#define IS_ZONE_EMPTY(zone) (zone->size == sizeof(t_zone) + GET_FIRST_BLOCK(zone)->size || \
							 (zone->type == LARGE && GET_FIRST_BLOCK(zone)->free))

#endif
