#include<stdio.h>
#include<stdlib.h>


/* 枚举类型
 * 枚举类型：枚举类型是一种用户自定义的数据类型，它由一组命名的整数常量组成。 
 * 枚举类型的定义使用关键字enum，后面跟着一个枚举类型的名称和一个包含枚举常量的列表。
 * 枚举常量的值从0开始，依次递增。
 * 
 * 枚举类型的使用：可以使用枚举类型来定义变量，并将其赋值为枚举常量。 
 * 也可以将枚举常量作为函数参数或返回值。
 */

typedef enum{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
}weekdays;

int main(void)
{
    
    printf("%d\n",MONDAY);

    weekdays day=FRIDAY;
    printf("%d\n",day);
    return 0;

}