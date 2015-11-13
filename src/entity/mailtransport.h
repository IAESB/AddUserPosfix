#ifndef MAILTRANSPORT_H
#define MAILTRANSPORT_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class MailTransport;
typedef shared_ptr<MailTransport> MailTransportPtr;
typedef vector<MailTransportPtr> MailTransportList;

class MailTransport
{
	long long transport_id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	long long server_id; //key: MUL
	std::string domain;
	std::string transport;
	long long sort_order;
	std::string active;
public:
	MailTransport();
	MailTransport(long long transport_id);
	void init();
	long long getTransportId() const;
	void setTransportId(long long value);
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
	std::string getTransport() const;
	void setTransport(std::string value);
	long long getSortOrder() const;
	void setSortOrder(long long value);
	std::string getActive() const;
	void setActive(std::string value);
};



#endif // MAILTRANSPORT_H
