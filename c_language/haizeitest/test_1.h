/*************************************************************************
	> File Name: test.h
	> Author: liuqian
	> Mail: 
	> Created Time: Tue 03 Nov 2020 06:29:18 PM CST
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

#define PRINT_1(str, attr) printf("\033[" #attr "m%s\033[0m ", #str);
#define PRINT_2(arg, attr) printf("\033[" #attr "m%s\033[0m\n", arg);
#define PRINT_3(arg, attr) PRINT_1(arg, attr)





//定义TEST宏
//调用add_function()
#define TEST(a, b) \
void a##_##b();\
__attribute__((constructor))\
void add_##a##_##b() {\
    add_function(a##_##b, #a "." #b);\
}\
void a##_##b()


#define EXPECT_EQ(a, b) \
if ((a) == (b)) {\
    PRINT_1([---------], 32);\
    PRINT_1(a ==  b, 0)\
    PRINT_1(TRUE\n, 32)\
} else {\
    PRINT_1([---------], 32);\
    PRINT_1(a  !=  b, 0)\
    PRINT_1(FALSE\n, 31)\
}

//#define EXPECT_EQ(a, b) printf("\033[32m[---------]\033[0m%s == %s %s\n", #a, #b, (a) == (b) ? "TRUE" : "FALSE");


//定义TEST宏对应的测试用例函数的函数指针类型
typedef void (*TestFuncT)();

//存放TEST测试用例函数和函数名的结构体,typedef重命名类型
typedef struct Function {
    TestFuncT func;
    const char* func_name;
} Function;

//添加函数及函数名到结构体数组中，并计数
void add_function(TestFuncT func, const char* func_name);

//循环执行结构体数组中的测试用例函数
int RUN_ALL_TESTS();

#endif
