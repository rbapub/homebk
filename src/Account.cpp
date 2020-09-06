#include <string>
#include "Account.h"

using std::string;

int Account::nextId = 1;

Account::Account(string aName, Currency* cur)
{
	setId(nextId);
	nextId++;
	setName(aName);
	currency = cur;
}

int Account::getId() const
{
	return id;
}

void Account::setId(int i)
{
	id = i;
}

string Account::getName() const
{
	return name;
}

void Account::setName(string n)
{
	name = n;
}

Currency* Account::getCurrency() const
{
	return currency;
}

string Account::getNote() const
{
	return note;
}

bool Account::isDefault() const
{
	return defAcc;
}

Account::~Account()
{
}
