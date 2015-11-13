#include "openvzostemplate.h"

OpenvzOstemplate::OpenvzOstemplate(){
	init();
}
OpenvzOstemplate::OpenvzOstemplate(long long ostemplate_id)
{
	init();
	this->ostemplate_id = ostemplate_id;
}

void OpenvzOstemplate::init()
{
}
long long OpenvzOstemplate::getOstemplateId() const
{
	return ostemplate_id;
}
void OpenvzOstemplate::setOstemplateId(long long value)
{
	ostemplate_id = value;
}
int OpenvzOstemplate::getSysUserid() const
{
	return sys_userid;
}
void OpenvzOstemplate::setSysUserid(int value)
{
	sys_userid = value;
}
int OpenvzOstemplate::getSysGroupid() const
{
	return sys_groupid;
}
void OpenvzOstemplate::setSysGroupid(int value)
{
	sys_groupid = value;
}
std::string OpenvzOstemplate::getSysPermUser() const
{
	return sys_perm_user;
}
void OpenvzOstemplate::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string OpenvzOstemplate::getSysPermGroup() const
{
	return sys_perm_group;
}
void OpenvzOstemplate::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string OpenvzOstemplate::getSysPermOther() const
{
	return sys_perm_other;
}
void OpenvzOstemplate::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
std::string OpenvzOstemplate::getTemplateName() const
{
	return template_name;
}
void OpenvzOstemplate::setTemplateName(std::string value)
{
	template_name = value;
}
std::string OpenvzOstemplate::getTemplateFile() const
{
	return template_file;
}
void OpenvzOstemplate::setTemplateFile(std::string value)
{
	template_file = value;
}
int OpenvzOstemplate::getServerId() const
{
	return server_id;
}
void OpenvzOstemplate::setServerId(int value)
{
	server_id = value;
}
std::string OpenvzOstemplate::getAllservers() const
{
	return allservers;
}
void OpenvzOstemplate::setAllservers(std::string value)
{
	allservers = value;
}
std::string OpenvzOstemplate::getActive() const
{
	return active;
}
void OpenvzOstemplate::setActive(std::string value)
{
	active = value;
}
std::string OpenvzOstemplate::getDescription() const
{
	return description;
}
void OpenvzOstemplate::setDescription(std::string value)
{
	description = value;
}

