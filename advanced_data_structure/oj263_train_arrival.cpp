/*************************************************************************
	> File Name: oj263_train_arrival.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Thu 21 Jan 2021 08:54:35 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

/* OJ263 火车进栈
 * next_permutation() 列出全排列中的下一排列方式
 * 合法序列中的某一数字i要出栈，则1~i均已入栈
 * 序列中下一个数字j，若j > i ，则i~j均已入栈；若j < i，则j是当前的栈顶元素
 */

//a是待判断是否合法的序列
//s是用来模拟的栈
int a[30], s[30], top;

//判断序列是否合法
bool is_valid(int *a, int n) {
    int j = 0;
    top = -1;
    for (int i = 0; i < n; i++) {
        while (j < a[i]) { s[++top] = (++j); }
        if (top == -1 || s[top] - a[i]) return false;
        --top;
    }
    return true;
}

int main() {
    //输出前20个数据
    int n, cnt = 20;
    cin >> n;
    for (int i = 0; i < n; i++) a[i] = i + 1;
    do {
        if (!is_valid(a, n)) continue;
        for (int i = 0; i < n; i++) {
            cout << a[i];
        }
        cout << endl;
        --cnt;
    } while (cnt && next_permutation(a, a + n));

    return 0;
}
