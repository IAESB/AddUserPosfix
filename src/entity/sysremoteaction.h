#ifndef SYSREMOTEACTION_H
#define SYSREMOTEACTION_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class SysRemoteaction;
typedef shared_ptr<SysRemoteaction> SysRemoteactionPtr;
typedef vector<SysRemoteactionPtr> SysRemoteactionList;

class SysRemoteaction
{
	long long action_id; //key: PRI
	long long server_id; //key: MUL
	int tstamp;
	std::string action_type;
	std::string action_param;
	std::string action_state;
	std::string response;
public:
	SysRemoteaction();
	SysRemoteaction(long long action_id);
	void init();
	long long getActionId() const;
	void setActionId(long long value);
	long long getServerId() const;
	void setServerId(long long value);
	int getTstamp() const;
	void setTstamp(int value);
	std::string getActionType() const;
	void setActionType(std::string value);
	std::string getActionParam() const;
	void setActionParam(std::string value);
	std::string getActionState() const;
	void setActionState(std::string value);
	std::string getResponse() const;
	void setResponse(std::string value);
};



#endif // SYSREMOTEACTION_H
