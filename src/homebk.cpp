#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>
#include <string>
#include "Date.h"
#include "Partner.h"

using namespace std;

int enterChoice();
void testDate();
void testPartner();

enum Choises { TESTDATE = 1, TESTPARTNER, END };

int main()
{
	int choice; // user's choice

	while ((choice = enterChoice()) != END)
	{
		switch (choice)
		{
		case TESTDATE:
			testDate();
			break;
		case TESTPARTNER:
			testPartner();
			break;
		default: // wrong input
			cerr << "Incorrect choice" << endl;
			break;
		}
	}

	return 0;
}

int enterChoice()
{
	cout << "\nEnter your choice:" << endl
		<< "1 - Test for date operations" << endl
		<< "2 - Test for partner operations" << endl
		<< "3 - end program\n? ";

	int menuChoice;
	cin >> menuChoice;

	return menuChoice;
}

void testDate()
{
	char timeBuffer[80];
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	const char* formatString = "%d/%m/%Y %H:%M:%S";
	strftime(timeBuffer, 80, formatString, timeinfo);
	cout << "Current date/time: " << timeBuffer << endl;

	Date d(timeinfo);
	cout << d << endl;

	Date d1;
	cout << d1 << endl;
}

void testPartner()
{
	string name;

	cout << "Enter partner's name: ";
	cin.ignore();
	getline(cin, name);

	Partner p(name);
	cout << p << endl;
}