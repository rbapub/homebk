#ifndef CURRENCY_H
#define CURRENCY_H

#include "ICatalogElement.h"

using std::string;

class Currency : public ICatalogElement
{
private:
	static int nextId;
	int id;
	string name;
public:
	Currency(string cName);
	~Currency();
	virtual int getId() const override;
	virtual string getName() const override;
	virtual void setId(int i) override;
	virtual void setName(string n) override;
};

#endif