#ifndef DOMAINREPOSITORY_H
#define DOMAINREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/domain.h"
using namespace soci;


class DomainRepository
{
	soci::session& dataBase;
public:
	DomainRepository(soci::session& dataBase);
	int insert(const Domain& domain);
	DomainPtr select(const Domain& domain);
	DomainList select(const string& where="");
	void update(const Domain& domain);
	void update(const Domain& oldObj, const Domain& newObj);
	void remove(const Domain& domain);
};

namespace soci
{
template<>
struct type_conversion<Domain>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, Domain & p)
	{
		if (v.get_indicator("Domain_domain_id") != i_null){
			p.setDomainId( v.template get<long long>("Domain_domain_id" ) );
		}
		if (v.get_indicator("Domain_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("Domain_sys_userid" ) );
		}
		if (v.get_indicator("Domain_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("Domain_sys_groupid" ) );
		}
		if (v.get_indicator("Domain_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("Domain_sys_perm_user" ) );
		}
		if (v.get_indicator("Domain_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("Domain_sys_perm_group" ) );
		}
		if (v.get_indicator("Domain_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("Domain_sys_perm_other" ) );
		}
		if (v.get_indicator("Domain_domain") != i_null){
			p.setDomain( v.template get<std::string>("Domain_domain" ) );
		}
	}
	static void to_base(const Domain & p, values & v, indicator & ind)
	{
		v.set( "Domain_domain_id", p.getDomainId() );
		v.set( "Domain_sys_userid", p.getSysUserid() );
		v.set( "Domain_sys_groupid", p.getSysGroupid() );
		v.set( "Domain_sys_perm_user", p.getSysPermUser() );
		v.set( "Domain_sys_perm_group", p.getSysPermGroup() );
		v.set( "Domain_sys_perm_other", p.getSysPermOther() );
		v.set( "Domain_domain", p.getDomain() );
		ind = i_ok;
	}
};
}

#endif // DOMAINREPOSITORY_H
