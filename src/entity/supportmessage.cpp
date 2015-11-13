#include "supportmessage.h"

SupportMessage::SupportMessage(){
	init();
}
SupportMessage::SupportMessage(long long support_message_id)
{
	init();
	this->support_message_id = support_message_id;
}

void SupportMessage::init()
{
}
long long SupportMessage::getSupportMessageId() const
{
	return support_message_id;
}
void SupportMessage::setSupportMessageId(long long value)
{
	support_message_id = value;
}
long long SupportMessage::getSysUserid() const
{
	return sys_userid;
}
void SupportMessage::setSysUserid(long long value)
{
	sys_userid = value;
}
long long SupportMessage::getSysGroupid() const
{
	return sys_groupid;
}
void SupportMessage::setSysGroupid(long long value)
{
	sys_groupid = value;
}
std::string SupportMessage::getSysPermUser() const
{
	return sys_perm_user;
}
void SupportMessage::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string SupportMessage::getSysPermGroup() const
{
	return sys_perm_group;
}
void SupportMessage::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string SupportMessage::getSysPermOther() const
{
	return sys_perm_other;
}
void SupportMessage::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
long long SupportMessage::getRecipientId() const
{
	return recipient_id;
}
void SupportMessage::setRecipientId(long long value)
{
	recipient_id = value;
}
long long SupportMessage::getSenderId() const
{
	return sender_id;
}
void SupportMessage::setSenderId(long long value)
{
	sender_id = value;
}
std::string SupportMessage::getSubject() const
{
	return subject;
}
void SupportMessage::setSubject(std::string value)
{
	subject = value;
}
std::string SupportMessage::getMessage() const
{
	return message;
}
void SupportMessage::setMessage(std::string value)
{
	message = value;
}
int SupportMessage::getTstamp() const
{
	return tstamp;
}
void SupportMessage::setTstamp(int value)
{
	tstamp = value;
}

