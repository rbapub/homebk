#include <iostream>
#include <string>
#include "Partner.h"

using std::string;

int Partner::nextId = 1;

Partner::Partner(string pName)
{
	id = nextId;
	nextId++;
	name=pName;
}

int Partner::getId() const
{
	return id;
}

void Partner::setId(int i)
{
	id = i;
}

string Partner::getName() const
{
	return name;
}

void Partner::setName(string n)
{
	name = n;
}

Partner::~Partner()
{
}

ostream & operator<<(ostream &output, const Partner &p)
{
	output << p.getName() << " (id: " << p.getId() << ')';
	return output;
}
