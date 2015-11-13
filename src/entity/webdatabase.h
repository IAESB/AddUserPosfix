#ifndef WEBDATABASE_H
#define WEBDATABASE_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class WebDatabase;
typedef shared_ptr<WebDatabase> WebDatabasePtr;
typedef vector<WebDatabasePtr> WebDatabaseList;

class WebDatabase
{
	long long database_id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	long long server_id;
	long long parent_domain_id;
	std::string type;
	std::string database_name;
	std::string database_name_prefix;
	long long database_quota;
	tm last_quota_notification;
	long long database_user_id; //key: MUL
	long long database_ro_user_id; //key: MUL
	std::string database_charset;
	std::string remote_access;
	std::string remote_ips;
	std::string backup_interval;
	int backup_copies;
	std::string active;
public:
	WebDatabase();
	WebDatabase(long long database_id);
	void init();
	long long getDatabaseId() const;
	void setDatabaseId(long long value);
	long long getSysUserid() const;
	void setSysUserid(long long value);
	long long getSysGroupid() const;
	void setSysGroupid(long long value);
	std::string getSysPermUser() const;
	void setSysPermUser(std::string value);
	std::string getSysPermGroup() const;
	void setSysPermGroup(std::string value);
	std::string getSysPermOther() const;
	void setSysPermOther(std::string value);
	long long getServerId() const;
	void setServerId(long long value);
	long long getParentDomainId() const;
	void setParentDomainId(long long value);
	std::string getType() const;
	void setType(std::string value);
	std::string getDatabaseName() const;
	void setDatabaseName(std::string value);
	std::string getDatabaseNamePrefix() const;
	void setDatabaseNamePrefix(std::string value);
	long long getDatabaseQuota() const;
	void setDatabaseQuota(long long value);
	tm getLastQuotaNotification() const;
	void setLastQuotaNotification(tm value);
	long long getDatabaseUserId() const;
	void setDatabaseUserId(long long value);
	long long getDatabaseRoUserId() const;
	void setDatabaseRoUserId(long long value);
	std::string getDatabaseCharset() const;
	void setDatabaseCharset(std::string value);
	std::string getRemoteAccess() const;
	void setRemoteAccess(std::string value);
	std::string getRemoteIps() const;
	void setRemoteIps(std::string value);
	std::string getBackupInterval() const;
	void setBackupInterval(std::string value);
	int getBackupCopies() const;
	void setBackupCopies(int value);
	std::string getActive() const;
	void setActive(std::string value);
};



#endif // WEBDATABASE_H
