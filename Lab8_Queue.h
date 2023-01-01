#pragma once
#include<iostream>
using namespace std;

//--------TASK1--------//
template<class T1>
class node
{
private:
	T1 Id;
	T1 data;

public:
	node<T1>* next;
	node(T1 id, T1 data)
	{
		this->data = data;
		this->Id = id;
		next = NULL;
	}

	node()
	{
		this->data = 0;
		this->Id = 0;
		next = NULL;
	}
	void setdata(T1 d) {
		data = d;
	}

	void setId(T1 id)
	{
		Id = id;
	}

	T1 getID()
	{
		return Id;
	}

	T1 getData()
	{
		return data;
	}


	
};

template<class T1>
class Queue
{
public:
	node<T1>* rear;
	node<T1>* front;
	Queue()
	{
		rear = front = NULL;
	}

	bool isEmpty()
	{
		if (front == NULL)
			return true;
		else
			return false;
	}

	void enqueue(T1 id, T1 data)
	{
		node<T1>* temp = new node<T1>(id, data);
		if (isEmpty())
		{
			front = rear = temp;
		}
		else
			rear->next = temp;
		    rear = temp;

	}

	void dequeue()
	{
		T1 val = -1;
		node<T1>* temp = new node<T1>();
		if (!isEmpty())
		{
			val = front->getData();
			temp = front;
			front = front->next;
			delete temp;
		}
		//return val;

	}

	T1 isfront()
	{
		return front->getData();
	}

	void print() {
		node<T1>* temp;
		temp = front;
		while (temp)
		{
			cout << "The data of Queue member is : " << temp->getData()<<endl;
			//cout << "The id of Queue member is : " << temp->getID() << endl;
			temp = temp->next;
		}

	}

	bool contains(T1 x)
	{
		bool find = false;
		node<T1>* temp;
		temp = front;
		while (temp)
		{
			if (temp->getData() == x)
			{
				find = true;
				break;
			}
			temp = temp->next;
		}
		return find;
	}

};

//--------TASK2--------//

template< class T1>
void RoundRobin(Queue<T1> q)
{
	int Quantime = 30;
	int diff=-1;
	while (q.isEmpty()==false)
	{ 
		diff = q.isfront() - Quantime;
		if (diff <= 0)
		{
			cout << "Execution time: " << q.isfront() << endl;
			cout << " Remaining time: " << diff << endl;
			q.dequeue();
			cout << "Task is completed. It has been removed from Queue.\n";
		}
		else
		{
			cout << "Execution time: " << q.isfront() << endl;
			cout << " Remaining time: " << diff << endl;
			int ID = q.front->getID();
			q.dequeue();
			q.enqueue(ID, diff);
			cout << "Task is not completed. It is being rescheduled.\n";
		}
	}
}

//--------TASK3--------//
template<class T1>
void ConcatQueues(string line)
{
	int numQueues = 1;
	for (int i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == 32)
		{
			numQueues++;
		}
	}

	Queue<char>* q=new Queue<char>[numQueues];
	int word = 0;
	cout << numQueues << endl;
	int num=0;
	while (line[num] != '\0') {
		for (int i = num; line[i] != 32; i++)
		{
			/*if (line[i] == 32)
			{
				num++;
			}*/
			q[word].enqueue(i, line[i]);
		}
		word++;
	}

	for (int i = 0; i < numQueues-1; i++)
	{
		q[i].rear->next = q[i + 1].front;
	}

	for (int i = 0; i < numQueues-1; i++)
	{
		q[i].print();
	}

	



}
