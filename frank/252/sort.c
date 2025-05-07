#include "sort.h"
#include<stdlib.h>

//包装器
static int compareWarpper(void* context,const void* a,const void*b)
{
    CompareFunc compare=(CompareFunc)context;
    return compare(a,b,NULL);
}

void genericSort(void*array,size_t length,size_t size,\
    CompareFunc compare,void* contxt)
{
#ifdef _WIN32
    qsort_s(array,length,size,compareWarpper,(void*)compare);
#else
    qsort(array,length,size,compareWarpper,context);
#endif
}