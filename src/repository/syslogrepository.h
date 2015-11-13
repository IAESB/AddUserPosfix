#ifndef SYSLOGREPOSITORY_H
#define SYSLOGREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/syslog.h"
using namespace soci;


class SysLogRepository
{
	soci::session& dataBase;
public:
	SysLogRepository(soci::session& dataBase);
	int insert(const SysLog& syslog);
	SysLogPtr select(const SysLog& syslog);
	SysLogList select(const string& where="");
	void update(const SysLog& syslog);
	void update(const SysLog& oldObj, const SysLog& newObj);
	void remove(const SysLog& syslog);
};

namespace soci
{
template<>
struct type_conversion<SysLog>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, SysLog & p)
	{
		if (v.get_indicator("SysLog_syslog_id") != i_null){
			p.setSyslogId( v.template get<long long>("SysLog_syslog_id" ) );
		}
		if (v.get_indicator("SysLog_server_id") != i_null){
			p.setServerId( v.template get<long long>("SysLog_server_id" ) );
		}
		if (v.get_indicator("SysLog_datalog_id") != i_null){
			p.setDatalogId( v.template get<long long>("SysLog_datalog_id" ) );
		}
		if (v.get_indicator("SysLog_loglevel") != i_null){
			p.setLoglevel( v.template get<int>("SysLog_loglevel" ) );
		}
		if (v.get_indicator("SysLog_tstamp") != i_null){
			p.setTstamp( v.template get<long long>("SysLog_tstamp" ) );
		}
		if (v.get_indicator("SysLog_message") != i_null){
			p.setMessage( v.template get<std::string>("SysLog_message" ) );
		}
	}
	static void to_base(const SysLog & p, values & v, indicator & ind)
	{
		v.set( "SysLog_syslog_id", p.getSyslogId() );
		v.set( "SysLog_server_id", p.getServerId() );
		v.set( "SysLog_datalog_id", p.getDatalogId() );
		v.set( "SysLog_loglevel", p.getLoglevel() );
		v.set( "SysLog_tstamp", p.getTstamp() );
		v.set( "SysLog_message", p.getMessage() );
		ind = i_ok;
	}
};
}

#endif // SYSLOGREPOSITORY_H
