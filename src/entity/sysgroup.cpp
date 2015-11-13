#include "sysgroup.h"

SysGroup::SysGroup(){
	init();
}
SysGroup::SysGroup(long long groupid)
{
	init();
	this->groupid = groupid;
}

void SysGroup::init()
{
}
long long SysGroup::getGroupid() const
{
	return groupid;
}
void SysGroup::setGroupid(long long value)
{
	groupid = value;
}
std::string SysGroup::getName() const
{
	return name;
}
void SysGroup::setName(std::string value)
{
	name = value;
}
std::string SysGroup::getDescription() const
{
	return description;
}
void SysGroup::setDescription(std::string value)
{
	description = value;
}
long long SysGroup::getClientId() const
{
	return client_id;
}
void SysGroup::setClientId(long long value)
{
	client_id = value;
}

