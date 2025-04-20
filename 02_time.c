#include<stdio.h>
#include<inttypes.h>
#include<time.h>

int main(void)
{
    time_t now = time(NULL);

    //printf("当前时间戳: %td\n", now);

    struct tm local_time;
    localtime_s(&local_time, &now);

    struct tm utc_time;
    gmtime_s(&utc_time, &now);

    char local_time_str[80];
    char utc_time_str[80];

    strftime(local_time_str, sizeof(local_time_str), "%Y-%m-%d %H:%M:%S", &local_time);

    strftime(utc_time_str, sizeof(utc_time_str), "%Y-%m-%d %H:%M:%S", &utc_time);

    printf("当前时间戳：%" PRIdMAX "\n", (intmax_t)now);
	printf("本地时间：%s\n", local_time_str);
	printf("UTC时间：%s\n", utc_time_str);

    return 0;
}
