#include "serverip.h"

ServerIp::ServerIp(){
	init();
}
ServerIp::ServerIp(long long server_ip_id)
{
	init();
	this->server_ip_id = server_ip_id;
}

void ServerIp::init()
{
}
long long ServerIp::getServerIpId() const
{
	return server_ip_id;
}
void ServerIp::setServerIpId(long long value)
{
	server_ip_id = value;
}
long long ServerIp::getSysUserid() const
{
	return sys_userid;
}
void ServerIp::setSysUserid(long long value)
{
	sys_userid = value;
}
long long ServerIp::getSysGroupid() const
{
	return sys_groupid;
}
void ServerIp::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string ServerIp::getSysPermUser() const
{
	return sys_perm_user;
}
void ServerIp::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string ServerIp::getSysPermGroup() const
{
	return sys_perm_group;
}
void ServerIp::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string ServerIp::getSysPermOther() const
{
	return sys_perm_other;
}
void ServerIp::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
long long ServerIp::getServerId() const
{
	return server_id;
}
void ServerIp::setServerId(long long value)
{
	server_id = value;
}
long long ServerIp::getClientId() const
{
	return client_id;
}
void ServerIp::setClientId(long long value)
{
	client_id = value;
}
std::string ServerIp::getIpType() const
{
	return ip_type;
}
void ServerIp::setIpType(std::string value)
{
	ip_type = value;
}
std::string ServerIp::getIpAddress() const
{
	return ip_address;
}
void ServerIp::setIpAddress(std::string value)
{
	ip_address = value;
}
std::string ServerIp::getVirtualhost() const
{
	return virtualhost;
}
void ServerIp::setVirtualhost(std::string value)
{
	virtualhost = value;
}
std::string ServerIp::getVirtualhostPort() const
{
	return virtualhost_port;
}
void ServerIp::setVirtualhostPort(std::string value)
{
	virtualhost_port = value;
}

