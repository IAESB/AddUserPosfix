#include "spamfilterwblist.h"

SpamfilterWblist::SpamfilterWblist(){
	init();
}
SpamfilterWblist::SpamfilterWblist(long long wblist_id)
{
	init();
	this->wblist_id = wblist_id;
}

void SpamfilterWblist::init()
{
}
long long SpamfilterWblist::getWblistId() const
{
	return wblist_id;
}
void SpamfilterWblist::setWblistId(long long value)
{
	wblist_id = value;
}
long long SpamfilterWblist::getSysUserid() const
{
	return sys_userid;
}
void SpamfilterWblist::setSysUserid(long long value)
{
	sys_userid = value;
}
long long SpamfilterWblist::getSysGroupid() const
{
	return sys_groupid;
}
void SpamfilterWblist::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string SpamfilterWblist::getSysPermUser() const
{
	return sys_perm_user;
}
void SpamfilterWblist::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string SpamfilterWblist::getSysPermGroup() const
{
	return sys_perm_group;
}
void SpamfilterWblist::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string SpamfilterWblist::getSysPermOther() const
{
	return sys_perm_other;
}
void SpamfilterWblist::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
long long SpamfilterWblist::getServerId() const
{
	return server_id;
}
void SpamfilterWblist::setServerId(long long value)
{
	server_id = value;
}
std::string SpamfilterWblist::getWb() const
{
	return wb;
}
void SpamfilterWblist::setWb(std::string value)
{
	wb = value;
}
long long SpamfilterWblist::getRid() const
{
	return rid;
}
void SpamfilterWblist::setRid(long long value)
{
	rid = value;
}
std::string SpamfilterWblist::getEmail() const
{
	return email;
}
void SpamfilterWblist::setEmail(std::string value)
{
	email = value;
}
int SpamfilterWblist::getPriority() const
{
	return priority;
}
void SpamfilterWblist::setPriority(int value)
{
	priority = value;
}
std::string SpamfilterWblist::getActive() const
{
	return active;
}
void SpamfilterWblist::setActive(std::string value)
{
	active = value;
}

