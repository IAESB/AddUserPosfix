#include "country.h"

Country::Country(){
	init();
}
Country::Country(std::string iso)
{
	init();
	this->iso = iso;
}

void Country::init()
{
}
std::string Country::getIso() const
{
	return iso;
}
void Country::setIso(std::string value)
{
	iso = value;
}
std::string Country::getName() const
{
	return name;
}
void Country::setName(std::string value)
{
	name = value;
}
std::string Country::getPrintableName() const
{
	return printable_name;
}
void Country::setPrintableName(std::string value)
{
	printable_name = value;
}
std::string Country::getIso3() const
{
	return iso3;
}
void Country::setIso3(std::string value)
{
	iso3 = value;
}
int Country::getNumcode() const
{
	return numcode;
}
void Country::setNumcode(int value)
{
	numcode = value;
}
std::string Country::getEu() const
{
	return eu;
}
void Country::setEu(std::string value)
{
	eu = value;
}

