#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdlib.h>

typedef struct s_block
{
	size_t size;
	int free;
} t_block;

typedef struct s_zone
{
	struct s_zone *next;
	struct s_zone *prev;
	size_t size;
} t_zone;

extern t_zone *g_zones;

#endif
