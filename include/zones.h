#ifndef ZONES_H
#define ZONES_H

#include "defines.h"
#include "structs.h"
#include "logger.h"

#include <sys/mman.h>
#include <string.h>

size_t get_zone_size(t_zone_type type, size_t size);
t_zone *get_zone(t_block *block);
t_zone_type get_zone_type(size_t size);

t_zone *alloc_zone(size_t size);
void free_zone(t_zone *zone);
void append_zone(t_zone *zone);
void remove_zone(t_zone *zone);
t_block *get_block(size_t size);
t_block *get_previous_block(t_zone *zone, t_block *block);

t_block *reserve_block(t_zone *zone, size_t size);
void return_block(void *block);
void split_block(t_zone *zone, t_block *block, size_t old);
t_block *resize_block(t_block *block, size_t size);
u_int8_t chk_ptr(t_zone *zone, void *ptr);

void show_alloc_mem(void);
void show_alloc_mem_ex(void);

#endif
