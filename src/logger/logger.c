#include "logger.h"

void log_blk(t_block *block)
{
	log_nb((unsigned long)block, 16);
	write(1, " - ", 3);
	log_nb((unsigned long)block + block->size, 16);
	write(1, " : ", 3);
	log_nb(block->size, 10);
	write(1, " bytes ", 7);
	if (block->free)
		write(1, "(\033[0;32mfree\033[0m)\n", 19);
	else
		write(1, "(\033[0;31mused\033[0m)\n", 19);
}

void log_zone(t_zone *zone)
{
	if (zone->size == TINY_ZONE)
		write(1, "TINY (", 6);
	else if (zone->size == SMALL_ZONE)
		write(1, "SMALL (", 7);
	else
		write(1, "LARGE (", 7);
	log_nb(zone->size, 10);
	write(1, " bytes) : ", 10);
	log_nb((unsigned long)zone, 16);
	write(1, "\n", 1);
}
