#include "openvztrafficrepository.h"
#include "util.hpp"
OpenvzTrafficRepository::OpenvzTrafficRepository(soci::session& db) : dataBase(db)
{
}

OpenvzTrafficPtr OpenvzTrafficRepository::select(const OpenvzTraffic& obj)
{
	soci::row row;
	OpenvzTrafficPtr openvztraffic(new OpenvzTraffic);
	dataBase << "SELECT  openvz_traffic.veid as OpenvzTraffic_veid, openvz_traffic.traffic_date as OpenvzTraffic_traffic_date, openvz_traffic.traffic_bytes as OpenvzTraffic_traffic_bytes"
	" FROM openvz_traffic "
	"WHERE openvz_traffic.veid = :OpenvzTraffic_veid AND openvz_traffic.traffic_date = :OpenvzTraffic_traffic_date", into(row), use(obj);
	if(!dataBase.got_data())
		openvztraffic.reset();
	else
		type_conversion<OpenvzTraffic>::from_base(row, i_ok, *openvztraffic);
	return openvztraffic;
}
OpenvzTrafficList OpenvzTrafficRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  openvz_traffic.veid as OpenvzTraffic_veid, openvz_traffic.traffic_date as OpenvzTraffic_traffic_date, openvz_traffic.traffic_bytes as OpenvzTraffic_traffic_bytes "
	" FROM openvz_traffic" 
	<< (where.size()?" WHERE "+where:"");
	OpenvzTrafficList openvztrafficList;
	for(row& r: rs)
	{
		OpenvzTrafficPtr openvztraffic(new OpenvzTraffic);
		type_conversion<OpenvzTraffic>::from_base(r, i_ok, *openvztraffic);
		openvztrafficList.push_back(openvztraffic);
	}
	return openvztrafficList;
}

int OpenvzTrafficRepository::insert(const OpenvzTraffic& openvztraffic)
{
	dataBase << "insert into openvz_traffic(veid, traffic_date, traffic_bytes)\
values(:OpenvzTraffic_veid, :OpenvzTraffic_traffic_date, :OpenvzTraffic_traffic_bytes)", use(openvztraffic);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void OpenvzTrafficRepository::remove(const OpenvzTraffic& openvztraffic)
{
	dataBase << "DELETE from openvz_traffic WHERE veid=:OpenvzTraffic_veid AND traffic_date=:OpenvzTraffic_traffic_date", use(openvztraffic);
}

void OpenvzTrafficRepository::update(const OpenvzTraffic& openvztraffic)
{
	dataBase << "update openvz_traffic set veid=:OpenvzTraffic_veid, traffic_date=:OpenvzTraffic_traffic_date, traffic_bytes=:OpenvzTraffic_traffic_bytes WHERE veid=:OpenvzTraffic_veid AND traffic_date=:OpenvzTraffic_traffic_date", use(openvztraffic);
}

void OpenvzTrafficRepository::update(const OpenvzTraffic& oldObj, const OpenvzTraffic& newObj)
{
	dataBase << "update openvz_traffic set veid=:OpenvzTraffic_veid, traffic_date=:OpenvzTraffic_traffic_date, traffic_bytes=:OpenvzTraffic_traffic_bytes WHERE veid='"<<oldObj.getVeid()<<"\'' AND traffic_date='"<<to_string(oldObj.getTrafficDate())<<"\'", use(newObj);
}

