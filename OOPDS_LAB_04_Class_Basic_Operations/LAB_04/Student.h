/* Student.h */

#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class StudentArray;

class Student : public Person
{
	friend class StudentArray;
	friend ostream & operator<< (ostream &, const Student &);
public:
	Student(); // default constructor
	Student(string n, Date dob, int id, string dept_n, double gpa);
	const Student operator=(const Student rightSide);
	void setST_id(int id) { st_id = id; }
	void setDept_name(string dp_n) { dept_name = dp_n; };
	void setGPA(double g) { gpa = g; }
private:
	int st_id;
	string dept_name;
	double gpa;
};

#endif