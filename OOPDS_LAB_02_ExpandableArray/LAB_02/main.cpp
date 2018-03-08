/* main.cpp for ExpandableArray */
#include <iostream>
#include <iomanip>
#include <string.h>

#include "ExpandableArray.h"

#define NUM_EA 10
#define NUM_EB 15

using namespace std;

void main()
{
	int n;
	double d = 0.0;
	ExpandableArray eA("eA"), eB("eB"), eC("eC");
	d = 0.0;
	for (int i = 0; i < NUM_EA; i++)
	{
		eA.insert(i, d);
		d += 1.1;
	}
	cout << "Contents of eA : ";
	eA.print(cout);
	cout << "Capacity of eA = " << eA.capacity() << endl;
	
	cout << "--------------------------------------------------------------------------------------------------------------" << endl;
	
	cout << "Configuring eB with " << NUM_EB * 3 << " elements .... " << endl;
	d = 10.0;
	for (int i = 0; i < NUM_EB; i++)
	{
		eB.insert(0, d);
		d += 2.2;
		eB.print(cout);
	}
	
	cout << "--------------------------------------------------------------------------------------------------------------" << endl;

	eA.copy(eB); //eC = eA = eB;
	eC.copy(eA);
	cout << "Capacity of after eA.copy(eB) : " << eA.capacity() << endl;
	cout << "Contents of eA (after copy()) : ";
	eA.print(cout);
	cout << "Capacity of after eC.copy(eA) : " << eC.capacity() << endl;
	cout << "Current size of eC = " << eC.size() << endl;
	cout << "Contents of eC (after copy()) : " << endl;
	for (int i = 0; i < eC.size(); i++)
	{
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);
		cout << setw(6) << eC.at(i) << " "; // using operator overloading of "[ ]"
	}
	cout << endl;

	cout << "--------------------------------------------------------------------------------------------------------------" << endl;

	eC.quickSort();
	eC.print(cout);
	eC.shuffle();
	eC.print(cout);
	eC.quickSort();
	eC.print(cout);

	cout << "--------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < eC.size(); i++)
	{
		eC.set(i, eC.at(i) * 2); // using operator overloading of "[ ]"
	}
	eC.print(cout);
	n = eC.size();
	for (int i = 0; i < n; i++)
	{
		eC.erase(0);
		eC.print(cout);
	}

	cout << "--------------------------------------------------------------------------------------------------------------" << endl;
}