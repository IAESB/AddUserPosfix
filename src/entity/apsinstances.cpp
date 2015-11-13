#include "apsinstances.h"

ApsInstances::ApsInstances(){
	init();
}
ApsInstances::ApsInstances(int id)
{
	init();
	this->id = id;
}

void ApsInstances::init()
{
}
int ApsInstances::getId() const
{
	return id;
}
void ApsInstances::setId(int value)
{
	id = value;
}
long long ApsInstances::getSysUserid() const
{
	return sys_userid;
}
void ApsInstances::setSysUserid(long long value)
{
	sys_userid = value;
}
long long ApsInstances::getSysGroupid() const
{
	return sys_groupid;
}
void ApsInstances::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string ApsInstances::getSysPermUser() const
{
	return sys_perm_user;
}
void ApsInstances::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string ApsInstances::getSysPermGroup() const
{
	return sys_perm_group;
}
void ApsInstances::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string ApsInstances::getSysPermOther() const
{
	return sys_perm_other;
}
void ApsInstances::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
int ApsInstances::getServerId() const
{
	return server_id;
}
void ApsInstances::setServerId(int value)
{
	server_id = value;
}
int ApsInstances::getCustomerId() const
{
	return customer_id;
}
void ApsInstances::setCustomerId(int value)
{
	customer_id = value;
}
int ApsInstances::getPackageId() const
{
	return package_id;
}
void ApsInstances::setPackageId(int value)
{
	package_id = value;
}
int ApsInstances::getInstanceStatus() const
{
	return instance_status;
}
void ApsInstances::setInstanceStatus(int value)
{
	instance_status = value;
}

