#include "sysremoteaction.h"

SysRemoteaction::SysRemoteaction(){
	init();
}
SysRemoteaction::SysRemoteaction(long long action_id)
{
	init();
	this->action_id = action_id;
}

void SysRemoteaction::init()
{
}
long long SysRemoteaction::getActionId() const
{
	return action_id;
}
void SysRemoteaction::setActionId(long long value)
{
	action_id = value;
}
long long SysRemoteaction::getServerId() const
{
	return server_id;
}
void SysRemoteaction::setServerId(long long value)
{
	server_id = value;
}
int SysRemoteaction::getTstamp() const
{
	return tstamp;
}
void SysRemoteaction::setTstamp(int value)
{
	tstamp = value;
}
std::string SysRemoteaction::getActionType() const
{
	return action_type;
}
void SysRemoteaction::setActionType(std::string value)
{
	action_type = value;
}
std::string SysRemoteaction::getActionParam() const
{
	return action_param;
}
void SysRemoteaction::setActionParam(std::string value)
{
	action_param = value;
}
std::string SysRemoteaction::getActionState() const
{
	return action_state;
}
void SysRemoteaction::setActionState(std::string value)
{
	action_state = value;
}
std::string SysRemoteaction::getResponse() const
{
	return response;
}
void SysRemoteaction::setResponse(std::string value)
{
	response = value;
}

