#ifndef MAILCONTENTFILTER_H
#define MAILCONTENTFILTER_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class MailContentFilter;
typedef shared_ptr<MailContentFilter> MailContentFilterPtr;
typedef vector<MailContentFilterPtr> MailContentFilterList;

class MailContentFilter
{
	long long content_filter_id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	int server_id;
	std::string type;
	std::string pattern;
	std::string data;
	std::string action;
	std::string active;
public:
	MailContentFilter();
	MailContentFilter(long long content_filter_id);
	void init();
	long long getContentFilterId() const;
	void setContentFilterId(long long value);
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
	std::string getType() const;
	void setType(std::string value);
	std::string getPattern() const;
	void setPattern(std::string value);
	std::string getData() const;
	void setData(std::string value);
	std::string getAction() const;
	void setAction(std::string value);
	std::string getActive() const;
	void setActive(std::string value);
};



#endif // MAILCONTENTFILTER_H
