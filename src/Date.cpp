#include <iostream>
#include <ctime>
#include "Date.h"

// month's days
const int Date::days[] =
{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// ctor Date
Date::Date(int y, int m, int d, int h, int min, int sec)
{
	setDate(y, m, d, h, min, sec);
}

// ctor Date on localtime()
Date::Date(tm *ti)
{
	setDate(ti->tm_year + 1900, ti->tm_mon + 1, ti->tm_mday,
		ti->tm_hour, ti->tm_min, ti->tm_sec);
}

// set year, month, day
void Date::setDate(int yy, int mm, int dd, int h, int min, int sec)
{
	year = (yy >= 1900 && yy <= 2100) ? yy : 1900;
	month = (mm >= 1 && mm <= 12) ? mm : 1;

	if (month == 2 && leapYear(year))
		day = (dd >= 1 && dd <= 29) ? dd : 1;
	else
		day = (dd >= 1 && dd <= days[month]) ? dd : 1;

	hour = (h >= 0 && h <= 23) ? h : 0;
	minute = (min >= 0 && min <= 59) ? min : 0;
	second = (sec >= 0 && sec <= 59) ? sec : 0;
}

Date &Date::operator++()
{
	helpIncrement();
	return *this; // return reference for lvalue
}

Date Date::operator++(int)
{
	Date temp = *this;
	helpIncrement();

	return temp;
}

const Date &Date::operator+=(int additionalDays)
{
	for (int i = 0; i < additionalDays; i++)
		helpIncrement();

	return *this; // allow cascade
}

// for leap year return true, else - false
bool Date::leapYear(int testYear) const
{
	if (testYear % 400 == 0 ||
		(testYear % 100 != 0 && testYear % 4 == 0))
		return true;
	else
		return false;
}

bool Date::endOfMonth(int testDay) const
{
	if (month == 2 && leapYear(year))
		// last day of february of leap year
		return testDay == 29;
	else
		return testDay == days[month];
}

int Date::getYear() const
{
	return year;
}

int Date::getMonth() const
{
	return month;
}

int Date::getDay() const
{
	return day;
}

int Date::getHour() const
{
	return hour;
}

int Date::getMinute() const
{
	return minute;
}

int Date::getSecond() const
{
	return second;
}

void Date::helpIncrement()
{
	if (!endOfMonth(day))
		day++;
	else
	{
		if (month < 12)
		{
			month++;
			day = 1;
		}
		else // last day of year
		{
			year++;
			month = 1;
			day = 1;
		}
	}
}

ostream &operator<<(ostream &output, const Date &d)
{
	static const char* monthName[13] =
	{ "", "January", "February", "March", "April", "May",
	"June", "July", "August", "September", "October",
	"November", "December" };

	const char* zeroDay = (d.day < 10 ? "0" : "");
	const char* zeroMin = (d.minute < 10 ? "0" : "");
	const char* zeroSec = (d.second < 10 ? "0" : "");

	output << zeroDay << d.day << ' ' << monthName[d.month] << ' ' << d.year << ' '
		<< d.hour << ':' << zeroMin << d.minute << ':' << zeroSec << d.second;

	return output;
}
