#include "dnstemplate.h"

DnsTemplate::DnsTemplate(){
	init();
}
DnsTemplate::DnsTemplate(long long template_id)
{
	init();
	this->template_id = template_id;
}

void DnsTemplate::init()
{
}
long long DnsTemplate::getTemplateId() const
{
	return template_id;
}
void DnsTemplate::setTemplateId(long long value)
{
	template_id = value;
}
long long DnsTemplate::getSysUserid() const
{
	return sys_userid;
}
void DnsTemplate::setSysUserid(long long value)
{
	sys_userid = value;
}
long long DnsTemplate::getSysGroupid() const
{
	return sys_groupid;
}
void DnsTemplate::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string DnsTemplate::getSysPermUser() const
{
	return sys_perm_user;
}
void DnsTemplate::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string DnsTemplate::getSysPermGroup() const
{
	return sys_perm_group;
}
void DnsTemplate::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string DnsTemplate::getSysPermOther() const
{
	return sys_perm_other;
}
void DnsTemplate::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
std::string DnsTemplate::getName() const
{
	return name;
}
void DnsTemplate::setName(std::string value)
{
	name = value;
}
std::string DnsTemplate::getFields() const
{
	return fields;
}
void DnsTemplate::setFields(std::string value)
{
	fields = value;
}
std::string DnsTemplate::getTemplate() const
{
	return template_;
}
void DnsTemplate::setTemplate(std::string value)
{
	template_ = value;
}
std::string DnsTemplate::getVisible() const
{
	return visible;
}
void DnsTemplate::setVisible(std::string value)
{
	visible = value;
}

