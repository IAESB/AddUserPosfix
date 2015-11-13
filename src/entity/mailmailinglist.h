#ifndef MAILMAILINGLIST_H
#define MAILMAILINGLIST_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class MailMailinglist;
typedef shared_ptr<MailMailinglist> MailMailinglistPtr;
typedef vector<MailMailinglistPtr> MailMailinglistList;

class MailMailinglist
{
	long long mailinglist_id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	long long server_id;
	std::string domain;
	std::string listname;
	std::string email;
	std::string password;
public:
	MailMailinglist();
	MailMailinglist(long long mailinglist_id);
	void init();
	long long getMailinglistId() const;
	void setMailinglistId(long long value);
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
	std::string getDomain() const;
	void setDomain(std::string value);
	std::string getListname() const;
	void setListname(std::string value);
	std::string getEmail() const;
	void setEmail(std::string value);
	std::string getPassword() const;
	void setPassword(std::string value);
};



#endif // MAILMAILINGLIST_H
