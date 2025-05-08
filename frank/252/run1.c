#include<stdio.h>
#include<stdlib.h>  //qsort()

#include "compare.h"
#include "sort.h"
#include "person.h"

int main(void)
{
    int intArr[]={1,6,3,4,65,532,511,543,86,234};

    const char* stringArr[]={"banana","apple","frank","xiaomi","microsoft","tencent"};

    genericSort(intArr,10,sizeof(intArr[0]),intCompare,NULL);
    genericSort(stringArr,6,sizeof(stringArr[0]),stringCompare,NULL);

    puts("\nintArr[]= ");
    for(size_t i=0;i<10;i++)
    {
        printf("%d ",intArr[i]);
    }

    puts("\nstringArr[]= ");
    for(size_t i=0;i<6;i++)
    {
        printf("%s ",stringArr[i]);
    }

    Person personArr[]={
        {"frank",30},
        {"tom",25},
        {"jerry",241},
        {"alice",87},
        {"david",654}
    };
    size_t peopleCount=sizeof(personArr)/sizeof(personArr[0]);
    CompareFunc compareFunctions[]={CompareByName,CompareByAge};

    int compareChoice=1; //0 for name,1 for age;

    genericSort(personArr,peopleCount,sizeof(Person),compareFunctions[compareChoice],NULL);

    puts("\npersonArr[]= ");
    for(size_t i=0;i<peopleCount;i++)
    {
        printf("%s,%d\n",personArr[i].name,personArr[i].age);
    }

    return 0;
}