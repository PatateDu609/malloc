#ifndef ZONES_H
#define ZONES_H

#include "defines.h"
#include "structs.h"
#include "logger.h"

#include <sys/mman.h>
#include <string.h>

size_t get_zone_size(size_t size);

t_zone *alloc_zone(size_t size);
void append_zone(t_zone *zone);

t_block *reserve_block(t_zone *zone, size_t size);
void split_block(t_zone *zone, t_block *block, size_t old);

void show_alloc_mem(void);

#endif
