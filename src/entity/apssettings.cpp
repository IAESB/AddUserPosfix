#include "apssettings.h"

ApsSettings::ApsSettings(){
	init();
}
ApsSettings::ApsSettings(int id)
{
	init();
	this->id = id;
}

void ApsSettings::init()
{
}
int ApsSettings::getId() const
{
	return id;
}
void ApsSettings::setId(int value)
{
	id = value;
}
std::string ApsSettings::getName() const
{
	return name;
}
void ApsSettings::setName(std::string value)
{
	name = value;
}
std::string ApsSettings::getValue() const
{
	return value;
}
void ApsSettings::setValue(std::string value)
{
	value = value;
}

