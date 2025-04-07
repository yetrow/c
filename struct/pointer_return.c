#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>

/*员工工资管理功能:
    1. 批量涨工资
    2. 计算并返回员工年终奖
    3. 查找最高工资的员工*/


#define EMLOYEES_COUNT 5

void update_salary(uint32_t* salaries, uint32_t increment);
void print_emp(uint32_t* salaries);
const uint32_t *find_max_salary(const uint32_t* salaries);

int main(void)
{
    /*员工工资管理
        批量涨工资
        计算并返回员工年终奖
        查找最高工资的员工*/

    uint32_t salaries[EMLOYEES_COUNT] = { 3000,4000,5000,6000,7000 };
    uint32_t increment = 1000;

    update_salary(salaries, increment);
    print_emp(salaries);
    const uint32_t *high_salary=find_max_salary(salaries);
    
	printf("The highest salary is %" PRIu32 "\n", *high_salary);


    return 0;
}
void update_salary(uint32_t* salaries, uint32_t increment)
{
    for (size_t i = 0; i < EMLOYEES_COUNT; i++)
    {
        salaries[i] += increment;
    }
}

void print_emp(uint32_t* salaries)
{
    for (size_t i = 0; i < EMLOYEES_COUNT; i++)
    {
        printf("%" PRIu32 " salary\n", salaries[i]);
    }
    printf("\n");
}

 const uint32_t* find_max_salary(const uint32_t* salaries)
{
    const uint32_t* highest_salary = salaries;
    for (size_t i = 0; i < EMLOYEES_COUNT; i++) 
    {
        if (*highest_salary<salaries[i]) {
            highest_salary = &salaries[i];
        }
    }
    return highest_salary;
}




// #include <stdio.h>
// #include <inttypes.h>
// #include <stdint.h>
// #include <stdlib.h>

// #define EMPLOYEES_COUNT 5

// // 函数声明
// void update_salaries(uint32_t salaries[], size_t count, uint32_t increment);
// void print_employees(const uint32_t salaries[], size_t count);
// uint32_t calculate_year_end_bonus(const uint32_t salaries[], size_t count);
// size_t find_highest_salary_employee(const uint32_t salaries[], size_t count);

// int main(void)
// {
//     /* 员工工资管理功能:
//         1. 批量涨工资
//         2. 计算并返回员工年终奖
//         3. 查找最高工资的员工 */
    
//     uint32_t salaries[EMPLOYEES_COUNT] = {3000, 4000, 5000, 6000, 7000};
//     uint32_t increment = 1000;
    
//     printf("Original salaries:\n");
//     print_employees(salaries, EMPLOYEES_COUNT);
    
//     // 涨工资
//     update_salaries(salaries, EMPLOYEES_COUNT, increment);
//     printf("\nAfter salary increase:\n");
//     print_employees(salaries, EMPLOYEES_COUNT);
    
//     // 计算年终奖(假设为一个月工资)
//     uint32_t total_bonus = calculate_year_end_bonus(salaries, EMPLOYEES_COUNT);
//     printf("\nTotal year-end bonus for all employees: %" PRIu32 "\n", total_bonus);
    
//     // 查找最高工资员工
//     size_t highest_index = find_highest_salary_employee(salaries, EMPLOYEES_COUNT);
//     printf("\nEmployee with highest salary: %zu, Salary: %" PRIu32 "\n", 
//            highest_index, salaries[highest_index]);
    
//     return 0;
// }

// // 更新所有员工工资
// void update_salaries(uint32_t salaries[], size_t count, uint32_t increment)
// {
//     for (size_t i = 0; i < count; i++)
//     {
//         salaries[i] += increment;
//     }
// }

// // 打印所有员工工资
// void print_employees(const uint32_t salaries[], size_t count)
// {
//     for (size_t i = 0; i < count; i++)
//     {
//         printf("Employee %zu salary: %" PRIu32 "\n", i, salaries[i]);
//     }
// }

// // 计算所有员工的年终奖总和(假设为一个月工资)
// uint32_t calculate_year_end_bonus(const uint32_t salaries[], size_t count)
// {
//     uint32_t total = 0;
//     for (size_t i = 0; i < count; i++)
//     {
//         total += salaries[i];
//     }
//     return total;
// }

// // 查找最高工资的员工索引
// size_t find_highest_salary_employee(const uint32_t salaries[], size_t count)
// {
//     size_t highest_index = 0;
//     uint32_t highest_salary = salaries[0];
    
//     for (size_t i = 1; i < count; i++)
//     {
//         if (salaries[i] > highest_salary)
//         {
//             highest_salary = salaries[i];
//             highest_index = i;
//         }
//     }
    
//     return highest_index;
// }