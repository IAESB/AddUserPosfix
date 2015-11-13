#ifndef MAILDOMAIN_H
#define MAILDOMAIN_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class MailDomain;
typedef shared_ptr<MailDomain> MailDomainPtr;
typedef vector<MailDomainPtr> MailDomainList;

class MailDomain
{
	long long domain_id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	long long server_id; //key: MUL
	std::string domain; //key: MUL
	std::string dkim;
	std::string dkim_selector;
	std::string dkim_private;
	std::string dkim_public;
	std::string active;
public:
	MailDomain();
	MailDomain(long long domain_id);
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
	long long getServerId() const;
	void setServerId(long long value);
	std::string getDomain() const;
	void setDomain(std::string value);
	std::string getDkim() const;
	void setDkim(std::string value);
	std::string getDkimSelector() const;
	void setDkimSelector(std::string value);
	std::string getDkimPrivate() const;
	void setDkimPrivate(std::string value);
	std::string getDkimPublic() const;
	void setDkimPublic(std::string value);
	std::string getActive() const;
	void setActive(std::string value);
};



#endif // MAILDOMAIN_H
