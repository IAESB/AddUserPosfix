#ifndef SYSDATALOG_H
#define SYSDATALOG_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class SysDatalog;
typedef shared_ptr<SysDatalog> SysDatalogPtr;
typedef vector<SysDatalogPtr> SysDatalogList;

class SysDatalog
{
	long long datalog_id; //key: PRI
	long long server_id; //key: MUL
	std::string dbtable;
	std::string dbidx;
	std::string action;
	int tstamp;
	std::string user;
	std::string data;
	std::string status;
	std::string error;
public:
	SysDatalog();
	SysDatalog(long long datalog_id);
	void init();
	long long getDatalogId() const;
	void setDatalogId(long long value);
	long long getServerId() const;
	void setServerId(long long value);
	std::string getDbtable() const;
	void setDbtable(std::string value);
	std::string getDbidx() const;
	void setDbidx(std::string value);
	std::string getAction() const;
	void setAction(std::string value);
	int getTstamp() const;
	void setTstamp(int value);
	std::string getUser() const;
	void setUser(std::string value);
	std::string getData() const;
	void setData(std::string value);
	std::string getStatus() const;
	void setStatus(std::string value);
	std::string getError() const;
	void setError(std::string value);
};



#endif // SYSDATALOG_H
