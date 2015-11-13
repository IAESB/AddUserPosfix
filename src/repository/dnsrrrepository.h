#ifndef DNSRRREPOSITORY_H
#define DNSRRREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/dnsrr.h"
using namespace soci;


class DnsRrRepository
{
	soci::session& dataBase;
public:
	DnsRrRepository(soci::session& dataBase);
	int insert(const DnsRr& dnsrr);
	DnsRrPtr select(const DnsRr& dnsrr);
	DnsRrList select(const string& where="");
	void update(const DnsRr& dnsrr);
	void update(const DnsRr& oldObj, const DnsRr& newObj);
	void remove(const DnsRr& dnsrr);
};

namespace soci
{
template<>
struct type_conversion<DnsRr>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, DnsRr & p)
	{
		if (v.get_indicator("DnsRr_id") != i_null){
			p.setId( v.template get<long long>("DnsRr_id" ) );
		}
		if (v.get_indicator("DnsRr_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("DnsRr_sys_userid" ) );
		}
		if (v.get_indicator("DnsRr_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("DnsRr_sys_groupid" ) );
		}
		if (v.get_indicator("DnsRr_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("DnsRr_sys_perm_user" ) );
		}
		if (v.get_indicator("DnsRr_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("DnsRr_sys_perm_group" ) );
		}
		if (v.get_indicator("DnsRr_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("DnsRr_sys_perm_other" ) );
		}
		if (v.get_indicator("DnsRr_server_id") != i_null){
			p.setServerId( v.template get<int>("DnsRr_server_id" ) );
		}
		if (v.get_indicator("DnsRr_zone") != i_null){
			p.setZone( v.template get<long long>("DnsRr_zone" ) );
		}
		if (v.get_indicator("DnsRr_name") != i_null){
			p.setName( v.template get<std::string>("DnsRr_name" ) );
		}
		if (v.get_indicator("DnsRr_type") != i_null){
			p.setType( v.template get<std::string>("DnsRr_type" ) );
		}
		if (v.get_indicator("DnsRr_data") != i_null){
			p.setData( v.template get<std::string>("DnsRr_data" ) );
		}
		if (v.get_indicator("DnsRr_aux") != i_null){
			p.setAux( v.template get<long long>("DnsRr_aux" ) );
		}
		if (v.get_indicator("DnsRr_ttl") != i_null){
			p.setTtl( v.template get<long long>("DnsRr_ttl" ) );
		}
		if (v.get_indicator("DnsRr_active") != i_null){
			p.setActive( v.template get<std::string>("DnsRr_active" ) );
		}
		if (v.get_indicator("DnsRr_stamp") != i_null){
			p.setStamp( v.template get<tm>("DnsRr_stamp" ) );
		}
		if (v.get_indicator("DnsRr_serial") != i_null){
			p.setSerial( v.template get<long long>("DnsRr_serial" ) );
		}
	}
	static void to_base(const DnsRr & p, values & v, indicator & ind)
	{
		v.set( "DnsRr_id", p.getId() );
		v.set( "DnsRr_sys_userid", p.getSysUserid() );
		v.set( "DnsRr_sys_groupid", p.getSysGroupid() );
		v.set( "DnsRr_sys_perm_user", p.getSysPermUser() );
		v.set( "DnsRr_sys_perm_group", p.getSysPermGroup() );
		v.set( "DnsRr_sys_perm_other", p.getSysPermOther() );
		v.set( "DnsRr_server_id", p.getServerId() );
		v.set( "DnsRr_zone", p.getZone() );
		v.set( "DnsRr_name", p.getName() );
		v.set( "DnsRr_type", p.getType() );
		v.set( "DnsRr_data", p.getData() );
		v.set( "DnsRr_aux", p.getAux() );
		v.set( "DnsRr_ttl", p.getTtl() );
		v.set( "DnsRr_active", p.getActive() );
		v.set( "DnsRr_stamp", p.getStamp() );
		v.set( "DnsRr_serial", p.getSerial() );
		ind = i_ok;
	}
};
}

#endif // DNSRRREPOSITORY_H
