#ifndef OPENVZOSTEMPLATEREPOSITORY_H
#define OPENVZOSTEMPLATEREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/openvzostemplate.h"
using namespace soci;


class OpenvzOstemplateRepository
{
	soci::session& dataBase;
public:
	OpenvzOstemplateRepository(soci::session& dataBase);
	int insert(const OpenvzOstemplate& openvzostemplate);
	OpenvzOstemplatePtr select(const OpenvzOstemplate& openvzostemplate);
	OpenvzOstemplateList select(const string& where="");
	void update(const OpenvzOstemplate& openvzostemplate);
	void update(const OpenvzOstemplate& oldObj, const OpenvzOstemplate& newObj);
	void remove(const OpenvzOstemplate& openvzostemplate);
};

namespace soci
{
template<>
struct type_conversion<OpenvzOstemplate>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, OpenvzOstemplate & p)
	{
		if (v.get_indicator("OpenvzOstemplate_ostemplate_id") != i_null){
			p.setOstemplateId( v.template get<long long>("OpenvzOstemplate_ostemplate_id" ) );
		}
		if (v.get_indicator("OpenvzOstemplate_sys_userid") != i_null){
			p.setSysUserid( v.template get<int>("OpenvzOstemplate_sys_userid" ) );
		}
		if (v.get_indicator("OpenvzOstemplate_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<int>("OpenvzOstemplate_sys_groupid" ) );
		}
		if (v.get_indicator("OpenvzOstemplate_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("OpenvzOstemplate_sys_perm_user" ) );
		}
		if (v.get_indicator("OpenvzOstemplate_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("OpenvzOstemplate_sys_perm_group" ) );
		}
		if (v.get_indicator("OpenvzOstemplate_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("OpenvzOstemplate_sys_perm_other" ) );
		}
		if (v.get_indicator("OpenvzOstemplate_template_name") != i_null){
			p.setTemplateName( v.template get<std::string>("OpenvzOstemplate_template_name" ) );
		}
		if (v.get_indicator("OpenvzOstemplate_template_file") != i_null){
			p.setTemplateFile( v.template get<std::string>("OpenvzOstemplate_template_file" ) );
		}
		if (v.get_indicator("OpenvzOstemplate_server_id") != i_null){
			p.setServerId( v.template get<int>("OpenvzOstemplate_server_id" ) );
		}
		if (v.get_indicator("OpenvzOstemplate_allservers") != i_null){
			p.setAllservers( v.template get<std::string>("OpenvzOstemplate_allservers" ) );
		}
		if (v.get_indicator("OpenvzOstemplate_active") != i_null){
			p.setActive( v.template get<std::string>("OpenvzOstemplate_active" ) );
		}
		if (v.get_indicator("OpenvzOstemplate_description") != i_null){
			p.setDescription( v.template get<std::string>("OpenvzOstemplate_description" ) );
		}
	}
	static void to_base(const OpenvzOstemplate & p, values & v, indicator & ind)
	{
		v.set( "OpenvzOstemplate_ostemplate_id", p.getOstemplateId() );
		v.set( "OpenvzOstemplate_sys_userid", p.getSysUserid() );
		v.set( "OpenvzOstemplate_sys_groupid", p.getSysGroupid() );
		v.set( "OpenvzOstemplate_sys_perm_user", p.getSysPermUser() );
		v.set( "OpenvzOstemplate_sys_perm_group", p.getSysPermGroup() );
		v.set( "OpenvzOstemplate_sys_perm_other", p.getSysPermOther() );
		v.set( "OpenvzOstemplate_template_name", p.getTemplateName() );
		v.set( "OpenvzOstemplate_template_file", p.getTemplateFile() );
		v.set( "OpenvzOstemplate_server_id", p.getServerId() );
		v.set( "OpenvzOstemplate_allservers", p.getAllservers() );
		v.set( "OpenvzOstemplate_active", p.getActive() );
		v.set( "OpenvzOstemplate_description", p.getDescription() );
		ind = i_ok;
	}
};
}

#endif // OPENVZOSTEMPLATEREPOSITORY_H
