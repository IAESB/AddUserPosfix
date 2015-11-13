#ifndef SPAMFILTERWBLIST_H
#define SPAMFILTERWBLIST_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class SpamfilterWblist;
typedef shared_ptr<SpamfilterWblist> SpamfilterWblistPtr;
typedef vector<SpamfilterWblistPtr> SpamfilterWblistList;

class SpamfilterWblist
{
	long long wblist_id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	long long server_id;
	std::string wb;
	long long rid;
	std::string email;
	int priority;
	std::string active;
public:
	SpamfilterWblist();
	SpamfilterWblist(long long wblist_id);
	void init();
	long long getWblistId() const;
	void setWblistId(long long value);
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
	std::string getWb() const;
	void setWb(std::string value);
	long long getRid() const;
	void setRid(long long value);
	std::string getEmail() const;
	void setEmail(std::string value);
	int getPriority() const;
	void setPriority(int value);
	std::string getActive() const;
	void setActive(std::string value);
};



#endif // SPAMFILTERWBLIST_H
