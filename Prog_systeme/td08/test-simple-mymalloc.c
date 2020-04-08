#include <stdio.h>
#include <strings.h>
#include "malloc.h"

int main()
{
    void *ptr1 = mymalloc(128);
    void *ptr2 = mymalloc(256);
    void *ptr3 = mymalloc(128);
    void *ptr4 = mymalloc(512);
    myfree(ptr2);

    // Add your code here.
    void *ptr5 = mymalloc(384);
    void *ptr6 = mymalloc(128);
    void *ptr7 = mymalloc(64);
}