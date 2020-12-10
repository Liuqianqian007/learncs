/*************************************************************************
	> File Name: 201024_binary_research.c
	> Author: liuqian
	> Mail: 
	> Created Time: Sat 24 Oct 2020 06:09:34 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>//gcc 编译时要加 -lm，因为math.h依赖于libm.so，默认情况省略了 -lc（查找libc.so）

//二分查找的循环实现
//然后改为求sqrt

double f(double x) {
    return x * x;
}

double binary_search(double (*arr)(double), double x) {
    double head = 0, tail = x, mid;
    if (x < 1.0) tail = 1.0;
    #define EPSL 1e-7
    while (tail - head > EPSL) {
        mid = (head + tail) / 2.0;
        if (arr(mid) < x) head = mid;
        else tail = mid;
    }
    #undef EPSL
    return head;
}

int main() {
    double x;
    while (~scanf("%lf", &x)){
        double ans = binary_search(f, x);
        printf("sqrt(%g) = %g\n", x, sqrt(x));
        printf("my_sqrt(%g) = %g\n", x, ans);
    }
    return 0;
}
