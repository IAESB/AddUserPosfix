#ifndef FIREWALLREPOSITORY_H
#define FIREWALLREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/firewall.h"
using namespace soci;


class FirewallRepository
{
	soci::session& dataBase;
public:
	FirewallRepository(soci::session& dataBase);
	int insert(const Firewall& firewall);
	FirewallPtr select(const Firewall& firewall);
	FirewallList select(const string& where="");
	void update(const Firewall& firewall);
	void update(const Firewall& oldObj, const Firewall& newObj);
	void remove(const Firewall& firewall);
};

namespace soci
{
template<>
struct type_conversion<Firewall>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, Firewall & p)
	{
		if (v.get_indicator("Firewall_firewall_id") != i_null){
			p.setFirewallId( v.template get<long long>("Firewall_firewall_id" ) );
		}
		if (v.get_indicator("Firewall_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("Firewall_sys_userid" ) );
		}
		if (v.get_indicator("Firewall_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("Firewall_sys_groupid" ) );
		}
		if (v.get_indicator("Firewall_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("Firewall_sys_perm_user" ) );
		}
		if (v.get_indicator("Firewall_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("Firewall_sys_perm_group" ) );
		}
		if (v.get_indicator("Firewall_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("Firewall_sys_perm_other" ) );
		}
		if (v.get_indicator("Firewall_server_id") != i_null){
			p.setServerId( v.template get<long long>("Firewall_server_id" ) );
		}
		if (v.get_indicator("Firewall_tcp_port") != i_null){
			p.setTcpPort( v.template get<std::string>("Firewall_tcp_port" ) );
		}
		if (v.get_indicator("Firewall_udp_port") != i_null){
			p.setUdpPort( v.template get<std::string>("Firewall_udp_port" ) );
		}
		if (v.get_indicator("Firewall_active") != i_null){
			p.setActive( v.template get<std::string>("Firewall_active" ) );
		}
	}
	static void to_base(const Firewall & p, values & v, indicator & ind)
	{
		v.set( "Firewall_firewall_id", p.getFirewallId() );
		v.set( "Firewall_sys_userid", p.getSysUserid() );
		v.set( "Firewall_sys_groupid", p.getSysGroupid() );
		v.set( "Firewall_sys_perm_user", p.getSysPermUser() );
		v.set( "Firewall_sys_perm_group", p.getSysPermGroup() );
		v.set( "Firewall_sys_perm_other", p.getSysPermOther() );
		v.set( "Firewall_server_id", p.getServerId() );
		v.set( "Firewall_tcp_port", p.getTcpPort() );
		v.set( "Firewall_udp_port", p.getUdpPort() );
		v.set( "Firewall_active", p.getActive() );
		ind = i_ok;
	}
};
}

#endif // FIREWALLREPOSITORY_H
