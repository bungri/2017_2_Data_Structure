#ifndef EXPANDABLE_ARRAY_H
#define EXPANDABLE_ARRAY_H

#include <iostream>
using namespace std;

/* Define a class ExpandableArray that dynamically expand when a bigger capacity is necessary.
   The class ExpandableArray contains a dynamically created double-type array as private data members. */

class ExpandableArray
{
public:
	ExpandableArray(char name[] = ""); // default constructor
	~ExpandableArray(); // default destructor
	/* Member functions size() and capacity() returns the current number of elements in the expandable array and the capacity, respectively. */
	int size() const { return n; } // return number of elements
	int capacity() const { return capa; } // return the capacity
	bool empty() const { return n == 0; }
	void reserve(int N); // reserve at least N slots
	void insert(int i, double element); // insert element e at index i
	void erase(int i); // delete/erase element at index i
	double& at(int i); // read element at index i
	void set(int i, double element); // replace element e at index i
	void copy(const ExpandableArray& ea); // copy from another expandable_array
	void print(ostream& fout);
	void quickSort();
	void quickSort(double *arr, int size);
	void shuffle();
private:
	bool isValidIndex(int index);
	void swap(double *dst, double *src);
	char name[16]; // name of expandable array
	int capa; // capacity of the expandable array
	int n; // current size of the elements in the expandable array
	double *dA; // pointer of double array
};

#endif