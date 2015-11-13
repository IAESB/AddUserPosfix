#include "alias.h"

Alias::Alias(){
	init();
}
Alias::Alias(std::string address)
{
	init();
	this->address = address;
}

void Alias::init()
{
	create_date = {0};
	change_date = {0};
}
std::string Alias::getAddress() const
{
	return address;
}
void Alias::setAddress(std::string value)
{
	address = value;
}
std::string Alias::getGoto() const
{
	return goto_;
}
void Alias::setGoto(std::string value)
{
	goto_ = value;
}
std::string Alias::getDomain() const
{
	return domain;
}
void Alias::setDomain(std::string value)
{
	domain = value;
}
tm Alias::getCreateDate() const
{
	return create_date;
}
void Alias::setCreateDate(tm value)
{
	create_date = value;
}
tm Alias::getChangeDate() const
{
	return change_date;
}
void Alias::setChangeDate(tm value)
{
	change_date = value;
}
std::string Alias::getAddInfo() const
{
	return add_info;
}
void Alias::setAddInfo(std::string value)
{
	add_info = value;
}
int Alias::getActive() const
{
	return active;
}
void Alias::setActive(int value)
{
	active = value;
}

