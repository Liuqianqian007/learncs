/*************************************************************************
	> File Name: 201111_priority_queue.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Wed 11 Nov 2020 07:46:50 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

struct node {
    int x, y;
    double z;
    /*
    bool operator< (const node &b) const {
        return this->x < b.x;
    }
    */
};


int main() {
    priority_queue<node> que;
    //que.push((node){1, 2, 2.5});
    //que.push((node){2, 4, 5.6});
    //cout << que.top().x << endl;
    //que.pop();
    //cout << que.top().x << endl;


    return 0;
}
