#include "mailforwarding.h"

MailForwarding::MailForwarding(){
	init();
}
MailForwarding::MailForwarding(long long forwarding_id)
{
	init();
	this->forwarding_id = forwarding_id;
}

void MailForwarding::init()
{
}
long long MailForwarding::getForwardingId() const
{
	return forwarding_id;
}
void MailForwarding::setForwardingId(long long value)
{
	forwarding_id = value;
}
long long MailForwarding::getSysUserid() const
{
	return sys_userid;
}
void MailForwarding::setSysUserid(long long value)
{
	sys_userid = value;
}
long long MailForwarding::getSysGroupid() const
{
	return sys_groupid;
}
void MailForwarding::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string MailForwarding::getSysPermUser() const
{
	return sys_perm_user;
}
void MailForwarding::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string MailForwarding::getSysPermGroup() const
{
	return sys_perm_group;
}
void MailForwarding::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string MailForwarding::getSysPermOther() const
{
	return sys_perm_other;
}
void MailForwarding::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
long long MailForwarding::getServerId() const
{
	return server_id;
}
void MailForwarding::setServerId(long long value)
{
	server_id = value;
}
std::string MailForwarding::getSource() const
{
	return source;
}
void MailForwarding::setSource(std::string value)
{
	source = value;
}
std::string MailForwarding::getDestination() const
{
	return destination;
}
void MailForwarding::setDestination(std::string value)
{
	destination = value;
}
std::string MailForwarding::getType() const
{
	return type;
}
void MailForwarding::setType(std::string value)
{
	type = value;
}
std::string MailForwarding::getActive() const
{
	return active;
}
void MailForwarding::setActive(std::string value)
{
	active = value;
}

