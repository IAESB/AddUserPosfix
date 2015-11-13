#ifndef SYSSESSION_H
#define SYSSESSION_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class SysSession;
typedef shared_ptr<SysSession> SysSessionPtr;
typedef vector<SysSessionPtr> SysSessionList;

class SysSession
{
	std::string session_id; //key: PRI
	tm date_created;
	tm last_updated; //key: MUL
	std::string permanent;
	std::string session_data;
public:
	SysSession();
	SysSession(std::string session_id);
	void init();
	std::string getSessionId() const;
	void setSessionId(std::string value);
	tm getDateCreated() const;
	void setDateCreated(tm value);
	tm getLastUpdated() const;
	void setLastUpdated(tm value);
	std::string getPermanent() const;
	void setPermanent(std::string value);
	std::string getSessionData() const;
	void setSessionData(std::string value);
};



#endif // SYSSESSION_H
