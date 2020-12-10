/*************************************************************************
	> File Name: 201120_oj531.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Fri 20 Nov 2020 08:40:30 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>

using namespace std;
//奇怪的电视

//求最短长度——广搜
//用二进制位存储状态（按钮数不大于20，用一个int即可）
//位运算转移状态

struct node {
    int status, step;
};

//num2[i]：二进制位i对应的十进制值2^i
//num[i]：用二进制位表示按下第i个按钮后弹出的按钮后，对应的十进制值
//共有2^21个状态
int n, num2[22] = {1}, check[2200000], num[25];

//初始化二进制位数值数组
void init() {
    for (int i = 1; i <= 20; i++) {
        num2[i] = num2[i - 1] * 2;
    }
}


int main() {
    init();
    //n为按钮个数
    cin >> n;
    int start = 0;
    //初始化起始状态start（对应第二行输入）
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            start += num2[i];
        }
    }
    //初始化按下某按钮后能弹出按钮的状态数组num
    //（对应第3行到最后一行输入）
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        for(int j = 1; j <= t; j++) {
            int t2;
            cin >> t2;
            num[i] += num2[t2];
        }
    }
    //开始广搜，寻找只有按钮3按下的状态对应的十进制数，即8
    queue<node> que;
    que.push((node){start, 0});
    check[start] = 1;
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        //终点：当前状态为3号按钮按下，不需要再走一步
        if (temp.status == 8) {
            cout << temp.step << endl;
            return 0;
        }
        for (int i = 1; i <= n; i++) {
            //如果当前按钮没被按下（按位与&运算要加括号）
            if ((temp.status & num2[i]) == 0) {
                //t表示当前状态
                //计算按下后的状态
                int t= temp.status;
                //~num[i]后为1的位对应的按钮状态不变，为0的位对应的按钮弹起
                //一个数&1等于自己，&0等于0
                t &= ~num[i];
                //当前按钮按下
                t |= num2[i];
                //此状态之前没有达到过则入队，并标记去重
                if (check[t] == 0) {
                    que.push((node){t, temp.step + 1});
                    check[t] = 1;
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
