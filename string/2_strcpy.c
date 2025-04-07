//strcpy用法
// strcpy函数的用法：将源字符串拷贝到目标字符串中，
//注意目标字符串的大小要足够大，否则会造成缓冲区溢出

#include<stdio.h>
#include<string.h>

int main(void)
{
    const char s[]="hello1";
    char d[50];
    //strcpy(d,s);
    strcpy_s(d,50,s);  //将s的内容拷贝到d中，需要给出d的size即sizeof(dest);  
    printf("%s\n",d);
    return 0;
}