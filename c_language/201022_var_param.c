/*************************************************************************
	> File Name: 201022_var_param.c
	> Author: liuqian
	> Mail: 
	> Created Time: Thu 22 Oct 2020 06:33:48 PM CST
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#include<stdarg.h>

//用可变参数函数输出n个数中的最大值
int max_int(int n, ...) {
    int ans = INT32_MIN;
    va_list arg;
    va_start(arg, n);
    while (n--) {
        int temp = va_arg(arg, int);//va_arg为宏定义，不是函数
        if (temp > ans) ans = temp;
    }
    va_end(arg);
    return ans;
}

int main() {
    printf("%d\n", max_int(3, 1, 5, 10));
    printf("%d\n", max_int(2, 1, 3));
    printf("%d\n", max_int(6, 1, 3, 5, 7, 13, 15, 17));
    return 0;
}
