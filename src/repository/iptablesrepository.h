#ifndef IPTABLESREPOSITORY_H
#define IPTABLESREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/iptables.h"
using namespace soci;


class IptablesRepository
{
	soci::session& dataBase;
public:
	IptablesRepository(soci::session& dataBase);
	int insert(const Iptables& iptables);
	IptablesPtr select(const Iptables& iptables);
	IptablesList select(const string& where="");
	void update(const Iptables& iptables);
	void update(const Iptables& oldObj, const Iptables& newObj);
	void remove(const Iptables& iptables);
};

namespace soci
{
template<>
struct type_conversion<Iptables>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, Iptables & p)
	{
		if (v.get_indicator("Iptables_iptables_id") != i_null){
			p.setIptablesId( v.template get<long long>("Iptables_iptables_id" ) );
		}
		if (v.get_indicator("Iptables_server_id") != i_null){
			p.setServerId( v.template get<long long>("Iptables_server_id" ) );
		}
		if (v.get_indicator("Iptables_table") != i_null){
			p.setTable( v.template get<std::string>("Iptables_table" ) );
		}
		if (v.get_indicator("Iptables_source_ip") != i_null){
			p.setSourceIp( v.template get<std::string>("Iptables_source_ip" ) );
		}
		if (v.get_indicator("Iptables_destination_ip") != i_null){
			p.setDestinationIp( v.template get<std::string>("Iptables_destination_ip" ) );
		}
		if (v.get_indicator("Iptables_protocol") != i_null){
			p.setProtocol( v.template get<std::string>("Iptables_protocol" ) );
		}
		if (v.get_indicator("Iptables_singleport") != i_null){
			p.setSingleport( v.template get<std::string>("Iptables_singleport" ) );
		}
		if (v.get_indicator("Iptables_multiport") != i_null){
			p.setMultiport( v.template get<std::string>("Iptables_multiport" ) );
		}
		if (v.get_indicator("Iptables_state") != i_null){
			p.setState( v.template get<std::string>("Iptables_state" ) );
		}
		if (v.get_indicator("Iptables_target") != i_null){
			p.setTarget( v.template get<std::string>("Iptables_target" ) );
		}
		if (v.get_indicator("Iptables_active") != i_null){
			p.setActive( v.template get<std::string>("Iptables_active" ) );
		}
	}
	static void to_base(const Iptables & p, values & v, indicator & ind)
	{
		v.set( "Iptables_iptables_id", p.getIptablesId() );
		v.set( "Iptables_server_id", p.getServerId() );
		v.set( "Iptables_table", p.getTable() );
		v.set( "Iptables_source_ip", p.getSourceIp() );
		v.set( "Iptables_destination_ip", p.getDestinationIp() );
		v.set( "Iptables_protocol", p.getProtocol() );
		v.set( "Iptables_singleport", p.getSingleport() );
		v.set( "Iptables_multiport", p.getMultiport() );
		v.set( "Iptables_state", p.getState() );
		v.set( "Iptables_target", p.getTarget() );
		v.set( "Iptables_active", p.getActive() );
		ind = i_ok;
	}
};
}

#endif // IPTABLESREPOSITORY_H
