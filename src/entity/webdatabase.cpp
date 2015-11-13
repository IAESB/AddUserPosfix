#include "webdatabase.h"

WebDatabase::WebDatabase(){
	init();
}
WebDatabase::WebDatabase(long long database_id)
{
	init();
	this->database_id = database_id;
}

void WebDatabase::init()
{
	last_quota_notification = {0};
}
long long WebDatabase::getDatabaseId() const
{
	return database_id;
}
void WebDatabase::setDatabaseId(long long value)
{
	database_id = value;
}
long long WebDatabase::getSysUserid() const
{
	return sys_userid;
}
void WebDatabase::setSysUserid(long long value)
{
	sys_userid = value;
}
long long WebDatabase::getSysGroupid() const
{
	return sys_groupid;
}
void WebDatabase::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string WebDatabase::getSysPermUser() const
{
	return sys_perm_user;
}
void WebDatabase::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string WebDatabase::getSysPermGroup() const
{
	return sys_perm_group;
}
void WebDatabase::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string WebDatabase::getSysPermOther() const
{
	return sys_perm_other;
}
void WebDatabase::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
long long WebDatabase::getServerId() const
{
	return server_id;
}
void WebDatabase::setServerId(long long value)
{
	server_id = value;
}
long long WebDatabase::getParentDomainId() const
{
	return parent_domain_id;
}
void WebDatabase::setParentDomainId(long long value)
{
	parent_domain_id = value;
}
std::string WebDatabase::getType() const
{
	return type;
}
void WebDatabase::setType(std::string value)
{
	type = value;
}
std::string WebDatabase::getDatabaseName() const
{
	return database_name;
}
void WebDatabase::setDatabaseName(std::string value)
{
	database_name = value;
}
std::string WebDatabase::getDatabaseNamePrefix() const
{
	return database_name_prefix;
}
void WebDatabase::setDatabaseNamePrefix(std::string value)
{
	database_name_prefix = value;
}
long long WebDatabase::getDatabaseQuota() const
{
	return database_quota;
}
void WebDatabase::setDatabaseQuota(long long value)
{
	database_quota = value;
}
tm WebDatabase::getLastQuotaNotification() const
{
	return last_quota_notification;
}
void WebDatabase::setLastQuotaNotification(tm value)
{
	last_quota_notification = value;
}
long long WebDatabase::getDatabaseUserId() const
{
	return database_user_id;
}
void WebDatabase::setDatabaseUserId(long long value)
{
	database_user_id = value;
}
long long WebDatabase::getDatabaseRoUserId() const
{
	return database_ro_user_id;
}
void WebDatabase::setDatabaseRoUserId(long long value)
{
	database_ro_user_id = value;
}
std::string WebDatabase::getDatabaseCharset() const
{
	return database_charset;
}
void WebDatabase::setDatabaseCharset(std::string value)
{
	database_charset = value;
}
std::string WebDatabase::getRemoteAccess() const
{
	return remote_access;
}
void WebDatabase::setRemoteAccess(std::string value)
{
	remote_access = value;
}
std::string WebDatabase::getRemoteIps() const
{
	return remote_ips;
}
void WebDatabase::setRemoteIps(std::string value)
{
	remote_ips = value;
}
std::string WebDatabase::getBackupInterval() const
{
	return backup_interval;
}
void WebDatabase::setBackupInterval(std::string value)
{
	backup_interval = value;
}
int WebDatabase::getBackupCopies() const
{
	return backup_copies;
}
void WebDatabase::setBackupCopies(int value)
{
	backup_copies = value;
}
std::string WebDatabase::getActive() const
{
	return active;
}
void WebDatabase::setActive(std::string value)
{
	active = value;
}

