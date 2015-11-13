#include "mailrelayrecipient.h"

MailRelayRecipient::MailRelayRecipient(){
	init();
}
MailRelayRecipient::MailRelayRecipient(long long relay_recipient_id)
{
	init();
	this->relay_recipient_id = relay_recipient_id;
}

void MailRelayRecipient::init()
{
}
long long MailRelayRecipient::getRelayRecipientId() const
{
	return relay_recipient_id;
}
void MailRelayRecipient::setRelayRecipientId(long long value)
{
	relay_recipient_id = value;
}
int MailRelayRecipient::getSysUserid() const
{
	return sys_userid;
}
void MailRelayRecipient::setSysUserid(int value)
{
	sys_userid = value;
}
int MailRelayRecipient::getSysGroupid() const
{
	return sys_groupid;
}
void MailRelayRecipient::setSysGroupid(int value)
{
	sys_groupid = value;
}
std::string MailRelayRecipient::getSysPermUser() const
{
	return sys_perm_user;
}
void MailRelayRecipient::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string MailRelayRecipient::getSysPermGroup() const
{
	return sys_perm_group;
}
void MailRelayRecipient::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string MailRelayRecipient::getSysPermOther() const
{
	return sys_perm_other;
}
void MailRelayRecipient::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
int MailRelayRecipient::getServerId() const
{
	return server_id;
}
void MailRelayRecipient::setServerId(int value)
{
	server_id = value;
}
std::string MailRelayRecipient::getSource() const
{
	return source;
}
void MailRelayRecipient::setSource(std::string value)
{
	source = value;
}
std::string MailRelayRecipient::getAccess() const
{
	return access;
}
void MailRelayRecipient::setAccess(std::string value)
{
	access = value;
}
std::string MailRelayRecipient::getActive() const
{
	return active;
}
void MailRelayRecipient::setActive(std::string value)
{
	active = value;
}

