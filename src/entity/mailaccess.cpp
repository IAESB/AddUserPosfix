#include "mailaccess.h"

MailAccess::MailAccess(){
	init();
}
MailAccess::MailAccess(long long access_id)
{
	init();
	this->access_id = access_id;
}

void MailAccess::init()
{
}
long long MailAccess::getAccessId() const
{
	return access_id;
}
void MailAccess::setAccessId(long long value)
{
	access_id = value;
}
long long MailAccess::getSysUserid() const
{
	return sys_userid;
}
void MailAccess::setSysUserid(long long value)
{
	sys_userid = value;
}
long long MailAccess::getSysGroupid() const
{
	return sys_groupid;
}
void MailAccess::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string MailAccess::getSysPermUser() const
{
	return sys_perm_user;
}
void MailAccess::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string MailAccess::getSysPermGroup() const
{
	return sys_perm_group;
}
void MailAccess::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string MailAccess::getSysPermOther() const
{
	return sys_perm_other;
}
void MailAccess::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
int MailAccess::getServerId() const
{
	return server_id;
}
void MailAccess::setServerId(int value)
{
	server_id = value;
}
std::string MailAccess::getSource() const
{
	return source;
}
void MailAccess::setSource(std::string value)
{
	source = value;
}
std::string MailAccess::getAccess() const
{
	return access;
}
void MailAccess::setAccess(std::string value)
{
	access = value;
}
std::string MailAccess::getType() const
{
	return type;
}
void MailAccess::setType(std::string value)
{
	type = value;
}
std::string MailAccess::getActive() const
{
	return active;
}
void MailAccess::setActive(std::string value)
{
	active = value;
}

