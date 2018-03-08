/* student.cpp */
#include <iomanip>

#include "Student.h"

ostream &operator<<(ostream &output, const Student &stud)
{
	output << "Student [name : " << setw(7) << stud.name;
	output << ", birth date : " << setw(4) << stud.birthDate.getYear() << "." << setw(2) << stud.birthDate.getMonth() << "." << setw(2) << stud.birthDate.getDay() << ".";
	output << ", st_id : " << setw(5) << stud.st_id;
	output << ", dept : " << setw(5) << stud.dept_name;
	output << ", gpa : " << fixed << setw(5) << setprecision(2) << stud.gpa << "]" << endl;
	return output;
}


Student::Student() : Person() // default constructor
{
	st_id = 0;
	dept_name = "";
	gpa = 0.0;
}

Student::Student(string n, Date dob, int id, string dept_n, double gpa) : Person(n, dob)
{
	this->st_id = id;
	this->dept_name = dept_n;
	this->gpa = gpa;
}

const Student Student::operator=(const Student rightSide)
{
	this->name = rightSide.name;
	this->birthDate = rightSide.birthDate;
	this->st_id = rightSide.st_id;
	this->dept_name = rightSide.dept_name;
	this->gpa = rightSide.gpa;
	return (*this);
}
