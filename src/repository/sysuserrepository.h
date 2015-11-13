#ifndef SYSUSERREPOSITORY_H
#define SYSUSERREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/sysuser.h"
using namespace soci;


class SysUserRepository
{
	soci::session& dataBase;
public:
	SysUserRepository(soci::session& dataBase);
	int insert(const SysUser& sysuser);
	SysUserPtr select(const SysUser& sysuser);
	SysUserList select(const string& where="");
	void update(const SysUser& sysuser);
	void update(const SysUser& oldObj, const SysUser& newObj);
	void remove(const SysUser& sysuser);
};

namespace soci
{
template<>
struct type_conversion<SysUser>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, SysUser & p)
	{
		if (v.get_indicator("SysUser_userid") != i_null){
			p.setUserid( v.template get<long long>("SysUser_userid" ) );
		}
		if (v.get_indicator("SysUser_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("SysUser_sys_userid" ) );
		}
		if (v.get_indicator("SysUser_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("SysUser_sys_groupid" ) );
		}
		if (v.get_indicator("SysUser_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("SysUser_sys_perm_user" ) );
		}
		if (v.get_indicator("SysUser_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("SysUser_sys_perm_group" ) );
		}
		if (v.get_indicator("SysUser_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("SysUser_sys_perm_other" ) );
		}
		if (v.get_indicator("SysUser_username") != i_null){
			p.setUsername( v.template get<std::string>("SysUser_username" ) );
		}
		if (v.get_indicator("SysUser_passwort") != i_null){
			p.setPasswort( v.template get<std::string>("SysUser_passwort" ) );
		}
		if (v.get_indicator("SysUser_modules") != i_null){
			p.setModules( v.template get<std::string>("SysUser_modules" ) );
		}
		if (v.get_indicator("SysUser_startmodule") != i_null){
			p.setStartmodule( v.template get<std::string>("SysUser_startmodule" ) );
		}
		if (v.get_indicator("SysUser_app_theme") != i_null){
			p.setAppTheme( v.template get<std::string>("SysUser_app_theme" ) );
		}
		if (v.get_indicator("SysUser_typ") != i_null){
			p.setTyp( v.template get<std::string>("SysUser_typ" ) );
		}
		if (v.get_indicator("SysUser_active") != i_null){
			p.setActive( v.template get<int>("SysUser_active" ) );
		}
		if (v.get_indicator("SysUser_language") != i_null){
			p.setLanguage( v.template get<std::string>("SysUser_language" ) );
		}
		if (v.get_indicator("SysUser_groups") != i_null){
			p.setGroups( v.template get<std::string>("SysUser_groups" ) );
		}
		if (v.get_indicator("SysUser_default_group") != i_null){
			p.setDefaultGroup( v.template get<long long>("SysUser_default_group" ) );
		}
		if (v.get_indicator("SysUser_client_id") != i_null){
			p.setClientId( v.template get<long long>("SysUser_client_id" ) );
		}
		if (v.get_indicator("SysUser_id_rsa") != i_null){
			p.setIdRsa( v.template get<std::string>("SysUser_id_rsa" ) );
		}
		if (v.get_indicator("SysUser_ssh_rsa") != i_null){
			p.setSshRsa( v.template get<std::string>("SysUser_ssh_rsa" ) );
		}
	}
	static void to_base(const SysUser & p, values & v, indicator & ind)
	{
		v.set( "SysUser_userid", p.getUserid() );
		v.set( "SysUser_sys_userid", p.getSysUserid() );
		v.set( "SysUser_sys_groupid", p.getSysGroupid() );
		v.set( "SysUser_sys_perm_user", p.getSysPermUser() );
		v.set( "SysUser_sys_perm_group", p.getSysPermGroup() );
		v.set( "SysUser_sys_perm_other", p.getSysPermOther() );
		v.set( "SysUser_username", p.getUsername() );
		v.set( "SysUser_passwort", p.getPasswort() );
		v.set( "SysUser_modules", p.getModules() );
		v.set( "SysUser_startmodule", p.getStartmodule() );
		v.set( "SysUser_app_theme", p.getAppTheme() );
		v.set( "SysUser_typ", p.getTyp() );
		v.set( "SysUser_active", p.getActive() );
		v.set( "SysUser_language", p.getLanguage() );
		v.set( "SysUser_groups", p.getGroups() );
		v.set( "SysUser_default_group", p.getDefaultGroup() );
		v.set( "SysUser_client_id", p.getClientId() );
		v.set( "SysUser_id_rsa", p.getIdRsa() );
		v.set( "SysUser_ssh_rsa", p.getSshRsa() );
		ind = i_ok;
	}
};
}

#endif // SYSUSERREPOSITORY_H
