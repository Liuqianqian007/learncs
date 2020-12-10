/*************************************************************************
	> File Name: 201121_binary_search.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sat 21 Nov 2020 07:14:24 PM CST
 ************************************************************************/
#include<stdio.h>

#define P(func) {\
    printf("%s = %d\n", #func, func);\
}


//1 3 5 7 9，普通二分
int binary_search1(int *num, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == x) return mid;
        if (num[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

//1111100000，找最后一个1
int binary_search2(int *num, int n) {
    int head = -1, tail = n - 1, mid;
    while (head < tail) {
        mid = (head + tail + 1)>> 1;
        if (num[mid] == 1) head = mid;
        else tail = mid - 1;
    }
    return head;//head为-1说明没找到
}


//0000011111,找第一个1
int binary_search3(int *num, int n) {
    int head = 0, tail = n, mid;
    while (head < tail ) {
        mid = (head + tail ) >> 1;
        if (num[mid] == 1) tail = mid;
        else head = mid + 1; 
    }
    //head为n说明没找到，返回-1
    return head == n ? -1 : head;
}

int main() {
    int arr1[10] = {1, 3, 5, 7, 9, 11, 13, 17, 19, 21};
    int arr2[10] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
    int arr3[10] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    P(binary_search1(arr1, 10, 3));
    P(binary_search2(arr2, 10));
    P(binary_search3(arr3, 10));

}
