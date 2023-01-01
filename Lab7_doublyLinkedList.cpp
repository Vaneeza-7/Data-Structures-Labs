#include<iostream>
#include"../Ds-Lab7/i210390.h"
using namespace std;


int main()
{
	linkList<string, int> EMP;
		EMP.insert("21i0390", "333", "12/12/12", 2000, 1000);
		EMP.insert("21i0391", "453", "10/09/14", 9000, 5000);
		EMP.insert("21i0392", "670", "02/05/18", 3500, 8000);
		EMP.insert("21i0393", "120", "05/11/20", 900, 450);

		EMP.print();
		if (EMP.search("21i0391"))
		{
			cout << "ID Found\n";
		}
		else
			cout << "ID not found.\n";


		if (EMP.UpdateSalary("21i0391", 1200))
		{
			cout << "Updated!\n";
			EMP.print();
		}
		else
			cout << "Not Updated.\n";

		cout << "Max Salary is : " << EMP.MaxSalary() << endl;

		if (EMP.remove("21i0392"))
		{
			cout << "Removed.\n";
		}
		else
			cout << "not removed.\n";
		

		
	

		return 0;
}