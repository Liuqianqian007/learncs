/*************************************************************************
	> File Name: main.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sat 31 Oct 2020 09:23:13 PM CST
 ************************************************************************/

#include<iostream>
#include <gtest/gtest.h>
using namespace std;

int add(int a, int b) {
    return a + b;
}

TEST(testfunc, add) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(2, 3), 7);
    EXPECT_EQ(add(3, 3), 6);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
