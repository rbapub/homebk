#ifndef ACCITEM_H
#define ACCITEM_H

#include "ICatalogElement.h"

enum class Direction
{
	INCOME,
	EXPENSE,
	ALL
};

class AccItem : public ICatalogElement
{
private:
	static int nextId;
	int id;
	string name;
	Direction direction;
	AccItem* parent;
public:
	AccItem(string iName, Direction dir, AccItem* par);
	~AccItem();
	virtual int getId() const override;
	virtual string getName() const override;
	virtual void setId(int i) override;
	virtual void setName(string n) override;
};

#endif