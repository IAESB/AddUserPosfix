#include "sysdatalog.h"

SysDatalog::SysDatalog(){
	init();
}
SysDatalog::SysDatalog(long long datalog_id)
{
	init();
	this->datalog_id = datalog_id;
}

void SysDatalog::init()
{
}
long long SysDatalog::getDatalogId() const
{
	return datalog_id;
}
void SysDatalog::setDatalogId(long long value)
{
	datalog_id = value;
}
long long SysDatalog::getServerId() const
{
	return server_id;
}
void SysDatalog::setServerId(long long value)
{
	server_id = value;
}
std::string SysDatalog::getDbtable() const
{
	return dbtable;
}
void SysDatalog::setDbtable(std::string value)
{
	dbtable = value;
}
std::string SysDatalog::getDbidx() const
{
	return dbidx;
}
void SysDatalog::setDbidx(std::string value)
{
	dbidx = value;
}
std::string SysDatalog::getAction() const
{
	return action;
}
void SysDatalog::setAction(std::string value)
{
	action = value;
}
int SysDatalog::getTstamp() const
{
	return tstamp;
}
void SysDatalog::setTstamp(int value)
{
	tstamp = value;
}
std::string SysDatalog::getUser() const
{
	return user;
}
void SysDatalog::setUser(std::string value)
{
	user = value;
}
std::string SysDatalog::getData() const
{
	return data;
}
void SysDatalog::setData(std::string value)
{
	data = value;
}
std::string SysDatalog::getStatus() const
{
	return status;
}
void SysDatalog::setStatus(std::string value)
{
	status = value;
}
std::string SysDatalog::getError() const
{
	return error;
}
void SysDatalog::setError(std::string value)
{
	error = value;
}

