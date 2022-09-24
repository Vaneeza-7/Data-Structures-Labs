//Design an application for List class using templates, with following data members :
//a. A pointer of type T
//b. A variable capacity of type int to hold the total capacity of the list
//c. A variable counter of type int which holds the current index of the list
//Your class should be able to perform following operations :
//
//1 insert(T item)
//Inserts an itemand increments the counter only if the list is not full
//
//2 insertAt(T item, int index)
//The function takes two parameters i.e., item of type Tand an integer parameter which points
//to the position where the insertion is to be done.Make sure you do not overwrite values.For
//this you will have to increment the counter to create additional space for the item to be
//inserted.
//
//3 insertAfter(T itemTobeInserted, T item)
//The first parameter of this function represents the item to be inserted in the list, the second
//parameter represents the item already present in the list.You must search the item already
//present in the listand then insert the itemtobeinserted after item.Use the functions of your
//own code instead of replicating logic.
//
//4 insertBefore(T itemTobeInserted, int item)
//The first parameter of this function represents the item to be inserted in the list, the second
//parameter represents the item already present in the list.You must search the item already
//present in the listand then insert the itemtobeinserted before item.Use the functions of your
//own code instead of replicating logic, i.e.
//
//5 isEmpty()
//Checks if the counter variable is zero, i.e., the list is empty there are no elements.
//
//6 isFull()
//Checks if the counter variable has reached the total capacity of the List, which means no
//more insertions are possible.
//
//7 remove(T item)
//Removes item passed through parameters.Make sure you update the counter after removing
//one item.
//
//8 removeBefore(T item)
//You pass an item through parameter, then search for it in the array, then remove the item
//present before this item.i.e. if I have{ 1, 2, 3, 4 } in array.I pass 3 to this function the
//resultant array should look like{ 1,3,4 }. Make sure you update counter after removing one
//item.
//
//9 removeAfter(T item)
//You pass an item through parameter, then search for it in the array, then remove the item
//present after this item.i.e. if I have{ 1, 2, 3, 4, 5 } in array.I pass 3 to this function the
//resultant array should look like{ 1,2, 3, 5 }. Make sure you update counter after removing one
//item.
//
//10 search(T item)
//This function searches for the item passed through parameter.If item exists, return index
//number.But if you didn’t get the item in the list, what are you going to return ?
//
//11 print()
//Print all the items of the List.
//
//12 operator==(List & amp; L)
//we can overload == to compare the items of two lists.If the lengths of both the lists aren’t
//same, you don’t have to go further to check for the items, i.e., the lists are already unequal.
//
//13 reverse()
//Reverse all the elements of the List.


#pragma once
#include<iostream>
using namespace std;

template <typename T>

class List
{ public:
	T* values;
	int capacity;
	int counter;

	List(int cap)
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

	bool isEmpty()
	{
		if (counter==0)
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

	bool insertAt(T val, int index)
	{
		if (!isFull())
		{
			int sizeprev = counter;
			counter++;
			T* temp = new T[counter];
			for (int i = 0; i < sizeprev+1; i++)
			{
				if(i>index)
				temp[i] = values[i-1];
				if (i < index)
					temp[i] = values[i];
				
			}

			for (int i = 0; i < counter; i++)
			{
				if (i == index)
					temp[index] = val;
			}

			values = temp;
			return true;
		}

		else
			return false;

	}

	bool insertAfter(T val, T item)
	{
		if (!isFull())
		{
			int itemPos;
			int sizeprev = counter;
			
			for (int i = 0; i < counter; i++)
			{
				if (values[i] == item)
					itemPos = i+1;
			}

			counter++;
			
			T* temp = new T[counter];
			
			for (int i = 0; i < sizeprev+1; i++)
			{
				if(i>itemPos)
				temp[i] = values[i-1];
				if (i < itemPos)
					temp[i] = values[i];
				
			}

			for (int i = 0; i < counter; i++)
			{
				if (i == itemPos)
					temp[itemPos] = val;
			}

			values = temp;
			return true;
		}

		else
			return false;

	}

	bool insertBefore(T val, int item)
	{
		if (!isFull())
		{
			int itemPos;
			int sizeprev = counter;

			for (int i = 0; i < counter; i++)
			{
				if (values[i] == item)
					itemPos = i ;
			}

			counter++;

			T* temp = new T[counter];

			for (int i = 0; i < sizeprev + 1; i++)
			{
				if (i > itemPos)
					temp[i] = values[i - 1];
				if (i < itemPos)
					temp[i] = values[i];

			}

			for (int i = 0; i < counter; i++)
			{
				if (i == itemPos)
					temp[itemPos] = val;
			}

			

			values = temp;
			
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
		int itemPos;
		int sizeprev = counter;

		for (int i = 0; i < counter; i++)
		{
			if (values[i] == val)
				itemPos = i;
		}

		counter--;

		T* temp = new T[counter];

		for (int i = 0; i < sizeprev; i++)
		{
			if (i > itemPos)
				temp[i - 1] = values[i];
			if (i < itemPos)
				temp[i] = values[i];

		}

		values = temp;
		
		return true;

	}

	bool removeBefore(T val)
	{
		bool flag = false;
		
		int itemPos;
		int sizeprev = counter;

		for (int i = 0; i < counter; i++)
		{
			if (values[i] == val)
				itemPos = i-1;
		}

		counter--;

		T* temp = new T[counter];

		for (int i = 0; i < sizeprev; i++)
		{
			if (i > itemPos)
				temp[i - 1] = values[i];
			if (i < itemPos)
				temp[i] = values[i];

		}

		

		values = temp;
		
		return true;

	}

	bool removeAfter(T val)
	{
		bool flag = false;
		
		int itemPos;
		int sizeprev = counter;

		for (int i = 0; i < counter; i++)
		{
			if (values[i] == val)
				itemPos = i + 1;
		}

		counter--;

		T* temp = new T[counter];

		for (int i = 0; i < sizeprev; i++)
		{
			if (i > itemPos)
				temp[i - 1] = values[i];
			if (i < itemPos)
				temp[i] = values[i];

		}


		values = temp;

		return true;

	}

	bool operator==(List& L)
	{
		bool flag = true;

		if (counter != L.counter)
			flag = false;

		else
			for (int i = 0; i < counter; i++)
			{
				if (values[i] != L.values[i])
					flag = false;
			}


		return flag; 
	}

	void reverse()
	{
		T* temp = new T[counter];
		for (int i = 0; i < counter; i++)
		{
			temp[counter-1-i] = values[i];
		}

		values = temp;
	}

	void print()
	{
		for (int i = 0; i < counter; i++)
		{
			cout << values[i] << " ";
		}
	}

};