#ifndef MAILUSERFILTERREPOSITORY_H
#define MAILUSERFILTERREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/mailuserfilter.h"
using namespace soci;


class MailUserFilterRepository
{
	soci::session& dataBase;
public:
	MailUserFilterRepository(soci::session& dataBase);
	int insert(const MailUserFilter& mailuserfilter);
	MailUserFilterPtr select(const MailUserFilter& mailuserfilter);
	MailUserFilterList select(const string& where="");
	void update(const MailUserFilter& mailuserfilter);
	void update(const MailUserFilter& oldObj, const MailUserFilter& newObj);
	void remove(const MailUserFilter& mailuserfilter);
};

namespace soci
{
template<>
struct type_conversion<MailUserFilter>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, MailUserFilter & p)
	{
		if (v.get_indicator("MailUserFilter_filter_id") != i_null){
			p.setFilterId( v.template get<long long>("MailUserFilter_filter_id" ) );
		}
		if (v.get_indicator("MailUserFilter_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("MailUserFilter_sys_userid" ) );
		}
		if (v.get_indicator("MailUserFilter_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("MailUserFilter_sys_groupid" ) );
		}
		if (v.get_indicator("MailUserFilter_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("MailUserFilter_sys_perm_user" ) );
		}
		if (v.get_indicator("MailUserFilter_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("MailUserFilter_sys_perm_group" ) );
		}
		if (v.get_indicator("MailUserFilter_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("MailUserFilter_sys_perm_other" ) );
		}
		if (v.get_indicator("MailUserFilter_mailuser_id") != i_null){
			p.setMailuserId( v.template get<long long>("MailUserFilter_mailuser_id" ) );
		}
		if (v.get_indicator("MailUserFilter_rulename") != i_null){
			p.setRulename( v.template get<std::string>("MailUserFilter_rulename" ) );
		}
		if (v.get_indicator("MailUserFilter_source") != i_null){
			p.setSource( v.template get<std::string>("MailUserFilter_source" ) );
		}
		if (v.get_indicator("MailUserFilter_searchterm") != i_null){
			p.setSearchterm( v.template get<std::string>("MailUserFilter_searchterm" ) );
		}
		if (v.get_indicator("MailUserFilter_op") != i_null){
			p.setOp( v.template get<std::string>("MailUserFilter_op" ) );
		}
		if (v.get_indicator("MailUserFilter_action") != i_null){
			p.setAction( v.template get<std::string>("MailUserFilter_action" ) );
		}
		if (v.get_indicator("MailUserFilter_target") != i_null){
			p.setTarget( v.template get<std::string>("MailUserFilter_target" ) );
		}
		if (v.get_indicator("MailUserFilter_active") != i_null){
			p.setActive( v.template get<std::string>("MailUserFilter_active" ) );
		}
	}
	static void to_base(const MailUserFilter & p, values & v, indicator & ind)
	{
		v.set( "MailUserFilter_filter_id", p.getFilterId() );
		v.set( "MailUserFilter_sys_userid", p.getSysUserid() );
		v.set( "MailUserFilter_sys_groupid", p.getSysGroupid() );
		v.set( "MailUserFilter_sys_perm_user", p.getSysPermUser() );
		v.set( "MailUserFilter_sys_perm_group", p.getSysPermGroup() );
		v.set( "MailUserFilter_sys_perm_other", p.getSysPermOther() );
		v.set( "MailUserFilter_mailuser_id", p.getMailuserId() );
		v.set( "MailUserFilter_rulename", p.getRulename() );
		v.set( "MailUserFilter_source", p.getSource() );
		v.set( "MailUserFilter_searchterm", p.getSearchterm() );
		v.set( "MailUserFilter_op", p.getOp() );
		v.set( "MailUserFilter_action", p.getAction() );
		v.set( "MailUserFilter_target", p.getTarget() );
		v.set( "MailUserFilter_active", p.getActive() );
		ind = i_ok;
	}
};
}

#endif // MAILUSERFILTERREPOSITORY_H
