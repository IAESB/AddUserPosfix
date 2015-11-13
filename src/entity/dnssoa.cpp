#include "dnssoa.h"

DnsSoa::DnsSoa(){
	init();
}
DnsSoa::DnsSoa(long long id)
{
	init();
	this->id = id;
}

void DnsSoa::init()
{
}
long long DnsSoa::getId() const
{
	return id;
}
void DnsSoa::setId(long long value)
{
	id = value;
}
long long DnsSoa::getSysUserid() const
{
	return sys_userid;
}
void DnsSoa::setSysUserid(long long value)
{
	sys_userid = value;
}
long long DnsSoa::getSysGroupid() const
{
	return sys_groupid;
}
void DnsSoa::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string DnsSoa::getSysPermUser() const
{
	return sys_perm_user;
}
void DnsSoa::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string DnsSoa::getSysPermGroup() const
{
	return sys_perm_group;
}
void DnsSoa::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string DnsSoa::getSysPermOther() const
{
	return sys_perm_other;
}
void DnsSoa::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
int DnsSoa::getServerId() const
{
	return server_id;
}
void DnsSoa::setServerId(int value)
{
	server_id = value;
}
std::string DnsSoa::getOrigin() const
{
	return origin;
}
void DnsSoa::setOrigin(std::string value)
{
	origin = value;
}
std::string DnsSoa::getNs() const
{
	return ns;
}
void DnsSoa::setNs(std::string value)
{
	ns = value;
}
std::string DnsSoa::getMbox() const
{
	return mbox;
}
void DnsSoa::setMbox(std::string value)
{
	mbox = value;
}
long long DnsSoa::getSerial() const
{
	return serial;
}
void DnsSoa::setSerial(long long value)
{
	serial = value;
}
long long DnsSoa::getRefresh() const
{
	return refresh;
}
void DnsSoa::setRefresh(long long value)
{
	refresh = value;
}
long long DnsSoa::getRetry() const
{
	return retry;
}
void DnsSoa::setRetry(long long value)
{
	retry = value;
}
long long DnsSoa::getExpire() const
{
	return expire;
}
void DnsSoa::setExpire(long long value)
{
	expire = value;
}
long long DnsSoa::getMinimum() const
{
	return minimum;
}
void DnsSoa::setMinimum(long long value)
{
	minimum = value;
}
long long DnsSoa::getTtl() const
{
	return ttl;
}
void DnsSoa::setTtl(long long value)
{
	ttl = value;
}
std::string DnsSoa::getActive() const
{
	return active;
}
void DnsSoa::setActive(std::string value)
{
	active = value;
}
std::string DnsSoa::getXfer() const
{
	return xfer;
}
void DnsSoa::setXfer(std::string value)
{
	xfer = value;
}
std::string DnsSoa::getAlsoNotify() const
{
	return also_notify;
}
void DnsSoa::setAlsoNotify(std::string value)
{
	also_notify = value;
}
std::string DnsSoa::getUpdateAcl() const
{
	return update_acl;
}
void DnsSoa::setUpdateAcl(std::string value)
{
	update_acl = value;
}

