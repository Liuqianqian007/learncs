/*************************************************************************
	> File Name: 201104_oj600.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 04 Nov 2020 08:49:04 PM CST
 ************************************************************************/

#include<cstdio>
using namespace std;
//双指针二维版

//num数组不能定义在函数内，系统栈大小为8MB，会溢出
int n, m, t, num[3005][3005];

int main() {
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    int x = n, y = 1;
    //scanf和cout不要同时使用，否则可能超时
    while (x >= 1 && y <= m) {
        if (num[x][y] == t){
            printf("%d %d\n", x, y);
            return 0;
        }
        else if (num[x][y] > t) {
            x--;
        } 
        else {
            y++;
        }
    }
    printf("%d\n", -1);
    return 0;
}
