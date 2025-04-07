#include<stdio.h>
#include<stdlib.h>


/* 结构体数组
 * 结构体数组：在一个结构体中定义另一个结构体类型的成员变量
 * 结构体指针访问结构体成员：使用->运算符来访问指针所指向的结构体的成员变量
 */

typedef struct{
    int x;
    int y;
}point;

int main(void)
{
    point num[2]={
        {1,2},
        {3,4}
    };

    for(size_t i=0;i<2;i++)
    {
        printf("x=%d,y=%d\n",num[i].x,num[i].y);
    }

    return 0;
}