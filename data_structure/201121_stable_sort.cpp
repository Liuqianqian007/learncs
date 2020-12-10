/*************************************************************************
	> File Name: 201121_stable_sort.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 24 Nov 2020 02:18:55 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//稳定排序
#define TEST(arr, n, func, args...) {\
    int *num = (int *)malloc(sizeof(int) * n);\
    memcpy(num, arr, sizeof(int) * n);\
    output(num, n);\
    printf("%s= ", #func);\
    func(args);\
    output(num, n);\
    free(num);\
}

#define swap(a, b) {\
    a ^= b; b ^= a; a ^= b;\
}

//插入排序
void insert_sort(int *num, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && num[j] < num[j - 1]; j--) {
            swap(num[j], num[j - 1]);
        }
    }
    return;
}

//冒泡排序
void bubble_sort(int *num, int n) {
    int times = 1;
    for (int i = 1; i < n && times; i++) {
        times = 0;
        for (int j = 0; j < n - i; j++) {
            if (num[j] > num[j + 1]) {
                swap(num[j], num[j + 1]);
                times++;
            }
        }
    }
    return;
}

//归并排序
void merge_sort(int *num, int l, int r) {
    if (r - l <= 1) {
        if (r - l == 1 && num[r] < num[l]) {
            swap(num[r], num[l]);
        }
        return;
    }
    int mid = (l + r) >> 1;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    int p1 = l, p2 = mid + 1, k = 0;
    while (p1 <= mid || p2 <= r) {
        if (p2 > r ||(p1 <= mid && num[p1] < num[p2])) {
            temp[k++] = num[p1++];
        } else {
            temp[k++] = num[p2++];
        }
    }
    memcpy(num + l, temp, sizeof(int) * (r - l + 1));
    free(temp);
    return;
}

void randint(int *num, int n) {
    while (n--) {
        num[n] = rand() %100;
    }
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
    TEST(arr, max_n, insert_sort, num, max_n);
    TEST(arr, max_n, bubble_sort, num, max_n);
    TEST(arr, max_n, merge_sort, num, 0, max_n - 1);
    #undef max_n
    return 0;
}
