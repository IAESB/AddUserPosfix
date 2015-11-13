#ifndef SYSDBSYNCREPOSITORY_H
#define SYSDBSYNCREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/sysdbsync.h"
using namespace soci;


class SysDbsyncRepository
{
	soci::session& dataBase;
public:
	SysDbsyncRepository(soci::session& dataBase);
	int insert(const SysDbsync& sysdbsync);
	SysDbsyncPtr select(const SysDbsync& sysdbsync);
	SysDbsyncList select(const string& where="");
	void update(const SysDbsync& sysdbsync);
	void update(const SysDbsync& oldObj, const SysDbsync& newObj);
	void remove(const SysDbsync& sysdbsync);
};

namespace soci
{
template<>
struct type_conversion<SysDbsync>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, SysDbsync & p)
	{
		if (v.get_indicator("SysDbsync_id") != i_null){
			p.setId( v.template get<long long>("SysDbsync_id" ) );
		}
		if (v.get_indicator("SysDbsync_jobname") != i_null){
			p.setJobname( v.template get<std::string>("SysDbsync_jobname" ) );
		}
		if (v.get_indicator("SysDbsync_sync_interval_minutes") != i_null){
			p.setSyncIntervalMinutes( v.template get<long long>("SysDbsync_sync_interval_minutes" ) );
		}
		if (v.get_indicator("SysDbsync_db_type") != i_null){
			p.setDbType( v.template get<std::string>("SysDbsync_db_type" ) );
		}
		if (v.get_indicator("SysDbsync_db_host") != i_null){
			p.setDbHost( v.template get<std::string>("SysDbsync_db_host" ) );
		}
		if (v.get_indicator("SysDbsync_db_name") != i_null){
			p.setDbName( v.template get<std::string>("SysDbsync_db_name" ) );
		}
		if (v.get_indicator("SysDbsync_db_username") != i_null){
			p.setDbUsername( v.template get<std::string>("SysDbsync_db_username" ) );
		}
		if (v.get_indicator("SysDbsync_db_password") != i_null){
			p.setDbPassword( v.template get<std::string>("SysDbsync_db_password" ) );
		}
		if (v.get_indicator("SysDbsync_db_tables") != i_null){
			p.setDbTables( v.template get<std::string>("SysDbsync_db_tables" ) );
		}
		if (v.get_indicator("SysDbsync_empty_datalog") != i_null){
			p.setEmptyDatalog( v.template get<long long>("SysDbsync_empty_datalog" ) );
		}
		if (v.get_indicator("SysDbsync_sync_datalog_external") != i_null){
			p.setSyncDatalogExternal( v.template get<long long>("SysDbsync_sync_datalog_external" ) );
		}
		if (v.get_indicator("SysDbsync_active") != i_null){
			p.setActive( v.template get<int>("SysDbsync_active" ) );
		}
		if (v.get_indicator("SysDbsync_last_datalog_id") != i_null){
			p.setLastDatalogId( v.template get<long long>("SysDbsync_last_datalog_id" ) );
		}
	}
	static void to_base(const SysDbsync & p, values & v, indicator & ind)
	{
		v.set( "SysDbsync_id", p.getId() );
		v.set( "SysDbsync_jobname", p.getJobname() );
		v.set( "SysDbsync_sync_interval_minutes", p.getSyncIntervalMinutes() );
		v.set( "SysDbsync_db_type", p.getDbType() );
		v.set( "SysDbsync_db_host", p.getDbHost() );
		v.set( "SysDbsync_db_name", p.getDbName() );
		v.set( "SysDbsync_db_username", p.getDbUsername() );
		v.set( "SysDbsync_db_password", p.getDbPassword() );
		v.set( "SysDbsync_db_tables", p.getDbTables() );
		v.set( "SysDbsync_empty_datalog", p.getEmptyDatalog() );
		v.set( "SysDbsync_sync_datalog_external", p.getSyncDatalogExternal() );
		v.set( "SysDbsync_active", p.getActive() );
		v.set( "SysDbsync_last_datalog_id", p.getLastDatalogId() );
		ind = i_ok;
	}
};
}

#endif // SYSDBSYNCREPOSITORY_H
