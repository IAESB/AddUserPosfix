#ifndef MAILACCESSREPOSITORY_H
#define MAILACCESSREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/mailaccess.h"
using namespace soci;


class MailAccessRepository
{
	soci::session& dataBase;
public:
	MailAccessRepository(soci::session& dataBase);
	int insert(const MailAccess& mailaccess);
	MailAccessPtr select(const MailAccess& mailaccess);
	MailAccessList select(const string& where="");
	void update(const MailAccess& mailaccess);
	void update(const MailAccess& oldObj, const MailAccess& newObj);
	void remove(const MailAccess& mailaccess);
};

namespace soci
{
template<>
struct type_conversion<MailAccess>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, MailAccess & p)
	{
		if (v.get_indicator("MailAccess_access_id") != i_null){
			p.setAccessId( v.template get<long long>("MailAccess_access_id" ) );
		}
		if (v.get_indicator("MailAccess_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("MailAccess_sys_userid" ) );
		}
		if (v.get_indicator("MailAccess_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("MailAccess_sys_groupid" ) );
		}
		if (v.get_indicator("MailAccess_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("MailAccess_sys_perm_user" ) );
		}
		if (v.get_indicator("MailAccess_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("MailAccess_sys_perm_group" ) );
		}
		if (v.get_indicator("MailAccess_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("MailAccess_sys_perm_other" ) );
		}
		if (v.get_indicator("MailAccess_server_id") != i_null){
			p.setServerId( v.template get<int>("MailAccess_server_id" ) );
		}
		if (v.get_indicator("MailAccess_source") != i_null){
			p.setSource( v.template get<std::string>("MailAccess_source" ) );
		}
		if (v.get_indicator("MailAccess_access") != i_null){
			p.setAccess( v.template get<std::string>("MailAccess_access" ) );
		}
		if (v.get_indicator("MailAccess_type") != i_null){
			p.setType( v.template get<std::string>("MailAccess_type" ) );
		}
		if (v.get_indicator("MailAccess_active") != i_null){
			p.setActive( v.template get<std::string>("MailAccess_active" ) );
		}
	}
	static void to_base(const MailAccess & p, values & v, indicator & ind)
	{
		v.set( "MailAccess_access_id", p.getAccessId() );
		v.set( "MailAccess_sys_userid", p.getSysUserid() );
		v.set( "MailAccess_sys_groupid", p.getSysGroupid() );
		v.set( "MailAccess_sys_perm_user", p.getSysPermUser() );
		v.set( "MailAccess_sys_perm_group", p.getSysPermGroup() );
		v.set( "MailAccess_sys_perm_other", p.getSysPermOther() );
		v.set( "MailAccess_server_id", p.getServerId() );
		v.set( "MailAccess_source", p.getSource() );
		v.set( "MailAccess_access", p.getAccess() );
		v.set( "MailAccess_type", p.getType() );
		v.set( "MailAccess_active", p.getActive() );
		ind = i_ok;
	}
};
}

#endif // MAILACCESSREPOSITORY_H
