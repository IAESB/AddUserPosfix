#ifndef WEBDAVUSERREPOSITORY_H
#define WEBDAVUSERREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/webdavuser.h"
using namespace soci;


class WebdavUserRepository
{
	soci::session& dataBase;
public:
	WebdavUserRepository(soci::session& dataBase);
	int insert(const WebdavUser& webdavuser);
	WebdavUserPtr select(const WebdavUser& webdavuser);
	WebdavUserList select(const string& where="");
	void update(const WebdavUser& webdavuser);
	void update(const WebdavUser& oldObj, const WebdavUser& newObj);
	void remove(const WebdavUser& webdavuser);
};

namespace soci
{
template<>
struct type_conversion<WebdavUser>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, WebdavUser & p)
	{
		if (v.get_indicator("WebdavUser_webdav_user_id") != i_null){
			p.setWebdavUserId( v.template get<long long>("WebdavUser_webdav_user_id" ) );
		}
		if (v.get_indicator("WebdavUser_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("WebdavUser_sys_userid" ) );
		}
		if (v.get_indicator("WebdavUser_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("WebdavUser_sys_groupid" ) );
		}
		if (v.get_indicator("WebdavUser_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("WebdavUser_sys_perm_user" ) );
		}
		if (v.get_indicator("WebdavUser_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("WebdavUser_sys_perm_group" ) );
		}
		if (v.get_indicator("WebdavUser_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("WebdavUser_sys_perm_other" ) );
		}
		if (v.get_indicator("WebdavUser_server_id") != i_null){
			p.setServerId( v.template get<long long>("WebdavUser_server_id" ) );
		}
		if (v.get_indicator("WebdavUser_parent_domain_id") != i_null){
			p.setParentDomainId( v.template get<long long>("WebdavUser_parent_domain_id" ) );
		}
		if (v.get_indicator("WebdavUser_username") != i_null){
			p.setUsername( v.template get<std::string>("WebdavUser_username" ) );
		}
		if (v.get_indicator("WebdavUser_username_prefix") != i_null){
			p.setUsernamePrefix( v.template get<std::string>("WebdavUser_username_prefix" ) );
		}
		if (v.get_indicator("WebdavUser_password") != i_null){
			p.setPassword( v.template get<std::string>("WebdavUser_password" ) );
		}
		if (v.get_indicator("WebdavUser_active") != i_null){
			p.setActive( v.template get<std::string>("WebdavUser_active" ) );
		}
		if (v.get_indicator("WebdavUser_dir") != i_null){
			p.setDir( v.template get<std::string>("WebdavUser_dir" ) );
		}
	}
	static void to_base(const WebdavUser & p, values & v, indicator & ind)
	{
		v.set( "WebdavUser_webdav_user_id", p.getWebdavUserId() );
		v.set( "WebdavUser_sys_userid", p.getSysUserid() );
		v.set( "WebdavUser_sys_groupid", p.getSysGroupid() );
		v.set( "WebdavUser_sys_perm_user", p.getSysPermUser() );
		v.set( "WebdavUser_sys_perm_group", p.getSysPermGroup() );
		v.set( "WebdavUser_sys_perm_other", p.getSysPermOther() );
		v.set( "WebdavUser_server_id", p.getServerId() );
		v.set( "WebdavUser_parent_domain_id", p.getParentDomainId() );
		v.set( "WebdavUser_username", p.getUsername() );
		v.set( "WebdavUser_username_prefix", p.getUsernamePrefix() );
		v.set( "WebdavUser_password", p.getPassword() );
		v.set( "WebdavUser_active", p.getActive() );
		v.set( "WebdavUser_dir", p.getDir() );
		ind = i_ok;
	}
};
}

#endif // WEBDAVUSERREPOSITORY_H
