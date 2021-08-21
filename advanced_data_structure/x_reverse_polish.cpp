/*************************************************************************
	> File Name: reverse_polish.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Thu 04 Feb 2021 08:22:30 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* 【数据结构C++】逆波兰式 
 * 输入四则运算表达式，输出逆波兰式和计算结果
 * 选择优先级最低的运算符作为根结点建立表达式树，递归遍历
 * 求值时将表达式树从下往上运算，输出逆波兰式采用后序遍历
 */
#define INF 0x3f3f3f3f

int calc(char *str, int l, int r) {
    //找到优先级最低的运算符的位置pos
    int pos = -1, pri = INF - 1, temp = 0;
    for (int i = l; i <= r; i++) {
        int cur = INF;
        switch (str[i]) {
            case '(': temp += 100; break;
            case ')': temp -= 100; break;
            case '+': 
            case '-': cur = temp + 1; break;
            case '*':
            case '/': cur = temp + 2; break;
            case '^': cur = temp + 3; break;                    
        }
        if (cur <= pri) {
            pos = i, pri = cur;                    
        }          
    }
    //如果字符串中没有运算符了，则输出数字num
    if (pos == -1) {
        int num = 0;
        for (int i = l; i <= r; i++) {
            if (str[i] < '0' || str[i] > '9') continue;
            num = num * 10 + str[i] - '0';                    
        }
        printf("%d", num);
        return num;           
    }
    //递归处理pos左侧和右侧的运算符
    int a = calc(str, l, pos - 1);
    printf(" ");
    int b = calc(str, pos + 1, r);
    printf(" %c", str[pos]);
    //运算
    switch (str[pos]) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return (int)pow(a, b);    
    }
    return 0;
}

char str[10000];

int main() {
    while (~scanf("%[^\n]s", str)) {
        getchar();
        int val = calc(str, 0, strlen(str) - 1);
        printf("\n");
        printf("%s = %d\n", str, val);        
    }
    return 0;
}
