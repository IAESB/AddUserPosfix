#ifndef SYSLOG_H
#define SYSLOG_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class SysLog;
typedef shared_ptr<SysLog> SysLogPtr;
typedef vector<SysLogPtr> SysLogList;

class SysLog
{
	long long syslog_id; //key: PRI
	long long server_id;
	long long datalog_id;
	int loglevel;
	long long tstamp;
	std::string message;
public:
	SysLog();
	SysLog(long long syslog_id);
	void init();
	long long getSyslogId() const;
	void setSyslogId(long long value);
	long long getServerId() const;
	void setServerId(long long value);
	long long getDatalogId() const;
	void setDatalogId(long long value);
	int getLoglevel() const;
	void setLoglevel(int value);
	long long getTstamp() const;
	void setTstamp(long long value);
	std::string getMessage() const;
	void setMessage(std::string value);
};



#endif // SYSLOG_H
