#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Country;
typedef shared_ptr<Country> CountryPtr;
typedef vector<CountryPtr> CountryList;

class Country
{
	std::string iso; //key: PRI
	std::string name;
	std::string printable_name;
	std::string iso3;
	int numcode;
	std::string eu;
public:
	Country();
	Country(std::string iso);
	void init();
	std::string getIso() const;
	void setIso(std::string value);
	std::string getName() const;
	void setName(std::string value);
	std::string getPrintableName() const;
	void setPrintableName(std::string value);
	std::string getIso3() const;
	void setIso3(std::string value);
	int getNumcode() const;
	void setNumcode(int value);
	std::string getEu() const;
	void setEu(std::string value);
};



#endif // COUNTRY_H
