#ifndef DNSSLAVEREPOSITORY_H
#define DNSSLAVEREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/dnsslave.h"
using namespace soci;


class DnsSlaveRepository
{
	soci::session& dataBase;
public:
	DnsSlaveRepository(soci::session& dataBase);
	int insert(const DnsSlave& dnsslave);
	DnsSlavePtr select(const DnsSlave& dnsslave);
	DnsSlaveList select(const string& where="");
	void update(const DnsSlave& dnsslave);
	void update(const DnsSlave& oldObj, const DnsSlave& newObj);
	void remove(const DnsSlave& dnsslave);
};

namespace soci
{
template<>
struct type_conversion<DnsSlave>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, DnsSlave & p)
	{
		if (v.get_indicator("DnsSlave_id") != i_null){
			p.setId( v.template get<long long>("DnsSlave_id" ) );
		}
		if (v.get_indicator("DnsSlave_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("DnsSlave_sys_userid" ) );
		}
		if (v.get_indicator("DnsSlave_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("DnsSlave_sys_groupid" ) );
		}
		if (v.get_indicator("DnsSlave_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("DnsSlave_sys_perm_user" ) );
		}
		if (v.get_indicator("DnsSlave_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("DnsSlave_sys_perm_group" ) );
		}
		if (v.get_indicator("DnsSlave_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("DnsSlave_sys_perm_other" ) );
		}
		if (v.get_indicator("DnsSlave_server_id") != i_null){
			p.setServerId( v.template get<int>("DnsSlave_server_id" ) );
		}
		if (v.get_indicator("DnsSlave_origin") != i_null){
			p.setOrigin( v.template get<std::string>("DnsSlave_origin" ) );
		}
		if (v.get_indicator("DnsSlave_ns") != i_null){
			p.setNs( v.template get<std::string>("DnsSlave_ns" ) );
		}
		if (v.get_indicator("DnsSlave_active") != i_null){
			p.setActive( v.template get<std::string>("DnsSlave_active" ) );
		}
		if (v.get_indicator("DnsSlave_xfer") != i_null){
			p.setXfer( v.template get<std::string>("DnsSlave_xfer" ) );
		}
	}
	static void to_base(const DnsSlave & p, values & v, indicator & ind)
	{
		v.set( "DnsSlave_id", p.getId() );
		v.set( "DnsSlave_sys_userid", p.getSysUserid() );
		v.set( "DnsSlave_sys_groupid", p.getSysGroupid() );
		v.set( "DnsSlave_sys_perm_user", p.getSysPermUser() );
		v.set( "DnsSlave_sys_perm_group", p.getSysPermGroup() );
		v.set( "DnsSlave_sys_perm_other", p.getSysPermOther() );
		v.set( "DnsSlave_server_id", p.getServerId() );
		v.set( "DnsSlave_origin", p.getOrigin() );
		v.set( "DnsSlave_ns", p.getNs() );
		v.set( "DnsSlave_active", p.getActive() );
		v.set( "DnsSlave_xfer", p.getXfer() );
		ind = i_ok;
	}
};
}

#endif // DNSSLAVEREPOSITORY_H
