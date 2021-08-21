/*************************************************************************
    > File Name: brute_matching.cpp
    > Author: liuqian
    > Mail: 
    > Created Time: Thu 28 Jan 2021 12:32:57 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

/* 暴力匹配  O(n * m)  */
int brute_matching(const char* s, const char* t) {
    for (int i = 0; s[i]; i++) {
        int flag = 0;
        for (int j = 0; t[j]; j++) {
            if (s[i + j] && s[i + j] == t[j]) continue;
            flag = 1;
            break;
        }
        if (flag == 0) return i;
    }
    return -1;
}

/* KMP算法 O(n + m) */
int getNext(const char *t, int &j, char now, int *next) {
    while (j != -1 && t[j + 1] != now) j = next[j];
    if (t[j + 1] == now) j+= 1;
    return j;
}

int kmp(const char* s, const char* t) {
    int n = strlen(t);
    int * next = (int *)malloc(sizeof(int) * n + 1);
    next[0] = -1;
    //获取模式串t每一个位置i的next[i]值
    //状态机模型
    for (int i = 1, j = -1; t[i]; i++) next[i] = getNext(t, j, t[i], next);
    //母串s与模式串t的匹配过程
    //s与t的对应字符的下一位相等则往后；不等则回溯，然后直接往后
    for (int i = 0, j = -1; s[i]; i++) {
        if (getNext(t, j, s[i], next) != n - 1) continue;
        return i - n + 1;
        
      /*前2行代码等价于：
        while (j != -1 && s[i] != t[j + 1]) j = next[j];
        if (s[i] == t[j + 1]) j += 1;
        if (t[j + 1] == 0) return i - n + 1;
        */
    }
    free(next);
    return -1; 
}

/* sunday算法 最优时间复杂度O(n/m) */
int sunday(const char *s, const char *t) {
    int offset[256];
    int m = strlen(t), n = strlen(s);
    //offset存储每个字符在模式串t中的倒数第几位最后出现过
    //若没出现过，则存储为在倒数第n+1位出现过
    for (int i = 0; i < 256; i++) offset[i] = m + 1;
    for (int i = 0; t[i]; i++) offset[t[i]] = m - i;
    //匹配过程：若失配，则将模式串往后移母串超出模式串的第一个字符的offset位
    for (int i = 0; i + m <= n; i+= offset[s[i + m]]) {
        int flag = 1;
        for (int j = 0; t[j] && flag; j++) {
            flag = flag && (s[i + j] && s[i + j] == t[j]);
        }
        if(flag == 1) return i;
    }
    return -1;
}

/* shift_and算法 最优时间复杂度O(n)
 * 适用于多模匹配，如(a|b|c)&(c|d)&e&(f|a|b)，第一个位置上可以为a或b或c
 * d和p数组可能长度不够，需要自己构造数据结构，使其支持左移和与运算
 */
int shift_and(const char *s, const char *t) {
    //d[i]表示字典序为i的字符对应模式串t的编码（模式串中存在的位标1，不存在的位标0）
    //len_t为模式串的长度
    int d[256] = {0}, len_t = 0, p = 0;
    for (int i = 0; t[i]; len_t++, i++) d[t[i]] |= (1 << i);
    //遍历母串s中的每一位字符
    //p的二进制形式中为1的位置分别表示到目前为止可以匹配到模式串的第几位
    for (int i = 0; s[i]; i++) {
        p = (p << 1 | 1) & d[s[i]];
        //当p的第len_t位为1时，表示遍历到母串的i位置时匹配成功
        if (p & (1 << (len_t - 1))) {
            return i - len_t + 1;
        }
    }
    return -1;
}

int main() {
    char s[100], t[100];
    while (scanf("%s%s", s, t) != EOF) {
        printf("match(%s, %s) = %d\n", s, t, brute_matching(s, t));
        printf("kmp(%s, %s) = %d\n", s, t, kmp(s, t));
        printf("sunday(%s, %s) = %d\n", s, t, sunday(s, t));
        printf("shift_and(%s, %s) = %d\n", s, t, shift_and(s, t));
    }
    return 0;
}
