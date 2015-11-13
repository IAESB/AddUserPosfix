#include "syslog.h"

SysLog::SysLog(){
	init();
}
SysLog::SysLog(long long syslog_id)
{
	init();
	this->syslog_id = syslog_id;
}

void SysLog::init()
{
}
long long SysLog::getSyslogId() const
{
	return syslog_id;
}
void SysLog::setSyslogId(long long value)
{
	syslog_id = value;
}
long long SysLog::getServerId() const
{
	return server_id;
}
void SysLog::setServerId(long long value)
{
	server_id = value;
}
long long SysLog::getDatalogId() const
{
	return datalog_id;
}
void SysLog::setDatalogId(long long value)
{
	datalog_id = value;
}
int SysLog::getLoglevel() const
{
	return loglevel;
}
void SysLog::setLoglevel(int value)
{
	loglevel = value;
}
long long SysLog::getTstamp() const
{
	return tstamp;
}
void SysLog::setTstamp(long long value)
{
	tstamp = value;
}
std::string SysLog::getMessage() const
{
	return message;
}
void SysLog::setMessage(std::string value)
{
	message = value;
}

