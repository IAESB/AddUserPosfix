#ifndef OPENVZTRAFFICREPOSITORY_H
#define OPENVZTRAFFICREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/openvztraffic.h"
using namespace soci;


class OpenvzTrafficRepository
{
	soci::session& dataBase;
public:
	OpenvzTrafficRepository(soci::session& dataBase);
	int insert(const OpenvzTraffic& openvztraffic);
	OpenvzTrafficPtr select(const OpenvzTraffic& openvztraffic);
	OpenvzTrafficList select(const string& where="");
	void update(const OpenvzTraffic& openvztraffic);
	void update(const OpenvzTraffic& oldObj, const OpenvzTraffic& newObj);
	void remove(const OpenvzTraffic& openvztraffic);
};

namespace soci
{
template<>
struct type_conversion<OpenvzTraffic>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, OpenvzTraffic & p)
	{
		if (v.get_indicator("OpenvzTraffic_veid") != i_null){
			p.setVeid( v.template get<int>("OpenvzTraffic_veid" ) );
		}
		if (v.get_indicator("OpenvzTraffic_traffic_date") != i_null){
			p.setTrafficDate( v.template get<tm>("OpenvzTraffic_traffic_date" ) );
		}
		if (v.get_indicator("OpenvzTraffic_traffic_bytes") != i_null){
			p.setTrafficBytes( v.template get<unsigned long long>("OpenvzTraffic_traffic_bytes" ) );
		}
	}
	static void to_base(const OpenvzTraffic & p, values & v, indicator & ind)
	{
		v.set( "OpenvzTraffic_veid", p.getVeid() );
		v.set( "OpenvzTraffic_traffic_date", p.getTrafficDate() );
		v.set( "OpenvzTraffic_traffic_bytes", p.getTrafficBytes() );
		ind = i_ok;
	}
};
}

#endif // OPENVZTRAFFICREPOSITORY_H
