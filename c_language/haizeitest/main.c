/*************************************************************************
	> File Name: main.cpp
	> Author: liuqian
	> Mail: 
	> Created Time: Sat 31 Oct 2020 09:23:13 PM CST
 ************************************************************************/

#include <test.h>

int add(int a, int b) {
    return a + b;
}

TEST(testfunc1, add) {
    EXPECT_EQ(add(2, 3), 5)
    EXPECT_NE(add(2, 1), 3)
    EXPECT_EQ(add(2, 3), 7)
    EXPECT_EQ(add(3, 3), 6)
}

TEST(testfunc2, add) {
    EXPECT_GT(add(5, 2), 8)
    EXPECT_EQ(add(2, -2), 5)
    EXPECT_EQ(add(-2, 0), 2)
    EXPECT_EQ(add(1, -1), 0)
}
TEST(testfunc3, add) {
    EXPECT_GT(add(5, 2), 6)
    EXPECT_LT(add(3, 5), 9)
}

int main(/*int argc, char *argv[]*/) {
    //testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
