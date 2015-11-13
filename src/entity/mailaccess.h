#ifndef MAILACCESS_H
#define MAILACCESS_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class MailAccess;
typedef shared_ptr<MailAccess> MailAccessPtr;
typedef vector<MailAccessPtr> MailAccessList;

class MailAccess
{
	long long access_id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	int server_id; //key: MUL
	std::string source;
	std::string access;
	std::string type;
	std::string active;
public:
	MailAccess();
	MailAccess(long long access_id);
	void init();
	long long getAccessId() const;
	void setAccessId(long long value);
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
	int getServerId() const;
	void setServerId(int value);
	std::string getSource() const;
	void setSource(std::string value);
	std::string getAccess() const;
	void setAccess(std::string value);
	std::string getType() const;
	void setType(std::string value);
	std::string getActive() const;
	void setActive(std::string value);
};



#endif // MAILACCESS_H
