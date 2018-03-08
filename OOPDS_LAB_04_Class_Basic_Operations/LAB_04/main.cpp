/* main.cpp (Date, Person, Student, StudentArray) */
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

#include "StudentArray.h"

#include <string>

#define NUM_STUDENTS 5

Student genStudent();
bool isLeapYear(int y);

void main()
{
	StudentArray studentArray(NUM_STUDENTS);
	Student st;
	ofstream fout;
	fout.open("output.txt");
	if (fout.fail())
	{
		cout << "Fail to open an output file (output.txt)\n";
		exit(1);
	}
	fout << "Initializing student array (num_students: " << NUM_STUDENTS << ")" << endl;
	srand(time(NULL));
	for (int i = 0; i < NUM_STUDENTS; i++)
	{
		st = genStudent();
		studentArray[i] = st;
	}
	fout << studentArray;
	fout << "\nSorting studentArray by student id : " << endl;
	studentArray.sortByST_ID();

	fout << studentArray;
	fout << "\nSorting studentArray by student name : " << endl;
	studentArray.sortByName();

	fout << studentArray;
	fout << "\nSorting studentArray by GPA : " << endl;
	studentArray.sortByGPA();

	fout << studentArray;
	fout << "\nSorting studentArray by BirthDate : " << endl;
	studentArray.sortByBirthDate();

	fout << studentArray;
	fout << endl;

	fout.close();
}

Student genStudent()
{
	//random name
	string name = "";
	for (int i = 0; i < (rand() % 3 + 5); i++)
	{
		if (i == 0)
			name += (char)(rand() % 26 + 'A');
		else
			name += (char)(rand() % 26 + 'a');
	}

	//random birthDate;
	int year = (rand() % 9999 + 1);
	int month = (rand() % 12 + 1);
	int day = 0;
	switch (month)
	{
	case 2: if (isLeapYear(year)) day = (rand() % 28 + 1);
			else day = (rand() % 27 + 1);
			break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: day = (rand() % 30 + 1);
		break;
	default: day = (rand() % 29 + 1);
	}
	Date birthDate(year, month, day);

	//random st_id;
	int st_id = (rand() % 90000 + 10000);

	//random dept_name
	string dept_name = "";
	for (int i = 0; i < (rand() % 2 + 3); i++)
	{
		dept_name += (char)(rand() % 26 + 65);
	}

	//random gpa
	double gpa = rand() % 100 + (double)rand() / 32767.0;

	Student result(name, birthDate, st_id, dept_name, gpa);
	return result;
}

bool isLeapYear(int y)
{
	if (y % 4 == 0)
	{
		if (y % 100 == 0)
		{
			if (y % 400 == 0)
				return true;
			else
				return false;
		}
		return true;
	}
	return false;

}