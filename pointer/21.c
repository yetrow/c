//回调函数
#include<stdio.h>
void sort(int *a,int n,int(*compare)(int,int))
{
    int i,j,temp;
    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++)
        {
            if(compare(a[j],a[j+1])>0)
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
    }
}
}
int compare(int a,int b)
{
    if(a>b) return 1;
    else return -1;
}
int main(void)
{
    int i,a[]={3,2,1,5,6,4};
    sort(a,6,compare);
    for(i=0;i<6;i++) printf("%d ",a[i]);
    return 0;
}


/*
void a()
{
    printf("hello\n");
}

void b(void(*ptr)())
{
    ptr();
}

int main(void)
{
    void(*p)()=a;
    b(p);


    return 0;
}
*/