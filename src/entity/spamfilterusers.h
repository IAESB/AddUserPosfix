#ifndef SPAMFILTERUSERS_H
#define SPAMFILTERUSERS_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class SpamfilterUsers;
typedef shared_ptr<SpamfilterUsers> SpamfilterUsersPtr;
typedef vector<SpamfilterUsersPtr> SpamfilterUsersList;

class SpamfilterUsers
{
	long long id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	long long server_id;
	int priority;
	long long policy_id;
	std::string email; //key: UNI
	std::string fullname;
	std::string local;
public:
	SpamfilterUsers();
	SpamfilterUsers(long long id);
	void init();
	long long getId() const;
	void setId(long long value);
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
	int getPriority() const;
	void setPriority(int value);
	long long getPolicyId() const;
	void setPolicyId(long long value);
	std::string getEmail() const;
	void setEmail(std::string value);
	std::string getFullname() const;
	void setFullname(std::string value);
	std::string getLocal() const;
	void setLocal(std::string value);
};



#endif // SPAMFILTERUSERS_H
