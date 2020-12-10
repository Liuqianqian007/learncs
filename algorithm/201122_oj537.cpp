/*************************************************************************
	> File Name: 201122_oj537.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Mon 23 Nov 2020 08:56:43 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
//门票
//排列组合问题——深搜

int l, c, cnt, ynum, fnum;
char num[30], ans[30];

//输出答案
void p() {
    for (int i = 0; i < l; i++) {
        cout << ans[i];
    }
    cout << endl;
}


//s表示从给定字母的第几个开始选
//deep表示答案选到了第几个
int func(int s,  int deep) {
    //选到要求的个数，满足条件则输出，不满足条件则返回上一次继续递归
    if (deep == l) {
        if (ynum >= 1 && fnum >= 2) {
            p();
            cnt++;
            //答案个数超过25000，则返回1，结束递归
            if (cnt == 25000) {
                return 1;
            }
        }
        return 0;
    }
    for (int i = s; i < c; i++) {
        int f = 0;
        ans[deep] = num[i];
        if (num[i] == 'a' || num[i] == 'e' || num[i] == 'i' || num[i] == 'o' || num[i] == 'u') {
            ynum++;
            f = 1;
        } else {
            fnum++;
        }
        //结束递归
        if (func(i + 1, deep + 1) == 1) {
            return 1;
        }
        //还原计数
        if (f == 1) {
            ynum--;
        } else {
            fnum--;
        }
    }
}


int main() {
    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        cin >> num[i];
    }
    //答案是按字典序输出的，要先排序
    sort(num, num + c);
    func(0, 0);
    return 0;
}
