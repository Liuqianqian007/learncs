/*************************************************************************
	> File Name: one_piece_heap.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Thu 04 Feb 2021 11:42:45 PM CST
 ************************************************************************/

#include <iostream>
#include <set>
using namespace std;
/* OJ646 海贼王堆 用set模拟堆 */

struct Data {
    string name;
    int sex, age, ind;
    bool operator<(const Data &a) const {
        if (name.find("wang") == 0 && a.name.find("wang") != 0) return true;
        if (name.find("wang") != 0 && a.name.find("wang") == 0) return false;
        if (sex - a.sex) return sex == 0;
        if (age - a.age) return age > a.age;
        if (name != a.name) return name < a.name;
        return ind < a.ind;            
    }
};

int main() {
    set<Data> s;
    int n, op;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> op;
        switch (op) {
            case 1: {
                string name;
                int sex, age;
                cin >> name >> sex >> age;
                s.insert({name, sex, age, i});
            } break;
            case 2: {
                if (s.size() == 0) cout << "empty" << endl;
                else cout << s.begin()->name << endl;
            } break;
            case 3: {
                if (s.size() == 0) break;
                s.erase(s.begin());
            } break;                    
        }            
    }
    return 0;
}
