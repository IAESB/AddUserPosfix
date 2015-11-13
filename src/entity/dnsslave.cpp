#include "dnsslave.h"

DnsSlave::DnsSlave(){
	init();
}
DnsSlave::DnsSlave(long long id)
{
	init();
	this->id = id;
}

void DnsSlave::init()
{
}
long long DnsSlave::getId() const
{
	return id;
}
void DnsSlave::setId(long long value)
{
	id = value;
}
long long DnsSlave::getSysUserid() const
{
	return sys_userid;
}
void DnsSlave::setSysUserid(long long value)
{
	sys_userid = value;
}
long long DnsSlave::getSysGroupid() const
{
	return sys_groupid;
}
void DnsSlave::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string DnsSlave::getSysPermUser() const
{
	return sys_perm_user;
}
void DnsSlave::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string DnsSlave::getSysPermGroup() const
{
	return sys_perm_group;
}
void DnsSlave::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string DnsSlave::getSysPermOther() const
{
	return sys_perm_other;
}
void DnsSlave::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
int DnsSlave::getServerId() const
{
	return server_id;
}
void DnsSlave::setServerId(int value)
{
	server_id = value;
}
std::string DnsSlave::getOrigin() const
{
	return origin;
}
void DnsSlave::setOrigin(std::string value)
{
	origin = value;
}
std::string DnsSlave::getNs() const
{
	return ns;
}
void DnsSlave::setNs(std::string value)
{
	ns = value;
}
std::string DnsSlave::getActive() const
{
	return active;
}
void DnsSlave::setActive(std::string value)
{
	active = value;
}
std::string DnsSlave::getXfer() const
{
	return xfer;
}
void DnsSlave::setXfer(std::string value)
{
	xfer = value;
}

