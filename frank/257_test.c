#include<stdio.h>
#include<errno.h>
#include<time.h>
#include<stdarg.h>

typedef enum{
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
}LogLevel;

const char* get_current_time();
void log_message(LogLevel level,const char* format,...);

int main(void)
{
    log_message(LOG_INFO,"This is a log with numbers %d",123);
    log_message(LOG_WARNING,"This is a warning message");
    log_message(LOG_ERROR,"This error point {%s} file","123.txt");


    return 0;
}

const char* get_current_time()
{
    static char buffer[20];
    time_t now_time=time(NULL);
    struct tm* time_info=localtime(&now_time);

    strftime(buffer,20,"%Y-%m-%d %H:%M:%S",time_info);

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



/*
你的看法 **不完全正确**。

`const char* format` **不是** 可变参数。

让我们再次明确一下 `log_message` 函数的参数：

```c
void log_message(LogLevel level, const char* format, ...);
//                     ^ Fixed Param 1   ^ Fixed Param 2  ^ Variable Parameters
```

*   `LogLevel level`: 这是**第一个固定参数**。每次调用 `log_message` 都必须提供一个 `LogLevel` 类型的值。
*   `const char* format`: 这是**第二个固定参数**。每次调用 `log_message` 都必须提供一个 `const char*` 类型的字符串指针。
*   `...`: 这三个点代表了**可变参数**。这些参数是可选的，数量和类型可以在每次调用时不同，它们位于 `format` 参数之后。

**`const char* format` 的真正作用：**

`format` 参数是一个**格式化字符串**。它的作用是：

1.  包含要打印的固定文本。
2.  包含格式说明符（例如 `%d`, `%s`, `%f` 等），这些说明符告诉 `printf` (或者在我们的代码中是 `vprintf`) 如何解释和处理**可变参数列表** (`...`) 中的下一个参数。

**举个例子：**

当你调用：
```c
log_message(LOG_INFO, "User %s logged in from IP %s", "Alice", "192.168.1.100");
```

*   `level` 是 `LOG_INFO`。
*   `format` 是 `"User %s logged in from IP %s"`。这是一个固定参数，一个字符串。
*   可变参数列表 (`...`) 是 `"Alice"` 和 `"192.168.1.100"`。这是两个字符串指针，它们是可变参数。

在 `log_message` 函数内部：

1.  `va_start(args, format);` 初始化 `args`，让它指向可变参数列表的开始（也就是 `"Alice"`）。
2.  `vprintf(format, args);` 被调用。`vprintf` 读取 `format` 字符串：
    *   它打印 "User "。
    *   它遇到 `%s`。它知道需要从 `args` 中取出一个字符串指针。它取出 `"Alice"`，并打印这个字符串。`args` 内部前进，指向下一个可变参数（`"192.168.1.100"`）。
    *   它打印 " logged in from IP "。
    *   它遇到 `%s`。它知道需要从 `args` 中再取出一个字符串指针。它取出 `"192.168.1.100"`，并打印这个字符串。`args` 内部前进。
    *   格式字符串结束。

**总结：**

*   `const char* format` 是一个 **固定的、必须提供的参数**。它不是可变参数的一部分。
*   它的作用是 **控制** 如何解析和使用后面的 **可变参数** (`...`)。它提供了一种模板，告诉函数需要从可变参数列表中取出什么类型和数量的参数。

所以，`format` 是一个固定参数，它是处理可变参数的“钥匙”或“说明书”。可变参数是 `...` 所代表的，位于 `format` 之后的那些可选参数。*/