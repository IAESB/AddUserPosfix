#ifndef SERVERPHPREPOSITORY_H
#define SERVERPHPREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/serverphp.h"
using namespace soci;


class ServerPhpRepository
{
	soci::session& dataBase;
public:
	ServerPhpRepository(soci::session& dataBase);
	int insert(const ServerPhp& serverphp);
	ServerPhpPtr select(const ServerPhp& serverphp);
	ServerPhpList select(const string& where="");
	void update(const ServerPhp& serverphp);
	void update(const ServerPhp& oldObj, const ServerPhp& newObj);
	void remove(const ServerPhp& serverphp);
};

namespace soci
{
template<>
struct type_conversion<ServerPhp>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, ServerPhp & p)
	{
		if (v.get_indicator("ServerPhp_server_php_id") != i_null){
			p.setServerPhpId( v.template get<long long>("ServerPhp_server_php_id" ) );
		}
		if (v.get_indicator("ServerPhp_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("ServerPhp_sys_userid" ) );
		}
		if (v.get_indicator("ServerPhp_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("ServerPhp_sys_groupid" ) );
		}
		if (v.get_indicator("ServerPhp_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("ServerPhp_sys_perm_user" ) );
		}
		if (v.get_indicator("ServerPhp_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("ServerPhp_sys_perm_group" ) );
		}
		if (v.get_indicator("ServerPhp_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("ServerPhp_sys_perm_other" ) );
		}
		if (v.get_indicator("ServerPhp_server_id") != i_null){
			p.setServerId( v.template get<long long>("ServerPhp_server_id" ) );
		}
		if (v.get_indicator("ServerPhp_client_id") != i_null){
			p.setClientId( v.template get<long long>("ServerPhp_client_id" ) );
		}
		if (v.get_indicator("ServerPhp_name") != i_null){
			p.setName( v.template get<std::string>("ServerPhp_name" ) );
		}
		if (v.get_indicator("ServerPhp_php_fastcgi_binary") != i_null){
			p.setPhpFastcgiBinary( v.template get<std::string>("ServerPhp_php_fastcgi_binary" ) );
		}
		if (v.get_indicator("ServerPhp_php_fastcgi_ini_dir") != i_null){
			p.setPhpFastcgiIniDir( v.template get<std::string>("ServerPhp_php_fastcgi_ini_dir" ) );
		}
		if (v.get_indicator("ServerPhp_php_fpm_init_script") != i_null){
			p.setPhpFpmInitScript( v.template get<std::string>("ServerPhp_php_fpm_init_script" ) );
		}
		if (v.get_indicator("ServerPhp_php_fpm_ini_dir") != i_null){
			p.setPhpFpmIniDir( v.template get<std::string>("ServerPhp_php_fpm_ini_dir" ) );
		}
		if (v.get_indicator("ServerPhp_php_fpm_pool_dir") != i_null){
			p.setPhpFpmPoolDir( v.template get<std::string>("ServerPhp_php_fpm_pool_dir" ) );
		}
	}
	static void to_base(const ServerPhp & p, values & v, indicator & ind)
	{
		v.set( "ServerPhp_server_php_id", p.getServerPhpId() );
		v.set( "ServerPhp_sys_userid", p.getSysUserid() );
		v.set( "ServerPhp_sys_groupid", p.getSysGroupid() );
		v.set( "ServerPhp_sys_perm_user", p.getSysPermUser() );
		v.set( "ServerPhp_sys_perm_group", p.getSysPermGroup() );
		v.set( "ServerPhp_sys_perm_other", p.getSysPermOther() );
		v.set( "ServerPhp_server_id", p.getServerId() );
		v.set( "ServerPhp_client_id", p.getClientId() );
		v.set( "ServerPhp_name", p.getName() );
		v.set( "ServerPhp_php_fastcgi_binary", p.getPhpFastcgiBinary() );
		v.set( "ServerPhp_php_fastcgi_ini_dir", p.getPhpFastcgiIniDir() );
		v.set( "ServerPhp_php_fpm_init_script", p.getPhpFpmInitScript() );
		v.set( "ServerPhp_php_fpm_ini_dir", p.getPhpFpmIniDir() );
		v.set( "ServerPhp_php_fpm_pool_dir", p.getPhpFpmPoolDir() );
		ind = i_ok;
	}
};
}

#endif // SERVERPHPREPOSITORY_H
