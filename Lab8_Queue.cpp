#include<iostream>
#include"21i0390.h"
#include<cstring>
using namespace std;


int main()
{
	Queue<int> Q1;
	Q1.enqueue(1, 50);
	Q1.enqueue(2, 30);
	Q1.enqueue(3, 80);
	Q1.enqueue(4, 100);

	RoundRobin(Q1);
	string x;
	x = "Data Structures and Algo";
	ConcatQueues<char>(x);

}