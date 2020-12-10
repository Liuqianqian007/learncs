/*************************************************************************
	> File Name: 20201020_1.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 20 Oct 2020 06:22:38 PM CST
 ************************************************************************/

#include<stdio.h>

//已知T285 = T165 = H143 = 40755;
//求下一个同时为三角形数、五边形数和六边形数的数
typedef long long ll; //int溢出

//三角形数
ll Triangle(ll n) {
    return n * (n + 1) / 2;
}
//五边形数
ll Pentagonal(ll n) {
    return n * (3 * n - 1) / 2;
}
//六边形数
ll Hexagonal(ll n) {
    return n * (2 * n - 1);
}    

ll binary_search(ll (*arr)(ll), ll n, ll x) {
    ll head = 1, tail = n, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (arr(mid) == x) return mid;
        if (arr(mid) < x) head = mid +1;
        else tail = mid - 1;
    }
    return -1;
}

int main() {
    ll n = 143;
    while (1) {
        n += 1;
        ll temp = Hexagonal(n);
        if (binary_search(Pentagonal, temp, temp) == -1) continue; //减少代码缩进
        //if (binary_search(Triangle, temp, temp) == -1) continue; //是六边形数一定是三角形数
        printf("%lld\n", temp);
        break;
    }
    return 0;
}
