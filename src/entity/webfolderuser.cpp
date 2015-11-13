#include "webfolderuser.h"

WebFolderUser::WebFolderUser(){
	init();
}
WebFolderUser::WebFolderUser(long long web_folder_user_id)
{
	init();
	this->web_folder_user_id = web_folder_user_id;
}

void WebFolderUser::init()
{
}
long long WebFolderUser::getWebFolderUserId() const
{
	return web_folder_user_id;
}
void WebFolderUser::setWebFolderUserId(long long value)
{
	web_folder_user_id = value;
}
int WebFolderUser::getSysUserid() const
{
	return sys_userid;
}
void WebFolderUser::setSysUserid(int value)
{
	sys_userid = value;
}
int WebFolderUser::getSysGroupid() const
{
	return sys_groupid;
}
void WebFolderUser::setSysGroupid(int value)
{
	sys_groupid = value;
}
std::string WebFolderUser::getSysPermUser() const
{
	return sys_perm_user;
}
void WebFolderUser::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string WebFolderUser::getSysPermGroup() const
{
	return sys_perm_group;
}
void WebFolderUser::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string WebFolderUser::getSysPermOther() const
{
	return sys_perm_other;
}
void WebFolderUser::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
int WebFolderUser::getServerId() const
{
	return server_id;
}
void WebFolderUser::setServerId(int value)
{
	server_id = value;
}
int WebFolderUser::getWebFolderId() const
{
	return web_folder_id;
}
void WebFolderUser::setWebFolderId(int value)
{
	web_folder_id = value;
}
std::string WebFolderUser::getUsername() const
{
	return username;
}
void WebFolderUser::setUsername(std::string value)
{
	username = value;
}
std::string WebFolderUser::getPassword() const
{
	return password;
}
void WebFolderUser::setPassword(std::string value)
{
	password = value;
}
std::string WebFolderUser::getActive() const
{
	return active;
}
void WebFolderUser::setActive(std::string value)
{
	active = value;
}

