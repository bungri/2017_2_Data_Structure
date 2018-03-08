/* ExpandableArray.cpp */
#include <iostream>
#include <iomanip>
#include <string.h>
#include <time.h>

#include "ExpandableArray.h"

using namespace std;

ExpandableArray::ExpandableArray(char name[]) // default constructor
{
	/* Constructor ExpandableArray(char name[]=“”) set the name with given string argument, set capa as 1, and dynamically create a double-type array of “capa” size. */
	cout << "ExpandableArray :: Constructor(name : " << name << ") - default Constructor\n";
	strcpy(this->name, name);
	capa = 1;
	n = 0;
	this->dA = (double*)calloc(capa, sizeof(double));
}

ExpandableArray::~ExpandableArray() // default destructor
{
	/* Destructor ~ExpandableArray() frees the allocated memory for dynamic double-type array. */
	cout << "ExpandableArray :: Destructor(name : " << this->name << ") - free memory of array (capacity : " << this->capa << ")\n";
	free(this->dA);
}
void ExpandableArray::reserve(int N) // reserve at least N slots
{
	/* Member function void reserve(int N) reserves a double-type array of given size N, if N is larger than current capacity.
	   When a bigger array is newly created, the elements are copied to the newly created array, and the old array is deleted */
	double *temp = (double*)calloc(N, sizeof(double));
	for (int i = 0; i < this->capa ; i++)
	{
		temp[i] = this->dA[i];
	}
	free(this->dA);
	dA = temp;
	cout << "ExpandableArray :: reserve .... Expanding array " << this->name << " capacity from " << this->capa << " to " << N << "\n";
	this->capa = N;
}
void ExpandableArray::insert(int i, double element) // insert element e at index i
{
	/* Member function void insert(int i, double element) inserts an element into the position i.
	   All elements from position i ~ position n-1 should be shifted to its next position in order to make a room for the new element.
	   If the capacity of the expandable array is not big enough to insert a new element, the capacity is expanded twice by new dynamic memory allocation using the member function reserve().*/
	if (!this->isValidIndex(i))
	{
		return;
	}
	if (n == capa)
		reserve(capa * 2);

	if (i >= n)
		dA[i] = element;
	else
	{
		for (int index = n; index > i; index--)
			dA[index] = dA[index - 1];
		dA[i] = element;
	}
	n++;
	cout << "ExpandableArray (" << this->name << ")::Insert(index = " << i << ", elem = " << setprecision(2) << element << ")\n";

}
void ExpandableArray::erase(int i) // delete/erase element at index i
{
	/* Member function void erase(int i) erases an element in the given position i.
	   When an element at position i is erased, all elements in positions i+1 ~ n-1 are shifted to the previous positions.*/
	if (!this->isValidIndex(i))
	{
		return;
	}
	cout << "ExpandableArray (" << this->name << ")::Erase(index = " << i << ", elem = " << setprecision(2) << dA[i] << ")\n";
	if (i >= n)
		dA[i] = 0;
	else
	{
		for (int index = i; index < n - 1; index++)
			dA[index] = dA[index + 1];
	}
	n--;

}
double& ExpandableArray::at(int i) // read element at index i
{
	/* Member function double& at(int i) reads the element at position i. */
	if (this->isValidIndex(i))
	{
		return this->dA[i];
	}
}
void ExpandableArray::set(int i, double element) // replace element e at index i
{
	/* Member function void set(int i, double element) replaces the element at position i by the given element. */
	if (!this->isValidIndex(i))
	{
		return;
	}
	dA[i] = element;
}
void ExpandableArray::copy(const ExpandableArray& ea) // copy from another expandable_array
{
	/* Member function void copy(const ExpandableArray& ea) copies from the given expandable array ea. */
	while (this->capa < ea.capa)
		reserve(this->capa * 2);
	this->n = 0;
	for (int i = 0; i < ea.n; i++)
	{
		this->dA[i] = ea.dA[i];;
		this->n++;
	}

}
void ExpandableArray::print(ostream& fout)
{
	fout.setf(iostream::fixed);
	fout.setf(iostream::showpoint);
	fout.precision(2);
	/* Member function void print(ostream& fout) prints out the contents of the expandable array into the specified output stream object fout.*/
	if (this->empty())
	{
		fout << "ExpandableArray is empty!!\n";
	}
	else {
		fout << this->name << "'s current size : " << n << "\n";
		for (int i = 0; i < this->n; i++)
		{
			fout << setw(7) << this->dA[i];
		}

		fout << "\n";
	}
}

bool ExpandableArray::isValidIndex(int index)
{
	/* Member function bool isValidIndex(int index) checks the validity of index for the member functions, insert(), erase() and set(), and generates error messages if the given index is out-of-range. */
	if (index > n)
	{
		cout << index << "is not vaild index(Out of range)... terminate program.\n";
		exit(1);
	}
	return index<=n;
}

void ExpandableArray::quickSort()
{
	cout << "Quick sort array " << this->name << "\n";
	quickSort(this->dA, this->n);
}

void ExpandableArray::quickSort(double *arr, int size)
{
	//sorts the given arr of students in increasing order of ID.Using the printStudents()
	//print out the arr of sorted arr of students.

	if (size <= 1)	//더이상 sorting 할 j항목이 없음!
	{
		return;
	}
	int right = size - 1;
	int storeIndex = 0;
	double pivotValue = arr[right / 2];
	swap(arr + right / 2, arr + right);	//가운데값을 pivotIndex로 잡아 right 값과 스왑 후 pivotValue 추출

	if (size > 1)
	{
		for (int left = 0; left < size; left++)
		{
			if (arr[left] < pivotValue) {
				if (left == storeIndex)	//storeIndex와 left가 같다면 swap을 하는 것은 메모리 낭비!
				{
					storeIndex++;
					continue;
				}
				swap(arr + left, arr + storeIndex);	//left가 pivotVale보다 작다면 storeIndex와 스왑 후 storeIndex 1 증가
				storeIndex++;
			}
		}
		swap(arr + storeIndex, arr + right);	//원래대로 스왑
	}
	quickSort(arr, storeIndex);	//recursive call - 왼쪽 / cut 할 배열이 없으니 최대값만 cut 해서 함수 호출
	quickSort(arr + (storeIndex + 1), size - (storeIndex + 1));	//sorting이 완료된 왼쪽 배열은 잘라내고 오른쪽 배열만 인수로 전달
}

void ExpandableArray::swap(double *dst, double *src)
{
	double temp = *src;
	*src = *dst;
	*dst = temp;
}

void ExpandableArray::shuffle()
{
	srand(time(NULL));
	int freq = rand() % 100 + n;
	cout << "Shuffle array " << this->name << " " << freq << " times \n";
	for (int i = 0; i < freq; i++)
		swap(dA + rand() % n, dA + rand() % n);
}