#ifndef WEBTRAFFICREPOSITORY_H
#define WEBTRAFFICREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/webtraffic.h"
using namespace soci;


class WebTrafficRepository
{
	soci::session& dataBase;
public:
	WebTrafficRepository(soci::session& dataBase);
	int insert(const WebTraffic& webtraffic);
	WebTrafficPtr select(const WebTraffic& webtraffic);
	WebTrafficList select(const string& where="");
	void update(const WebTraffic& webtraffic);
	void update(const WebTraffic& oldObj, const WebTraffic& newObj);
	void remove(const WebTraffic& webtraffic);
};

namespace soci
{
template<>
struct type_conversion<WebTraffic>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, WebTraffic & p)
	{
		if (v.get_indicator("WebTraffic_hostname") != i_null){
			p.setHostname( v.template get<std::string>("WebTraffic_hostname" ) );
		}
		if (v.get_indicator("WebTraffic_traffic_date") != i_null){
			p.setTrafficDate( v.template get<tm>("WebTraffic_traffic_date" ) );
		}
		if (v.get_indicator("WebTraffic_traffic_bytes") != i_null){
			p.setTrafficBytes( v.template get<unsigned long long>("WebTraffic_traffic_bytes" ) );
		}
	}
	static void to_base(const WebTraffic & p, values & v, indicator & ind)
	{
		v.set( "WebTraffic_hostname", p.getHostname() );
		v.set( "WebTraffic_traffic_date", p.getTrafficDate() );
		v.set( "WebTraffic_traffic_bytes", p.getTrafficBytes() );
		ind = i_ok;
	}
};
}

#endif // WEBTRAFFICREPOSITORY_H
