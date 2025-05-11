#include <stdio.h> // 包含标准输入输出库，用于printf和fprintf等函数
#include <stdarg.h> // 包含可变参数列表库，用于处理可变数量的函数参数


/**
 * 计算可变参数的平均值
 * @param num 参数数量
 * @param ... 可变参数列表(整数)
 * @return 平均值，如果参数无效返回0.0
 */
double average(int num, ...) // 定义一个函数，计算可变数量整数参数的平均值
{
    if (num <= 0) { // 检查参数数量是否有效
        fprintf(stderr, "Error: Invalid parameter count %d\n", num); // 如果无效，输出错误信息到标准错误流
        return 0.0; 
    }

    double sum = 0.0; // 初始化总和为0.0
    va_list args; // 声明一个va_list变量，用于存储可变参数列表信息

    va_start(args, num); // 初始化可变参数列表，num是最后一个固定参数

    for (int i = 0; i < num; i++) { // 循环遍历可变参数
        int value = va_arg(args, int); // 获取当前可变参数的值，并指定其类型为int
        sum += value; // 将获取的值加到总和中
    }

    va_end(args); // 结束可变参数列表的处理

    return num>0 ? sum / num : 0; // 计算并返回平均值，如果num>0则返回sum/num，否则返回0
}

int main(void)
{
   
    printf("Average: %.2f\n", average(3, 1, 2, 3)); // 调用average函数计算1, 2, 3的平均值并打印
    printf("Average: %.2f\n", average(5, 1, 2, 3, 4, 5)); // 调用average函数计算1, 2, 3, 4, 5的平均值并打印
    printf("Average: %.2f\n", average(0));  // 测试参数数量为0的错误情况

    return 0; 
}