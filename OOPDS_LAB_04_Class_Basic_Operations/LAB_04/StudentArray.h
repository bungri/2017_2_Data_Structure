/* StudentArray.h */

#ifndef STUDENT_ARRAY_H
#define STUDENT_ARRAY_H

#include <iostream>

#include "Student.h"

using namespace std;

class StudentArray
{
	friend ostream & operator<< (ostream &, const StudentArray &);
public:
	StudentArray(int size); // constructor
	StudentArray(const StudentArray &obj);
	~StudentArray();
	int size() { return num_students; }
	Student &operator[](int index) const;
	void sortByBirthDate();
	void sortByName();
	void sortByST_ID();
	void sortByGPA();
private:
	bool isValidIndex(int index) const;
	void returnError() const;
	Student *students;
	int num_students;
	//sorting func.
	template<typename T>
	void QuickSort(Student *arr, int size, T *subArr);
};

#endif