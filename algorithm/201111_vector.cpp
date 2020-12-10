/*************************************************************************
	> File Name: 201111_vector.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 11 Nov 2020 07:26:12 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


int main() {
    /*
    vector<int> v;
    for (int i = 105; i <= 110; i++) {
        v.push_back(i);
        cout << v.size() << endl;
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    */
    vector<vector<int>> v;
    v.push_back(vector<int>());
    for (int i = 66; i <= 70; i++) {
        v[0].push_back(i);
    }
    v.push_back(vector<int>(5, 6));
    v.push_back(vector<int>{1,2,3,4,5});
    v.push_back(vector<int>(3));
    v.push_back(vector<int>{0, 1});
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << "\t";
        }
        cout << endl;
    }



    return 0;
}
