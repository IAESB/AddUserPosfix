#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Server;
typedef shared_ptr<Server> ServerPtr;
typedef vector<ServerPtr> ServerList;

class Server
{
	long long server_id; //key: PRI
	long long sys_userid;
	long long sys_groupid;
	std::string sys_perm_user;
	std::string sys_perm_group;
	std::string sys_perm_other;
	std::string server_name;
	int mail_server;
	int web_server;
	int dns_server;
	int file_server;
	int db_server;
	int vserver_server;
	int proxy_server;
	int firewall_server;
	std::string config;
	unsigned long long updated;
	long long mirror_server_id;
	long long dbversion;
	int active;
public:
	Server();
	Server(long long server_id);
	void init();
	long long getServerId() const;
	void setServerId(long long value);
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
	std::string getServerName() const;
	void setServerName(std::string value);
	int getMailServer() const;
	void setMailServer(int value);
	int getWebServer() const;
	void setWebServer(int value);
	int getDnsServer() const;
	void setDnsServer(int value);
	int getFileServer() const;
	void setFileServer(int value);
	int getDbServer() const;
	void setDbServer(int value);
	int getVserverServer() const;
	void setVserverServer(int value);
	int getProxyServer() const;
	void setProxyServer(int value);
	int getFirewallServer() const;
	void setFirewallServer(int value);
	std::string getConfig() const;
	void setConfig(std::string value);
	unsigned long long getUpdated() const;
	void setUpdated(unsigned long long value);
	long long getMirrorServerId() const;
	void setMirrorServerId(long long value);
	long long getDbversion() const;
	void setDbversion(long long value);
	int getActive() const;
	void setActive(int value);
};



#endif // SERVER_H
