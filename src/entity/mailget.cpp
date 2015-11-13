#include "mailget.h"

MailGet::MailGet(){
	init();
}
MailGet::MailGet(long long mailget_id)
{
	init();
	this->mailget_id = mailget_id;
}

void MailGet::init()
{
}
long long MailGet::getMailgetId() const
{
	return mailget_id;
}
void MailGet::setMailgetId(long long value)
{
	mailget_id = value;
}
long long MailGet::getSysUserid() const
{
	return sys_userid;
}
void MailGet::setSysUserid(long long value)
{
	sys_userid = value;
}
long long MailGet::getSysGroupid() const
{
	return sys_groupid;
}
void MailGet::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string MailGet::getSysPermUser() const
{
	return sys_perm_user;
}
void MailGet::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string MailGet::getSysPermGroup() const
{
	return sys_perm_group;
}
void MailGet::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string MailGet::getSysPermOther() const
{
	return sys_perm_other;
}
void MailGet::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
long long MailGet::getServerId() const
{
	return server_id;
}
void MailGet::setServerId(long long value)
{
	server_id = value;
}
std::string MailGet::getType() const
{
	return type;
}
void MailGet::setType(std::string value)
{
	type = value;
}
std::string MailGet::getSourceServer() const
{
	return source_server;
}
void MailGet::setSourceServer(std::string value)
{
	source_server = value;
}
std::string MailGet::getSourceUsername() const
{
	return source_username;
}
void MailGet::setSourceUsername(std::string value)
{
	source_username = value;
}
std::string MailGet::getSourcePassword() const
{
	return source_password;
}
void MailGet::setSourcePassword(std::string value)
{
	source_password = value;
}
std::string MailGet::getSourceDelete() const
{
	return source_delete;
}
void MailGet::setSourceDelete(std::string value)
{
	source_delete = value;
}
std::string MailGet::getSourceReadAll() const
{
	return source_read_all;
}
void MailGet::setSourceReadAll(std::string value)
{
	source_read_all = value;
}
std::string MailGet::getDestination() const
{
	return destination;
}
void MailGet::setDestination(std::string value)
{
	destination = value;
}
std::string MailGet::getActive() const
{
	return active;
}
void MailGet::setActive(std::string value)
{
	active = value;
}

