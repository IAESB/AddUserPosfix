#ifndef DNSTEMPLATE_H
#define DNSTEMPLATE_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class DnsTemplate;
typedef shared_ptr<DnsTemplate> DnsTemplatePtr;
typedef vector<DnsTemplatePtr> DnsTemplateList;

class DnsTemplate
{
	long long template_id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	std::string name;
	std::string fields;
	std::string template_;
	std::string visible;
public:
	DnsTemplate();
	DnsTemplate(long long template_id);
	void init();
	long long getTemplateId() const;
	void setTemplateId(long long value);
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
	std::string getName() const;
	void setName(std::string value);
	std::string getFields() const;
	void setFields(std::string value);
	std::string getTemplate() const;
	void setTemplate(std::string value);
	std::string getVisible() const;
	void setVisible(std::string value);
};



#endif // DNSTEMPLATE_H
