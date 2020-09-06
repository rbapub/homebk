#include <iostream>
#include <ctime>
#include "Date.h"

//инициализировать статический элемент в области действия файла
//массив последних дней месяцев
const int Date::days[] =
{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

//конструктор Date
Date::Date(int y, int m, int d, int h, int min, int sec)
{
	setDate(y, m, d, h, min, sec);
}

//конструктор Date на основании данных из функции localtime()
Date::Date(tm *ti)
{
	setDate(ti->tm_year + 1900, ti->tm_mon + 1, ti->tm_mday,
		ti->tm_hour, ti->tm_min, ti->tm_sec);
}

//установить год, месяц, день
void Date::setDate(int yy, int mm, int dd, int h, int min, int sec)
{
	year = (yy >= 1900 && yy <= 2100) ? yy : 1900;
	month = (mm >= 1 && mm <= 12) ? mm : 1;

	//проверить, високосный-ли год и установить день
	if (month == 2 && leapYear(year))
		day = (dd >= 1 && dd <= 29) ? dd : 1;
	else
		day = (dd >= 1 && dd <= days[month]) ? dd : 1;

	hour = (h >= 0 && h <= 23) ? h : 0;
	minute = (min >= 0 && min <= 59) ? min : 0;
	second = (sec >= 0 && sec <= 59) ? sec : 0;
}

//перегруженная операция префиксного инкремента
Date &Date::operator++()
{
	helpIncrement(); //инкрементировать дату
	return *this; //возврат ссылки для получения lvalue
}

//перегруженная операция постфиксного инкремента;
//для целого параметра-пустышки нет имени параметра
Date Date::operator++(int)
{
	//запомнить текущее состояние объекта
	Date temp = *this;
	helpIncrement();

	//вернуть неинкрементированный сохраненный объект
	return temp; //возврат значения, не ссылки
}

//прибавить к дате указанное число дней
const Date &Date::operator+=(int additionalDays)
{
	for (int i = 0; i < additionalDays; i++)
		helpIncrement();

	return *this; //разрешает каскадирование
}

//если високосный год, возвратить true; иначе - false
bool Date::leapYear(int testYear) const
{
	if (testYear % 400 == 0 ||
		(testYear % 100 != 0 && testYear % 4 == 0))
		return true; //високосный год
	else
		return false;
}

//определить, является-ли день последним днем месяца
bool Date::endOfMonth(int testDay) const
{
	if (month == 2 && leapYear(year))
		//последний день февраля високосного года
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

//вспомогательная функция для инкремента даты
void Date::helpIncrement()
{
	//не последний день месяца
	if (!endOfMonth(day))
		//инкрементировать день
		day++;
	else
	{
		//последний день месяца и месяц <12
		if (month < 12)
		{
			month++; //инкрементировать месяц
			day = 1; //первый день нового месяца
		}
		else //последний день года
		{
			year++; //инкрементировать год
			month = 1; //первый месяц нового года
			day = 1; //первый день нового месяца
		}
	}
}

//перегруженная операция вывода
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
