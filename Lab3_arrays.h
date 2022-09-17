#pragma once
#include<iostream>
#include<fstream>
using namespace std;

//Task1
//Make a menu of the following operations using two dimensional array of size m x n.You should use
//user - defined functions which accept 2 - D array A, and its size mand n as arguments.The options are :
//To input elements into matrix of size m x n
//To display elements of matrix of size m x n
//Sum of all elements of matrix of size m x n
//To display row - wise sum of matrix of size m x n
//To display column - wise sum of matrix of size m x n
//To create transpose of matrix of size n x m

int arraySum(int arr[5][5], int row, int col)
{
	int m = row;
	int n = col;
	int sum = 0;
	int** array = new int*[m];
	for (int i = 0; i < m; i++)
	{
		array[i] = new int[n];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			array[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum = sum + array[i][j];
		}
	}


	return sum;
}

int* rowSum(int arr[][4], int row, int col)
{
	int m = row;
	int n = col;
	int sum=0;
	int** array = new int* [m];
	for (int i = 0; i < m; i++)
	{
		array[i] = new int[n];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			array[i][j] = arr[i][j];
		}
	}

	int* sumarray = new int[m];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum = sum + array[i][j];
		}
		sumarray[i] = sum;
		sum = 0;
	}

	
	return sumarray;
}

int* colSum(int arr[][4], int row, int col)
{
	int m = row;
	int n = col;
	int sum=0;
	int** array = new int* [m];
	for (int i = 0; i < m; i++)
	{
		array[i] = new int[n];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			array[i][j] = arr[i][j];
		}
	}

	int* sumarray = new int[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			sum = sum + array[j][i];
		}
		sumarray[i] = sum;
		sum = 0;
	}


	return sumarray;
}

int** transposeMatrix(int arr[][2], int row, int col)
{
	int m = col;
	int n = row;
	int** array = new int* [m];
	for (int i = 0; i < m; i++)
	{
		array[i] = new int[n];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			array[i][j] = arr[j][i];
		}
	}

	return array;
}


//-------------TASK2--------------
//Write a C++ program for two dimensional arrays Aand B of size m x n to calculate,
// Addition of Aand B
// Multiplication of Aand B

int** matrixSum(int arr1[][3], int arr2[][3], int row, int col)
{
	int m = row;
	int n = col;
	int** array = new int* [m];
	for (int i = 0; i < m; i++)
	{
		array[i] = new int[n];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			array[i][j] = arr1[i][j]+arr2[i][j];
		}
	}

	return array;

}

int multiplyMatrix(int arr1[][4], int arr2[][4], int row, int col, int row2, int col2)
{
	int m = row;
	int n = col;
	int sum=0;
	int s=0;
	int** array = new int* [m];
	for (int i = 0; i < m; i++)
	{
		array[i] = new int[n];
	}

	for (int i = 0; i < m; i++)
	{
		
		for (int j = 0; j < n; j++)
		{
			sum = sum + (arr1[i][j] * arr2[j][i]);

			array[i][j] = sum;
			
		}
		sum = 0;
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			s = s + array[i][j];
		}
	}


	return s*2;
}

//-------------Task3------------
//Write a C++ program for two dimensional array A of size m x n to calculate,
//Left diagonal sum
//Right diagonal sum

int leftDiagonalSum(int arr[][4], int row, int col)
{
	int m = row;
	int n = col;
	int sum = 0;
	int** array = new int* [m];
	for (int i = 0; i < m; i++)
	{
		array[i] = new int[n];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			array[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(i==j)
			sum = sum + array[i][j];
		}
	}


	return sum;

}

int rightDiagonalSum(int arr[][4], int row, int col)
{
	int m = row;
	int n = col;
	int sum = 0;
	int** array = new int* [m];
	for (int i = 0; i < m; i++)
	{
		array[i] = new int[n];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			array[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j <n ; j++)
		{
			if(i+j==3)
				sum = sum + array[i][j];
		}
	}


	return sum;

}

//-----------------TASK4--------------
//Write a program in C++ which accepts a 2 dimensional array of integers and its size as arguments
//and displays the elements of middle row and the elements of middle column.
//[Assuming the 2D Array to be a square matrix with odd dimension i.e. 3x3, 5x5, 7x7 etc...]

int* displayMiddleRow(int arr[][5], int row)
{

	int m = row;
	int n = 5;

	int* resarray = new int[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 2)
				resarray[j] = arr[i][j];

		}
		
	}


	return resarray;

	
}

int* displayMiddleCol(int arr[][5], int row)
{

	int m = row;
	int n = 5;

	int* resarray = new int[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j == 2)
				resarray[i] = arr[i][j];

		}

	}
	return resarray;

}

//--------------Task5----------------
/*We have a problem in C++ we cannot handle an integer number more than 8bytes.So the solution is
to store the number(from input) as string and then to array*/

int* toIntArray(string str)
{
	int size = str.length();
	int* res = new int[size];
	for (int i = 0; i < size; i++)
	{
		res[i] = str[i] - 48;
	}
	return res;
}

//Now take input for 2 arrays using above method and then add two arrays.

int* addTwoArray(string str1, string str2)
{
	int size1 = str1.length();
	int* res1 = new int[size1];

	int size2 = str2.length();
	int* res2 = new int[size2];

	res1 = toIntArray(str1);
	res2 = toIntArray(str2);

	int* res3 = new int[size1];
	for (int i = 0; i < size1; i++)
	{
		res3[i] = res1[i] + res2[i];
	}

	return res3;
}

//Subtract the arrays.

int* subTwoArray(string str1, string str2)
{
	int size1 = str1.length();
	int* res1 = new int[size1];

	int size2 = str2.length();
	int* res2 = new int[size2];

	res1 = toIntArray(str1);
	res2 = toIntArray(str2);

	int* res3 = new int[size1];
	for (int i = 0; i < size1; i++)
	{
		res3[i] = res1[i] - res2[i];
	}

	return res3;
}



//----------------the following code doesnt pass the test case
// Create a text file and store integer data in it. You have to read the data from the text file and store it
//into two dimensional array of 5x5, then calculate the row - wise sum of two dimensional which you
//read from the text file and store the sum in third one dimensional array.
//int* readFromFile()
//{
//	ofstream outputFile;
//	outputFile.open("File.txt");
//	outputFile <<  "1 1 1 1 1  1 1 1 1 1  1 1 1 1 1  1 1 1 1 1  1 1 1 1 1";
//	outputFile.close();
//
//	ifstream inputFile;
//	inputFile.open("File.txt");
//
//	int m = 5;
//	int n = 5;
//	int sum = 0;
//	int** array = new int* [m];
//	for (int i = 0; i < m; i++)
//	{
//		array[i] = new int[n];
//	}
//
//	int a;
//	char string;
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//		    inputFile >> string;
//			array[i][j] = int(string);
//		}
//	}
//
//	inputFile.close();
//
//	int* arr = new int[m];
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			arr[i]= array[i][j];
//		}
//	}
//
//
//	return arr;
//}