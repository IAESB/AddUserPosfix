#ifndef WEBDAVUSER_H
#define WEBDAVUSER_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class WebdavUser;
typedef shared_ptr<WebdavUser> WebdavUserPtr;
typedef vector<WebdavUserPtr> WebdavUserList;

class WebdavUser
{
	long long webdav_user_id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	long long server_id;
	long long parent_domain_id;
	std::string username;
	std::string username_prefix;
	std::string password;
	std::string active;
	std::string dir;
public:
	WebdavUser();
	WebdavUser(long long webdav_user_id);
	void init();
	long long getWebdavUserId() const;
	void setWebdavUserId(long long value);
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
	std::string getUsername() const;
	void setUsername(std::string value);
	std::string getUsernamePrefix() const;
	void setUsernamePrefix(std::string value);
	std::string getPassword() const;
	void setPassword(std::string value);
	std::string getActive() const;
	void setActive(std::string value);
	std::string getDir() const;
	void setDir(std::string value);
};



#endif // WEBDAVUSER_H
