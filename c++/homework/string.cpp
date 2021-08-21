/*************************************************************************
	> File Name: string.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 02 Mar 2021 02:14:43 PM CST
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

int main() {
    string s("Today is"), s1 = s, s2 = s;

    s1.insert(s1.size(), " Sunday.");
    s2.append(" Sunday.");
    cout << s1 << endl << s2 << endl;

    s1.erase(9, 3);
    s1.insert(9, "Satur");

    s2.replace(9, 3, "Satur");
    cout << s1 << endl << s2 << endl;

    return 0;
}
