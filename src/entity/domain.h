#ifndef DOMAIN_H
#define DOMAIN_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Domain;
typedef shared_ptr<Domain> DomainPtr;
typedef vector<DomainPtr> DomainList;

class Domain
{
	long long domain_id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	std::string domain; //key: UNI
public:
	Domain();
	Domain(long long domain_id);
	void init();
	long long getDomainId() const;
	void setDomainId(long long value);
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
	std::string getDomain() const;
	void setDomain(std::string value);
};



#endif // DOMAIN_H
