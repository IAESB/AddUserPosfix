#include "mailuserfilter.h"

MailUserFilter::MailUserFilter(){
	init();
}
MailUserFilter::MailUserFilter(long long filter_id)
{
	init();
	this->filter_id = filter_id;
}

void MailUserFilter::init()
{
}
long long MailUserFilter::getFilterId() const
{
	return filter_id;
}
void MailUserFilter::setFilterId(long long value)
{
	filter_id = value;
}
long long MailUserFilter::getSysUserid() const
{
	return sys_userid;
}
void MailUserFilter::setSysUserid(long long value)
{
	sys_userid = value;
}
long long MailUserFilter::getSysGroupid() const
{
	return sys_groupid;
}
void MailUserFilter::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string MailUserFilter::getSysPermUser() const
{
	return sys_perm_user;
}
void MailUserFilter::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string MailUserFilter::getSysPermGroup() const
{
	return sys_perm_group;
}
void MailUserFilter::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string MailUserFilter::getSysPermOther() const
{
	return sys_perm_other;
}
void MailUserFilter::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
long long MailUserFilter::getMailuserId() const
{
	return mailuser_id;
}
void MailUserFilter::setMailuserId(long long value)
{
	mailuser_id = value;
}
std::string MailUserFilter::getRulename() const
{
	return rulename;
}
void MailUserFilter::setRulename(std::string value)
{
	rulename = value;
}
std::string MailUserFilter::getSource() const
{
	return source;
}
void MailUserFilter::setSource(std::string value)
{
	source = value;
}
std::string MailUserFilter::getSearchterm() const
{
	return searchterm;
}
void MailUserFilter::setSearchterm(std::string value)
{
	searchterm = value;
}
std::string MailUserFilter::getOp() const
{
	return op;
}
void MailUserFilter::setOp(std::string value)
{
	op = value;
}
std::string MailUserFilter::getAction() const
{
	return action;
}
void MailUserFilter::setAction(std::string value)
{
	action = value;
}
std::string MailUserFilter::getTarget() const
{
	return target;
}
void MailUserFilter::setTarget(std::string value)
{
	target = value;
}
std::string MailUserFilter::getActive() const
{
	return active;
}
void MailUserFilter::setActive(std::string value)
{
	active = value;
}

