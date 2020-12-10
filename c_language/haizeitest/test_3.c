/*************************************************************************
	> File Name: test.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 03 Nov 2020 07:47:58 PM CST
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<test.h>
#include<math.h>
#include<linklist.h>
#include<stdlib.h>

Function func_head, *func_tail = &func_head;
FunctionInfo haizei_test_info;

void add_function(TestFuncT func, const char* func_name) {
    Function *temp = (Function*) calloc(1, sizeof(Function));//清空地址
    temp->func = func;
    temp->str = strdup(str);//
    func_tail->p.next = &(temp->p);//尾插法
    func_tail = temp;
    return;
}
  
int RUN_ALL_TESTS() {
    for (struct LinkNode* p = func_head.p.next; p; p = p->next) {
        Function *func = Head(p, Function, p);
        haizei_test_info.success = 0;
        haizei_test_info.total = 0;
        printf(GREEN_HL("[====RUN====] ") RED_HL("%s\n"), func->str);
        func->func();
        double rate = 100.f * haizei_test_info.success / haizei_test_info.total;
        // 浮点数判等
        printf(GREEN_HL("["));
        if (fabs(rate - 100.0) < 1e-6) {
            printf(BLUE_HL("%6.2lf%%"), rate);
        } else {
            printf(RED("%6.2lf%%"), rate);
        }
        printf(GREEN_HL("] ") "total : %d    success : %d\n", 
                haizei_test_info.total, 
                haizei_test_info.success
        );
    }
    return 0;
}
