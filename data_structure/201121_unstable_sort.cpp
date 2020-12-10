/*************************************************************************
	> File Name: 201121_unstable_sort.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 24 Nov 2020 02:19:26 PM CST
 ************************************************************************/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
//不稳定排序
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

#define TEST(arr, n, func, args...) {\
    int *num = (int *) malloc(sizeof(int) * n);\
    memcpy(num, arr, sizeof(int) * n);\
    output(num, n);\
    printf("%s = ", #func);\
    func(args);\
    output(num, n);\
    free(num);\
}


//选择排序
void select_sort(int *num, int n) {
    for (int i = 0; i < n - 1; i++) {
        int ind = i;
        for (int j = i + 1; j < n; j++) {
            if (num[ind] > num[j]) ind = j;
        }
        swap(num[i], num[ind]);
    }
    return;
}

//快速排序
void quick_sort(int *num, int l, int r) {
    if (l > r) return;
    int x = l, y = r, z = num[x];
    while (x < y) {
        while (x < y && num[y] > z) y--;
        if (x < y) num[x++] = num[y];
        while (x < y && num[x] < z) x++;
        if (x < y) num[y--] = num[x];
    }
    num[x] = z;
    quick_sort(num, l, x - 1);
    quick_sort(num, x + 1, r);
    return;
}

void randint(int *num, int n) {
    while (n--) num[n] = rand() % 100;
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
    TEST(arr, max_n, select_sort, num, max_n);
    TEST(arr, max_n, quick_sort, num, 0, max_n- 1);
    return 0;
}
