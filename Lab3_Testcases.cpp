#include "pch.h"
#include "Header.h"



TEST(arraySum, T1) {
	int arr[][5] = { { 1,2,3,4,5 },{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5 },{1,2,3,4,5} };
	int sum = arraySum(arr, 5, 5);
	EXPECT_EQ(75, sum);
}

TEST(arraySum, T2) {
	int arr[][5] = { { 1,2,6,8,0},{10,6,8,3,5},{15,9,4,7,2},{8,5,2,7,6},{7,5,3,1,9} };
	int sum = arraySum(arr, 5, 5);
	EXPECT_EQ(139, sum);
}


TEST(rowSum, T1) {
	int arr[][4] = { { 1,5,8,2},{1,4,10,8},{7,2,0,1},{1,23,3,4} };
	int res[4] = { 16,23,10,31 };
	int* sum = rowSum(arr,4,4);
	for (int i = 0; i < 4; i++)
		EXPECT_EQ(res[i], sum[i]);
}
TEST(rowSum, T2) {
	int arr[][4] = { { 1,8,2,9},{4,10,8,2},{7,2,1,6} };
	int res[3] = { 20,24,16 };
	int* sum = rowSum(arr,3,4);
	for (int i = 0; i < 3; i++)
		EXPECT_EQ(res[i], sum[i]);
}


TEST(colSum, T1) {
	int arr[][4] = { { 1,5,8,2},{1,4,10,8},{7,2,0,1},{1,23,3,4} };
	int res[4] = { 10,34,21,15 };
	int* sum = colSum(arr,4,4);
	for (int i = 0; i < 4; i++)
		EXPECT_EQ(res[i], sum[i]);
}
TEST(colSum, T2) {
	int arr[][4] = { { 7,5,3,2},{0,4,3,8},{7,2,4,1},{3,8,5,0} };
	int res[4] = { 17,19,15,11 };
	int* sum = colSum(arr,4,4);
	for (int i = 0; i < 4; i++)
		EXPECT_EQ(res[i], sum[i]);
}

TEST(transposeMatrix, T1) {
	int arr[][2] = { {8,2},{1,4} };
	int res[][2] = { {8,1},{2,4} };
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			EXPECT_EQ(res[i][j], transposeMatrix(arr,2,2)[i][j]);
}
TEST(transposeMatrix, T2) {
	int arr[][2] = { {10,8},{3,9} };
	int res[][2] = { {10,3},{8,9} };
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			EXPECT_EQ(res[i][j], transposeMatrix(arr,2,2)[i][j]);
}


TEST(matrixSum, T1) {
	int arr[][3] = { {8,2,4},{1,4,9},{4,8,1} };
	int arr1[][3] = { {1,8,1},{2,5,4},{5,4,0} };
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			EXPECT_EQ(arr[i][j] + arr1[i][j], matrixSum(arr, arr1,3,3)[i][j]);
}
TEST(matrixSum, T2) {
	int arr[3][3] = { {10,8,7},{3,9,1} ,{3,8,5} };
	int arr1[3][3] = { {10,3,1},{8,9,10},{5,3,9} };
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			EXPECT_EQ(arr[i][j] + arr1[i][j], matrixSum(arr, arr1,3,3)[i][j]);
}

TEST(matrixMult, T1) {
	int mat1[4][4] = { { 1, 1, 1, 1 },{ 2, 2, 2, 2 },{ 3, 3, 3, 3 },{ 4, 4, 4, 4 } };// 4*4
	int mat2[4][4] = { { 1, 1, 1, 1 },{ 2, 2, 2, 2 },{ 3, 3, 3, 3 },{ 4, 4, 4, 4 } };//4*4
	EXPECT_EQ(400, multiplyMatrix(mat1, mat2, 4, 4, 4, 4));
}
/*

*/





TEST(leftdiagonalSum, T1)
{
	int arr[][4] = { {1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4} };
	EXPECT_EQ(10, leftDiagonalSum(arr,4,4));
}
TEST(leftdiagonalSum, T2)
{
	int arr[][4] = { {1,5,3,9},{54,8,9,4},{1,4,2,9},{4,9,2,0} };
	EXPECT_EQ(11, leftDiagonalSum(arr,4,4));
}

TEST(rightdiagonalSum, T1)
{
	int arr[][4] = { {1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4} };
	EXPECT_EQ(10, rightDiagonalSum(arr,4,4));
}
TEST(rightdiagonalSum, T2)
{
	int arr[][4] = { {1,5,3,9},{54,8,9,4},{1,4,2,9},{4,9,2,0} };
	EXPECT_EQ(26, rightDiagonalSum(arr,4,4));
}


TEST(displayMiddleRow, T1)
{
	int arr[][5] = { {1,5,9,3,5},{14,8,2,0,4},{4,4,0,1,2},{7,45,89,2,9},{5,2,8,5,0} };
	int res[5] = { 4,4,0,1,2 };
	for (int i = 0; i < 5; i++)
		EXPECT_EQ(res[i], displayMiddleRow(arr, 5)[i]);
}
TEST(displayMiddleRow, T2)
{
	int arr[][5] = { {1,2,3,4,5}, {6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25} };
	int res[5] = { 11,12,13,14,15 };
	for (int i = 0; i < 5; i++)
		EXPECT_EQ(res[i], displayMiddleRow(arr, 5)[i]);
}

TEST(displayMiddleCol, T1)
{
	int arr[][5] = { {1,5,9,3,5},{14,8,2,0,4},{4,4,0,1,2},{7,45,89,2,9},{5,2,8,5,0} };
	int res[5] = { 9,2,0,89,8 };
	for (int i = 0; i < 5; i++)
		EXPECT_EQ(res[i], displayMiddleCol(arr, 5)[i]);
}
TEST(displayMiddleCol, T2)
{
	int arr[][5] = { {1,2,3,4,5}, {6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25} };
	int res[5] = { 3,8,13,18,23 };
	for (int i = 0; i < 5; i++)
		EXPECT_EQ(res[i], displayMiddleCol(arr, 5)[i]);
}


TEST(readFromFile, T1) {

	int res[5] = { 5,5,5,5,5 };
	
	int* sum = readFromFile();
	for (int i = 0; i < 5; i++)
		EXPECT_EQ(res[i], sum[i]);
}





//write test cases for Task 5 by yourself



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