#include <string>
#include "AccItem.h"

using std::string;

int AccItem::nextId = 1;

AccItem::AccItem(string iName, Direction dir = Direction::ALL, AccItem* par = nullptr)
{
	id = nextId;
	nextId++;
	name = iName;
	direction = dir;
	parent = par;
}

int AccItem::getId() const
{
	return id;
}

void AccItem::setId(int i)
{
	id = i;
}

string AccItem::getName() const
{
	return name;
}

void AccItem::setName(string n)
{
	name = n;
}

AccItem::~AccItem()
{
}
