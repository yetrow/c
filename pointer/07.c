#include<stdio.h>
#include<stdlib.h>

//函数返回指针

void print()
{
    printf("hello\n");

}
int *add(int *a,int *b)
{

    printf("函数a的地址(&a)是%d\n",&a);
    printf("函数中a的地址是(地址是main函数中的a)%d\n",a);
    printf("*a的值是%d\n",*a);
   int *c=(int*)malloc(sizeof(int));//错误写法: int c=(*a)+(*b);
   *c=(*a)+(*b);                    //          return &c;
   return c; 
   //返回的是heap上的内存地址，而不是stack上的
}

int main(void)
{
    int a=2,b=4;
    printf("main中a的地址是%d\n",&a);
    int *p=add(&a,&b);
    print();
    //紧接着调用 print()，print 函数的栈帧会覆盖 add 函数的栈帧（包括原来的 c 的位置）。
    //因此，printf("sum=%d", *p); 尝试读取的 *p 可能已经被 print 的栈数据覆盖，导致输出错误或崩溃。
    printf("sum=%d",*p);
    free(p);
    return 0;
}

// // 方法1：直接返回值（推荐）
// int add(int a, int b) {
//     return a + b;
// }

// // 方法2：通过指针参数返回
// void add(int a, int b, int *result) {
//     *result = a + b;
// }

// int main() {
//     // 方法1
//     int sum = add(2, 4);
//     printf("sum=%d\n", sum);

//     // 方法2
//     int res;
//     add(2, 4, &res);
//     printf("sum=%d\n", res);
// }
