#include "syssession.h"

SysSession::SysSession(){
	init();
}
SysSession::SysSession(std::string session_id)
{
	init();
	this->session_id = session_id;
}

void SysSession::init()
{
	date_created = {0};
	last_updated = {0};
}
std::string SysSession::getSessionId() const
{
	return session_id;
}
void SysSession::setSessionId(std::string value)
{
	session_id = value;
}
tm SysSession::getDateCreated() const
{
	return date_created;
}
void SysSession::setDateCreated(tm value)
{
	date_created = value;
}
tm SysSession::getLastUpdated() const
{
	return last_updated;
}
void SysSession::setLastUpdated(tm value)
{
	last_updated = value;
}
std::string SysSession::getPermanent() const
{
	return permanent;
}
void SysSession::setPermanent(std::string value)
{
	permanent = value;
}
std::string SysSession::getSessionData() const
{
	return session_data;
}
void SysSession::setSessionData(std::string value)
{
	session_data = value;
}

