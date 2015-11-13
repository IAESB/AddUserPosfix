#include "mailtransport.h"

MailTransport::MailTransport(){
	init();
}
MailTransport::MailTransport(long long transport_id)
{
	init();
	this->transport_id = transport_id;
}

void MailTransport::init()
{
}
long long MailTransport::getTransportId() const
{
	return transport_id;
}
void MailTransport::setTransportId(long long value)
{
	transport_id = value;
}
long long MailTransport::getSysUserid() const
{
	return sys_userid;
}
void MailTransport::setSysUserid(long long value)
{
	sys_userid = value;
}
long long MailTransport::getSysGroupid() const
{
	return sys_groupid;
}
void MailTransport::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string MailTransport::getSysPermUser() const
{
	return sys_perm_user;
}
void MailTransport::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string MailTransport::getSysPermGroup() const
{
	return sys_perm_group;
}
void MailTransport::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string MailTransport::getSysPermOther() const
{
	return sys_perm_other;
}
void MailTransport::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
long long MailTransport::getServerId() const
{
	return server_id;
}
void MailTransport::setServerId(long long value)
{
	server_id = value;
}
std::string MailTransport::getDomain() const
{
	return domain;
}
void MailTransport::setDomain(std::string value)
{
	domain = value;
}
std::string MailTransport::getTransport() const
{
	return transport;
}
void MailTransport::setTransport(std::string value)
{
	transport = value;
}
long long MailTransport::getSortOrder() const
{
	return sort_order;
}
void MailTransport::setSortOrder(long long value)
{
	sort_order = value;
}
std::string MailTransport::getActive() const
{
	return active;
}
void MailTransport::setActive(std::string value)
{
	active = value;
}

