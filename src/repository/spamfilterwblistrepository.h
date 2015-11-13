#ifndef SPAMFILTERWBLISTREPOSITORY_H
#define SPAMFILTERWBLISTREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/spamfilterwblist.h"
using namespace soci;


class SpamfilterWblistRepository
{
	soci::session& dataBase;
public:
	SpamfilterWblistRepository(soci::session& dataBase);
	int insert(const SpamfilterWblist& spamfilterwblist);
	SpamfilterWblistPtr select(const SpamfilterWblist& spamfilterwblist);
	SpamfilterWblistList select(const string& where="");
	void update(const SpamfilterWblist& spamfilterwblist);
	void update(const SpamfilterWblist& oldObj, const SpamfilterWblist& newObj);
	void remove(const SpamfilterWblist& spamfilterwblist);
};

namespace soci
{
template<>
struct type_conversion<SpamfilterWblist>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, SpamfilterWblist & p)
	{
		if (v.get_indicator("SpamfilterWblist_wblist_id") != i_null){
			p.setWblistId( v.template get<long long>("SpamfilterWblist_wblist_id" ) );
		}
		if (v.get_indicator("SpamfilterWblist_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("SpamfilterWblist_sys_userid" ) );
		}
		if (v.get_indicator("SpamfilterWblist_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("SpamfilterWblist_sys_groupid" ) );
		}
		if (v.get_indicator("SpamfilterWblist_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("SpamfilterWblist_sys_perm_user" ) );
		}
		if (v.get_indicator("SpamfilterWblist_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("SpamfilterWblist_sys_perm_group" ) );
		}
		if (v.get_indicator("SpamfilterWblist_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("SpamfilterWblist_sys_perm_other" ) );
		}
		if (v.get_indicator("SpamfilterWblist_server_id") != i_null){
			p.setServerId( v.template get<long long>("SpamfilterWblist_server_id" ) );
		}
		if (v.get_indicator("SpamfilterWblist_wb") != i_null){
			p.setWb( v.template get<std::string>("SpamfilterWblist_wb" ) );
		}
		if (v.get_indicator("SpamfilterWblist_rid") != i_null){
			p.setRid( v.template get<long long>("SpamfilterWblist_rid" ) );
		}
		if (v.get_indicator("SpamfilterWblist_email") != i_null){
			p.setEmail( v.template get<std::string>("SpamfilterWblist_email" ) );
		}
		if (v.get_indicator("SpamfilterWblist_priority") != i_null){
			p.setPriority( v.template get<int>("SpamfilterWblist_priority" ) );
		}
		if (v.get_indicator("SpamfilterWblist_active") != i_null){
			p.setActive( v.template get<std::string>("SpamfilterWblist_active" ) );
		}
	}
	static void to_base(const SpamfilterWblist & p, values & v, indicator & ind)
	{
		v.set( "SpamfilterWblist_wblist_id", p.getWblistId() );
		v.set( "SpamfilterWblist_sys_userid", p.getSysUserid() );
		v.set( "SpamfilterWblist_sys_groupid", p.getSysGroupid() );
		v.set( "SpamfilterWblist_sys_perm_user", p.getSysPermUser() );
		v.set( "SpamfilterWblist_sys_perm_group", p.getSysPermGroup() );
		v.set( "SpamfilterWblist_sys_perm_other", p.getSysPermOther() );
		v.set( "SpamfilterWblist_server_id", p.getServerId() );
		v.set( "SpamfilterWblist_wb", p.getWb() );
		v.set( "SpamfilterWblist_rid", p.getRid() );
		v.set( "SpamfilterWblist_email", p.getEmail() );
		v.set( "SpamfilterWblist_priority", p.getPriority() );
		v.set( "SpamfilterWblist_active", p.getActive() );
		ind = i_ok;
	}
};
}

#endif // SPAMFILTERWBLISTREPOSITORY_H
