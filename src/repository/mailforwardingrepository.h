#ifndef MAILFORWARDINGREPOSITORY_H
#define MAILFORWARDINGREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/mailforwarding.h"
using namespace soci;


class MailForwardingRepository
{
	soci::session& dataBase;
public:
	MailForwardingRepository(soci::session& dataBase);
	int insert(const MailForwarding& mailforwarding);
	MailForwardingPtr select(const MailForwarding& mailforwarding);
	MailForwardingList select(const string& where="");
	void update(const MailForwarding& mailforwarding);
	void update(const MailForwarding& oldObj, const MailForwarding& newObj);
	void remove(const MailForwarding& mailforwarding);
};

namespace soci
{
template<>
struct type_conversion<MailForwarding>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, MailForwarding & p)
	{
		if (v.get_indicator("MailForwarding_forwarding_id") != i_null){
			p.setForwardingId( v.template get<long long>("MailForwarding_forwarding_id" ) );
		}
		if (v.get_indicator("MailForwarding_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("MailForwarding_sys_userid" ) );
		}
		if (v.get_indicator("MailForwarding_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("MailForwarding_sys_groupid" ) );
		}
		if (v.get_indicator("MailForwarding_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("MailForwarding_sys_perm_user" ) );
		}
		if (v.get_indicator("MailForwarding_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("MailForwarding_sys_perm_group" ) );
		}
		if (v.get_indicator("MailForwarding_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("MailForwarding_sys_perm_other" ) );
		}
		if (v.get_indicator("MailForwarding_server_id") != i_null){
			p.setServerId( v.template get<long long>("MailForwarding_server_id" ) );
		}
		if (v.get_indicator("MailForwarding_source") != i_null){
			p.setSource( v.template get<std::string>("MailForwarding_source" ) );
		}
		if (v.get_indicator("MailForwarding_destination") != i_null){
			p.setDestination( v.template get<std::string>("MailForwarding_destination" ) );
		}
		if (v.get_indicator("MailForwarding_type") != i_null){
			p.setType( v.template get<std::string>("MailForwarding_type" ) );
		}
		if (v.get_indicator("MailForwarding_active") != i_null){
			p.setActive( v.template get<std::string>("MailForwarding_active" ) );
		}
	}
	static void to_base(const MailForwarding & p, values & v, indicator & ind)
	{
		v.set( "MailForwarding_forwarding_id", p.getForwardingId() );
		v.set( "MailForwarding_sys_userid", p.getSysUserid() );
		v.set( "MailForwarding_sys_groupid", p.getSysGroupid() );
		v.set( "MailForwarding_sys_perm_user", p.getSysPermUser() );
		v.set( "MailForwarding_sys_perm_group", p.getSysPermGroup() );
		v.set( "MailForwarding_sys_perm_other", p.getSysPermOther() );
		v.set( "MailForwarding_server_id", p.getServerId() );
		v.set( "MailForwarding_source", p.getSource() );
		v.set( "MailForwarding_destination", p.getDestination() );
		v.set( "MailForwarding_type", p.getType() );
		v.set( "MailForwarding_active", p.getActive() );
		ind = i_ok;
	}
};
}

#endif // MAILFORWARDINGREPOSITORY_H
