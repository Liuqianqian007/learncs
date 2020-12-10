/*************************************************************************
	> File Name: test.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 03 Nov 2020 07:47:58 PM CST
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<test.h>

int success_cnt = 0, cnt = 0;

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
        success_cnt = 0;
        cnt = 0;
        printf(GREEN_HL("[====RUN====] ") RED_HL("%s\n"), func_arr[i].func_name);
        func_arr[i].func();
        printf(GREEN_HL("["));
        if (success_cnt != cnt) {
            printf(RED_HL("%8.2f%%  "), 100.0 * success_cnt / cnt);
            
        } else{
            printf(BLUE_HL("  100.00%%  "));
        }
        printf(GREEN_HL("]"));
        printf("total : %d   success : %d\n", cnt, success_cnt);
    }
    return 0;
}
