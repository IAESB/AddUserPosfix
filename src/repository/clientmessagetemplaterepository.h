#ifndef CLIENTMESSAGETEMPLATEREPOSITORY_H
#define CLIENTMESSAGETEMPLATEREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/clientmessagetemplate.h"
using namespace soci;


class ClientMessageTemplateRepository
{
	soci::session& dataBase;
public:
	ClientMessageTemplateRepository(soci::session& dataBase);
	int insert(const ClientMessageTemplate& clientmessagetemplate);
	ClientMessageTemplatePtr select(const ClientMessageTemplate& clientmessagetemplate);
	ClientMessageTemplateList select(const string& where="");
	void update(const ClientMessageTemplate& clientmessagetemplate);
	void update(const ClientMessageTemplate& oldObj, const ClientMessageTemplate& newObj);
	void remove(const ClientMessageTemplate& clientmessagetemplate);
};

namespace soci
{
template<>
struct type_conversion<ClientMessageTemplate>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, ClientMessageTemplate & p)
	{
		if (v.get_indicator("ClientMessageTemplate_client_message_template_id") != i_null){
			p.setClientMessageTemplateId( v.template get<long long>("ClientMessageTemplate_client_message_template_id" ) );
		}
		if (v.get_indicator("ClientMessageTemplate_sys_userid") != i_null){
			p.setSysUserid( v.template get<int>("ClientMessageTemplate_sys_userid" ) );
		}
		if (v.get_indicator("ClientMessageTemplate_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<int>("ClientMessageTemplate_sys_groupid" ) );
		}
		if (v.get_indicator("ClientMessageTemplate_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("ClientMessageTemplate_sys_perm_user" ) );
		}
		if (v.get_indicator("ClientMessageTemplate_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("ClientMessageTemplate_sys_perm_group" ) );
		}
		if (v.get_indicator("ClientMessageTemplate_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("ClientMessageTemplate_sys_perm_other" ) );
		}
		if (v.get_indicator("ClientMessageTemplate_template_type") != i_null){
			p.setTemplateType( v.template get<std::string>("ClientMessageTemplate_template_type" ) );
		}
		if (v.get_indicator("ClientMessageTemplate_template_name") != i_null){
			p.setTemplateName( v.template get<std::string>("ClientMessageTemplate_template_name" ) );
		}
		if (v.get_indicator("ClientMessageTemplate_subject") != i_null){
			p.setSubject( v.template get<std::string>("ClientMessageTemplate_subject" ) );
		}
		if (v.get_indicator("ClientMessageTemplate_message") != i_null){
			p.setMessage( v.template get<std::string>("ClientMessageTemplate_message" ) );
		}
	}
	static void to_base(const ClientMessageTemplate & p, values & v, indicator & ind)
	{
		v.set( "ClientMessageTemplate_client_message_template_id", p.getClientMessageTemplateId() );
		v.set( "ClientMessageTemplate_sys_userid", p.getSysUserid() );
		v.set( "ClientMessageTemplate_sys_groupid", p.getSysGroupid() );
		v.set( "ClientMessageTemplate_sys_perm_user", p.getSysPermUser() );
		v.set( "ClientMessageTemplate_sys_perm_group", p.getSysPermGroup() );
		v.set( "ClientMessageTemplate_sys_perm_other", p.getSysPermOther() );
		v.set( "ClientMessageTemplate_template_type", p.getTemplateType() );
		v.set( "ClientMessageTemplate_template_name", p.getTemplateName() );
		v.set( "ClientMessageTemplate_subject", p.getSubject() );
		v.set( "ClientMessageTemplate_message", p.getMessage() );
		ind = i_ok;
	}
};
}

#endif // CLIENTMESSAGETEMPLATEREPOSITORY_H
