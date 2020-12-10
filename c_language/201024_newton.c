/*************************************************************************
	> File Name: 201024_newton.c
	> Author: liuqian
	> Mail: 
	> Created Time: Sat 24 Oct 2020 07:24:27 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>

//牛顿迭代法解方程

double F(double x, double n) {
    return x * x - n;
}

double f(double x) {
    return 2 * x;
}

double NewTon (double(*F) (double, double), double (*f) (double), double n) {
    double x = n / 2.0;
    #define EPSL 1e-7
    while (fabs(F(x, n)) > EPSL) {
        x -= F(x, n) / f(x);
    }
    #undef EPSL
    return x;
}

double my_sqrt(double n) {
    return NewTon(F, f, n);
}

int main() {
    double n;
    while(~scanf("%lf", &n)) {
        printf("sqrt(%g) = %g\n", n, sqrt(n));
        printf("my_sqrt(%g) = %g\n", n, NewTon(F, f, n));

    }
    return 0;
}
