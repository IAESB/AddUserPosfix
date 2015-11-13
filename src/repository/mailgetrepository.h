#ifndef MAILGETREPOSITORY_H
#define MAILGETREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/mailget.h"
using namespace soci;


class MailGetRepository
{
	soci::session& dataBase;
public:
	MailGetRepository(soci::session& dataBase);
	int insert(const MailGet& mailget);
	MailGetPtr select(const MailGet& mailget);
	MailGetList select(const string& where="");
	void update(const MailGet& mailget);
	void update(const MailGet& oldObj, const MailGet& newObj);
	void remove(const MailGet& mailget);
};

namespace soci
{
template<>
struct type_conversion<MailGet>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, MailGet & p)
	{
		if (v.get_indicator("MailGet_mailget_id") != i_null){
			p.setMailgetId( v.template get<long long>("MailGet_mailget_id" ) );
		}
		if (v.get_indicator("MailGet_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("MailGet_sys_userid" ) );
		}
		if (v.get_indicator("MailGet_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("MailGet_sys_groupid" ) );
		}
		if (v.get_indicator("MailGet_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("MailGet_sys_perm_user" ) );
		}
		if (v.get_indicator("MailGet_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("MailGet_sys_perm_group" ) );
		}
		if (v.get_indicator("MailGet_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("MailGet_sys_perm_other" ) );
		}
		if (v.get_indicator("MailGet_server_id") != i_null){
			p.setServerId( v.template get<long long>("MailGet_server_id" ) );
		}
		if (v.get_indicator("MailGet_type") != i_null){
			p.setType( v.template get<std::string>("MailGet_type" ) );
		}
		if (v.get_indicator("MailGet_source_server") != i_null){
			p.setSourceServer( v.template get<std::string>("MailGet_source_server" ) );
		}
		if (v.get_indicator("MailGet_source_username") != i_null){
			p.setSourceUsername( v.template get<std::string>("MailGet_source_username" ) );
		}
		if (v.get_indicator("MailGet_source_password") != i_null){
			p.setSourcePassword( v.template get<std::string>("MailGet_source_password" ) );
		}
		if (v.get_indicator("MailGet_source_delete") != i_null){
			p.setSourceDelete( v.template get<std::string>("MailGet_source_delete" ) );
		}
		if (v.get_indicator("MailGet_source_read_all") != i_null){
			p.setSourceReadAll( v.template get<std::string>("MailGet_source_read_all" ) );
		}
		if (v.get_indicator("MailGet_destination") != i_null){
			p.setDestination( v.template get<std::string>("MailGet_destination" ) );
		}
		if (v.get_indicator("MailGet_active") != i_null){
			p.setActive( v.template get<std::string>("MailGet_active" ) );
		}
	}
	static void to_base(const MailGet & p, values & v, indicator & ind)
	{
		v.set( "MailGet_mailget_id", p.getMailgetId() );
		v.set( "MailGet_sys_userid", p.getSysUserid() );
		v.set( "MailGet_sys_groupid", p.getSysGroupid() );
		v.set( "MailGet_sys_perm_user", p.getSysPermUser() );
		v.set( "MailGet_sys_perm_group", p.getSysPermGroup() );
		v.set( "MailGet_sys_perm_other", p.getSysPermOther() );
		v.set( "MailGet_server_id", p.getServerId() );
		v.set( "MailGet_type", p.getType() );
		v.set( "MailGet_source_server", p.getSourceServer() );
		v.set( "MailGet_source_username", p.getSourceUsername() );
		v.set( "MailGet_source_password", p.getSourcePassword() );
		v.set( "MailGet_source_delete", p.getSourceDelete() );
		v.set( "MailGet_source_read_all", p.getSourceReadAll() );
		v.set( "MailGet_destination", p.getDestination() );
		v.set( "MailGet_active", p.getActive() );
		ind = i_ok;
	}
};
}

#endif // MAILGETREPOSITORY_H
