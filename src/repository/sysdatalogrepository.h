#ifndef SYSDATALOGREPOSITORY_H
#define SYSDATALOGREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/sysdatalog.h"
using namespace soci;


class SysDatalogRepository
{
	soci::session& dataBase;
public:
	SysDatalogRepository(soci::session& dataBase);
	int insert(const SysDatalog& sysdatalog);
	SysDatalogPtr select(const SysDatalog& sysdatalog);
	SysDatalogList select(const string& where="");
	void update(const SysDatalog& sysdatalog);
	void update(const SysDatalog& oldObj, const SysDatalog& newObj);
	void remove(const SysDatalog& sysdatalog);
};

namespace soci
{
template<>
struct type_conversion<SysDatalog>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, SysDatalog & p)
	{
		if (v.get_indicator("SysDatalog_datalog_id") != i_null){
			p.setDatalogId( v.template get<long long>("SysDatalog_datalog_id" ) );
		}
		if (v.get_indicator("SysDatalog_server_id") != i_null){
			p.setServerId( v.template get<long long>("SysDatalog_server_id" ) );
		}
		if (v.get_indicator("SysDatalog_dbtable") != i_null){
			p.setDbtable( v.template get<std::string>("SysDatalog_dbtable" ) );
		}
		if (v.get_indicator("SysDatalog_dbidx") != i_null){
			p.setDbidx( v.template get<std::string>("SysDatalog_dbidx" ) );
		}
		if (v.get_indicator("SysDatalog_action") != i_null){
			p.setAction( v.template get<std::string>("SysDatalog_action" ) );
		}
		if (v.get_indicator("SysDatalog_tstamp") != i_null){
			p.setTstamp( v.template get<int>("SysDatalog_tstamp" ) );
		}
		if (v.get_indicator("SysDatalog_user") != i_null){
			p.setUser( v.template get<std::string>("SysDatalog_user" ) );
		}
		if (v.get_indicator("SysDatalog_data") != i_null){
			p.setData( v.template get<std::string>("SysDatalog_data" ) );
		}
		if (v.get_indicator("SysDatalog_status") != i_null){
			p.setStatus( v.template get<std::string>("SysDatalog_status" ) );
		}
		if (v.get_indicator("SysDatalog_error") != i_null){
			p.setError( v.template get<std::string>("SysDatalog_error" ) );
		}
	}
	static void to_base(const SysDatalog & p, values & v, indicator & ind)
	{
		v.set( "SysDatalog_datalog_id", p.getDatalogId() );
		v.set( "SysDatalog_server_id", p.getServerId() );
		v.set( "SysDatalog_dbtable", p.getDbtable() );
		v.set( "SysDatalog_dbidx", p.getDbidx() );
		v.set( "SysDatalog_action", p.getAction() );
		v.set( "SysDatalog_tstamp", p.getTstamp() );
		v.set( "SysDatalog_user", p.getUser() );
		v.set( "SysDatalog_data", p.getData() );
		v.set( "SysDatalog_status", p.getStatus() );
		v.set( "SysDatalog_error", p.getError() );
		ind = i_ok;
	}
};
}

#endif // SYSDATALOGREPOSITORY_H
