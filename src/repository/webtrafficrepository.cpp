#include "webtrafficrepository.h"
#include "util.hpp"
WebTrafficRepository::WebTrafficRepository(soci::session& db) : dataBase(db)
{
}

WebTrafficPtr WebTrafficRepository::select(const WebTraffic& obj)
{
	soci::row row;
	WebTrafficPtr webtraffic(new WebTraffic);
	dataBase << "SELECT  web_traffic.hostname as WebTraffic_hostname, web_traffic.traffic_date as WebTraffic_traffic_date, web_traffic.traffic_bytes as WebTraffic_traffic_bytes"
	" FROM web_traffic "
	"WHERE web_traffic.hostname = :WebTraffic_hostname AND web_traffic.traffic_date = :WebTraffic_traffic_date", into(row), use(obj);
	if(!dataBase.got_data())
		webtraffic.reset();
	else
		type_conversion<WebTraffic>::from_base(row, i_ok, *webtraffic);
	return webtraffic;
}
WebTrafficList WebTrafficRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  web_traffic.hostname as WebTraffic_hostname, web_traffic.traffic_date as WebTraffic_traffic_date, web_traffic.traffic_bytes as WebTraffic_traffic_bytes "
	" FROM web_traffic" 
	<< (where.size()?" WHERE "+where:"");
	WebTrafficList webtrafficList;
	for(row& r: rs)
	{
		WebTrafficPtr webtraffic(new WebTraffic);
		type_conversion<WebTraffic>::from_base(r, i_ok, *webtraffic);
		webtrafficList.push_back(webtraffic);
	}
	return webtrafficList;
}

int WebTrafficRepository::insert(const WebTraffic& webtraffic)
{
	dataBase << "insert into web_traffic(hostname, traffic_date, traffic_bytes)\
values(:WebTraffic_hostname, :WebTraffic_traffic_date, :WebTraffic_traffic_bytes)", use(webtraffic);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void WebTrafficRepository::remove(const WebTraffic& webtraffic)
{
	dataBase << "DELETE from web_traffic WHERE hostname=:WebTraffic_hostname AND traffic_date=:WebTraffic_traffic_date", use(webtraffic);
}

void WebTrafficRepository::update(const WebTraffic& webtraffic)
{
	dataBase << "update web_traffic set hostname=:WebTraffic_hostname, traffic_date=:WebTraffic_traffic_date, traffic_bytes=:WebTraffic_traffic_bytes WHERE hostname=:WebTraffic_hostname AND traffic_date=:WebTraffic_traffic_date", use(webtraffic);
}

void WebTrafficRepository::update(const WebTraffic& oldObj, const WebTraffic& newObj)
{
	dataBase << "update web_traffic set hostname=:WebTraffic_hostname, traffic_date=:WebTraffic_traffic_date, traffic_bytes=:WebTraffic_traffic_bytes WHERE hostname='"<<oldObj.getHostname()<<"\'' AND traffic_date='"<<to_string(oldObj.getTrafficDate())<<"\'", use(newObj);
}

