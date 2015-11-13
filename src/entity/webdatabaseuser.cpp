#include "webdatabaseuser.h"

WebDatabaseUser::WebDatabaseUser(){
	init();
}
WebDatabaseUser::WebDatabaseUser(long long database_user_id)
{
	init();
	this->database_user_id = database_user_id;
}

void WebDatabaseUser::init()
{
}
long long WebDatabaseUser::getDatabaseUserId() const
{
	return database_user_id;
}
void WebDatabaseUser::setDatabaseUserId(long long value)
{
	database_user_id = value;
}
long long WebDatabaseUser::getSysUserid() const
{
	return sys_userid;
}
void WebDatabaseUser::setSysUserid(long long value)
{
	sys_userid = value;
}
long long WebDatabaseUser::getSysGroupid() const
{
	return sys_groupid;
}
void WebDatabaseUser::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string WebDatabaseUser::getSysPermUser() const
{
	return sys_perm_user;
}
void WebDatabaseUser::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string WebDatabaseUser::getSysPermGroup() const
{
	return sys_perm_group;
}
void WebDatabaseUser::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string WebDatabaseUser::getSysPermOther() const
{
	return sys_perm_other;
}
void WebDatabaseUser::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
long long WebDatabaseUser::getServerId() const
{
	return server_id;
}
void WebDatabaseUser::setServerId(long long value)
{
	server_id = value;
}
std::string WebDatabaseUser::getDatabaseUser() const
{
	return database_user;
}
void WebDatabaseUser::setDatabaseUser(std::string value)
{
	database_user = value;
}
std::string WebDatabaseUser::getDatabaseUserPrefix() const
{
	return database_user_prefix;
}
void WebDatabaseUser::setDatabaseUserPrefix(std::string value)
{
	database_user_prefix = value;
}
std::string WebDatabaseUser::getDatabasePassword() const
{
	return database_password;
}
void WebDatabaseUser::setDatabasePassword(std::string value)
{
	database_password = value;
}
std::string WebDatabaseUser::getDatabasePasswordMongo() const
{
	return database_password_mongo;
}
void WebDatabaseUser::setDatabasePasswordMongo(std::string value)
{
	database_password_mongo = value;
}

