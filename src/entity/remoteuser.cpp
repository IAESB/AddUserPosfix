#include "remoteuser.h"

RemoteUser::RemoteUser(){
	init();
}
RemoteUser::RemoteUser(long long remote_userid)
{
	init();
	this->remote_userid = remote_userid;
}

void RemoteUser::init()
{
}
long long RemoteUser::getRemoteUserid() const
{
	return remote_userid;
}
void RemoteUser::setRemoteUserid(long long value)
{
	remote_userid = value;
}
long long RemoteUser::getSysUserid() const
{
	return sys_userid;
}
void RemoteUser::setSysUserid(long long value)
{
	sys_userid = value;
}
long long RemoteUser::getSysGroupid() const
{
	return sys_groupid;
}
void RemoteUser::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string RemoteUser::getSysPermUser() const
{
	return sys_perm_user;
}
void RemoteUser::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string RemoteUser::getSysPermGroup() const
{
	return sys_perm_group;
}
void RemoteUser::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string RemoteUser::getSysPermOther() const
{
	return sys_perm_other;
}
void RemoteUser::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
std::string RemoteUser::getRemoteUsername() const
{
	return remote_username;
}
void RemoteUser::setRemoteUsername(std::string value)
{
	remote_username = value;
}
std::string RemoteUser::getRemotePassword() const
{
	return remote_password;
}
void RemoteUser::setRemotePassword(std::string value)
{
	remote_password = value;
}
std::string RemoteUser::getRemoteFunctions() const
{
	return remote_functions;
}
void RemoteUser::setRemoteFunctions(std::string value)
{
	remote_functions = value;
}

