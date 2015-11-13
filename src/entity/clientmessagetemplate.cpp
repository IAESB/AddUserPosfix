#include "clientmessagetemplate.h"

ClientMessageTemplate::ClientMessageTemplate(){
	init();
}
ClientMessageTemplate::ClientMessageTemplate(long long client_message_template_id)
{
	init();
	this->client_message_template_id = client_message_template_id;
}

void ClientMessageTemplate::init()
{
}
long long ClientMessageTemplate::getClientMessageTemplateId() const
{
	return client_message_template_id;
}
void ClientMessageTemplate::setClientMessageTemplateId(long long value)
{
	client_message_template_id = value;
}
int ClientMessageTemplate::getSysUserid() const
{
	return sys_userid;
}
void ClientMessageTemplate::setSysUserid(int value)
{
	sys_userid = value;
}
int ClientMessageTemplate::getSysGroupid() const
{
	return sys_groupid;
}
void ClientMessageTemplate::setSysGroupid(int value)
{
	sys_groupid = value;
}
std::string ClientMessageTemplate::getSysPermUser() const
{
	return sys_perm_user;
}
void ClientMessageTemplate::setSysPermUser(std::string value)
{
	sys_perm_user = value;
}
std::string ClientMessageTemplate::getSysPermGroup() const
{
	return sys_perm_group;
}
void ClientMessageTemplate::setSysPermGroup(std::string value)
{
	sys_perm_group = value;
}
std::string ClientMessageTemplate::getSysPermOther() const
{
	return sys_perm_other;
}
void ClientMessageTemplate::setSysPermOther(std::string value)
{
	sys_perm_other = value;
}
std::string ClientMessageTemplate::getTemplateType() const
{
	return template_type;
}
void ClientMessageTemplate::setTemplateType(std::string value)
{
	template_type = value;
}
std::string ClientMessageTemplate::getTemplateName() const
{
	return template_name;
}
void ClientMessageTemplate::setTemplateName(std::string value)
{
	template_name = value;
}
std::string ClientMessageTemplate::getSubject() const
{
	return subject;
}
void ClientMessageTemplate::setSubject(std::string value)
{
	subject = value;
}
std::string ClientMessageTemplate::getMessage() const
{
	return message;
}
void ClientMessageTemplate::setMessage(std::string value)
{
	message = value;
}

