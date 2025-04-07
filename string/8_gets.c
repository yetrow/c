// #include<stdio.h>
// #include<string.h>

// int main(void)
// {
//     char butter[100]={0};
//     if(gets_s(butter,sizeof(butter))==NULL)
//     {
//         printf("error\n");
//     }
//     else{
//         printf("你的输入是%s\n",butter);
//     }

//     return 0;
// }

#include <stdio.h>
#include <string.h>

//gets_s() 是 C11 标准引入的安全替代 gets() 的函数，但 MinGW 默认没有实现它。

int main(void)
{
    char butter[100] = {0};
    if (gets_s(butter, sizeof(butter)) == NULL)
    {
        printf("error\n");
    }
    else
    {
        printf("你的输入是%s\n", butter);
    }

    return 0;
}