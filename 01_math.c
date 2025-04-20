#define _USE_MATH_DEFINES
#include<stdio.h>
#include<math.h>
#include<inttypes.h>

int main(void)
{
    double num_sqrt=16.0;
    double num_fabs=-5.2;
    double num_ceil=2.3;
    double num_floor=2.9;
    double num_fmod=5.5;//取模的被除数
    double num2_fmod=2.0;//取模的除数
    double num_pow=2.0;

    double result_sqrt=sqrt(num_sqrt);
    double result_fabs=fabs(num_fabs);
    double result_ceil=ceil(num_ceil);
    double result_floor=floor(num_floor);
    double result_fmod=fmod(num_fmod,num2_fmod);//
    double result_pow=pow(num_pow,num2_fmod);

    printf("平方根：%.2f\n",result_sqrt);
    printf("绝对值：%.2f\n",result_fabs);
    printf("向上取整：%.2f\n",result_ceil);
    printf("向下取整：%.2f\n",result_floor);
    printf("取模：%.2f\n",result_fmod);
    printf("幂：%.2f\n",result_pow);

    return 0;

}