#ifndef DATE_H
#define DATE_H

using std::ostream;

class Date
{
	friend ostream &operator<<(ostream &, const Date &);
	public:
		Date(int y=1900, int m=1, int d=1, int h=0, int min=0, int sec=0); //конструктор по умолчанию
		Date(tm *ti);
		void setDate(int, int, int, int, int, int); //установить дату
		Date &operator++(); //операция префиксного инкремента
		Date operator++(int); //операция постфиксного инкремента
		const Date &operator+=(int); //прибавить дни к дате
		bool leapYear(int) const; //проверка на високосный год
		bool endOfMonth(int) const; //проверка на последний день месяца
		int getYear() const;
		int getMonth() const;
		int getDay() const;
		int getHour() const;
		int getMinute() const;
		int getSecond() const;
	private:
		int month;
		int day;
		int year;
		int hour;
		int minute;
		int second;
		static const int days[]; //массив дней в месяцах
		void helpIncrement(); //сервисная функция для инкремента даты
};

#endif