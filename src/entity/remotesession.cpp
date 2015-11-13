#include "remotesession.h"

RemoteSession::RemoteSession(){
	init();
}
RemoteSession::RemoteSession(std::string remote_session)
{
	init();
	this->remote_session = remote_session;
}

void RemoteSession::init()
{
}
std::string RemoteSession::getRemoteSession() const
{
	return remote_session;
}
void RemoteSession::setRemoteSession(std::string value)
{
	remote_session = value;
}
long long RemoteSession::getRemoteUserid() const
{
	return remote_userid;
}
void RemoteSession::setRemoteUserid(long long value)
{
	remote_userid = value;
}
std::string RemoteSession::getRemoteFunctions() const
{
	return remote_functions;
}
void RemoteSession::setRemoteFunctions(std::string value)
{
	remote_functions = value;
}
int RemoteSession::getClientLogin() const
{
	return client_login;
}
void RemoteSession::setClientLogin(int value)
{
	client_login = value;
}
long long RemoteSession::getTstamp() const
{
	return tstamp;
}
void RemoteSession::setTstamp(long long value)
{
	tstamp = value;
}

