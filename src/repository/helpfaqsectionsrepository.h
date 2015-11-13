#ifndef HELPFAQSECTIONSREPOSITORY_H
#define HELPFAQSECTIONSREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/helpfaqsections.h"
using namespace soci;


class HelpFaqSectionsRepository
{
	soci::session& dataBase;
public:
	HelpFaqSectionsRepository(soci::session& dataBase);
	int insert(const HelpFaqSections& helpfaqsections);
	HelpFaqSectionsPtr select(const HelpFaqSections& helpfaqsections);
	HelpFaqSectionsList select(const string& where="");
	void update(const HelpFaqSections& helpfaqsections);
	void update(const HelpFaqSections& oldObj, const HelpFaqSections& newObj);
	void remove(const HelpFaqSections& helpfaqsections);
};

namespace soci
{
template<>
struct type_conversion<HelpFaqSections>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, HelpFaqSections & p)
	{
		if (v.get_indicator("HelpFaqSections_hfs_id") != i_null){
			p.setHfsId( v.template get<int>("HelpFaqSections_hfs_id" ) );
		}
		if (v.get_indicator("HelpFaqSections_hfs_name") != i_null){
			p.setHfsName( v.template get<std::string>("HelpFaqSections_hfs_name" ) );
		}
		if (v.get_indicator("HelpFaqSections_hfs_order") != i_null){
			p.setHfsOrder( v.template get<int>("HelpFaqSections_hfs_order" ) );
		}
		if (v.get_indicator("HelpFaqSections_sys_userid") != i_null){
			p.setSysUserid( v.template get<int>("HelpFaqSections_sys_userid" ) );
		}
		if (v.get_indicator("HelpFaqSections_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<int>("HelpFaqSections_sys_groupid" ) );
		}
		if (v.get_indicator("HelpFaqSections_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("HelpFaqSections_sys_perm_user" ) );
		}
		if (v.get_indicator("HelpFaqSections_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("HelpFaqSections_sys_perm_group" ) );
		}
		if (v.get_indicator("HelpFaqSections_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("HelpFaqSections_sys_perm_other" ) );
		}
	}
	static void to_base(const HelpFaqSections & p, values & v, indicator & ind)
	{
		v.set( "HelpFaqSections_hfs_id", p.getHfsId() );
		v.set( "HelpFaqSections_hfs_name", p.getHfsName() );
		v.set( "HelpFaqSections_hfs_order", p.getHfsOrder() );
		v.set( "HelpFaqSections_sys_userid", p.getSysUserid() );
		v.set( "HelpFaqSections_sys_groupid", p.getSysGroupid() );
		v.set( "HelpFaqSections_sys_perm_user", p.getSysPermUser() );
		v.set( "HelpFaqSections_sys_perm_group", p.getSysPermGroup() );
		v.set( "HelpFaqSections_sys_perm_other", p.getSysPermOther() );
		ind = i_ok;
	}
};
}

#endif // HELPFAQSECTIONSREPOSITORY_H
