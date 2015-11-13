#include "openvzip.h"

OpenvzIp::OpenvzIp(){
	init();
}
OpenvzIp::OpenvzIp(long long ip_address_id)
{
	init();
	this->ip_address_id = ip_address_id;
}

void OpenvzIp::init()
{
}
long long OpenvzIp::getIpAddressId() const
{
	return ip_address_id;
}
void OpenvzIp::setIpAddressId(long long value)
{
	ip_address_id = value;
}
int OpenvzIp::getSysUserid() const
{
	return sys_userid;
}
void OpenvzIp::setSysUserid(int value)
{
	sys_userid = value;
}
int OpenvzIp::getSysGroupid() const
{
	return sys_groupid;
}
void OpenvzIp::setSysGroupid(int value)
{
	sys_groupid = value;
}
std::string OpenvzIp::getSysPermUser() const
{
	return sys_perm_user;
}
void OpenvzIp::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string OpenvzIp::getSysPermGroup() const
{
	return sys_perm_group;
}
void OpenvzIp::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string OpenvzIp::getSysPermOther() const
{
	return sys_perm_other;
}
void OpenvzIp::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
int OpenvzIp::getServerId() const
{
	return server_id;
}
void OpenvzIp::setServerId(int value)
{
	server_id = value;
}
std::string OpenvzIp::getIpAddress() const
{
	return ip_address;
}
void OpenvzIp::setIpAddress(std::string value)
{
	ip_address = value;
}
int OpenvzIp::getVmId() const
{
	return vm_id;
}
void OpenvzIp::setVmId(int value)
{
	vm_id = value;
}
std::string OpenvzIp::getReserved() const
{
	return reserved;
}
void OpenvzIp::setReserved(std::string value)
{
	reserved = value;
}

