#ifndef MAILCONTENTFILTERREPOSITORY_H
#define MAILCONTENTFILTERREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/mailcontentfilter.h"
using namespace soci;


class MailContentFilterRepository
{
	soci::session& dataBase;
public:
	MailContentFilterRepository(soci::session& dataBase);
	int insert(const MailContentFilter& mailcontentfilter);
	MailContentFilterPtr select(const MailContentFilter& mailcontentfilter);
	MailContentFilterList select(const string& where="");
	void update(const MailContentFilter& mailcontentfilter);
	void update(const MailContentFilter& oldObj, const MailContentFilter& newObj);
	void remove(const MailContentFilter& mailcontentfilter);
};

namespace soci
{
template<>
struct type_conversion<MailContentFilter>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, MailContentFilter & p)
	{
		if (v.get_indicator("MailContentFilter_content_filter_id") != i_null){
			p.setContentFilterId( v.template get<long long>("MailContentFilter_content_filter_id" ) );
		}
		if (v.get_indicator("MailContentFilter_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("MailContentFilter_sys_userid" ) );
		}
		if (v.get_indicator("MailContentFilter_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("MailContentFilter_sys_groupid" ) );
		}
		if (v.get_indicator("MailContentFilter_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("MailContentFilter_sys_perm_user" ) );
		}
		if (v.get_indicator("MailContentFilter_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("MailContentFilter_sys_perm_group" ) );
		}
		if (v.get_indicator("MailContentFilter_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("MailContentFilter_sys_perm_other" ) );
		}
		if (v.get_indicator("MailContentFilter_server_id") != i_null){
			p.setServerId( v.template get<int>("MailContentFilter_server_id" ) );
		}
		if (v.get_indicator("MailContentFilter_type") != i_null){
			p.setType( v.template get<std::string>("MailContentFilter_type" ) );
		}
		if (v.get_indicator("MailContentFilter_pattern") != i_null){
			p.setPattern( v.template get<std::string>("MailContentFilter_pattern" ) );
		}
		if (v.get_indicator("MailContentFilter_data") != i_null){
			p.setData( v.template get<std::string>("MailContentFilter_data" ) );
		}
		if (v.get_indicator("MailContentFilter_action") != i_null){
			p.setAction( v.template get<std::string>("MailContentFilter_action" ) );
		}
		if (v.get_indicator("MailContentFilter_active") != i_null){
			p.setActive( v.template get<std::string>("MailContentFilter_active" ) );
		}
	}
	static void to_base(const MailContentFilter & p, values & v, indicator & ind)
	{
		v.set( "MailContentFilter_content_filter_id", p.getContentFilterId() );
		v.set( "MailContentFilter_sys_userid", p.getSysUserid() );
		v.set( "MailContentFilter_sys_groupid", p.getSysGroupid() );
		v.set( "MailContentFilter_sys_perm_user", p.getSysPermUser() );
		v.set( "MailContentFilter_sys_perm_group", p.getSysPermGroup() );
		v.set( "MailContentFilter_sys_perm_other", p.getSysPermOther() );
		v.set( "MailContentFilter_server_id", p.getServerId() );
		v.set( "MailContentFilter_type", p.getType() );
		v.set( "MailContentFilter_pattern", p.getPattern() );
		v.set( "MailContentFilter_data", p.getData() );
		v.set( "MailContentFilter_action", p.getAction() );
		v.set( "MailContentFilter_active", p.getActive() );
		ind = i_ok;
	}
};
}

#endif // MAILCONTENTFILTERREPOSITORY_H
