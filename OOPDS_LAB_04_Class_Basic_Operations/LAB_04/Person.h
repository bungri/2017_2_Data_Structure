/* person.h */

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

#include "Date.h"

class Person
{
	friend ostream & operator<< (ostream &, const Person &);
public:
	Person();
	Person(string n, Date bd);
	void setName(string n) { name = n; }
	void setBirthDate(Date bd) { birthDate = bd; }
	string getName() { return name; }
	Date getBirthDate() { return birthDate; }
protected:
	string name;
	Date birthDate;
};

#endif