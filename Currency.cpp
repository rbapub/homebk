#include <string>
#include "Currency.h"

using std::string;

int Currency::nextId = 1;

Currency::Currency(string cName)
{
	id = nextId;
	nextId++;
	name = cName;
}

int Currency::getId() const
{
	return id;
}

void Currency::setId(int i)
{
	id = i;
}

string Currency::getName() const
{
	return name;
}

void Currency::setName(string n)
{
	name = n;
}

Currency::~Currency()
{
}
