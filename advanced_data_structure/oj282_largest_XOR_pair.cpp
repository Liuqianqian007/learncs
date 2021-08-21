/*************************************************************************
	> File Name: oj282_largest_XOR_pair.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sat 30 Jan 2021 12:29:00 PM CST
 ************************************************************************/
#include<iostream>
using namespace std;
/* OJ282 最大异或对 字典树+贪心
 * 异或值最大，即各个数位尽可能不一样
 * 把数字从高位到低位存入字典树，按照贪心策略在字典树中寻找与某个数字x各个位置上尽量相反的数字
 */

#define MAX_N 100000
#define BASE 31
//定义结点：
//每个结点指向两个子结点，分别表示0和1
//tree数组共有31 * 100000个元素，表示最多有100000个整数，每个int占31bit
struct node {
    node *next[2];
} tree[MAX_N * BASE+ 5];

//创建结点：cnt表示tree数组已消耗多少个元素
int cnt = 0;
node *getNode() {
    return &tree[cnt++];
}

//把数字x插入字典树中
void insert(node *root, int x) {
    //从高位到低位
    for (int i = 30; i >= 0; i--) {
        //ind表示数字x的第i位是0还是1，!!表示归一化
        int ind = !!(x & (1 << i));
        //生成子结点并继续迭代
        if (root->next[ind] == NULL) root->next[ind] = getNode();
        root = root->next[ind];   
    }
    return;
}

//在字典树中寻找与x异或值最大的数字
int query(node *root, int x) {
    int ans = 0;
    //从高位到低位贪心
    for (int i = 30; i >= 0; i--) {
        //ind表示将数字x的第i位的0或1取反
        int ind = !(x & (1 << i));
        //如果下一层存在与数字x的第i位相反的结点，则前往此节点，并将异或结果ans的该位取1
        if (root->next[ind]) {
            ans |= (1 << i);
            root = root->next[ind];
        }
        //ind取反
        else {
            root = root->next[!ind];
        }
    }
    return ans;
}


int main() {
    //n为数字总数
    int n;
    cin >> n;
    //num为当前数字
    int ans = 0, num;
    node *root = getNode();
    cin >> num, n--;
    insert(root, num);
    while (n--) {
        cin >> num;
        //对于当前数字，先与前面的数字（已生成的字典树）两两异或，取最大值，再将自身插入到字典树中
        ans = max(query(root, num), ans);
        insert(root, num);
    }
    cout << ans << endl;
    return 0;
}



