#include "pch.h"
#include"Header.h"
TEST(Add, t1) {
	EXPECT_EQ(13, add(5, 8));
}
TEST(Add, t2) {
	EXPECT_EQ(11.13, add(6.9, 4.23));
}

TEST(Add, t3) {
	int arr[5] = { 1,2,3,4,5 };
	int arr2[5] = { 6,7,8,9,10 };
	int* result = add(arr, arr2);
	for (int i = 0; i < 5; i++)
		EXPECT_EQ(arr[i] + arr2[i], result[i]);
}
TEST(Add, t4) {
	double arr[5] = { 1.2,2.5,3.1,4.8,5.1 };
	double arr2[5] = { 6.8,7.1,8.6,9.2,10.5 };
	double* result = add(arr, arr2);
	for (int i = 0; i < 5; i++)
		EXPECT_EQ(arr[i] + arr2[i], result[i]);
}
TEST(Sub, t5) {
	EXPECT_EQ(5, sub(12, 7));
}
TEST(Div, t6) {
	EXPECT_EQ(2, Div(12, 6));
}
TEST(Div, t7) {
	EXPECT_EQ(3.5, Div(7.0, 2.0));
}
TEST(Prime, t8) {
	EXPECT_EQ(true, prime(23));
}
TEST(Prime, t9) {
	EXPECT_EQ(false, prime(6));
}
TEST(Factorial, t10) {
	EXPECT_EQ(120, Fact(5));
}
TEST(Factorial, t11) {
	EXPECT_EQ(24, Fact(4));
}
TEST(SQRT, t12) {
	EXPECT_EQ(2, SQRT(4));
}
TEST(SQRT, t13) {
	EXPECT_EQ(9, SQRT(81));
}

TEST(split, T1) {
	int Arr[] = { 5,3,2,10 };
	EXPECT_EQ(10, SplitToSets(Arr, 4));

}
TEST(split, T2) {
	int Arr[] = { 4,3,5,7,11 };
	EXPECT_EQ(16, SplitToSets(Arr, 5));// slpited into: [5,7,11] sum=23, [4,3] sum=7 and diffrence is 16;
}

TEST(super, T1) {
	string str = "ZYY";
	EXPECT_TRUE(superString(str));
}
TEST(super, T2) {
	string str = "ZYYZ";
	EXPECT_FALSE(superString(str));
}
TEST(super, T3) {
	string str = "ASDF";
	EXPECT_FALSE(superString(str));
}


TEST(subStr, T1) {
	string str = "ABBA";
	EXPECT_EQ(4, subPalindrome(str));//A,A,AA,B,B,BB
}


TEST(subStr, T2) {
	string str = "AABAA";
	EXPECT_EQ(5, subPalindrome(str));//A,AA,ABA,B,AABAA
}


TEST(subStr, T3) {
	string str = "MOM";
	EXPECT_EQ(3, subPalindrome(str));//M,O,MOM
}



TEST(intArray, T1) {
	string str = "1234567890";
	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	int* res = toIntArray(str);
	for (int i = 0; i < 10; i++)
		EXPECT_EQ(arr[i], res[i]);
}

TEST(intArray, T2) {
	string str1 = "1111111111";
	string str2 = "1111111111";

	int arr[] = { 2,2,2,2,2,2,2,2,2,2 };

	int* res = addTwoArray(str1, str2);
	for (int i = 0; i < 10; i++)
		EXPECT_EQ(arr[i], res[i]);
}
TEST(intArray, T3) {
	string str1 = "1111111111";
	string str2 = "1111111111";

	int arr[] = { 0,0,0,0,0,0,0,0,0,0 };

	int* res = subTwoArray(str1, str2);
	for (int i = 0; i < 10; i++)
		EXPECT_EQ(arr[i], res[i]);
}