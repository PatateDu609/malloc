#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_malloc.h"

int main(int ac, char **av)
{
    int n = atoi(av[1]);
    int m = atoi(av[2]);

    printf("N = %d, M = %d\n", n, m);
    int tiny = ((n + sizeof(t_block)) * 100) / getpagesize();
    int small = ((m + sizeof(t_block)) * 100) / getpagesize();
    printf("tiny = %d, small = %d\n", tiny, small);
    return 0;
}