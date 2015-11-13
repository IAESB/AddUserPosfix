#include "webfolder.h"

WebFolder::WebFolder(){
	init();
}
WebFolder::WebFolder(long long web_folder_id)
{
	init();
	this->web_folder_id = web_folder_id;
}

void WebFolder::init()
{
}
long long WebFolder::getWebFolderId() const
{
	return web_folder_id;
}
void WebFolder::setWebFolderId(long long value)
{
	web_folder_id = value;
}
int WebFolder::getSysUserid() const
{
	return sys_userid;
}
void WebFolder::setSysUserid(int value)
{
	sys_userid = value;
}
int WebFolder::getSysGroupid() const
{
	return sys_groupid;
}
void WebFolder::setSysGroupid(int value)
{
	sys_groupid = value;
}
std::string WebFolder::getSysPermUser() const
{
	return sys_perm_user;
}
void WebFolder::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string WebFolder::getSysPermGroup() const
{
	return sys_perm_group;
}
void WebFolder::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string WebFolder::getSysPermOther() const
{
	return sys_perm_other;
}
void WebFolder::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
int WebFolder::getServerId() const
{
	return server_id;
}
void WebFolder::setServerId(int value)
{
	server_id = value;
}
int WebFolder::getParentDomainId() const
{
	return parent_domain_id;
}
void WebFolder::setParentDomainId(int value)
{
	parent_domain_id = value;
}
std::string WebFolder::getPath() const
{
	return path;
}
void WebFolder::setPath(std::string value)
{
	path = value;
}
std::string WebFolder::getActive() const
{
	return active;
}
void WebFolder::setActive(std::string value)
{
	active = value;
}

