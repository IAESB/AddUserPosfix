#include "clientcircle.h"

ClientCircle::ClientCircle(){
	init();
}
ClientCircle::ClientCircle(int circle_id)
{
	init();
	this->circle_id = circle_id;
}

void ClientCircle::init()
{
}
int ClientCircle::getCircleId() const
{
	return circle_id;
}
void ClientCircle::setCircleId(int value)
{
	circle_id = value;
}
int ClientCircle::getSysUserid() const
{
	return sys_userid;
}
void ClientCircle::setSysUserid(int value)
{
	sys_userid = value;
}
int ClientCircle::getSysGroupid() const
{
	return sys_groupid;
}
void ClientCircle::setSysGroupid(int value)
{
	sys_groupid = value;
}
std::string ClientCircle::getSysPermUser() const
{
	return sys_perm_user;
}
void ClientCircle::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string ClientCircle::getSysPermGroup() const
{
	return sys_perm_group;
}
void ClientCircle::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string ClientCircle::getSysPermOther() const
{
	return sys_perm_other;
}
void ClientCircle::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
std::string ClientCircle::getCircleName() const
{
	return circle_name;
}
void ClientCircle::setCircleName(std::string value)
{
	circle_name = value;
}
std::string ClientCircle::getClientIds() const
{
	return client_ids;
}
void ClientCircle::setClientIds(std::string value)
{
	client_ids = value;
}
std::string ClientCircle::getDescription() const
{
	return description;
}
void ClientCircle::setDescription(std::string value)
{
	description = value;
}
std::string ClientCircle::getActive() const
{
	return active;
}
void ClientCircle::setActive(std::string value)
{
	active = value;
}

