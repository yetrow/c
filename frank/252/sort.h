#pragma once
#include<stddef.h>

//泛型编程
typedef int(*CompareFunc)(const void*,const void*, void* contxt);

void genericSort(void* array,size_t length,size_t size,CompareFunc compare,void*contxt);