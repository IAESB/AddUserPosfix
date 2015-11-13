#ifndef SERVERREPOSITORY_H
#define SERVERREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/server.h"
using namespace soci;


class ServerRepository
{
	soci::session& dataBase;
public:
	ServerRepository(soci::session& dataBase);
	int insert(const Server& server);
	ServerPtr select(const Server& server);
	ServerList select(const string& where="");
	void update(const Server& server);
	void update(const Server& oldObj, const Server& newObj);
	void remove(const Server& server);
};

namespace soci
{
template<>
struct type_conversion<Server>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, Server & p)
	{
		if (v.get_indicator("Server_server_id") != i_null){
			p.setServerId( v.template get<long long>("Server_server_id" ) );
		}
		if (v.get_indicator("Server_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("Server_sys_userid" ) );
		}
		if (v.get_indicator("Server_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("Server_sys_groupid" ) );
		}
		if (v.get_indicator("Server_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("Server_sys_perm_user" ) );
		}
		if (v.get_indicator("Server_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("Server_sys_perm_group" ) );
		}
		if (v.get_indicator("Server_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("Server_sys_perm_other" ) );
		}
		if (v.get_indicator("Server_server_name") != i_null){
			p.setServerName( v.template get<std::string>("Server_server_name" ) );
		}
		if (v.get_indicator("Server_mail_server") != i_null){
			p.setMailServer( v.template get<int>("Server_mail_server" ) );
		}
		if (v.get_indicator("Server_web_server") != i_null){
			p.setWebServer( v.template get<int>("Server_web_server" ) );
		}
		if (v.get_indicator("Server_dns_server") != i_null){
			p.setDnsServer( v.template get<int>("Server_dns_server" ) );
		}
		if (v.get_indicator("Server_file_server") != i_null){
			p.setFileServer( v.template get<int>("Server_file_server" ) );
		}
		if (v.get_indicator("Server_db_server") != i_null){
			p.setDbServer( v.template get<int>("Server_db_server" ) );
		}
		if (v.get_indicator("Server_vserver_server") != i_null){
			p.setVserverServer( v.template get<int>("Server_vserver_server" ) );
		}
		if (v.get_indicator("Server_proxy_server") != i_null){
			p.setProxyServer( v.template get<int>("Server_proxy_server" ) );
		}
		if (v.get_indicator("Server_firewall_server") != i_null){
			p.setFirewallServer( v.template get<int>("Server_firewall_server" ) );
		}
		if (v.get_indicator("Server_config") != i_null){
			p.setConfig( v.template get<std::string>("Server_config" ) );
		}
		if (v.get_indicator("Server_updated") != i_null){
			p.setUpdated( v.template get<unsigned long long>("Server_updated" ) );
		}
		if (v.get_indicator("Server_mirror_server_id") != i_null){
			p.setMirrorServerId( v.template get<long long>("Server_mirror_server_id" ) );
		}
		if (v.get_indicator("Server_dbversion") != i_null){
			p.setDbversion( v.template get<long long>("Server_dbversion" ) );
		}
		if (v.get_indicator("Server_active") != i_null){
			p.setActive( v.template get<int>("Server_active" ) );
		}
	}
	static void to_base(const Server & p, values & v, indicator & ind)
	{
		v.set( "Server_server_id", p.getServerId() );
		v.set( "Server_sys_userid", p.getSysUserid() );
		v.set( "Server_sys_groupid", p.getSysGroupid() );
		v.set( "Server_sys_perm_user", p.getSysPermUser() );
		v.set( "Server_sys_perm_group", p.getSysPermGroup() );
		v.set( "Server_sys_perm_other", p.getSysPermOther() );
		v.set( "Server_server_name", p.getServerName() );
		v.set( "Server_mail_server", p.getMailServer() );
		v.set( "Server_web_server", p.getWebServer() );
		v.set( "Server_dns_server", p.getDnsServer() );
		v.set( "Server_file_server", p.getFileServer() );
		v.set( "Server_db_server", p.getDbServer() );
		v.set( "Server_vserver_server", p.getVserverServer() );
		v.set( "Server_proxy_server", p.getProxyServer() );
		v.set( "Server_firewall_server", p.getFirewallServer() );
		v.set( "Server_config", p.getConfig() );
		v.set( "Server_updated", p.getUpdated() );
		v.set( "Server_mirror_server_id", p.getMirrorServerId() );
		v.set( "Server_dbversion", p.getDbversion() );
		v.set( "Server_active", p.getActive() );
		ind = i_ok;
	}
};
}

#endif // SERVERREPOSITORY_H
