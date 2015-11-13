#ifndef MAILDOMAINREPOSITORY_H
#define MAILDOMAINREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/maildomain.h"
using namespace soci;


class MailDomainRepository
{
	soci::session& dataBase;
public:
	MailDomainRepository(soci::session& dataBase);
	int insert(const MailDomain& maildomain);
	MailDomainPtr select(const MailDomain& maildomain);
	MailDomainList select(const string& where="");
	void update(const MailDomain& maildomain);
	void update(const MailDomain& oldObj, const MailDomain& newObj);
	void remove(const MailDomain& maildomain);
};

namespace soci
{
template<>
struct type_conversion<MailDomain>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, MailDomain & p)
	{
		if (v.get_indicator("MailDomain_domain_id") != i_null){
			p.setDomainId( v.template get<long long>("MailDomain_domain_id" ) );
		}
		if (v.get_indicator("MailDomain_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("MailDomain_sys_userid" ) );
		}
		if (v.get_indicator("MailDomain_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("MailDomain_sys_groupid" ) );
		}
		if (v.get_indicator("MailDomain_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("MailDomain_sys_perm_user" ) );
		}
		if (v.get_indicator("MailDomain_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("MailDomain_sys_perm_group" ) );
		}
		if (v.get_indicator("MailDomain_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("MailDomain_sys_perm_other" ) );
		}
		if (v.get_indicator("MailDomain_server_id") != i_null){
			p.setServerId( v.template get<long long>("MailDomain_server_id" ) );
		}
		if (v.get_indicator("MailDomain_domain") != i_null){
			p.setDomain( v.template get<std::string>("MailDomain_domain" ) );
		}
		if (v.get_indicator("MailDomain_dkim") != i_null){
			p.setDkim( v.template get<std::string>("MailDomain_dkim" ) );
		}
		if (v.get_indicator("MailDomain_dkim_selector") != i_null){
			p.setDkimSelector( v.template get<std::string>("MailDomain_dkim_selector" ) );
		}
		if (v.get_indicator("MailDomain_dkim_private") != i_null){
			p.setDkimPrivate( v.template get<std::string>("MailDomain_dkim_private" ) );
		}
		if (v.get_indicator("MailDomain_dkim_public") != i_null){
			p.setDkimPublic( v.template get<std::string>("MailDomain_dkim_public" ) );
		}
		if (v.get_indicator("MailDomain_active") != i_null){
			p.setActive( v.template get<std::string>("MailDomain_active" ) );
		}
	}
	static void to_base(const MailDomain & p, values & v, indicator & ind)
	{
		v.set( "MailDomain_domain_id", p.getDomainId() );
		v.set( "MailDomain_sys_userid", p.getSysUserid() );
		v.set( "MailDomain_sys_groupid", p.getSysGroupid() );
		v.set( "MailDomain_sys_perm_user", p.getSysPermUser() );
		v.set( "MailDomain_sys_perm_group", p.getSysPermGroup() );
		v.set( "MailDomain_sys_perm_other", p.getSysPermOther() );
		v.set( "MailDomain_server_id", p.getServerId() );
		v.set( "MailDomain_domain", p.getDomain() );
		v.set( "MailDomain_dkim", p.getDkim() );
		v.set( "MailDomain_dkim_selector", p.getDkimSelector() );
		v.set( "MailDomain_dkim_private", p.getDkimPrivate() );
		v.set( "MailDomain_dkim_public", p.getDkimPublic() );
		v.set( "MailDomain_active", p.getActive() );
		ind = i_ok;
	}
};
}

#endif // MAILDOMAINREPOSITORY_H
