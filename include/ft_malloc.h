#ifndef MALLOC_H
#define MALLOC_H

#include <stdlib.h>
#include <unistd.h>

#include "defines.h"
#include "structs.h"
#include "zones.h"

size_t align(size_t size);

t_block *__realloc(t_block *block, size_t size);

void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void free(void *ptr);

#endif
