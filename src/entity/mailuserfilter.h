#ifndef MAILUSERFILTER_H
#define MAILUSERFILTER_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class MailUserFilter;
typedef shared_ptr<MailUserFilter> MailUserFilterPtr;
typedef vector<MailUserFilterPtr> MailUserFilterList;

class MailUserFilter
{
	long long filter_id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	long long mailuser_id;
	std::string rulename;
	std::string source;
	std::string searchterm;
	std::string op;
	std::string action;
	std::string target;
	std::string active;
public:
	MailUserFilter();
	MailUserFilter(long long filter_id);
	void init();
	long long getFilterId() const;
	void setFilterId(long long value);
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
	long long getMailuserId() const;
	void setMailuserId(long long value);
	std::string getRulename() const;
	void setRulename(std::string value);
	std::string getSource() const;
	void setSource(std::string value);
	std::string getSearchterm() const;
	void setSearchterm(std::string value);
	std::string getOp() const;
	void setOp(std::string value);
	std::string getAction() const;
	void setAction(std::string value);
	std::string getTarget() const;
	void setTarget(std::string value);
	std::string getActive() const;
	void setActive(std::string value);
};



#endif // MAILUSERFILTER_H
