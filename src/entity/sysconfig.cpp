#include "sysconfig.h"

SysConfig::SysConfig(){
	init();
}
SysConfig::SysConfig(std::string group, std::string name)
{
	init();
	this->group = group;
	this->name = name;
}

void SysConfig::init()
{
}
std::string SysConfig::getGroup() const
{
	return group;
}
void SysConfig::setGroup(std::string value)
{
	group = value;
}
std::string SysConfig::getName() const
{
	return name;
}
void SysConfig::setName(std::string value)
{
	name = value;
}
std::string SysConfig::getValue() const
{
	return value;
}
void SysConfig::setValue(std::string value)
{
	value = value;
}

