#include "logger.h"

static char *get_base_set(int base)
{
	if (base == 16)
		return ("0123456789abcdef");
	else
		return ("0123456789");
}

static void _log_nb(unsigned long n, int l, char *base)
{
	if (n / l)
		_log_nb(n / l, l, base);
	write(1, &base[n % l], 1);
}

void log_nb(unsigned long n, int base)
{
	char *base_set = get_base_set(base);
	if (base == 16)
		write(1, "0x", 2);
	_log_nb(n, base, base_set);
}
