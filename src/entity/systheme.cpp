#include "systheme.h"

SysTheme::SysTheme(){
	init();
}
SysTheme::SysTheme(long long var_id)
{
	init();
	this->var_id = var_id;
}

void SysTheme::init()
{
}
long long SysTheme::getSysUserid() const
{
	return sys_userid;
}
void SysTheme::setSysUserid(long long value)
{
	sys_userid = value;
}
long long SysTheme::getSysGroupid() const
{
	return sys_groupid;
}
void SysTheme::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string SysTheme::getSysPermUser() const
{
	return sys_perm_user;
}
void SysTheme::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string SysTheme::getSysPermGroup() const
{
	return sys_perm_group;
}
void SysTheme::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string SysTheme::getSysPermOther() const
{
	return sys_perm_other;
}
void SysTheme::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
long long SysTheme::getVarId() const
{
	return var_id;
}
void SysTheme::setVarId(long long value)
{
	var_id = value;
}
std::string SysTheme::getTplName() const
{
	return tpl_name;
}
void SysTheme::setTplName(std::string value)
{
	tpl_name = value;
}
std::string SysTheme::getUsername() const
{
	return username;
}
void SysTheme::setUsername(std::string value)
{
	username = value;
}
std::string SysTheme::getLogoUrl() const
{
	return logo_url;
}
void SysTheme::setLogoUrl(std::string value)
{
	logo_url = value;
}

