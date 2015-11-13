#ifndef WEBDATABASEUSER_H
#define WEBDATABASEUSER_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class WebDatabaseUser;
typedef shared_ptr<WebDatabaseUser> WebDatabaseUserPtr;
typedef vector<WebDatabaseUserPtr> WebDatabaseUserList;

class WebDatabaseUser
{
	long long database_user_id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	long long server_id;
	std::string database_user;
	std::string database_user_prefix;
	std::string database_password;
	std::string database_password_mongo;
public:
	WebDatabaseUser();
	WebDatabaseUser(long long database_user_id);
	void init();
	long long getDatabaseUserId() const;
	void setDatabaseUserId(long long value);
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
	std::string getDatabaseUser() const;
	void setDatabaseUser(std::string value);
	std::string getDatabaseUserPrefix() const;
	void setDatabaseUserPrefix(std::string value);
	std::string getDatabasePassword() const;
	void setDatabasePassword(std::string value);
	std::string getDatabasePasswordMongo() const;
	void setDatabasePasswordMongo(std::string value);
};



#endif // WEBDATABASEUSER_H
