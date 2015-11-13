#ifndef MAILFORWARDING_H
#define MAILFORWARDING_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class MailForwarding;
typedef shared_ptr<MailForwarding> MailForwardingPtr;
typedef vector<MailForwardingPtr> MailForwardingList;

class MailForwarding
{
	long long forwarding_id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	long long server_id; //key: MUL
	std::string source;
	std::string destination;
	std::string type; //key: MUL
	std::string active;
public:
	MailForwarding();
	MailForwarding(long long forwarding_id);
	void init();
	long long getForwardingId() const;
	void setForwardingId(long long value);
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
	std::string getSource() const;
	void setSource(std::string value);
	std::string getDestination() const;
	void setDestination(std::string value);
	std::string getType() const;
	void setType(std::string value);
	std::string getActive() const;
	void setActive(std::string value);
};



#endif // MAILFORWARDING_H
