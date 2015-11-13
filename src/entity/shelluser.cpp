#include "shelluser.h"

ShellUser::ShellUser(){
	init();
}
ShellUser::ShellUser(long long shell_user_id)
{
	init();
	this->shell_user_id = shell_user_id;
}

void ShellUser::init()
{
}
long long ShellUser::getShellUserId() const
{
	return shell_user_id;
}
void ShellUser::setShellUserId(long long value)
{
	shell_user_id = value;
}
long long ShellUser::getSysUserid() const
{
	return sys_userid;
}
void ShellUser::setSysUserid(long long value)
{
	sys_userid = value;
}
long long ShellUser::getSysGroupid() const
{
	return sys_groupid;
}
void ShellUser::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string ShellUser::getSysPermUser() const
{
	return sys_perm_user;
}
void ShellUser::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string ShellUser::getSysPermGroup() const
{
	return sys_perm_group;
}
void ShellUser::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string ShellUser::getSysPermOther() const
{
	return sys_perm_other;
}
void ShellUser::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
long long ShellUser::getServerId() const
{
	return server_id;
}
void ShellUser::setServerId(long long value)
{
	server_id = value;
}
long long ShellUser::getParentDomainId() const
{
	return parent_domain_id;
}
void ShellUser::setParentDomainId(long long value)
{
	parent_domain_id = value;
}
std::string ShellUser::getUsername() const
{
	return username;
}
void ShellUser::setUsername(std::string value)
{
	username = value;
}
std::string ShellUser::getUsernamePrefix() const
{
	return username_prefix;
}
void ShellUser::setUsernamePrefix(std::string value)
{
	username_prefix = value;
}
std::string ShellUser::getPassword() const
{
	return password;
}
void ShellUser::setPassword(std::string value)
{
	password = value;
}
long long ShellUser::getQuotaSize() const
{
	return quota_size;
}
void ShellUser::setQuotaSize(long long value)
{
	quota_size = value;
}
std::string ShellUser::getActive() const
{
	return active;
}
void ShellUser::setActive(std::string value)
{
	active = value;
}
std::string ShellUser::getPuser() const
{
	return puser;
}
void ShellUser::setPuser(std::string value)
{
	puser = value;
}
std::string ShellUser::getPgroup() const
{
	return pgroup;
}
void ShellUser::setPgroup(std::string value)
{
	pgroup = value;
}
std::string ShellUser::getShell() const
{
	return shell;
}
void ShellUser::setShell(std::string value)
{
	shell = value;
}
std::string ShellUser::getDir() const
{
	return dir;
}
void ShellUser::setDir(std::string value)
{
	dir = value;
}
std::string ShellUser::getChroot() const
{
	return chroot;
}
void ShellUser::setChroot(std::string value)
{
	chroot = value;
}
std::string ShellUser::getSshRsa() const
{
	return ssh_rsa;
}
void ShellUser::setSshRsa(std::string value)
{
	ssh_rsa = value;
}

