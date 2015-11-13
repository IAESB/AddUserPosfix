#ifndef HELPFAQREPOSITORY_H
#define HELPFAQREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/helpfaq.h"
using namespace soci;


class HelpFaqRepository
{
	soci::session& dataBase;
public:
	HelpFaqRepository(soci::session& dataBase);
	int insert(const HelpFaq& helpfaq);
	HelpFaqPtr select(const HelpFaq& helpfaq);
	HelpFaqList select(const string& where="");
	void update(const HelpFaq& helpfaq);
	void update(const HelpFaq& oldObj, const HelpFaq& newObj);
	void remove(const HelpFaq& helpfaq);
};

namespace soci
{
template<>
struct type_conversion<HelpFaq>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, HelpFaq & p)
	{
		if (v.get_indicator("HelpFaq_hf_id") != i_null){
			p.setHfId( v.template get<int>("HelpFaq_hf_id" ) );
		}
		if (v.get_indicator("HelpFaq_hf_section") != i_null){
			p.setHfSection( v.template get<int>("HelpFaq_hf_section" ) );
		}
		if (v.get_indicator("HelpFaq_hf_order") != i_null){
			p.setHfOrder( v.template get<int>("HelpFaq_hf_order" ) );
		}
		if (v.get_indicator("HelpFaq_hf_question") != i_null){
			p.setHfQuestion( v.template get<std::string>("HelpFaq_hf_question" ) );
		}
		if (v.get_indicator("HelpFaq_hf_answer") != i_null){
			p.setHfAnswer( v.template get<std::string>("HelpFaq_hf_answer" ) );
		}
		if (v.get_indicator("HelpFaq_sys_userid") != i_null){
			p.setSysUserid( v.template get<int>("HelpFaq_sys_userid" ) );
		}
		if (v.get_indicator("HelpFaq_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<int>("HelpFaq_sys_groupid" ) );
		}
		if (v.get_indicator("HelpFaq_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("HelpFaq_sys_perm_user" ) );
		}
		if (v.get_indicator("HelpFaq_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("HelpFaq_sys_perm_group" ) );
		}
		if (v.get_indicator("HelpFaq_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("HelpFaq_sys_perm_other" ) );
		}
	}
	static void to_base(const HelpFaq & p, values & v, indicator & ind)
	{
		v.set( "HelpFaq_hf_id", p.getHfId() );
		v.set( "HelpFaq_hf_section", p.getHfSection() );
		v.set( "HelpFaq_hf_order", p.getHfOrder() );
		v.set( "HelpFaq_hf_question", p.getHfQuestion() );
		v.set( "HelpFaq_hf_answer", p.getHfAnswer() );
		v.set( "HelpFaq_sys_userid", p.getSysUserid() );
		v.set( "HelpFaq_sys_groupid", p.getSysGroupid() );
		v.set( "HelpFaq_sys_perm_user", p.getSysPermUser() );
		v.set( "HelpFaq_sys_perm_group", p.getSysPermGroup() );
		v.set( "HelpFaq_sys_perm_other", p.getSysPermOther() );
		ind = i_ok;
	}
};
}

#endif // HELPFAQREPOSITORY_H
