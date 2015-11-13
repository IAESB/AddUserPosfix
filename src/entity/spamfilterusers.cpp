#include "spamfilterusers.h"

SpamfilterUsers::SpamfilterUsers(){
	init();
}
SpamfilterUsers::SpamfilterUsers(long long id)
{
	init();
	this->id = id;
}

void SpamfilterUsers::init()
{
}
long long SpamfilterUsers::getId() const
{
	return id;
}
void SpamfilterUsers::setId(long long value)
{
	id = value;
}
long long SpamfilterUsers::getSysUserid() const
{
	return sys_userid;
}
void SpamfilterUsers::setSysUserid(long long value)
{
	sys_userid = value;
}
long long SpamfilterUsers::getSysGroupid() const
{
	return sys_groupid;
}
void SpamfilterUsers::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string SpamfilterUsers::getSysPermUser() const
{
	return sys_perm_user;
}
void SpamfilterUsers::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string SpamfilterUsers::getSysPermGroup() const
{
	return sys_perm_group;
}
void SpamfilterUsers::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string SpamfilterUsers::getSysPermOther() const
{
	return sys_perm_other;
}
void SpamfilterUsers::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
long long SpamfilterUsers::getServerId() const
{
	return server_id;
}
void SpamfilterUsers::setServerId(long long value)
{
	server_id = value;
}
int SpamfilterUsers::getPriority() const
{
	return priority;
}
void SpamfilterUsers::setPriority(int value)
{
	priority = value;
}
long long SpamfilterUsers::getPolicyId() const
{
	return policy_id;
}
void SpamfilterUsers::setPolicyId(long long value)
{
	policy_id = value;
}
std::string SpamfilterUsers::getEmail() const
{
	return email;
}
void SpamfilterUsers::setEmail(std::string value)
{
	email = value;
}
std::string SpamfilterUsers::getFullname() const
{
	return fullname;
}
void SpamfilterUsers::setFullname(std::string value)
{
	fullname = value;
}
std::string SpamfilterUsers::getLocal() const
{
	return local;
}
void SpamfilterUsers::setLocal(std::string value)
{
	local = value;
}

