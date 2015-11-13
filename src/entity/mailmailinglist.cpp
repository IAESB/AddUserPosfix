#include "mailmailinglist.h"

MailMailinglist::MailMailinglist(){
	init();
}
MailMailinglist::MailMailinglist(long long mailinglist_id)
{
	init();
	this->mailinglist_id = mailinglist_id;
}

void MailMailinglist::init()
{
}
long long MailMailinglist::getMailinglistId() const
{
	return mailinglist_id;
}
void MailMailinglist::setMailinglistId(long long value)
{
	mailinglist_id = value;
}
long long MailMailinglist::getSysUserid() const
{
	return sys_userid;
}
void MailMailinglist::setSysUserid(long long value)
{
	sys_userid = value;
}
long long MailMailinglist::getSysGroupid() const
{
	return sys_groupid;
}
void MailMailinglist::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string MailMailinglist::getSysPermUser() const
{
	return sys_perm_user;
}
void MailMailinglist::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string MailMailinglist::getSysPermGroup() const
{
	return sys_perm_group;
}
void MailMailinglist::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string MailMailinglist::getSysPermOther() const
{
	return sys_perm_other;
}
void MailMailinglist::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
long long MailMailinglist::getServerId() const
{
	return server_id;
}
void MailMailinglist::setServerId(long long value)
{
	server_id = value;
}
std::string MailMailinglist::getDomain() const
{
	return domain;
}
void MailMailinglist::setDomain(std::string value)
{
	domain = value;
}
std::string MailMailinglist::getListname() const
{
	return listname;
}
void MailMailinglist::setListname(std::string value)
{
	listname = value;
}
std::string MailMailinglist::getEmail() const
{
	return email;
}
void MailMailinglist::setEmail(std::string value)
{
	email = value;
}
std::string MailMailinglist::getPassword() const
{
	return password;
}
void MailMailinglist::setPassword(std::string value)
{
	password = value;
}

