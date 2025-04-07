//字符数组
#include<stdio.h>
#include<string.h>

int main(void)
{
    char c[6]="john";
    // c[0]='j' ;
    // c[1]='o' ;
    // c[2]='h' ;
    // c[3]='n' ;
    // c[4]='\0' ;
    // c[5]='\0' ;
    // c[6]='\0' ;
    printf("c的sizeof长度%d\n",sizeof(c));
    int len=strlen(c);
    printf("c是%s\n",c);
    printf("c的strlen长度%d\n",len);

    puts("------\n");

    char d[6]={'j','o','h','n','\0'};
    // d[0]='j' ;
    // d[1]='o' ;
    // d[2]='h' ;
    // d[3]='n' ;
    // d[4]='\0' ;
    // d[5]='\0' ;
    // d[6]='\0' ;
    printf("d的sizeof长度%d\n",sizeof(d));
    int len1=strlen(d);
    printf("d是%s\n",d);
    printf("d的strlen长度%d\n",len1);


    return 0;
}