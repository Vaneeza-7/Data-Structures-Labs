#include "pch.h"
#include <gtest/gtest.h>
#include "../DS-lab9/21i0390.h"
using namespace std;

/////////////Q1 //////////////
stack<int> s1; // create object of stack class

TEST(task1, T1) {
    s1.push(1);
    s1.push(2);
    s1.push(3);
    node<int>* top = s1.Peek();
    EXPECT_EQ(3, top->val);
}

TEST(task1, T2) {
    s1.pop();
    node<int>* top = s1.Peek();
    EXPECT_EQ(2, top->val);
    s1.pop();
    top = s1.Peek();
    EXPECT_EQ(1, top->val);

}
TEST(task1, T3) {
    s1.push(3);
    s1.push(4);
    EXPECT_EQ(3, s1.sizeofstack());// if size is key word change it it sizeOfStack.
}

///////////////////Q3/////////////////

MinStack s2;
TEST(task3, T1) {

    s2.push(6);
    s2.push(7);
    s2.push(8);

    EXPECT_EQ(8, s2.top());
    EXPECT_EQ(6, s2.getMin());

    s2.push(5);

    EXPECT_EQ(5, s2.top());
    EXPECT_EQ(5, s2.getMin());

    s2.push(3);

    EXPECT_EQ(3, s2.top());
    EXPECT_EQ(3, s2.getMin());

    s2.pop();

    EXPECT_EQ(5, s2.top());
    EXPECT_EQ(5, s2.getMin());

}

/////////////Q2/////////////////////
TEST(task2, T1) {
    EXPECT_TRUE(validate("Text1.txt"));
}

TEST(task2, T2) {
    EXPECT_FALSE(validate("Text2.txt"));
}

TEST(task2, T3) {
    EXPECT_FALSE(validate("Text3.txt"));
}