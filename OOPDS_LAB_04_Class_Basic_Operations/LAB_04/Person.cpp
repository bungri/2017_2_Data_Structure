/* Person.cpp */

#include "Person.h"

ostream &operator<<(ostream &output, const Person &prsn)
{
	return output;
}

Person::Person()
{
	this->name = "";
}

Person::Person(string n, Date bd)
{
	setName(n);
	setBirthDate(bd);
}
