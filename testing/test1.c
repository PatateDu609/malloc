#include <stdlib.h>

//to test with /usr/bin/time -v

void show()
{
#ifndef TRUE_MALLOC 
    show_alloc_mem();
#endif
}

int      main(void)
{
    int   i;
    char  *addr;

    i = 0;
    while (i < 1024)
    {
        addr = (char*)malloc(1024);
        addr[0] = 42;
        i++;
    }
    // show();
    return (0);
}
