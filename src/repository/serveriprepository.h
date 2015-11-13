#ifndef SERVERIPREPOSITORY_H
#define SERVERIPREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/serverip.h"
using namespace soci;


class ServerIpRepository
{
	soci::session& dataBase;
public:
	ServerIpRepository(soci::session& dataBase);
	int insert(const ServerIp& serverip);
	ServerIpPtr select(const ServerIp& serverip);
	ServerIpList select(const string& where="");
	void update(const ServerIp& serverip);
	void update(const ServerIp& oldObj, const ServerIp& newObj);
	void remove(const ServerIp& serverip);
};

namespace soci
{
template<>
struct type_conversion<ServerIp>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, ServerIp & p)
	{
		if (v.get_indicator("ServerIp_server_ip_id") != i_null){
			p.setServerIpId( v.template get<long long>("ServerIp_server_ip_id" ) );
		}
		if (v.get_indicator("ServerIp_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("ServerIp_sys_userid" ) );
		}
		if (v.get_indicator("ServerIp_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("ServerIp_sys_groupid" ) );
		}
		if (v.get_indicator("ServerIp_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("ServerIp_sys_perm_user" ) );
		}
		if (v.get_indicator("ServerIp_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("ServerIp_sys_perm_group" ) );
		}
		if (v.get_indicator("ServerIp_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("ServerIp_sys_perm_other" ) );
		}
		if (v.get_indicator("ServerIp_server_id") != i_null){
			p.setServerId( v.template get<long long>("ServerIp_server_id" ) );
		}
		if (v.get_indicator("ServerIp_client_id") != i_null){
			p.setClientId( v.template get<long long>("ServerIp_client_id" ) );
		}
		if (v.get_indicator("ServerIp_ip_type") != i_null){
			p.setIpType( v.template get<std::string>("ServerIp_ip_type" ) );
		}
		if (v.get_indicator("ServerIp_ip_address") != i_null){
			p.setIpAddress( v.template get<std::string>("ServerIp_ip_address" ) );
		}
		if (v.get_indicator("ServerIp_virtualhost") != i_null){
			p.setVirtualhost( v.template get<std::string>("ServerIp_virtualhost" ) );
		}
		if (v.get_indicator("ServerIp_virtualhost_port") != i_null){
			p.setVirtualhostPort( v.template get<std::string>("ServerIp_virtualhost_port" ) );
		}
	}
	static void to_base(const ServerIp & p, values & v, indicator & ind)
	{
		v.set( "ServerIp_server_ip_id", p.getServerIpId() );
		v.set( "ServerIp_sys_userid", p.getSysUserid() );
		v.set( "ServerIp_sys_groupid", p.getSysGroupid() );
		v.set( "ServerIp_sys_perm_user", p.getSysPermUser() );
		v.set( "ServerIp_sys_perm_group", p.getSysPermGroup() );
		v.set( "ServerIp_sys_perm_other", p.getSysPermOther() );
		v.set( "ServerIp_server_id", p.getServerId() );
		v.set( "ServerIp_client_id", p.getClientId() );
		v.set( "ServerIp_ip_type", p.getIpType() );
		v.set( "ServerIp_ip_address", p.getIpAddress() );
		v.set( "ServerIp_virtualhost", p.getVirtualhost() );
		v.set( "ServerIp_virtualhost_port", p.getVirtualhostPort() );
		ind = i_ok;
	}
};
}

#endif // SERVERIPREPOSITORY_H
