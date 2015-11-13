#include "sysdbsync.h"

SysDbsync::SysDbsync(){
	init();
}
SysDbsync::SysDbsync(long long id)
{
	init();
	this->id = id;
}

void SysDbsync::init()
{
}
long long SysDbsync::getId() const
{
	return id;
}
void SysDbsync::setId(long long value)
{
	id = value;
}
std::string SysDbsync::getJobname() const
{
	return jobname;
}
void SysDbsync::setJobname(std::string value)
{
	jobname = value;
}
long long SysDbsync::getSyncIntervalMinutes() const
{
	return sync_interval_minutes;
}
void SysDbsync::setSyncIntervalMinutes(long long value)
{
	sync_interval_minutes = value;
}
std::string SysDbsync::getDbType() const
{
	return db_type;
}
void SysDbsync::setDbType(std::string value)
{
	db_type = value;
}
std::string SysDbsync::getDbHost() const
{
	return db_host;
}
void SysDbsync::setDbHost(std::string value)
{
	db_host = value;
}
std::string SysDbsync::getDbName() const
{
	return db_name;
}
void SysDbsync::setDbName(std::string value)
{
	db_name = value;
}
std::string SysDbsync::getDbUsername() const
{
	return db_username;
}
void SysDbsync::setDbUsername(std::string value)
{
	db_username = value;
}
std::string SysDbsync::getDbPassword() const
{
	return db_password;
}
void SysDbsync::setDbPassword(std::string value)
{
	db_password = value;
}
std::string SysDbsync::getDbTables() const
{
	return db_tables;
}
void SysDbsync::setDbTables(std::string value)
{
	db_tables = value;
}
long long SysDbsync::getEmptyDatalog() const
{
	return empty_datalog;
}
void SysDbsync::setEmptyDatalog(long long value)
{
	empty_datalog = value;
}
long long SysDbsync::getSyncDatalogExternal() const
{
	return sync_datalog_external;
}
void SysDbsync::setSyncDatalogExternal(long long value)
{
	sync_datalog_external = value;
}
int SysDbsync::getActive() const
{
	return active;
}
void SysDbsync::setActive(int value)
{
	active = value;
}
long long SysDbsync::getLastDatalogId() const
{
	return last_datalog_id;
}
void SysDbsync::setLastDatalogId(long long value)
{
	last_datalog_id = value;
}

