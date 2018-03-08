/* date.cpp */

#include <iostream>
#include <iomanip>

#include "Date.h"

using namespace std;

static int monthlyDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
static char weekDayList[7][10] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };


istream &operator>>(istream &input, Date &date)
{
	input >> date.year;
	input >> date.month;
	input >> date.day;
	return input;
}

ostream &operator<<(ostream &output, const Date &date)
{
	output << "Date [" << setw(4) << date.getYear() << "." << setw(2) << date.getMonth() << "." << setw(2) << date.getDay()  << "(" << weekDayList[date.getWeekDay()] << ")]" << endl;
	return output;
}

Date::Date() // default constructor
{
	this->year = 1;
	this->month = 1;
	this->day = 1;
}

Date::Date(int y, int m, int d) // constructor
{
	setDate(y, m, d);
}

void Date::setDate(int newYear, int newMonth, int newDay)
{
	if (newYear >= 1)
		this->year = newYear;
	else
		returnError();

	if ((newMonth >= 1) && (newMonth <= 12))
		this->month = newMonth;
	else
		returnError();

	int temp;
	if ((isLeapYear(this->year)) && (this->month == 2))
		temp = 29;
	else
		temp = monthlyDays[this->month - 1];

	if ((newDay >= 1) && (newDay <= temp))
		this->day = newDay;
	else
		returnError();
}

int Date::getYearDay()const
{
	int yearDay = 0;
	for (int i = 1; i < this->month; i++)
	{
		if ((isLeapYear(this->year)) && (i == 2))
			yearDay += 29;
		else
			yearDay += monthlyDays[i - 1];
	}
	yearDay += this->day;
	return yearDay;
}

int	Date::getWeekDay()const
{
	int weekDay = (getElapsedDays() - 1) % 7;
	return weekDay;
}

int Date::getElapsedDays()const // get elapsed days from AD 1. 1. 1.
{
	int elapsedDays = 0;
	for (int i = 1; i < this->year; i++)
	{
		if (isLeapYear(i))
			elapsedDays += 366;
		else
			elapsedDays += 365;
	}
	elapsedDays += this->getYearDay();
	return elapsedDays;
}

const Date Date::operator=(const Date rightSide)
{
	int y, m, d;
	string n;
	y = rightSide.year;
	m = rightSide.month;
	d = rightSide.day;
	if (isValidDate(y, m, d))
	{
		this->year = y;
		this->month = m;
		this->day = d;
		return *this;
	}
	else {
		return Date(0, 0, 0);
	}
}

bool Date::operator>(Date rightSide)
{
	return this->getElapsedDays() > rightSide.getElapsedDays();
}

bool Date::operator<(Date rightSide)
{
	return this->getElapsedDays() < rightSide.getElapsedDays();
}

bool Date::operator==(Date rightSide)
{
	return this->getElapsedDays() == rightSide.getElapsedDays();
}

bool Date::isLeapYear()const // check whether the year is leap year
{
	if (this->year % 4 == 0)
	{
		if (this->year % 100 == 0)
		{
			if (this->year % 400 == 0)
				return true;
			else
				return false;
		}
		return true;
	}
	return false;
}

bool Date::isLeapYear(int y)const // check whether the given year y is leap year
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

bool Date::isValidDate(int y, int m, int d)
{
	if (y < 1)
		return false;

	if ((m < 1) && (m > 12))
		return false;

	bool tempflag = false;

	if ((isLeapYear(y)) && (m == 2) && (d < 29))
		tempflag = true;

	if ((d < 1) && (d > monthlyDays[m - 1]))
	{
		if (tempflag)
			return true;
		else
			return false;
	}
	return true;
}

void Date::returnError()
{
	cout << "Invaild operation! halt program." << endl;
	exit(1);
}
