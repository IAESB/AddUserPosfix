#ifndef MAILMAILINGLISTREPOSITORY_H
#define MAILMAILINGLISTREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/mailmailinglist.h"
using namespace soci;


class MailMailinglistRepository
{
	soci::session& dataBase;
public:
	MailMailinglistRepository(soci::session& dataBase);
	int insert(const MailMailinglist& mailmailinglist);
	MailMailinglistPtr select(const MailMailinglist& mailmailinglist);
	MailMailinglistList select(const string& where="");
	void update(const MailMailinglist& mailmailinglist);
	void update(const MailMailinglist& oldObj, const MailMailinglist& newObj);
	void remove(const MailMailinglist& mailmailinglist);
};

namespace soci
{
template<>
struct type_conversion<MailMailinglist>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, MailMailinglist & p)
	{
		if (v.get_indicator("MailMailinglist_mailinglist_id") != i_null){
			p.setMailinglistId( v.template get<long long>("MailMailinglist_mailinglist_id" ) );
		}
		if (v.get_indicator("MailMailinglist_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("MailMailinglist_sys_userid" ) );
		}
		if (v.get_indicator("MailMailinglist_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("MailMailinglist_sys_groupid" ) );
		}
		if (v.get_indicator("MailMailinglist_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("MailMailinglist_sys_perm_user" ) );
		}
		if (v.get_indicator("MailMailinglist_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("MailMailinglist_sys_perm_group" ) );
		}
		if (v.get_indicator("MailMailinglist_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("MailMailinglist_sys_perm_other" ) );
		}
		if (v.get_indicator("MailMailinglist_server_id") != i_null){
			p.setServerId( v.template get<long long>("MailMailinglist_server_id" ) );
		}
		if (v.get_indicator("MailMailinglist_domain") != i_null){
			p.setDomain( v.template get<std::string>("MailMailinglist_domain" ) );
		}
		if (v.get_indicator("MailMailinglist_listname") != i_null){
			p.setListname( v.template get<std::string>("MailMailinglist_listname" ) );
		}
		if (v.get_indicator("MailMailinglist_email") != i_null){
			p.setEmail( v.template get<std::string>("MailMailinglist_email" ) );
		}
		if (v.get_indicator("MailMailinglist_password") != i_null){
			p.setPassword( v.template get<std::string>("MailMailinglist_password" ) );
		}
	}
	static void to_base(const MailMailinglist & p, values & v, indicator & ind)
	{
		v.set( "MailMailinglist_mailinglist_id", p.getMailinglistId() );
		v.set( "MailMailinglist_sys_userid", p.getSysUserid() );
		v.set( "MailMailinglist_sys_groupid", p.getSysGroupid() );
		v.set( "MailMailinglist_sys_perm_user", p.getSysPermUser() );
		v.set( "MailMailinglist_sys_perm_group", p.getSysPermGroup() );
		v.set( "MailMailinglist_sys_perm_other", p.getSysPermOther() );
		v.set( "MailMailinglist_server_id", p.getServerId() );
		v.set( "MailMailinglist_domain", p.getDomain() );
		v.set( "MailMailinglist_listname", p.getListname() );
		v.set( "MailMailinglist_email", p.getEmail() );
		v.set( "MailMailinglist_password", p.getPassword() );
		ind = i_ok;
	}
};
}

#endif // MAILMAILINGLISTREPOSITORY_H
