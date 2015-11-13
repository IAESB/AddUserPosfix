#ifndef DNSSLAVE_H
#define DNSSLAVE_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class DnsSlave;
typedef shared_ptr<DnsSlave> DnsSlavePtr;
typedef vector<DnsSlavePtr> DnsSlaveList;

class DnsSlave
{
	long long id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	int server_id;
	std::string origin; //key: MUL
	std::string ns;
	std::string active; //key: MUL
	std::string xfer;
public:
	DnsSlave();
	DnsSlave(long long id);
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
	int getServerId() const;
	void setServerId(int value);
	std::string getOrigin() const;
	void setOrigin(std::string value);
	std::string getNs() const;
	void setNs(std::string value);
	std::string getActive() const;
	void setActive(std::string value);
	std::string getXfer() const;
	void setXfer(std::string value);
};



#endif // DNSSLAVE_H
