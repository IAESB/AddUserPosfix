#ifndef MAILRELAYRECIPIENTREPOSITORY_H
#define MAILRELAYRECIPIENTREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/mailrelayrecipient.h"
using namespace soci;


class MailRelayRecipientRepository
{
	soci::session& dataBase;
public:
	MailRelayRecipientRepository(soci::session& dataBase);
	int insert(const MailRelayRecipient& mailrelayrecipient);
	MailRelayRecipientPtr select(const MailRelayRecipient& mailrelayrecipient);
	MailRelayRecipientList select(const string& where="");
	void update(const MailRelayRecipient& mailrelayrecipient);
	void update(const MailRelayRecipient& oldObj, const MailRelayRecipient& newObj);
	void remove(const MailRelayRecipient& mailrelayrecipient);
};

namespace soci
{
template<>
struct type_conversion<MailRelayRecipient>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, MailRelayRecipient & p)
	{
		if (v.get_indicator("MailRelayRecipient_relay_recipient_id") != i_null){
			p.setRelayRecipientId( v.template get<long long>("MailRelayRecipient_relay_recipient_id" ) );
		}
		if (v.get_indicator("MailRelayRecipient_sys_userid") != i_null){
			p.setSysUserid( v.template get<int>("MailRelayRecipient_sys_userid" ) );
		}
		if (v.get_indicator("MailRelayRecipient_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<int>("MailRelayRecipient_sys_groupid" ) );
		}
		if (v.get_indicator("MailRelayRecipient_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("MailRelayRecipient_sys_perm_user" ) );
		}
		if (v.get_indicator("MailRelayRecipient_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("MailRelayRecipient_sys_perm_group" ) );
		}
		if (v.get_indicator("MailRelayRecipient_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("MailRelayRecipient_sys_perm_other" ) );
		}
		if (v.get_indicator("MailRelayRecipient_server_id") != i_null){
			p.setServerId( v.template get<int>("MailRelayRecipient_server_id" ) );
		}
		if (v.get_indicator("MailRelayRecipient_source") != i_null){
			p.setSource( v.template get<std::string>("MailRelayRecipient_source" ) );
		}
		if (v.get_indicator("MailRelayRecipient_access") != i_null){
			p.setAccess( v.template get<std::string>("MailRelayRecipient_access" ) );
		}
		if (v.get_indicator("MailRelayRecipient_active") != i_null){
			p.setActive( v.template get<std::string>("MailRelayRecipient_active" ) );
		}
	}
	static void to_base(const MailRelayRecipient & p, values & v, indicator & ind)
	{
		v.set( "MailRelayRecipient_relay_recipient_id", p.getRelayRecipientId() );
		v.set( "MailRelayRecipient_sys_userid", p.getSysUserid() );
		v.set( "MailRelayRecipient_sys_groupid", p.getSysGroupid() );
		v.set( "MailRelayRecipient_sys_perm_user", p.getSysPermUser() );
		v.set( "MailRelayRecipient_sys_perm_group", p.getSysPermGroup() );
		v.set( "MailRelayRecipient_sys_perm_other", p.getSysPermOther() );
		v.set( "MailRelayRecipient_server_id", p.getServerId() );
		v.set( "MailRelayRecipient_source", p.getSource() );
		v.set( "MailRelayRecipient_access", p.getAccess() );
		v.set( "MailRelayRecipient_active", p.getActive() );
		ind = i_ok;
	}
};
}

#endif // MAILRELAYRECIPIENTREPOSITORY_H
