#ifndef REMOTESESSION_H
#define REMOTESESSION_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class RemoteSession;
typedef shared_ptr<RemoteSession> RemoteSessionPtr;
typedef vector<RemoteSessionPtr> RemoteSessionList;

class RemoteSession
{
	std::string remote_session; //key: PRI
	long long remote_userid;
	std::string remote_functions;
	int client_login;
	long long tstamp;
public:
	RemoteSession();
	RemoteSession(std::string remote_session);
	void init();
	std::string getRemoteSession() const;
	void setRemoteSession(std::string value);
	long long getRemoteUserid() const;
	void setRemoteUserid(long long value);
	std::string getRemoteFunctions() const;
	void setRemoteFunctions(std::string value);
	int getClientLogin() const;
	void setClientLogin(int value);
	long long getTstamp() const;
	void setTstamp(long long value);
};



#endif // REMOTESESSION_H
