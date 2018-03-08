/* main.cpp */
#include <iostream>
#include <fstream>
#include <iomanip>

#include "Date.h"
#include "DateArray.h"

using namespace std;

#define NUM_DATES 8

int main()
{
	Date AD010101(1, 1, 1, "AD010101"), newYearDay(2017, 1, 1, "New Year's Day"),
		today, christmas(2017, 12, 25, "Christmas"), thisChristmas;
	int daysToChristmas;
	DateArray dates(NUM_DATES);
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	int tempp = christmas.getYearDay();
	if (fin.fail())
	{
		cout << "Fail to open an input file (input.txt)\n";
		exit(1);
	}
	fout.open("output.txt");
	if (fout.fail())
	{
		cout << "Fail to open an output file (output.txt)\n";
		exit(1);
	}
	//cin >> today; today.setName("today");
	today = Date(2017, 12, 31, "Today");
	fout << today << endl;
	thisChristmas = Date(today.getYear(), 12, 25);

	if (today == thisChristmas)
	{
		fout << "Happy Christmas !!" << endl;
	}
	else
	{
		daysToChristmas = thisChristmas.getElapsedDays() - today.getElapsedDays();
		if (daysToChristmas > 0)
			fout << "Sorry today is not Christmas - You should wait " << daysToChristmas << " days !!" << endl;
		else
			fout << "Sorry this year's Christmas was " << -daysToChristmas << " days before !!" << endl;
	}
	fout << endl;

	dates[0] = today;
	fout << "dates[0] = today;\n" << dates[0] << endl << endl;

	dates[1] = ++today; dates[1].setName("dates[1]");
	fout << "dates[1] = ++today;\n" << dates[1] << endl;
	fout << "Currently " << today << endl << endl;

	dates[2] = today++; dates[2].setName("dates[2]");
	fout << "dates[2] = today++;\n" << dates[2] << endl;
	fout << "Currently " << today << endl << endl;

	dates[3] = today--; dates[3].setName("dates[3]");
	fout << "dates[3] = today--;\n" << dates[3] << endl;
	fout << "Currently " << today << endl << endl;

	dates[4] = --today; dates[4].setName("dates[4]");
	fout << "dates[4] = --today;\n" << dates[4] << endl;
	fout << "Currently " << today << endl;

	dates[5] = newYearDay;
	dates[6] = christmas;
	dates[7] = AD010101;

	fout << endl << "Before sorting dates: " << endl;
	for (int i = 0; i < NUM_DATES; i++)
	{
		fout << dates[i] << endl;
	}

	dates.sort();

	fout << endl << "After sorting dates: " << endl;
	for (int i = 0; i < NUM_DATES; i++)
	{
		fout << dates[i] << endl;
	}
	fout << endl;

	fin.close();
	fout.close();

	return 0;
}