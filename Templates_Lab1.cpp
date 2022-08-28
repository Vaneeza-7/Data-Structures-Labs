#include<iostream>
using namespace std;

template <typename T>

T smaller(T a, T b)
{
	if (a < b)
		return a;
	if(b<a)
	 return b;
}

template <typename T>

T smaller(T a, T b, T c)
{
	if (a < b && a < c)
		return a;

	if (b < a && b < c)
		return b;

	if (c < b && c < a)
		return c;

}

//---------------------------------TASK3-------------------

template <typename T>

T* sameElement(T* arr1, T* arr2, int size1, int size2)
{//{
//	int count = 0;
//	
//	for (int i = 0; i < size1; i++)
//	{
//		if (arr1[i] == arr2[i])
//		{
//			//arr[i] = arr1[i];
//			count++;
//		}
//	/*	for (int j = 0; j < count; j++)
//		{
//			if (arr1[j] == arr2[j])
//			{
//				arr[count] = arr1[j];
//			}
//		}*/
//	}
//
//
//	T* arr = new T[count];
//
//	for (int i = 0; i < size1; i++)
//	{
//		for (int j = 0; j < size2; j++)
//		{
//			if(arr1[j]==arr2[j])
//
//			 arr[i] = arr1[j];
//		}
//	}
	int count = 0;

	T* arr = new T[size1];
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j ++ )
		{
			if (arr1[i] == arr2[j])
			{
				arr[count] = arr1[i];
				count++;
			}
		}
	}

	return arr;

}

template <typename T>
T* concatenateArrays(T* arr1, T* arr2, int size1, int size2)
{
	/*int count = 0;
	int Size = size1 + size2;
	T* arr = new T[Size];
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j ++ )
		{
			if (arr1[i] != arr2[j])
			{
				arr[count] = arr1[i];
				count++;
			}
		}
	}*/

	int Size = size1 + size2;
	T* arr = new T[Size];
	for (int i = 0; i < size1; i++)
	{
		arr[i] = arr1[i];
	}

	for (int i = 0; i < size2; i++)
	{
		arr[Size1] = arr2[i];
		Size1++;
	}

	for (int i = 0; i < Size; i++)
	{

	}


	return arr;
}


//----------------Task4--------------

template <typename T>

class container
{
	T* values;
	int capacity;
	int counter;

public:
	container(int cap)
	{
		capacity = cap;
		counter = 0;
		values = new T[capacity];
	}

	bool isFull()
	{
		if (capacity == counter)
		return true;
		else
			return false;

	}

	bool insert(T val)
	{
		if (!isFull())
		{
			values[counter] = val;
			counter++;
			return true;
		}

		else 
			return false;

	}

	bool search(T val)
	{
		bool found = false;

		for (int i = 0; i < capacity; i++)
		{
			if (values[i] == val)
			{
				found = true;

			}
		}

		return found;

	}

	bool remove(T val)
	{
		bool flag = false;
		/*if (search(val) == true)
		{
			capacity = capacity - 1;
		}*/
		for (int i = 0; i < capacity; i++)
		{
			if (val==values[i])
			{
				flag = true;
				counter--;
			}

		}

		return flag;
	}

};