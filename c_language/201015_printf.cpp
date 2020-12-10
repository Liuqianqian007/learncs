/*************************************************************************
	> File Name: 3.printf.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Thu 15 Oct 2020 06:13:54 PM CST
 ************************************************************************/

#include <stdio.h>
#define swap(a,b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

int main() {
    //当n的二进制第一位为1，则加上()，第二位为1.加上[]，第三位为1，加上{}
    int n;
    scanf("%d", &n);
    printf("%d\n", n);
    char str[1000] = {0}, buffer[1000] = {0}, *p = str, *q = buffer;

    //读入IP地址
    sprintf(str,"%d.%d.%d.%d", 192, 168, 1, 2);
    printf("%s\n", str);
    if (n & 1) {
        sprintf(q,"(%s)", p);
        swap(p, q);
    }
    if (n & 2) {
        sprintf(q, "[%s]", p);
        swap(p, q);
    }
    if (n & 4) {
        sprintf(q, "{%s}", p);
        swap(p, q);
    }
    printf("%s\n", p);
    FILE* fout = fopen("output", "w");
    fprintf(stdout, "stdout = %s\n", p);
    fprintf(stderr, "stderr = %s\n", p);
    return 0;
}


