#include "webdavuser.h"

WebdavUser::WebdavUser(){
	init();
}
WebdavUser::WebdavUser(long long webdav_user_id)
{
	init();
	this->webdav_user_id = webdav_user_id;
}

void WebdavUser::init()
{
}
long long WebdavUser::getWebdavUserId() const
{
	return webdav_user_id;
}
void WebdavUser::setWebdavUserId(long long value)
{
	webdav_user_id = value;
}
long long WebdavUser::getSysUserid() const
{
	return sys_userid;
}
void WebdavUser::setSysUserid(long long value)
{
	sys_userid = value;
}
long long WebdavUser::getSysGroupid() const
{
	return sys_groupid;
}
void WebdavUser::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string WebdavUser::getSysPermUser() const
{
	return sys_perm_user;
}
void WebdavUser::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string WebdavUser::getSysPermGroup() const
{
	return sys_perm_group;
}
void WebdavUser::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string WebdavUser::getSysPermOther() const
{
	return sys_perm_other;
}
void WebdavUser::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
long long WebdavUser::getServerId() const
{
	return server_id;
}
void WebdavUser::setServerId(long long value)
{
	server_id = value;
}
long long WebdavUser::getParentDomainId() const
{
	return parent_domain_id;
}
void WebdavUser::setParentDomainId(long long value)
{
	parent_domain_id = value;
}
std::string WebdavUser::getUsername() const
{
	return username;
}
void WebdavUser::setUsername(std::string value)
{
	username = value;
}
std::string WebdavUser::getUsernamePrefix() const
{
	return username_prefix;
}
void WebdavUser::setUsernamePrefix(std::string value)
{
	username_prefix = value;
}
std::string WebdavUser::getPassword() const
{
	return password;
}
void WebdavUser::setPassword(std::string value)
{
	password = value;
}
std::string WebdavUser::getActive() const
{
	return active;
}
void WebdavUser::setActive(std::string value)
{
	active = value;
}
std::string WebdavUser::getDir() const
{
	return dir;
}
void WebdavUser::setDir(std::string value)
{
	dir = value;
}

