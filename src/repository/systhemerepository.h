#ifndef SYSTHEMEREPOSITORY_H
#define SYSTHEMEREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/systheme.h"
using namespace soci;


class SysThemeRepository
{
	soci::session& dataBase;
public:
	SysThemeRepository(soci::session& dataBase);
	int insert(const SysTheme& systheme);
	SysThemePtr select(const SysTheme& systheme);
	SysThemeList select(const string& where="");
	void update(const SysTheme& systheme);
	void update(const SysTheme& oldObj, const SysTheme& newObj);
	void remove(const SysTheme& systheme);
};

namespace soci
{
template<>
struct type_conversion<SysTheme>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, SysTheme & p)
	{
		if (v.get_indicator("SysTheme_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("SysTheme_sys_userid" ) );
		}
		if (v.get_indicator("SysTheme_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("SysTheme_sys_groupid" ) );
		}
		if (v.get_indicator("SysTheme_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("SysTheme_sys_perm_user" ) );
		}
		if (v.get_indicator("SysTheme_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("SysTheme_sys_perm_group" ) );
		}
		if (v.get_indicator("SysTheme_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("SysTheme_sys_perm_other" ) );
		}
		if (v.get_indicator("SysTheme_var_id") != i_null){
			p.setVarId( v.template get<long long>("SysTheme_var_id" ) );
		}
		if (v.get_indicator("SysTheme_tpl_name") != i_null){
			p.setTplName( v.template get<std::string>("SysTheme_tpl_name" ) );
		}
		if (v.get_indicator("SysTheme_username") != i_null){
			p.setUsername( v.template get<std::string>("SysTheme_username" ) );
		}
		if (v.get_indicator("SysTheme_logo_url") != i_null){
			p.setLogoUrl( v.template get<std::string>("SysTheme_logo_url" ) );
		}
	}
	static void to_base(const SysTheme & p, values & v, indicator & ind)
	{
		v.set( "SysTheme_sys_userid", p.getSysUserid() );
		v.set( "SysTheme_sys_groupid", p.getSysGroupid() );
		v.set( "SysTheme_sys_perm_user", p.getSysPermUser() );
		v.set( "SysTheme_sys_perm_group", p.getSysPermGroup() );
		v.set( "SysTheme_sys_perm_other", p.getSysPermOther() );
		v.set( "SysTheme_var_id", p.getVarId() );
		v.set( "SysTheme_tpl_name", p.getTplName() );
		v.set( "SysTheme_username", p.getUsername() );
		v.set( "SysTheme_logo_url", p.getLogoUrl() );
		ind = i_ok;
	}
};
}

#endif // SYSTHEMEREPOSITORY_H
