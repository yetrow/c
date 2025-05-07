#include<stdio.h>
#include<stdlib.h>  //qsort()

//比较函数
int compare_values(const void* a,const void* b);
void generic_sort(void*array,size_t element_size,size_t element_count\
,int (*compare)(const void*,const void*));

int main(void)
{
    int ints[]={-2,90,0,-123,3,41,1};
    size_t ints_count=sizeof(ints)/sizeof(ints[0]);
    int a=5,b=3;
    printf("%d\n",compare_values(&a,&b));

    generic_sort(ints,sizeof(ints[0]),ints_count,compare_values);
    for(size_t i=0;i<ints_count;i++)
    {
        printf("%d ",ints[i]);
    }
    
    return 0;
}

int compare_values(const void* a,const void* b)
{
    int arg1=*(const int*)a;
    int arg2=*(const int*)b;
    if(arg1<arg2) return -1;
    else return 1;
    return 0;
}

void generic_sort(void*array,size_t element_size,size_t element_count\
    ,int (*compare)(const void*,const void*))
{
    qsort(array,element_count,element_size,compare);
}
    