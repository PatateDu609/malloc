#include <stdlib.h>

int main()
{
    void *ptr = malloc(128);
    void *ptr1 = malloc(16);
    int *ptr2 = malloc(sizeof(int));
    *ptr2 = 5;
    show_alloc_mem_ex(); 
    return (0); 
}