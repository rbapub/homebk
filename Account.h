#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "ICatalogElement.h"
#include "Currency.h"

using std::string;

class Account : public ICatalogElement
{
private:
	static int nextId;
	int id;
	string name;
	Currency* currency;
	string note;
	bool isDefault;
public:
	Account(string aName, Currency* cur);
	~Account();
	virtual int getId() const override;
	virtual string getName() const override;
	virtual void setId(int i) override;
	virtual void setName(string n) override;
	Currency* getCurrency() const;
	string getNote() const;
	bool isDefault() const;
};

#endif