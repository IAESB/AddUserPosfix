#ifndef DNSTEMPLATEREPOSITORY_H
#define DNSTEMPLATEREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/dnstemplate.h"
using namespace soci;


class DnsTemplateRepository
{
	soci::session& dataBase;
public:
	DnsTemplateRepository(soci::session& dataBase);
	int insert(const DnsTemplate& dnstemplate);
	DnsTemplatePtr select(const DnsTemplate& dnstemplate);
	DnsTemplateList select(const string& where="");
	void update(const DnsTemplate& dnstemplate);
	void update(const DnsTemplate& oldObj, const DnsTemplate& newObj);
	void remove(const DnsTemplate& dnstemplate);
};

namespace soci
{
template<>
struct type_conversion<DnsTemplate>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, DnsTemplate & p)
	{
		if (v.get_indicator("DnsTemplate_template_id") != i_null){
			p.setTemplateId( v.template get<long long>("DnsTemplate_template_id" ) );
		}
		if (v.get_indicator("DnsTemplate_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("DnsTemplate_sys_userid" ) );
		}
		if (v.get_indicator("DnsTemplate_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("DnsTemplate_sys_groupid" ) );
		}
		if (v.get_indicator("DnsTemplate_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("DnsTemplate_sys_perm_user" ) );
		}
		if (v.get_indicator("DnsTemplate_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("DnsTemplate_sys_perm_group" ) );
		}
		if (v.get_indicator("DnsTemplate_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("DnsTemplate_sys_perm_other" ) );
		}
		if (v.get_indicator("DnsTemplate_name") != i_null){
			p.setName( v.template get<std::string>("DnsTemplate_name" ) );
		}
		if (v.get_indicator("DnsTemplate_fields") != i_null){
			p.setFields( v.template get<std::string>("DnsTemplate_fields" ) );
		}
		if (v.get_indicator("DnsTemplate_template_") != i_null){
			p.setTemplate( v.template get<std::string>("DnsTemplate_template_" ) );
		}
		if (v.get_indicator("DnsTemplate_visible") != i_null){
			p.setVisible( v.template get<std::string>("DnsTemplate_visible" ) );
		}
	}
	static void to_base(const DnsTemplate & p, values & v, indicator & ind)
	{
		v.set( "DnsTemplate_template_id", p.getTemplateId() );
		v.set( "DnsTemplate_sys_userid", p.getSysUserid() );
		v.set( "DnsTemplate_sys_groupid", p.getSysGroupid() );
		v.set( "DnsTemplate_sys_perm_user", p.getSysPermUser() );
		v.set( "DnsTemplate_sys_perm_group", p.getSysPermGroup() );
		v.set( "DnsTemplate_sys_perm_other", p.getSysPermOther() );
		v.set( "DnsTemplate_name", p.getName() );
		v.set( "DnsTemplate_fields", p.getFields() );
		v.set( "DnsTemplate_template_", p.getTemplate() );
		v.set( "DnsTemplate_visible", p.getVisible() );
		ind = i_ok;
	}
};
}

#endif // DNSTEMPLATEREPOSITORY_H
