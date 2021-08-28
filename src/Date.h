#ifndef DATE_H
#define DATE_H

using std::ostream;

class Date
{
	friend ostream &operator<<(ostream &, const Date &);
	public:
		Date(int y=1900, int m=1, int d=1, int h=0, int min=0, int sec=0); // default ctor
		Date(tm *ti);
		void setDate(int, int, int, int, int, int);
		Date &operator++();
		Date operator++(int);
		const Date &operator+=(int); // add days to date
		bool leapYear(int) const; // leap year test
		bool endOfMonth(int) const; // last day of month test
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
		static const int days[]; // days in monthes
		void helpIncrement(); // date's increment service function
};

#endif