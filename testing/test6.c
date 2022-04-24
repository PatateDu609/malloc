#include <stdlib.h>

void show()
{
#ifndef TRUE_MALLOC 
    show_alloc_mem();
#endif
}

int main()
{
    malloc(1024);
    malloc(1024 * 32);
    malloc(1024 * 1024);
    malloc(1024 * 1024 * 16);
    malloc(1024 * 1024 * 128);
    show();
    return (0); 
}