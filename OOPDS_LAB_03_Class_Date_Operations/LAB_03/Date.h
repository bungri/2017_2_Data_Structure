#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date
{
	friend istream &operator>>(istream &input, Date &date);
	friend ostream &operator<<(ostream &output, const Date &date);
	friend class DateArray;
public:
	Date(); // default constructor
	Date(int y, int m, int d); // constructor
	Date(int y, int m, int d, string n); // constructor
	Date(int y, int m, int d, char n[]); // constructor
	void setDate(int newYear, int newMonth, int newDay);
	int getYear()const { return this->year; }
	int getMonth()const { return this->month; }
	int getDay()const { return this->day; }
	string getName()const { return name; }
	void setName(string n) { name = n; }
	void setName(char n[]) { name = string(n); }
	int getYearDay()const;
	int getWeekDay()const;
	int getElapsedDays()const; // get elapsed days from AD 1. 1. 1.
	const Date operator+(int dd);
	const Date operator-(int dd);
	const Date operator++(); // prefix
	const Date operator++(int dummy); // postfix
	const Date operator--(); // prefix
	const Date operator--(int dummy); // postfix
	const Date operator=(const Date rightSide);
	bool operator>(Date rightSide);
	bool operator<(Date rightSide);
	bool operator==(Date rightSide);
private:
	bool isLeapYear()const; // check whether the year is leap year
	bool isLeapYear(int y)const; // check whether the given year y is leap year
	bool isValidDate(int y, int m, int d)const;
	void returnError();
	string name;
	int year;
	int month;
	int day;
};

#endif