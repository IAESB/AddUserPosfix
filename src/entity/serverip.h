#ifndef SERVERIP_H
#define SERVERIP_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class ServerIp;
typedef shared_ptr<ServerIp> ServerIpPtr;
typedef vector<ServerIpPtr> ServerIpList;

class ServerIp
{
	long long server_ip_id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	long long server_id;
	long long client_id;
	std::string ip_type;
	std::string ip_address;
	std::string virtualhost;
	std::string virtualhost_port;
public:
	ServerIp();
	ServerIp(long long server_ip_id);
	void init();
	long long getServerIpId() const;
	void setServerIpId(long long value);
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
	long long getClientId() const;
	void setClientId(long long value);
	std::string getIpType() const;
	void setIpType(std::string value);
	std::string getIpAddress() const;
	void setIpAddress(std::string value);
	std::string getVirtualhost() const;
	void setVirtualhost(std::string value);
	std::string getVirtualhostPort() const;
	void setVirtualhostPort(std::string value);
};



#endif // SERVERIP_H
