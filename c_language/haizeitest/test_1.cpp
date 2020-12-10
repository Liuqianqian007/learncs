/*************************************************************************
	> File Name: test.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 03 Nov 2020 07:47:58 PM CST
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<test.h>

int func_cnt;
Function func_arr[100];

void add_function(TestFuncT func, const char* func_name) {
    func_arr[func_cnt].func = func;
    func_arr[func_cnt].func_name = func_name;
    func_cnt++;
    return;
}

int RUN_ALL_TESTS() {
    for (int i = 0; i < func_cnt; i++) {
        PRINT_1([===RUN===], 32);
        PRINT_2(func_arr[i].func_name, 31);
        //printf("\033[32m[===RUN===] \033[31m%s\n\033[0m", func_arr[i].func_name);
        func_arr[i].func();
        printf("total :     success : \n");
    }
    return 0;
}
