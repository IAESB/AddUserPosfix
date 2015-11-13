#include "domain.h"

Domain::Domain(){
	init();
}
Domain::Domain(long long domain_id)
{
	init();
	this->domain_id = domain_id;
}

void Domain::init()
{
}
long long Domain::getDomainId() const
{
	return domain_id;
}
void Domain::setDomainId(long long value)
{
	domain_id = value;
}
long long Domain::getSysUserid() const
{
	return sys_userid;
}
void Domain::setSysUserid(long long value)
{
	sys_userid = value;
}
long long Domain::getSysGroupid() const
{
	return sys_groupid;
}
void Domain::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string Domain::getSysPermUser() const
{
	return sys_perm_user;
}
void Domain::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string Domain::getSysPermGroup() const
{
	return sys_perm_group;
}
void Domain::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string Domain::getSysPermOther() const
{
	return sys_perm_other;
}
void Domain::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
std::string Domain::getDomain() const
{
	return domain;
}
void Domain::setDomain(std::string value)
{
	domain = value;
}

