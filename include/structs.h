#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdlib.h>

typedef enum e_zone_type
{
	TINY,
	SMALL,
	LARGE
} t_zone_type;

typedef struct s_block
{
	size_t size;
	u_int16_t free;
} t_block;

typedef struct s_zone
{
	struct s_zone *next;
	struct s_zone *prev;
	size_t size;
	t_zone_type type;
} t_zone;

extern t_zone *g_zones;

#endif
