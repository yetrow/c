#include <stdio.h>
#include <string.h>


/*
函数	匹配逻辑	            典型应用场景
strspn	匹配 accept 中的字符	验证字符串前缀（如数字、字母）
strcspn	排除 reject 中的字符	查找首次出现的非法字符位置*/

int main() {
    char str[] = "123abc456";
    char accept[] = "0123456789";  // 只接受数字

    size_t len = strspn(str, accept);
    printf("开头连续数字的长度: %zu\n", len);  // 输出 3（"123"）


     char str1[] = "Hello123World!";
        
    // 计算开头的字母长度
    size_t alpha_len1 = strspn(str1, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    printf("开头的字母长度: %zu\n", alpha_len1);  // 输出 5（"Hello"）
    
    // 计算首次出现数字或符号的位置
    size_t break_pos1 = strcspn(str1, "0123456789!@#");
    printf("首次出现数字/符号的位置: %zu\n", break_pos1);  // 输出 5（'1'的位置）
        

    return 0;
}

