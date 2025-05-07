#include "compare.h"
#include "person.h"

#include<string.h>
#include<stdint.h>

int intCompare(const void* a,const void* b,void* context)
{
    (void)context;
    int intA=*(const int*)a;
    int intB=*(const int*)b;
    return intA-intB; 
}

int stringCompare(const void*a,const void* b,void* context)
{
    (void)context;
    const char* str1=*(const char**)a;
    const char* str2=*(const char**)b;
    return strncmp(str1,str2,SIZE_MAX);
}

int CompareByName(const void*a,const void* b,void* context)
{
    (void)context;
    const Person* personA=(const Person*)a;
    const Person* personB=(const Person*)b;
    return strncmp(personA->name,personB->name,SIZE_MAX);
}

int CompareByAge(const void*a,const void* b,void* context)
{
    (void)context;
    const Person* personA=(const Person*)a;
    const Person* personB=(const Person*)b;
    return personA->age-personB->age;
}