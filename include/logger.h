#ifndef LOGGER_H
#define LOGGER_H

#include "defines.h"
#include "structs.h"
#include <unistd.h>

void log_blk(t_block *block);
void log_zone(t_zone *zone);

void log_nb(unsigned long nb, int base);

#endif
