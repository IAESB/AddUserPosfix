#ifndef SPAMFILTERUSERSREPOSITORY_H
#define SPAMFILTERUSERSREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/spamfilterusers.h"
using namespace soci;


class SpamfilterUsersRepository
{
	soci::session& dataBase;
public:
	SpamfilterUsersRepository(soci::session& dataBase);
	int insert(const SpamfilterUsers& spamfilterusers);
	SpamfilterUsersPtr select(const SpamfilterUsers& spamfilterusers);
	SpamfilterUsersList select(const string& where="");
	void update(const SpamfilterUsers& spamfilterusers);
	void update(const SpamfilterUsers& oldObj, const SpamfilterUsers& newObj);
	void remove(const SpamfilterUsers& spamfilterusers);
};

namespace soci
{
template<>
struct type_conversion<SpamfilterUsers>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, SpamfilterUsers & p)
	{
		if (v.get_indicator("SpamfilterUsers_id") != i_null){
			p.setId( v.template get<long long>("SpamfilterUsers_id" ) );
		}
		if (v.get_indicator("SpamfilterUsers_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("SpamfilterUsers_sys_userid" ) );
		}
		if (v.get_indicator("SpamfilterUsers_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("SpamfilterUsers_sys_groupid" ) );
		}
		if (v.get_indicator("SpamfilterUsers_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("SpamfilterUsers_sys_perm_user" ) );
		}
		if (v.get_indicator("SpamfilterUsers_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("SpamfilterUsers_sys_perm_group" ) );
		}
		if (v.get_indicator("SpamfilterUsers_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("SpamfilterUsers_sys_perm_other" ) );
		}
		if (v.get_indicator("SpamfilterUsers_server_id") != i_null){
			p.setServerId( v.template get<long long>("SpamfilterUsers_server_id" ) );
		}
		if (v.get_indicator("SpamfilterUsers_priority") != i_null){
			p.setPriority( v.template get<int>("SpamfilterUsers_priority" ) );
		}
		if (v.get_indicator("SpamfilterUsers_policy_id") != i_null){
			p.setPolicyId( v.template get<long long>("SpamfilterUsers_policy_id" ) );
		}
		if (v.get_indicator("SpamfilterUsers_email") != i_null){
			p.setEmail( v.template get<std::string>("SpamfilterUsers_email" ) );
		}
		if (v.get_indicator("SpamfilterUsers_fullname") != i_null){
			p.setFullname( v.template get<std::string>("SpamfilterUsers_fullname" ) );
		}
		if (v.get_indicator("SpamfilterUsers_local") != i_null){
			p.setLocal( v.template get<std::string>("SpamfilterUsers_local" ) );
		}
	}
	static void to_base(const SpamfilterUsers & p, values & v, indicator & ind)
	{
		v.set( "SpamfilterUsers_id", p.getId() );
		v.set( "SpamfilterUsers_sys_userid", p.getSysUserid() );
		v.set( "SpamfilterUsers_sys_groupid", p.getSysGroupid() );
		v.set( "SpamfilterUsers_sys_perm_user", p.getSysPermUser() );
		v.set( "SpamfilterUsers_sys_perm_group", p.getSysPermGroup() );
		v.set( "SpamfilterUsers_sys_perm_other", p.getSysPermOther() );
		v.set( "SpamfilterUsers_server_id", p.getServerId() );
		v.set( "SpamfilterUsers_priority", p.getPriority() );
		v.set( "SpamfilterUsers_policy_id", p.getPolicyId() );
		v.set( "SpamfilterUsers_email", p.getEmail() );
		v.set( "SpamfilterUsers_fullname", p.getFullname() );
		v.set( "SpamfilterUsers_local", p.getLocal() );
		ind = i_ok;
	}
};
}

#endif // SPAMFILTERUSERSREPOSITORY_H
