#ifndef FIREWALL_H
#define FIREWALL_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Firewall;
typedef shared_ptr<Firewall> FirewallPtr;
typedef vector<FirewallPtr> FirewallList;

class Firewall
{
	long long firewall_id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	long long server_id;
	std::string tcp_port;
	std::string udp_port;
	std::string active;
public:
	Firewall();
	Firewall(long long firewall_id);
	void init();
	long long getFirewallId() const;
	void setFirewallId(long long value);
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
	std::string getTcpPort() const;
	void setTcpPort(std::string value);
	std::string getUdpPort() const;
	void setUdpPort(std::string value);
	std::string getActive() const;
	void setActive(std::string value);
};



#endif // FIREWALL_H
