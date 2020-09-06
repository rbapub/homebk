#ifndef ICATALOGELEMENT_H
#define ICATALOGELEMENT_H

using std::string;

class ICatalogElement
{
public:
	virtual int getId() const = 0;
	virtual string getName() const = 0;
	virtual void setId(int i) = 0;
	virtual void setName(string n) = 0;
	virtual ~ICatalogElement() {};
};

#endif