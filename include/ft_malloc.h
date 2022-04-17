#ifndef MALLOC_H
#define MALLOC_H

#include <stdlib.h>
#include <unistd.h>

#include "defines.h"
#include "structs.h"
#include "zones.h"

void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void free(void *ptr);

#endif
