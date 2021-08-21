/*************************************************************************
	> File Name: oj372_twin_sequence.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sat 23 Jan 2021 09:47:07 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

/* OJ372 双生序列 单调队列
 * 对比两个序列的单调队列是否相同
 */

#define MAX_N 500000

class Queue {
public:
    Queue(int *arr) : arr(arr) {};
    //生成单调递增队列
    void push(int i) {
        while (tail - head && arr[q[tail - 1]] > arr[i]) --tail;
        q[tail++] = i;
        return;
    }
    void pop() { ++head; }
    int size() { return tail - head; }

private:
    int *arr;
    int q[MAX_N + 5], head, tail;
};

int a[MAX_N + 5], b[MAX_N + 5];
int n;
Queue q1(a), q2(b);

//读入两个序列的数据
void read() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    return;
}

int main() {
    read();
    int p;
    for (p = 0; p < n; p++) {
        q1.push(p);
        q2.push(p);
        if (q1.size() != q2.size()) break;
    }
    cout << p << endl;
    return 0;
}
