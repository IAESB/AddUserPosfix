#include "monitordatarepository.h"
#include "util.hpp"
MonitorDataRepository::MonitorDataRepository(soci::session& db) : dataBase(db)
{
}

MonitorDataPtr MonitorDataRepository::select(const MonitorData& obj)
{
	soci::row row;
	MonitorDataPtr monitordata(new MonitorData);
	dataBase << "SELECT  monitor_data.server_id as MonitorData_server_id, monitor_data.type as MonitorData_type, monitor_data.created as MonitorData_created, monitor_data.data as MonitorData_data, monitor_data.state as MonitorData_state"
	" FROM monitor_data "
	"WHERE monitor_data.server_id = :MonitorData_server_id AND monitor_data.type = :MonitorData_type AND monitor_data.created = :MonitorData_created", into(row), use(obj);
	if(!dataBase.got_data())
		monitordata.reset();
	else
		type_conversion<MonitorData>::from_base(row, i_ok, *monitordata);
	return monitordata;
}
MonitorDataList MonitorDataRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  monitor_data.server_id as MonitorData_server_id, monitor_data.type as MonitorData_type, monitor_data.created as MonitorData_created, monitor_data.data as MonitorData_data, monitor_data.state as MonitorData_state "
	" FROM monitor_data" 
	<< (where.size()?" WHERE "+where:"");
	MonitorDataList monitordataList;
	for(row& r: rs)
	{
		MonitorDataPtr monitordata(new MonitorData);
		type_conversion<MonitorData>::from_base(r, i_ok, *monitordata);
		monitordataList.push_back(monitordata);
	}
	return monitordataList;
}

int MonitorDataRepository::insert(const MonitorData& monitordata)
{
	dataBase << "insert into monitor_data(server_id, type, created, data, state)\
values(:MonitorData_server_id, :MonitorData_type, :MonitorData_created, :MonitorData_data, :MonitorData_state)", use(monitordata);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void MonitorDataRepository::remove(const MonitorData& monitordata)
{
	dataBase << "DELETE from monitor_data WHERE server_id=:MonitorData_server_id AND type=:MonitorData_type AND created=:MonitorData_created", use(monitordata);
}

void MonitorDataRepository::update(const MonitorData& monitordata)
{
	dataBase << "update monitor_data set server_id=:MonitorData_server_id, type=:MonitorData_type, created=:MonitorData_created, data=:MonitorData_data, state=:MonitorData_state WHERE server_id=:MonitorData_server_id AND type=:MonitorData_type AND created=:MonitorData_created", use(monitordata);
}

void MonitorDataRepository::update(const MonitorData& oldObj, const MonitorData& newObj)
{
	dataBase << "update monitor_data set server_id=:MonitorData_server_id, type=:MonitorData_type, created=:MonitorData_created, data=:MonitorData_data, state=:MonitorData_state WHERE server_id='"<<oldObj.getServerId()<<"\'' AND type='"<<oldObj.getType()<<"\'' AND created='"<<oldObj.getCreated()<<"\'", use(newObj);
}

