#ifndef MAILTRANSPORTREPOSITORY_H
#define MAILTRANSPORTREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/mailtransport.h"
using namespace soci;


class MailTransportRepository
{
	soci::session& dataBase;
public:
	MailTransportRepository(soci::session& dataBase);
	int insert(const MailTransport& mailtransport);
	MailTransportPtr select(const MailTransport& mailtransport);
	MailTransportList select(const string& where="");
	void update(const MailTransport& mailtransport);
	void update(const MailTransport& oldObj, const MailTransport& newObj);
	void remove(const MailTransport& mailtransport);
};

namespace soci
{
template<>
struct type_conversion<MailTransport>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, MailTransport & p)
	{
		if (v.get_indicator("MailTransport_transport_id") != i_null){
			p.setTransportId( v.template get<long long>("MailTransport_transport_id" ) );
		}
		if (v.get_indicator("MailTransport_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("MailTransport_sys_userid" ) );
		}
		if (v.get_indicator("MailTransport_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("MailTransport_sys_groupid" ) );
		}
		if (v.get_indicator("MailTransport_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("MailTransport_sys_perm_user" ) );
		}
		if (v.get_indicator("MailTransport_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("MailTransport_sys_perm_group" ) );
		}
		if (v.get_indicator("MailTransport_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("MailTransport_sys_perm_other" ) );
		}
		if (v.get_indicator("MailTransport_server_id") != i_null){
			p.setServerId( v.template get<long long>("MailTransport_server_id" ) );
		}
		if (v.get_indicator("MailTransport_domain") != i_null){
			p.setDomain( v.template get<std::string>("MailTransport_domain" ) );
		}
		if (v.get_indicator("MailTransport_transport") != i_null){
			p.setTransport( v.template get<std::string>("MailTransport_transport" ) );
		}
		if (v.get_indicator("MailTransport_sort_order") != i_null){
			p.setSortOrder( v.template get<long long>("MailTransport_sort_order" ) );
		}
		if (v.get_indicator("MailTransport_active") != i_null){
			p.setActive( v.template get<std::string>("MailTransport_active" ) );
		}
	}
	static void to_base(const MailTransport & p, values & v, indicator & ind)
	{
		v.set( "MailTransport_transport_id", p.getTransportId() );
		v.set( "MailTransport_sys_userid", p.getSysUserid() );
		v.set( "MailTransport_sys_groupid", p.getSysGroupid() );
		v.set( "MailTransport_sys_perm_user", p.getSysPermUser() );
		v.set( "MailTransport_sys_perm_group", p.getSysPermGroup() );
		v.set( "MailTransport_sys_perm_other", p.getSysPermOther() );
		v.set( "MailTransport_server_id", p.getServerId() );
		v.set( "MailTransport_domain", p.getDomain() );
		v.set( "MailTransport_transport", p.getTransport() );
		v.set( "MailTransport_sort_order", p.getSortOrder() );
		v.set( "MailTransport_active", p.getActive() );
		ind = i_ok;
	}
};
}

#endif // MAILTRANSPORTREPOSITORY_H
