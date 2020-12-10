/*************************************************************************
	> File Name: 201121_quick_sort.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 24 Nov 2020 02:19:55 PM CST
 ************************************************************************/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//快排优化
//针对逆序排序的优化
//1.取中间值作为基准值
//2.一半递归采用循环      
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

void quick_sort(int *num, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = num[(l + r) >> 1];
        do {
            while (x <= y && num[x] < z) x++;
            while (x <= y && num[y] > z) y--;
            if (x <= y) {
                swap(num[x], num[y]);
                x++, y--;
            }
        }while (x <= y);
        //要使得循环结束后x大于y
        quick_sort(num, x, r);
        r = y;
    }
    return;
}
void randint(int *num, int n) {
    while(n--) num[n] = rand() % 100;
    return;
}
void output(int *num, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }
    printf("]\n");
    return;
}
 

int main() {
    srand(time(0));
    #define max_n 20 
    int arr[max_n];
    randint(arr, max_n);
    output(arr, max_n);
    quick_sort(arr, 0, max_n - 1);
    output(arr, max_n);
    #undef max_n
    return 0;
}
