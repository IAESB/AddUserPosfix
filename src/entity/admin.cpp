#include "admin.h"

Admin::Admin(){
	init();
}
Admin::Admin(std::string username)
{
	init();
	this->username = username;
}

void Admin::init()
{
	create_date = {0};
	change_date = {0};
}
std::string Admin::getUsername() const
{
	return username;
}
void Admin::setUsername(std::string value)
{
	username = value;
}
std::string Admin::getPassword() const
{
	return password;
}
void Admin::setPassword(std::string value)
{
	password = value;
}
std::string Admin::getDomain() const
{
	return domain;
}
void Admin::setDomain(std::string value)
{
	domain = value;
}
tm Admin::getCreateDate() const
{
	return create_date;
}
void Admin::setCreateDate(tm value)
{
	create_date = value;
}
tm Admin::getChangeDate() const
{
	return change_date;
}
void Admin::setChangeDate(tm value)
{
	change_date = value;
}
std::string Admin::getPermite() const
{
	return permite;
}
void Admin::setPermite(std::string value)
{
	permite = value;
}
int Admin::getActive() const
{
	return active;
}
void Admin::setActive(int value)
{
	active = value;
}

