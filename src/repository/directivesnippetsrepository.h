#ifndef DIRECTIVESNIPPETSREPOSITORY_H
#define DIRECTIVESNIPPETSREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/directivesnippets.h"
using namespace soci;


class DirectiveSnippetsRepository
{
	soci::session& dataBase;
public:
	DirectiveSnippetsRepository(soci::session& dataBase);
	int insert(const DirectiveSnippets& directivesnippets);
	DirectiveSnippetsPtr select(const DirectiveSnippets& directivesnippets);
	DirectiveSnippetsList select(const string& where="");
	void update(const DirectiveSnippets& directivesnippets);
	void update(const DirectiveSnippets& oldObj, const DirectiveSnippets& newObj);
	void remove(const DirectiveSnippets& directivesnippets);
};

namespace soci
{
template<>
struct type_conversion<DirectiveSnippets>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, DirectiveSnippets & p)
	{
		if (v.get_indicator("DirectiveSnippets_directive_snippets_id") != i_null){
			p.setDirectiveSnippetsId( v.template get<long long>("DirectiveSnippets_directive_snippets_id" ) );
		}
		if (v.get_indicator("DirectiveSnippets_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("DirectiveSnippets_sys_userid" ) );
		}
		if (v.get_indicator("DirectiveSnippets_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("DirectiveSnippets_sys_groupid" ) );
		}
		if (v.get_indicator("DirectiveSnippets_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("DirectiveSnippets_sys_perm_user" ) );
		}
		if (v.get_indicator("DirectiveSnippets_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("DirectiveSnippets_sys_perm_group" ) );
		}
		if (v.get_indicator("DirectiveSnippets_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("DirectiveSnippets_sys_perm_other" ) );
		}
		if (v.get_indicator("DirectiveSnippets_name") != i_null){
			p.setName( v.template get<std::string>("DirectiveSnippets_name" ) );
		}
		if (v.get_indicator("DirectiveSnippets_type") != i_null){
			p.setType( v.template get<std::string>("DirectiveSnippets_type" ) );
		}
		if (v.get_indicator("DirectiveSnippets_snippet") != i_null){
			p.setSnippet( v.template get<std::string>("DirectiveSnippets_snippet" ) );
		}
		if (v.get_indicator("DirectiveSnippets_active") != i_null){
			p.setActive( v.template get<std::string>("DirectiveSnippets_active" ) );
		}
	}
	static void to_base(const DirectiveSnippets & p, values & v, indicator & ind)
	{
		v.set( "DirectiveSnippets_directive_snippets_id", p.getDirectiveSnippetsId() );
		v.set( "DirectiveSnippets_sys_userid", p.getSysUserid() );
		v.set( "DirectiveSnippets_sys_groupid", p.getSysGroupid() );
		v.set( "DirectiveSnippets_sys_perm_user", p.getSysPermUser() );
		v.set( "DirectiveSnippets_sys_perm_group", p.getSysPermGroup() );
		v.set( "DirectiveSnippets_sys_perm_other", p.getSysPermOther() );
		v.set( "DirectiveSnippets_name", p.getName() );
		v.set( "DirectiveSnippets_type", p.getType() );
		v.set( "DirectiveSnippets_snippet", p.getSnippet() );
		v.set( "DirectiveSnippets_active", p.getActive() );
		ind = i_ok;
	}
};
}

#endif // DIRECTIVESNIPPETSREPOSITORY_H
