#ifndef MAILTRAFFICREPOSITORY_H
#define MAILTRAFFICREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/mailtraffic.h"
using namespace soci;


class MailTrafficRepository
{
	soci::session& dataBase;
public:
	MailTrafficRepository(soci::session& dataBase);
	int insert(const MailTraffic& mailtraffic);
	MailTrafficPtr select(const MailTraffic& mailtraffic);
	MailTrafficList select(const string& where="");
	void update(const MailTraffic& mailtraffic);
	void update(const MailTraffic& oldObj, const MailTraffic& newObj);
	void remove(const MailTraffic& mailtraffic);
};

namespace soci
{
template<>
struct type_conversion<MailTraffic>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, MailTraffic & p)
	{
		if (v.get_indicator("MailTraffic_traffic_id") != i_null){
			p.setTrafficId( v.template get<long long>("MailTraffic_traffic_id" ) );
		}
		if (v.get_indicator("MailTraffic_mailuser_id") != i_null){
			p.setMailuserId( v.template get<long long>("MailTraffic_mailuser_id" ) );
		}
		if (v.get_indicator("MailTraffic_month") != i_null){
			p.setMonth( v.template get<std::string>("MailTraffic_month" ) );
		}
		if (v.get_indicator("MailTraffic_traffic") != i_null){
			p.setTraffic( v.template get<unsigned long long>("MailTraffic_traffic" ) );
		}
	}
	static void to_base(const MailTraffic & p, values & v, indicator & ind)
	{
		v.set( "MailTraffic_traffic_id", p.getTrafficId() );
		v.set( "MailTraffic_mailuser_id", p.getMailuserId() );
		v.set( "MailTraffic_month", p.getMonth() );
		v.set( "MailTraffic_traffic", p.getTraffic() );
		ind = i_ok;
	}
};
}

#endif // MAILTRAFFICREPOSITORY_H
