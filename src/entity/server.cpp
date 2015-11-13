#include "server.h"

Server::Server(){
	init();
}
Server::Server(long long server_id)
{
	init();
	this->server_id = server_id;
}

void Server::init()
{
}
long long Server::getServerId() const
{
	return server_id;
}
void Server::setServerId(long long value)
{
	server_id = value;
}
long long Server::getSysUserid() const
{
	return sys_userid;
}
void Server::setSysUserid(long long value)
{
	sys_userid = value;
}
long long Server::getSysGroupid() const
{
	return sys_groupid;
}
void Server::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string Server::getSysPermUser() const
{
	return sys_perm_user;
}
void Server::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string Server::getSysPermGroup() const
{
	return sys_perm_group;
}
void Server::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string Server::getSysPermOther() const
{
	return sys_perm_other;
}
void Server::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
std::string Server::getServerName() const
{
	return server_name;
}
void Server::setServerName(std::string value)
{
	server_name = value;
}
int Server::getMailServer() const
{
	return mail_server;
}
void Server::setMailServer(int value)
{
	mail_server = value;
}
int Server::getWebServer() const
{
	return web_server;
}
void Server::setWebServer(int value)
{
	web_server = value;
}
int Server::getDnsServer() const
{
	return dns_server;
}
void Server::setDnsServer(int value)
{
	dns_server = value;
}
int Server::getFileServer() const
{
	return file_server;
}
void Server::setFileServer(int value)
{
	file_server = value;
}
int Server::getDbServer() const
{
	return db_server;
}
void Server::setDbServer(int value)
{
	db_server = value;
}
int Server::getVserverServer() const
{
	return vserver_server;
}
void Server::setVserverServer(int value)
{
	vserver_server = value;
}
int Server::getProxyServer() const
{
	return proxy_server;
}
void Server::setProxyServer(int value)
{
	proxy_server = value;
}
int Server::getFirewallServer() const
{
	return firewall_server;
}
void Server::setFirewallServer(int value)
{
	firewall_server = value;
}
std::string Server::getConfig() const
{
	return config;
}
void Server::setConfig(std::string value)
{
	config = value;
}
unsigned long long Server::getUpdated() const
{
	return updated;
}
void Server::setUpdated(unsigned long long value)
{
	updated = value;
}
long long Server::getMirrorServerId() const
{
	return mirror_server_id;
}
void Server::setMirrorServerId(long long value)
{
	mirror_server_id = value;
}
long long Server::getDbversion() const
{
	return dbversion;
}
void Server::setDbversion(long long value)
{
	dbversion = value;
}
int Server::getActive() const
{
	return active;
}
void Server::setActive(int value)
{
	active = value;
}

