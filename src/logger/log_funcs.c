#include "logger.h"

void log_malloc(void *ptr, size_t size)
{
	log_nb((unsigned long)ptr, 16);
	write(1, " = malloc(", 10);
	log_nb(size, 10);
	write(1, ");\n", 3);
}

void log_realloc(void *data, void *ptr, size_t size)
{
	log_nb((unsigned long)data, 16);
	write(1, " = realloc(", 11);
	log_nb((unsigned long)ptr, 16);
	write(1, ", ", 2);
	log_nb(size, 10);
	write(1, ");\n", 3);
}

void log_calloc(void *ptr, size_t nmemb, size_t size)
{
	log_nb((unsigned long)ptr, 16);
	write(1, " = calloc(", 10);
	log_nb(nmemb, 10);
	write(1, ", ", 2);
	log_nb(size, 10);
	write(1, ");\n", 3);
}

void log_free(void *ptr)
{
	write(1, "free(", 6);
	log_nb((unsigned long)ptr, 16);
	write(1, ");\n", 3);
}
