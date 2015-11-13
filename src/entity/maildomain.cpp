#include "maildomain.h"

MailDomain::MailDomain(){
	init();
}
MailDomain::MailDomain(long long domain_id)
{
	init();
	this->domain_id = domain_id;
}

void MailDomain::init()
{
}
long long MailDomain::getDomainId() const
{
	return domain_id;
}
void MailDomain::setDomainId(long long value)
{
	domain_id = value;
}
long long MailDomain::getSysUserid() const
{
	return sys_userid;
}
void MailDomain::setSysUserid(long long value)
{
	sys_userid = value;
}
long long MailDomain::getSysGroupid() const
{
	return sys_groupid;
}
void MailDomain::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string MailDomain::getSysPermUser() const
{
	return sys_perm_user;
}
void MailDomain::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string MailDomain::getSysPermGroup() const
{
	return sys_perm_group;
}
void MailDomain::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string MailDomain::getSysPermOther() const
{
	return sys_perm_other;
}
void MailDomain::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
long long MailDomain::getServerId() const
{
	return server_id;
}
void MailDomain::setServerId(long long value)
{
	server_id = value;
}
std::string MailDomain::getDomain() const
{
	return domain;
}
void MailDomain::setDomain(std::string value)
{
	domain = value;
}
std::string MailDomain::getDkim() const
{
	return dkim;
}
void MailDomain::setDkim(std::string value)
{
	dkim = value;
}
std::string MailDomain::getDkimSelector() const
{
	return dkim_selector;
}
void MailDomain::setDkimSelector(std::string value)
{
	dkim_selector = value;
}
std::string MailDomain::getDkimPrivate() const
{
	return dkim_private;
}
void MailDomain::setDkimPrivate(std::string value)
{
	dkim_private = value;
}
std::string MailDomain::getDkimPublic() const
{
	return dkim_public;
}
void MailDomain::setDkimPublic(std::string value)
{
	dkim_public = value;
}
std::string MailDomain::getActive() const
{
	return active;
}
void MailDomain::setActive(std::string value)
{
	active = value;
}

