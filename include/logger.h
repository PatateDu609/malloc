#ifndef LOGGER_H
#define LOGGER_H

#include "defines.h"
#include "structs.h"
#include <unistd.h>

void log_blk(t_block *block);
void log_zone(t_zone *zone);

void log_nb(unsigned long nb, int base);

void log_malloc(void *ptr, size_t size);
void log_realloc(void *data, void *ptr, size_t size);
void log_calloc(void *ptr, size_t nmemb, size_t size);
void log_free(void *ptr);

#endif
