#include<stdio.h>
#include<time.h>
#include<errno.h>
#include<stdarg.h>

//自定义日志函数

typedef enum{
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
}LogLevel;

const char* get_current_time();
void log_message(LogLevel level,const char* format,...);

int main(void)
{

    log_message(LOG_INFO,"This is a log message with a number: %d",123);
    log_message(LOG_WARNING,"This is a warning message");
    log_message(LOG_ERROR,"This is an error message: %s","123.txt");


    return 0;
}

const char* get_current_time()
{
    static char buffer[20];
    time_t now=time(NULL);
    struct tm* tm_info=localtime(&now);
    strftime(buffer,20,"%Y-%m-%d %H:%M:%S",tm_info);
    return buffer;
}
void log_message(LogLevel level,const char* format,...)
{
    const char* level_str;
    switch(level)
    {
        case LOG_INFO:level_str="INFO";break;
        case LOG_WARNING:level_str="WARNING";break;
        case LOG_ERROR:level_str="ERROR";break;
        default:level_str="UNKNOWN";break;
    }
    printf("[%s] [%s] ",get_current_time(),level_str);
    va_list args;
    va_start(args,format);
    vprintf(format,args);
    va_end(args);
    printf("\n");
}
