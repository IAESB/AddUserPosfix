#include "dnsrr.h"

DnsRr::DnsRr(){
	init();
}
DnsRr::DnsRr(long long id)
{
	init();
	this->id = id;
}

void DnsRr::init()
{
	stamp = {0};
}
long long DnsRr::getId() const
{
	return id;
}
void DnsRr::setId(long long value)
{
	id = value;
}
long long DnsRr::getSysUserid() const
{
	return sys_userid;
}
void DnsRr::setSysUserid(long long value)
{
	sys_userid = value;
}
long long DnsRr::getSysGroupid() const
{
	return sys_groupid;
}
void DnsRr::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string DnsRr::getSysPermUser() const
{
	return sys_perm_user;
}
void DnsRr::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string DnsRr::getSysPermGroup() const
{
	return sys_perm_group;
}
void DnsRr::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string DnsRr::getSysPermOther() const
{
	return sys_perm_other;
}
void DnsRr::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
int DnsRr::getServerId() const
{
	return server_id;
}
void DnsRr::setServerId(int value)
{
	server_id = value;
}
long long DnsRr::getZone() const
{
	return zone;
}
void DnsRr::setZone(long long value)
{
	zone = value;
}
std::string DnsRr::getName() const
{
	return name;
}
void DnsRr::setName(std::string value)
{
	name = value;
}
std::string DnsRr::getType() const
{
	return type;
}
void DnsRr::setType(std::string value)
{
	type = value;
}
std::string DnsRr::getData() const
{
	return data;
}
void DnsRr::setData(std::string value)
{
	data = value;
}
long long DnsRr::getAux() const
{
	return aux;
}
void DnsRr::setAux(long long value)
{
	aux = value;
}
long long DnsRr::getTtl() const
{
	return ttl;
}
void DnsRr::setTtl(long long value)
{
	ttl = value;
}
std::string DnsRr::getActive() const
{
	return active;
}
void DnsRr::setActive(std::string value)
{
	active = value;
}
tm DnsRr::getStamp() const
{
	return stamp;
}
void DnsRr::setStamp(tm value)
{
	stamp = value;
}
long long DnsRr::getSerial() const
{
	return serial;
}
void DnsRr::setSerial(long long value)
{
	serial = value;
}

