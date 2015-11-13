#ifndef MONITORDATAREPOSITORY_H
#define MONITORDATAREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/monitordata.h"
using namespace soci;


class MonitorDataRepository
{
	soci::session& dataBase;
public:
	MonitorDataRepository(soci::session& dataBase);
	int insert(const MonitorData& monitordata);
	MonitorDataPtr select(const MonitorData& monitordata);
	MonitorDataList select(const string& where="");
	void update(const MonitorData& monitordata);
	void update(const MonitorData& oldObj, const MonitorData& newObj);
	void remove(const MonitorData& monitordata);
};

namespace soci
{
template<>
struct type_conversion<MonitorData>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, MonitorData & p)
	{
		if (v.get_indicator("MonitorData_server_id") != i_null){
			p.setServerId( v.template get<long long>("MonitorData_server_id" ) );
		}
		if (v.get_indicator("MonitorData_type") != i_null){
			p.setType( v.template get<std::string>("MonitorData_type" ) );
		}
		if (v.get_indicator("MonitorData_created") != i_null){
			p.setCreated( v.template get<long long>("MonitorData_created" ) );
		}
		if (v.get_indicator("MonitorData_data") != i_null){
			p.setData( v.template get<std::string>("MonitorData_data" ) );
		}
		if (v.get_indicator("MonitorData_state") != i_null){
			p.setState( v.template get<std::string>("MonitorData_state" ) );
		}
	}
	static void to_base(const MonitorData & p, values & v, indicator & ind)
	{
		v.set( "MonitorData_server_id", p.getServerId() );
		v.set( "MonitorData_type", p.getType() );
		v.set( "MonitorData_created", p.getCreated() );
		v.set( "MonitorData_data", p.getData() );
		v.set( "MonitorData_state", p.getState() );
		ind = i_ok;
	}
};
}

#endif // MONITORDATAREPOSITORY_H
