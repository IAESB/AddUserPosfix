#ifndef SYSDBSYNC_H
#define SYSDBSYNC_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class SysDbsync;
typedef shared_ptr<SysDbsync> SysDbsyncPtr;
typedef vector<SysDbsyncPtr> SysDbsyncList;

class SysDbsync
{
	long long id; //key: PRI
	std::string jobname;
	long long sync_interval_minutes;
	std::string db_type;
	std::string db_host;
	std::string db_name;
	std::string db_username;
	std::string db_password;
	std::string db_tables;
	long long empty_datalog;
	long long sync_datalog_external;
	int active;
	long long last_datalog_id; //key: MUL
public:
	SysDbsync();
	SysDbsync(long long id);
	void init();
	long long getId() const;
	void setId(long long value);
	std::string getJobname() const;
	void setJobname(std::string value);
	long long getSyncIntervalMinutes() const;
	void setSyncIntervalMinutes(long long value);
	std::string getDbType() const;
	void setDbType(std::string value);
	std::string getDbHost() const;
	void setDbHost(std::string value);
	std::string getDbName() const;
	void setDbName(std::string value);
	std::string getDbUsername() const;
	void setDbUsername(std::string value);
	std::string getDbPassword() const;
	void setDbPassword(std::string value);
	std::string getDbTables() const;
	void setDbTables(std::string value);
	long long getEmptyDatalog() const;
	void setEmptyDatalog(long long value);
	long long getSyncDatalogExternal() const;
	void setSyncDatalogExternal(long long value);
	int getActive() const;
	void setActive(int value);
	long long getLastDatalogId() const;
	void setLastDatalogId(long long value);
};



#endif // SYSDBSYNC_H
