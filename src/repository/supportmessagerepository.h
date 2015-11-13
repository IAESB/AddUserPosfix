#ifndef SUPPORTMESSAGEREPOSITORY_H
#define SUPPORTMESSAGEREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/supportmessage.h"
using namespace soci;


class SupportMessageRepository
{
	soci::session& dataBase;
public:
	SupportMessageRepository(soci::session& dataBase);
	int insert(const SupportMessage& supportmessage);
	SupportMessagePtr select(const SupportMessage& supportmessage);
	SupportMessageList select(const string& where="");
	void update(const SupportMessage& supportmessage);
	void update(const SupportMessage& oldObj, const SupportMessage& newObj);
	void remove(const SupportMessage& supportmessage);
};

namespace soci
{
template<>
struct type_conversion<SupportMessage>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, SupportMessage & p)
	{
		if (v.get_indicator("SupportMessage_support_message_id") != i_null){
			p.setSupportMessageId( v.template get<long long>("SupportMessage_support_message_id" ) );
		}
		if (v.get_indicator("SupportMessage_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("SupportMessage_sys_userid" ) );
		}
		if (v.get_indicator("SupportMessage_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("SupportMessage_sys_groupid" ) );
		}
		if (v.get_indicator("SupportMessage_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("SupportMessage_sys_perm_user" ) );
		}
		if (v.get_indicator("SupportMessage_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("SupportMessage_sys_perm_group" ) );
		}
		if (v.get_indicator("SupportMessage_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("SupportMessage_sys_perm_other" ) );
		}
		if (v.get_indicator("SupportMessage_recipient_id") != i_null){
			p.setRecipientId( v.template get<long long>("SupportMessage_recipient_id" ) );
		}
		if (v.get_indicator("SupportMessage_sender_id") != i_null){
			p.setSenderId( v.template get<long long>("SupportMessage_sender_id" ) );
		}
		if (v.get_indicator("SupportMessage_subject") != i_null){
			p.setSubject( v.template get<std::string>("SupportMessage_subject" ) );
		}
		if (v.get_indicator("SupportMessage_message") != i_null){
			p.setMessage( v.template get<std::string>("SupportMessage_message" ) );
		}
		if (v.get_indicator("SupportMessage_tstamp") != i_null){
			p.setTstamp( v.template get<int>("SupportMessage_tstamp" ) );
		}
	}
	static void to_base(const SupportMessage & p, values & v, indicator & ind)
	{
		v.set( "SupportMessage_support_message_id", p.getSupportMessageId() );
		v.set( "SupportMessage_sys_userid", p.getSysUserid() );
		v.set( "SupportMessage_sys_groupid", p.getSysGroupid() );
		v.set( "SupportMessage_sys_perm_user", p.getSysPermUser() );
		v.set( "SupportMessage_sys_perm_group", p.getSysPermGroup() );
		v.set( "SupportMessage_sys_perm_other", p.getSysPermOther() );
		v.set( "SupportMessage_recipient_id", p.getRecipientId() );
		v.set( "SupportMessage_sender_id", p.getSenderId() );
		v.set( "SupportMessage_subject", p.getSubject() );
		v.set( "SupportMessage_message", p.getMessage() );
		v.set( "SupportMessage_tstamp", p.getTstamp() );
		ind = i_ok;
	}
};
}

#endif // SUPPORTMESSAGEREPOSITORY_H
