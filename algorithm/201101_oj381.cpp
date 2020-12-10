/*************************************************************************
	> File Name: 201101_oj381.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 03 Nov 2020 05:17:19 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//谁拿了最多奖学金

//sort函数用法
struct Student {
    string name;
    int index, avg, cla, paper, sum;
    char leader, west;
};

Student stu[105];

int func(Student s) {
    if (s.avg > 80 && s.paper >=1) s.sum += 8000;
    if (s.avg > 85 && s.cla > 80) s.sum += 4000;
    if (s.avg > 90) s.sum += 2000;
    if (s.avg > 85 && s.west == 'Y') s.sum += 1000;
    if (s.cla > 80 && s.leader == 'Y') s.sum += 850;
    return s.sum;
}

bool cmp(Student a, Student b) {
    if (a.sum == b.sum) return a.index < b.index;
    return a.sum > b.sum;
}

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> stu[i].name >> stu[i].avg >> stu[i].cla >>
        stu[i].leader >> stu[i].west >> stu[i].paper;
        stu[i].index = i + 1;
        stu[i].sum = func(stu[i]);
        ans += stu[i].sum;
    }
    sort(stu, stu + n, cmp);
    cout << stu[0].name << endl << stu[0].sum << endl << ans << endl;

    return 0;
}
