/*************************************************************************
	> File Name: 201027_hong.c
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 27 Oct 2020 07:14:09 PM CST
 ************************************************************************/

#include<stdio.h>
//定义一个输出无bug的宏定义MAX

#define MAX(a, b) ({\
    __typeof(a) _a = (a);\
    __typeof(b) _b = (b);\
    _a > _b ? _a : _b;\
})
#define P(func) {\
    printf("%s = %d\n", #func, func);\
}
//#func将func字符串化,即给func加上" "
//({})等价于表达式，返回{}内最后一个语句的结果

int main() {
    int a = 7;
    P(MAX(2, 3));
    P(MAX(2, 3));
    P(MAX(2, MAX(2, 3)));
    P(MAX(2, 3 > 4 ? 3 : 4));
    P(MAX(a++, 6));
    P(a);
    return 0;
}
