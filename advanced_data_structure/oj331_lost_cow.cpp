/*************************************************************************
	> File Name: oj331_lost_cow.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 26 Jan 2021 01:42:42 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

/* OJ331 Lost Cow 树状数组（前缀和）+ 二分查找（第一个目标）
 * 思路：从最后一个位置从后往前确定该位置的元素值
 * 使用一个标记数组来标记数字1~n是否已使用，0表示已使用，1表示未使用
 * 未使用数字的顺序由标记数组的前缀和（树状数组）来表示
 * 此处的前缀和为单调序列，寻找大小排在某位的数字使用二分查找
 */

#define MAX_N 80000
#define lowbit(x) (x & -x)
int n;
//结果数组，，
int ind[MAX_N + 5];
//题目给定的数组
int cnt[MAX_N + 5];

//树状数组
int c[MAX_N + 5];
//单点修改原数组，维护树状数组
void add(int i, int x, int n) {
    while (i <= n) {
        c[i] += x;
        i += lowbit(i);
    }
    return;
}
//使用树状数组查询原数组的前缀和
int query(int i) {
    int sum = 0;
    while (i) {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}

void read() {
    cin >> n;
    //输入给定数组，表示该位置元素前面有几个比自己小的元素
    for (int i = 2; i <= n; i++) cin >> cnt[i];
    //初始化mark数组的树状数组，此时mark数组中全为1
    for (int i = 1; i <= n; i++) {
        add(i, 1, n);
    }
}

//二分答案：00001111，寻找第一个1
int binary_search(int n, int x) {
    int head = 1, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (query(mid) < x) head = mid + 1;
        else tail = mid;
    }
    return head;
}

void solve() {
    //从最后一个位置往前遍历
    for (int i = n; i >= 1; i--) {
        //确定该位置的元素值，即在标记数组的前缀和数组（树状数组）中寻找值为cnt[i] + 1的下标
        ind[i] = binary_search(n, cnt[i] + 1);
        //更新标记数组的前缀和数组，已使用的值的标记值-1
        add(ind[i], -1, n);
    }
}

//输出每个位置上的元素值
void output() {
    for (int i = 1; i <= n; i++) {
        cout << ind[i] << endl;
    }
    return;
}

int main() { 
    read();
    solve();
    output();
    return 0;
}
