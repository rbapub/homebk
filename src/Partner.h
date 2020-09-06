#ifndef PARTNER_H
#define PARTNER_H

#include "ICatalogElement.h"

using std::ostream;
using std::string;

class Partner : public ICatalogElement
{
private:
	static int nextId;
	int id;
	string name;
public:
	Partner(string pName);
	~Partner();
	virtual int getId() const override;
	virtual string getName() const override;
	virtual void setId(int i) override;
	virtual void setName(string n) override;
	friend ostream& operator<<(ostream&, const Partner&);
};

#endif