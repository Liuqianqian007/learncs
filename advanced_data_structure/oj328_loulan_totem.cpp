/*************************************************************************
	> File Name: oj328_louln_totem.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 27 Jan 2021 04:41:51 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

/* OJ328 楼兰图腾 树状数组 
 * 思路：
 * 1. 找^和找v思路相同，即遍历所有y坐标，将i位置前/后小于（或大于）val(i)的元素个数相乘，再累加
 * 2. 1~n中某个数字已出现则在标记数组中标记为1，否则为0
 * 3. i位置前小于val(i)的元素个数可用标记数组的树状数组（前缀和）来记录
 */
#define MAX_N 200000
#define lowbit(x) (x & -x)
int n;
int val[MAX_N + 5];
int c[MAX_N + 5];

//树状数组单点修改
void add(int i, int x, int n) {
    while (i <= n) {
        c[i] += x;
        i += lowbit(i);
    }
    return;
}

//树状数组查询前缀和
long long query(int i) {
    long long sum = 0;
    while (i) {
        sum += c[i];
        i  -= lowbit(i);
    }
    return sum;
}

//输入y坐标val[i]
void read() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }     
    return;
}

//big表示v的个数，small表示^的个数
void solve(long long &big, long long &small) {
    big = small = 0;
    //遍历n个y坐标
    for (int i = 1; i <= n; i++) {
        //small_pre和small_post分别为当前元素前后小于当前元素值的元素个数
        //big_pre和big_post分别为当前元素前后大于当前元素值的元素个数
        //val[i]表示1~n连续n个数，因此可以这样运算
        long long small_pre = query(val[i]);
        long long small_post = val[i] - 1 - small_pre;
        long long big_pre = i - 1 - small_pre;
        long long big_post = n - val[i] - big_pre;
        big += big_pre * big_post;
        small += small_pre * small_post;
        add(val[i], 1, n);
    }
    return;
}

int main() {
    long long big, small;
    read();
    solve(big, small);
    cout << big << " " << small << endl;
    return 0;
}
