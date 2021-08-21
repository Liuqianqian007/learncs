/*************************************************************************
	> File Name: manacher.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Thu 04 Feb 2021 11:15:53 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;
/* LC5 最长回文子串 马拉车算法
 * 步骤：
 * 1. 在字符间插入#，统一回文中心
 * 2. 以当前右边界最靠右的回文子串的回文中心c作为参考，处理字符i
 * 时间复杂度O(n)
 */

class Solution {
    public:
    //预处理，插入#
    string get_new_string(string &s) {
        string ns = "#";
        for (int i = 0; s[i]; i++) {
            (ns += s[i]) += "#";                    
        }
        return ns;            
    }
    string longestPalindrome(string s) {
        string ns = get_new_string(s);
        //r数组存储每个字符的回文半径
        int *r = new int[ns.size()], c;
        r[0] = 1, c = 0;
        //遍历一次，确定每个字符的回文半径
        for (int i = 1; i < ns.size(); i++) {
            //当前字符i在c的回文半径之外时，确定i的初始回文半径
            if (i >= c + r[c]) {
                r[i] = 1;                            
            } 
            //当前字符i在c的回文半径之内时，借助回文中心为c的子串确定i的初始回文半径
            else {
                r[i] = min(c + r[c] - i, r[2 * c - i]);                           
            }
            //扩张回文半径
            while (i - r[i] >= 0 && ns[i - r[i]] == ns[i + r[i]]) r[i] += 1;
            //更新c点
            if (i + r[i] > c + r[c]) c = i;                    
        }
        int ans = 0;
        string ret = "";
        for (int i = 0; ns[i]; i++) {
            if (r[i] <= ans) continue;
            ans = r[i];
            ret = "";
            //输出去掉#的最长回文子串
            for (int j = i - r[i] + 1; j < i + r[i]; j++) {
                if (ns[j] == '#') continue;
                ret += ns[j];
            }                    
        }
        return ret;   
    }
};

int main() {
    Solution solv;
    string s;
    while (cin >> s) {
        cout << solv.longestPalindrome(s) << endl;
    }
    return 0;
}
