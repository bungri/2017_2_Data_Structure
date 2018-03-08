#ifndef DATEARRAY_H
#define DATEARRAY_H

#include "Date.h"

class DateArray
{
public:
	DateArray(int size); // constructor
	DateArray(const DateArray &obj);
	~DateArray();
	int size() { return arraySize; }
	Date &operator[](int sub);
	void sort();
private:
	bool isValidIndex(int index);
	void returnError();
	Date *pDate;
	int arraySize;
	void quickSort(Date *arr, int size);
};

#endif