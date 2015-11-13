#include "mailcontentfilter.h"

MailContentFilter::MailContentFilter(){
	init();
}
MailContentFilter::MailContentFilter(long long content_filter_id)
{
	init();
	this->content_filter_id = content_filter_id;
}

void MailContentFilter::init()
{
}
long long MailContentFilter::getContentFilterId() const
{
	return content_filter_id;
}
void MailContentFilter::setContentFilterId(long long value)
{
	content_filter_id = value;
}
long long MailContentFilter::getSysUserid() const
{
	return sys_userid;
}
void MailContentFilter::setSysUserid(long long value)
{
	sys_userid = value;
}
long long MailContentFilter::getSysGroupid() const
{
	return sys_groupid;
}
void MailContentFilter::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string MailContentFilter::getSysPermUser() const
{
	return sys_perm_user;
}
void MailContentFilter::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string MailContentFilter::getSysPermGroup() const
{
	return sys_perm_group;
}
void MailContentFilter::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string MailContentFilter::getSysPermOther() const
{
	return sys_perm_other;
}
void MailContentFilter::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
int MailContentFilter::getServerId() const
{
	return server_id;
}
void MailContentFilter::setServerId(int value)
{
	server_id = value;
}
std::string MailContentFilter::getType() const
{
	return type;
}
void MailContentFilter::setType(std::string value)
{
	type = value;
}
std::string MailContentFilter::getPattern() const
{
	return pattern;
}
void MailContentFilter::setPattern(std::string value)
{
	pattern = value;
}
std::string MailContentFilter::getData() const
{
	return data;
}
void MailContentFilter::setData(std::string value)
{
	data = value;
}
std::string MailContentFilter::getAction() const
{
	return action;
}
void MailContentFilter::setAction(std::string value)
{
	action = value;
}
std::string MailContentFilter::getActive() const
{
	return active;
}
void MailContentFilter::setActive(std::string value)
{
	active = value;
}

