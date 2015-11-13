#include "firewall.h"

Firewall::Firewall(){
	init();
}
Firewall::Firewall(long long firewall_id)
{
	init();
	this->firewall_id = firewall_id;
}

void Firewall::init()
{
}
long long Firewall::getFirewallId() const
{
	return firewall_id;
}
void Firewall::setFirewallId(long long value)
{
	firewall_id = value;
}
long long Firewall::getSysUserid() const
{
	return sys_userid;
}
void Firewall::setSysUserid(long long value)
{
	sys_userid = value;
}
long long Firewall::getSysGroupid() const
{
	return sys_groupid;
}
void Firewall::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string Firewall::getSysPermUser() const
{
	return sys_perm_user;
}
void Firewall::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string Firewall::getSysPermGroup() const
{
	return sys_perm_group;
}
void Firewall::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string Firewall::getSysPermOther() const
{
	return sys_perm_other;
}
void Firewall::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
long long Firewall::getServerId() const
{
	return server_id;
}
void Firewall::setServerId(long long value)
{
	server_id = value;
}
std::string Firewall::getTcpPort() const
{
	return tcp_port;
}
void Firewall::setTcpPort(std::string value)
{
	tcp_port = value;
}
std::string Firewall::getUdpPort() const
{
	return udp_port;
}
void Firewall::setUdpPort(std::string value)
{
	udp_port = value;
}
std::string Firewall::getActive() const
{
	return active;
}
void Firewall::setActive(std::string value)
{
	active = value;
}

