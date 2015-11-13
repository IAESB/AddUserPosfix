#include "syslogrepository.h"
#include "util.hpp"
SysLogRepository::SysLogRepository(soci::session& db) : dataBase(db)
{
}

SysLogPtr SysLogRepository::select(const SysLog& obj)
{
	soci::row row;
	SysLogPtr syslog(new SysLog);
	dataBase << "SELECT  sys_log.syslog_id as SysLog_syslog_id, sys_log.server_id as SysLog_server_id, sys_log.datalog_id as SysLog_datalog_id, sys_log.loglevel as SysLog_loglevel, sys_log.tstamp as SysLog_tstamp, sys_log.message as SysLog_message"
	" FROM sys_log "
	"WHERE sys_log.syslog_id = :SysLog_syslog_id", into(row), use(obj);
	if(!dataBase.got_data())
		syslog.reset();
	else
		type_conversion<SysLog>::from_base(row, i_ok, *syslog);
	return syslog;
}
SysLogList SysLogRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  sys_log.syslog_id as SysLog_syslog_id, sys_log.server_id as SysLog_server_id, sys_log.datalog_id as SysLog_datalog_id, sys_log.loglevel as SysLog_loglevel, sys_log.tstamp as SysLog_tstamp, sys_log.message as SysLog_message "
	" FROM sys_log" 
	<< (where.size()?" WHERE "+where:"");
	SysLogList syslogList;
	for(row& r: rs)
	{
		SysLogPtr syslog(new SysLog);
		type_conversion<SysLog>::from_base(r, i_ok, *syslog);
		syslogList.push_back(syslog);
	}
	return syslogList;
}

int SysLogRepository::insert(const SysLog& syslog)
{
	dataBase << "insert into sys_log(syslog_id, server_id, datalog_id, loglevel, tstamp, message)\
values(:SysLog_syslog_id, :SysLog_server_id, :SysLog_datalog_id, :SysLog_loglevel, :SysLog_tstamp, :SysLog_message)", use(syslog);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void SysLogRepository::remove(const SysLog& syslog)
{
	dataBase << "DELETE from sys_log WHERE syslog_id=:SysLog_syslog_id", use(syslog);
}

void SysLogRepository::update(const SysLog& syslog)
{
	dataBase << "update sys_log set syslog_id=:SysLog_syslog_id, server_id=:SysLog_server_id, datalog_id=:SysLog_datalog_id, loglevel=:SysLog_loglevel, tstamp=:SysLog_tstamp, message=:SysLog_message WHERE syslog_id=:SysLog_syslog_id", use(syslog);
}

void SysLogRepository::update(const SysLog& oldObj, const SysLog& newObj)
{
	dataBase << "update sys_log set syslog_id=:SysLog_syslog_id, server_id=:SysLog_server_id, datalog_id=:SysLog_datalog_id, loglevel=:SysLog_loglevel, tstamp=:SysLog_tstamp, message=:SysLog_message WHERE syslog_id='"<<oldObj.getSyslogId()<<"\'", use(newObj);
}

