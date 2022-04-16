#ifndef MALLOC_H
#define MALLOC_H

#include <stdlib.h>
#include <unistd.h>

void *malloc(size_t size);
void free(void *ptr);

#endif
