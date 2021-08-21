/*************************************************************************
	> File Name: oj261_stack_on_top_of_stack.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Thu 21 Jan 2021 12:17:35 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stack>
#include<cinttypes>
using namespace std;

/* OJ261 对顶栈
 * 逻辑上的光标位置在两个栈相对的栈顶
 * 插入：第一个栈入栈
 * 删除：第一个栈弹栈
 * 左移：第一个栈弹栈，弹出元素进入第二个栈
 * 右移：第二个栈弹栈，弹出元素进入第一个栈
 * 询问：维护一个数组，元素更新时更新数组
 */

class NewStruct {
public:
    NewStruct() {
        sum[0] = 0;
        ans[0] = INT64_MIN;
    }
    void insert(long long x) {
        s1.push(x);
        int ind = s1.size();
        long long val = x + sum[ind - 1];
        sum[ind] = val;
        ans[ind] = max(ans[ind - 1], val);
        return;
    }
    void del() {
        if (s1.empty()) return;
        s1.pop();
        return;
    }
    void move_left() {
        if (s1.empty()) return;
        s2.push(s1.top());
        del();
        return;
    }
    void move_right() {
        if (s2.empty()) return;
        insert(s2.top());
        s2.pop();
        return;
    }
    long long query(long long k) {
        return ans[k];
    }

private:
    stack<long long> s1, s2;
    //sum存储当前位置的前缀和
    long long sum[1005];
    //ans存储到当前位置的最大前缀和
    long long ans[1005];
};

int main() {
    long long n;
    cin >> n;
    string op;
    int val;
    NewStruct s;
    for (int i = 0; i < n; i++) {
        cin >> op;
        switch (op[0]) {
            case 'I': cin >>val; s.insert(val); break;
            case 'D': s.del(); break;
            case 'L': s.move_left(); break;
            case 'R': s.move_right(); break;
            case 'Q': cin >>val; cout << s.query(val) << endl; break;
        }
    }
    return 0;
}
