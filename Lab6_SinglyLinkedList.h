#pragma once
#include<iostream>
#include<conio.h>

using namespace std;
template <class T>
class Node
{
public:
	T data;
	Node* next;

	Node()
	{
		data = 0;
		next = NULL;
	}

	Node(T d, Node* n)
	{
		data = d;
		next = n;
	}

	Node(T d)
	{
		data = d;
	}

	void setData(T d)
	{
		data = d;
	}

	void setNext(Node* n)
	{
		next = n;
	}

	T getData()
	{
		return data;
	}

	Node* getNext()
	{
		return next;
	}

};

template <class T>
class SLinkedList {

public:

	Node<T>* head;


	SLinkedList()
	{
		head = NULL;
	}

	void insert(T d)
	{
		//if the head is null then the new node is head. else find the end of the list and insert node there.

		Node<T>* n = new Node<T>(d);
		n->next = NULL;
		if (head == NULL)
		{
			head = n;
		}
		else
		{
			Node<T>* temp = head;

			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = n;
		}

	}

	bool isEmpty()
	{
		if (head == NULL)
			return true;
		else return false;
	}

	void insertAtHead(T d)
	{
		Node<T>* n = new Node<T>(d);
		n->next = head;
		head = n;
	}

	void InsertAtIndex(T d, int index)
	{
		/*if (index < 0)
			return NULL;*/

		Node<T>* temp = head;
		int currIndex = 1;
		while (temp && index > currIndex)
		{
			temp = temp->next;
			currIndex++;
		}
		/*if (index > 0 && temp == NULL) return NULL;*/

		Node<T>* n = new Node<T>(d);

		if (index == 0)
		{
			n->next = head;
			head = n;
		}
		else
		{
			n->next = temp->next;
			temp->next = n;
		}
	}

	T search(int index)
	{
		int currIndex = 1;
		Node<T>* temp = head;
		while (temp->next != NULL && index > currIndex)
		{
			if (currIndex == index)
				return temp->data;
			else
				temp = temp->next;
			currIndex++;
		}
	}

	void update(int index, T d)
	{
		int currIndex = 0;
		Node<T>* temp = head;
		while (temp->next != NULL)
		{
			if (currIndex == index)
				temp->setData(d);
			else
				temp = temp->next;
			currIndex++;
		}
	}

	void remove(T d)
	{
		//int currIndex = 1;
		Node<T>* temp = head;
		while (temp->next != NULL /*&& index > currIndex*/)
		{
			if (temp->data == d)
			{
				Node<T>* deletedNode = temp->next;
				temp->next = temp->next->next;
				delete deletedNode;
			}
			else
				temp = temp->next;
			//currIndex++;
		}
	}

	void print()
	{
		Node<T>* temp = head;
		while (temp->next != NULL)
		{
			cout << temp->getData() << " ";
			temp = temp->next;
		}
	}
};