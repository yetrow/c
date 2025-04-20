#include<stdio.h>
#include<stdlib.h>

//动态内存

int main(void)
{
    int n;
    printf("输入数组的大小\n");
    scanf_s("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));//相当于(int*)realloc(NULL,n*sizeof(int)
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    // free(a); 而int *p=(int*)realloc(a,0)=free(a);
    // puts("\n");
    // int *b=(int*)calloc(n,sizeof(int));
    // // for(int i=0;i<n;i++)
    // // {
    // //     a[i]=i;
    // // }
    // for(int i=0;i<n;i++)
    // {
    //     printf("%d ",b[i]);
    // }
    // free(b);

    puts("\n");
    int* c = (int*)realloc(a, 2 * n * sizeof(int));
    printf("a=%d,c=%d\n", a, c);
    for (int i = 0; i < 2*n; i++)
    {
        printf("%d ", c[i]);
    }
    return 0;
}