#pragma once
#include<iostream>
#include<fstream>
using namespace std;

//-------------------------------TASK1---------------------
template<class T1>
class node
{
private:
	

public:
	T1 val;
	node<T1>* next;
	node(T1 val)
	{
		this->val = val;
		next = NULL;
	}

	node()
	{
		this->val = 0;
		next = NULL;
	}
	void setdata(T1 d) {
		val = d;
	}

	T1 getData()
	{
		return val;
	}


};

template<class T1>
class stack
{
public:
	int size;
	node<T1>* top;
	stack()
	{
		size = -1;
		top = NULL;
	}

	bool isEmpty()
	{
		if (top == NULL)
			return true;
		else
			return false;
	}

	void push(T1 d)
	{
		node<T1>* temp = new node<T1>(d);
		if (isEmpty())
		{
			top = temp;
			size++;
		}
		else
			temp->next=top;
		    top = temp;
			size++;
	}

	void pop()
	{
		node<T1>* temp = new node<T1>();
		if (!isEmpty())
		{
			temp = top;
			top = top->next;
			delete temp;
			size--;
		}
		else
			cout << "Stack is already empty";
	}


	node<T1>* Peek()
	{
		return top;
	}

	void clear()
	{
		while (isEmpty()!=true)
		{
			pop();
		}
	}

	int sizeofstack()
	{
		return size;
	}

	~stack()
	{
		while (isEmpty() != true)
		{
			pop();
		}
	}

	void print() {
		node<T1>* temp;
		temp = top;
		while (temp)
		{
			cout << "The data of stack is : " << top->getData() << endl;
			temp = temp->next;
		}

	}

};
//--------------------TASK3------------------
class MinStack
{
	stack<int> s;
	stack<int> aux;
public:
	void push(int val)
	{
		if (s.isEmpty() && aux.isEmpty())
		{
			s.push(val);
			aux.push(val);
		}
		else
			s.push(val);
			if(val<aux.top->getData())
			aux.push(val);

	}
	void pop()
	{
		s.pop();
		aux.pop();

	}
	int top()
	{
		return s.top->getData();
	}

	int size() {
		return s.sizeofstack();
	}

	bool isEmpty() {
		if (s.isEmpty())
		{
			return true;
		}
		else
			return false;
	}
	int getMin() {

		return aux.top->getData();
	}
};

//--------------------TASK2---------------------
bool validate(string filename)
{
	stack<char> s;
	ifstream input;
	input.open(filename);

	char data;
	while (input>>data) {
		if (data == '{')
		{
			s.push(data);
		}
		else if (data == '}')
		{
			s.pop();
		}
	}
	input.close();

	if (s.isEmpty())
		return true;
	if (!s.isEmpty())
		return false;
}