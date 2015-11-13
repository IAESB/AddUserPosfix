#include "sysuser.h"

SysUser::SysUser(){
	init();
}
SysUser::SysUser(long long userid)
{
	init();
	this->userid = userid;
}

void SysUser::init()
{
}
long long SysUser::getUserid() const
{
	return userid;
}
void SysUser::setUserid(long long value)
{
	userid = value;
}
long long SysUser::getSysUserid() const
{
	return sys_userid;
}
void SysUser::setSysUserid(long long value)
{
	sys_userid = value;
}
long long SysUser::getSysGroupid() const
{
	return sys_groupid;
}
void SysUser::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string SysUser::getSysPermUser() const
{
	return sys_perm_user;
}
void SysUser::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string SysUser::getSysPermGroup() const
{
	return sys_perm_group;
}
void SysUser::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string SysUser::getSysPermOther() const
{
	return sys_perm_other;
}
void SysUser::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
std::string SysUser::getUsername() const
{
	return username;
}
void SysUser::setUsername(std::string value)
{
	username = value;
}
std::string SysUser::getPasswort() const
{
	return passwort;
}
void SysUser::setPasswort(std::string value)
{
	passwort = value;
}
std::string SysUser::getModules() const
{
	return modules;
}
void SysUser::setModules(std::string value)
{
	modules = value;
}
std::string SysUser::getStartmodule() const
{
	return startmodule;
}
void SysUser::setStartmodule(std::string value)
{
	startmodule = value;
}
std::string SysUser::getAppTheme() const
{
	return app_theme;
}
void SysUser::setAppTheme(std::string value)
{
	app_theme = value;
}
std::string SysUser::getTyp() const
{
	return typ;
}
void SysUser::setTyp(std::string value)
{
	typ = value;
}
int SysUser::getActive() const
{
	return active;
}
void SysUser::setActive(int value)
{
	active = value;
}
std::string SysUser::getLanguage() const
{
	return language;
}
void SysUser::setLanguage(std::string value)
{
	language = value;
}
std::string SysUser::getGroups() const
{
	return groups;
}
void SysUser::setGroups(std::string value)
{
	groups = value;
}
long long SysUser::getDefaultGroup() const
{
	return default_group;
}
void SysUser::setDefaultGroup(long long value)
{
	default_group = value;
}
long long SysUser::getClientId() const
{
	return client_id;
}
void SysUser::setClientId(long long value)
{
	client_id = value;
}
std::string SysUser::getIdRsa() const
{
	return id_rsa;
}
void SysUser::setIdRsa(std::string value)
{
	id_rsa = value;
}
std::string SysUser::getSshRsa() const
{
	return ssh_rsa;
}
void SysUser::setSshRsa(std::string value)
{
	ssh_rsa = value;
}

