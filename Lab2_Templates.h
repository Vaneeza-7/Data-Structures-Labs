#pragma once
#include<iostream>
#include<cmath>
using namespace std;

//---------------------------TASK1------------------
//Implement the calculator using templates.
//1 - add to number
//2 - add two arrays and return the sum in third.
//3 - subtract two numbers
//4 - div two numbers
//5 - prime number
//6 - factorial using recursion
//7 - square root of number


template<class T>

T add(T a, T b)
{
	return a + b;
}
template<class T>

T sub(T a, T b)
{
	return a - b;
}

template <class T>
T* add(T* a, T* b)
{
	int i = 0;
	int size = 0;

	while (a[i] != 0)
	{
		size++;
		i++;
	}

	T* temp = new T[size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = a[i] + b[i];
	}

	return temp;
}

template <class T>
T Div(T a, T b)
{
	return a / b;

}

template <class T>

bool prime(T a)
{
	bool flag = true;
	for (int i = 2; i <= a / 2; i++) {
		if (a % i == 0) {
			flag = false;
			break;
		}
	}
	return flag;
}

template <class T>

T Fact(T n) 
{
	if (n <= 1) {
		return 1;
	}
	else {

		return n * Fact(n - 1);

	}

}

template <class T>
T SQRT(T a)
{
	return sqrt(a);
}

//----------------------------TASK2------------------
//You are given an array; you have to split it into sets(possibly empty) such that :
//1. The difference between the sizes of these two sets must not exceed 1.
//2. The difference between the sum of elements of these two sets should be maximum
//possible.
//The array is : [5, 3, 2, 10] .Optimal splitting is : { 5, 10 }, { 3, 2 }. Difference between the sums of
//sets is 10.

template <class T>
void swap(T*& a, T*& b)
{
	T* temp;
	temp = a;
	a = b;
	b = temp;
}

void bubblesort(int arr[], int n)
{
	if (n == 0 || n == 1)
	{
		return;
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			swap(arr[i], arr[i + 1]);
		}
	}
	bubblesort(arr, n - 1);
}

template <class T>
T SplitToSets(T* arr, int size)
{
	bubblesort(arr, size);
	int num1 = 0;
	int num2 = 0;
	for (int i = 0; i < size / 2; i++)
	{
		num1 = num1 + arr[i];
	}

	for (int i = size/2; i < size; i++)
	{
		num2 = num2 + arr[i];
	}

	return num2 - num1;
}


//--------------------------TASK3--------------------
//Write a program that takes a string as inputand calculate the possible number of sub - string that are
//palindrome.But substring that are unique.
//Recall that a palindrome is a non - empty string that reads the same backward as forward.Two sub -
//strings are considered to be different if they have different lengths or start at different positions in the
//original string.
//For example string “ABBA” has possible 4 sub - string palindromes{ A, B, BB, ABBA }
int subPalindrome(string str)
{
	int subs = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		subs++;
	}

	return subs;
}

