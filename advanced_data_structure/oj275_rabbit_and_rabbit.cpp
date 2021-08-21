/*************************************************************************
	> File Name: oj275_rabbit_and_rabbit.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Fri 29 Jan 2021 07:51:29 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

/* OJ275 兔子和兔子 哈希法字符串匹配 + 求逆元
 *
 */
#define MAX_N 1000000
#define P 10007
#define base 13
long long  inv[P + 5];
long long  K[MAX_N + 5];
long long  H[MAX_N + 5];
char s[MAX_N + 5];

void init() {
    inv[1] = 1;
    for (long long i = 2; i < P; i++) {
        //inv[i] = (P - (P/i)) * inv[P % i] % P;
        inv[i] =  ((-(P / i) * inv[P % i]) % P + P) % P;
    }
    K[0] = 1;
    for (long long i = 1; i <= MAX_N; i++) {
        K[i] = (K[i - 1] * base) % P;
    }
    H[0] = 0;
    for (long long i = 1; s[i]; i++) {
        H[i] = (H[i - 1] + K[i] * s[i]) % P;
    }
    return;
}

long long  getH(long long l, long long r) {
    return ((H[r] - H[l - 1]) % P * inv[K[l]] % P + P) % P;
}

long long isSame(long long i, long long j, long long n) {
    for (long long k = 0; k < n; k++) {
        if (s[i + k] - s[j + k]) return false;
    }
    return true;
}

int main() {
    long long m, l1, l2, r1, r2;
    init();
    scanf("%s%lld", s + 1, &m);
    for (long long i = 0; i < m; i++) {
        scanf("%lld%lld%lld%lld", &l1, &r1, &l2, &r2);
        long long n1 = r1 - l1 + 1, n2 = r2 - l2 + 1;
        if (n1 - n2 ||  getH(l1, r1) - getH(l2, r2)){
            printf("No\n");
        }
        else {
            if (isSame(l1, l2, n1)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
