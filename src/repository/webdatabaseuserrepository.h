#ifndef WEBDATABASEUSERREPOSITORY_H
#define WEBDATABASEUSERREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/webdatabaseuser.h"
using namespace soci;


class WebDatabaseUserRepository
{
	soci::session& dataBase;
public:
	WebDatabaseUserRepository(soci::session& dataBase);
	int insert(const WebDatabaseUser& webdatabaseuser);
	WebDatabaseUserPtr select(const WebDatabaseUser& webdatabaseuser);
	WebDatabaseUserList select(const string& where="");
	void update(const WebDatabaseUser& webdatabaseuser);
	void update(const WebDatabaseUser& oldObj, const WebDatabaseUser& newObj);
	void remove(const WebDatabaseUser& webdatabaseuser);
};

namespace soci
{
template<>
struct type_conversion<WebDatabaseUser>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, WebDatabaseUser & p)
	{
		if (v.get_indicator("WebDatabaseUser_database_user_id") != i_null){
			p.setDatabaseUserId( v.template get<long long>("WebDatabaseUser_database_user_id" ) );
		}
		if (v.get_indicator("WebDatabaseUser_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("WebDatabaseUser_sys_userid" ) );
		}
		if (v.get_indicator("WebDatabaseUser_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("WebDatabaseUser_sys_groupid" ) );
		}
		if (v.get_indicator("WebDatabaseUser_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("WebDatabaseUser_sys_perm_user" ) );
		}
		if (v.get_indicator("WebDatabaseUser_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("WebDatabaseUser_sys_perm_group" ) );
		}
		if (v.get_indicator("WebDatabaseUser_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("WebDatabaseUser_sys_perm_other" ) );
		}
		if (v.get_indicator("WebDatabaseUser_server_id") != i_null){
			p.setServerId( v.template get<long long>("WebDatabaseUser_server_id" ) );
		}
		if (v.get_indicator("WebDatabaseUser_database_user") != i_null){
			p.setDatabaseUser( v.template get<std::string>("WebDatabaseUser_database_user" ) );
		}
		if (v.get_indicator("WebDatabaseUser_database_user_prefix") != i_null){
			p.setDatabaseUserPrefix( v.template get<std::string>("WebDatabaseUser_database_user_prefix" ) );
		}
		if (v.get_indicator("WebDatabaseUser_database_password") != i_null){
			p.setDatabasePassword( v.template get<std::string>("WebDatabaseUser_database_password" ) );
		}
		if (v.get_indicator("WebDatabaseUser_database_password_mongo") != i_null){
			p.setDatabasePasswordMongo( v.template get<std::string>("WebDatabaseUser_database_password_mongo" ) );
		}
	}
	static void to_base(const WebDatabaseUser & p, values & v, indicator & ind)
	{
		v.set( "WebDatabaseUser_database_user_id", p.getDatabaseUserId() );
		v.set( "WebDatabaseUser_sys_userid", p.getSysUserid() );
		v.set( "WebDatabaseUser_sys_groupid", p.getSysGroupid() );
		v.set( "WebDatabaseUser_sys_perm_user", p.getSysPermUser() );
		v.set( "WebDatabaseUser_sys_perm_group", p.getSysPermGroup() );
		v.set( "WebDatabaseUser_sys_perm_other", p.getSysPermOther() );
		v.set( "WebDatabaseUser_server_id", p.getServerId() );
		v.set( "WebDatabaseUser_database_user", p.getDatabaseUser() );
		v.set( "WebDatabaseUser_database_user_prefix", p.getDatabaseUserPrefix() );
		v.set( "WebDatabaseUser_database_password", p.getDatabasePassword() );
		v.set( "WebDatabaseUser_database_password_mongo", p.getDatabasePasswordMongo() );
		ind = i_ok;
	}
};
}

#endif // WEBDATABASEUSERREPOSITORY_H
