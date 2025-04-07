#include<stdio.h>
#include<stdlib.h>

/* 结构体嵌套结构体
 * 结构体指针访问结构体成员
 * 
 * 结构体嵌套结构体：在一个结构体中定义另一个结构体类型的成员变量
 * 结构体指针访问结构体成员：使用->运算符来访问指针所指向的结构体的成员变量
 */

typedef struct {
    char address[20];
    char city[20];
    char country[20];
}address;

typedef struct{
    char name[20];
    int age;
    address addr;
}person;


int main(void){

    person tom={
        "tom",
        20,
        {"123 Main St", "New York", "USA"}
    };

    printf("name=%s\n",tom.name);
    printf("age=%d\n",tom.age);
    printf("address=%s\n",tom.addr.address);
    printf("city=%s\n",tom.addr.city);
    printf("country=%s\n",tom.addr.country);

    puts("------------------\n");

    person*p=&tom;
    printf("name=%s\n",p->name);
    printf("age=%d\n",p->age);
    printf("address=%s\n",p->addr.address);

    return 0;
}