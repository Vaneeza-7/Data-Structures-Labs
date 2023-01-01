#pragma once
#include<iostream>
#include<new>
using namespace std;

template<class T1, class T2>
class node
{
private:
	T1 EmpID;
	T1 CNIC;
	T1 JoiningDate;
	T2 Salary;
	T2 Bonus;
public:
	node<T1, T2> *next;
	node<T1, T2> *prev;
	node(T1 id, T1 CNIC, T1 JoiningDate, T2 salary, T2 bonus)
	{
		this ->EmpID = id;
		this ->CNIC = CNIC;
		this ->JoiningDate = JoiningDate;
		this ->Salary = salary;
		this ->Bonus = bonus;
	}

	node()
	{
		this->EmpID = "000";
		this->CNIC = "000";
		this->JoiningDate = "000";
		this->Salary = 0;
		this->Bonus = 0;
	}
	void setSalary(T2 sal) {
		Salary = sal;
	}

	T1 getID()
	{
		return EmpID;
	}

	T1 getcnic()
	{
		return CNIC;
	}

	T1 getJoiningdate()
	{
		return JoiningDate;
	}

	T2 getSalary()
	{
		return Salary;
	}

	T2 getBonus()
	{
		return Bonus;
	}
};

template<class T1, class T2>
class linkList
{
public:
	node<T1, T2> *head;
	node<T1, T2> *tail;
	linkList()
	{
		head = tail = NULL;
	}
	linkList(const linkList& l)
	{
		while(l.head!=tail){
			this->EmpID = l->head.EmpID;
			this->CNIC = l->head.CNIC;
			this->JoiningDate = l->head.JoiningDate;
			this->Salary = l->head.Salary;
			this->Bonus = l->head.Bonus;
			l.head = l.head->next;
		}

	}

	bool isEmpty()
	{
		if (head == NULL)
			return true;
		else
			return false;
	}

	void insert(T1 id, T1 CNIC, T1 JoiningDate, T2 salary, T2 bonus)
	{
		node<T1, T2>* temp = new node<T1,T2>(id, CNIC, JoiningDate, salary, bonus);
		if (isEmpty())
		{
			head = tail = temp;
			head->prev = tail;
			tail->next = head;
		}
		else
			tail->next = temp;
		    temp->prev = tail;
			temp->next = head;
			
			head->prev = temp;
			tail = temp;
			
	}

	bool search(T1 id)
	{
		bool found = false;
		node<T1, T2>* temp = new node<T1,T2>();
		temp = head;
		do
		{
			if (temp->getID() == id)
			{
				found = true;
				break;
			}
			temp = temp->next;

		} while (temp != tail->next);

		return found;
	}
	bool UpdateSalary(T1 id, T2 newSalary) {
		bool update = false;
		node<T1, T2>* temp;
		temp = head;
			do
			{
				if (temp->getID() == id)
				{
					temp->setSalary(newSalary);
					update = true;
					break;
				}
				else
					temp = temp->next;
			} while (temp->getID() != id || temp != tail->next);
	
			return update;
	}
	T2 MaxSalary() {
		node<T1, T2>* temp = new node<T1, T2>();
		temp = head;
		T2 maxSal = temp->getSalary();
		do
		{
			if (temp->getSalary() > maxSal)
				maxSal = temp->getSalary();
			else
				temp = temp->next;
		} while (temp != tail->next);

		return maxSal;
	}

	bool remove(T1 id)
	{
		bool remove = false;
		node<T1, T2>* temp=new node<T1, T2>();
		temp = head;
		try {
			do
			{
				if (temp->getID() == id)
				{
					//temp->prev = temp->next;
					//(temp->next)->prev = temp->prev;
					temp->next = (temp->prev)->next;
					temp->prev = (temp->next)->prev;
					delete temp;
					temp = NULL;
					remove = true;
					break;
				}
				else
					temp = temp->next;

			} while (temp != tail->next);
		}
		catch (bad_alloc)
		{
			cout << "Exception is thrown here.\n";
		}
		return remove;

	}

	void print() {
		node<T1, T2>* temp;
		temp = head;
		do{
		
			cout << "Employee ID: " << temp->getID();
			cout << " Employee CNIC: " << temp->getcnic();
			cout << " Employee Joining date: " << temp->getJoiningdate();
			cout << " Employee Salary: " << temp->getSalary();
			cout << " Employee Bonus: " << temp->getBonus();
			cout << "\n-------------\n";
			temp = temp->next;
		} while (temp != tail->next);
		

	}
};

