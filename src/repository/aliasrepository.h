#ifndef ALIASREPOSITORY_H
#define ALIASREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/alias.h"
using namespace soci;


class AliasRepository
{
	soci::session& dataBase;
public:
	AliasRepository(soci::session& dataBase);
	int insert(const Alias& alias);
	AliasPtr select(const Alias& alias);
	AliasList select(const string& where="");
	void update(const Alias& alias);
	void update(const Alias& oldObj, const Alias& newObj);
	void remove(const Alias& alias);
};

namespace soci
{
template<>
struct type_conversion<Alias>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, Alias & p)
	{
		if (v.get_indicator("Alias_address") != i_null){
			p.setAddress( v.template get<std::string>("Alias_address" ) );
		}
		if (v.get_indicator("Alias_goto_") != i_null){
			p.setGoto( v.template get<std::string>("Alias_goto_" ) );
		}
		if (v.get_indicator("Alias_domain") != i_null){
			p.setDomain( v.template get<std::string>("Alias_domain" ) );
		}
		if (v.get_indicator("Alias_create_date") != i_null){
			p.setCreateDate( v.template get<tm>("Alias_create_date" ) );
		}
		if (v.get_indicator("Alias_change_date") != i_null){
			p.setChangeDate( v.template get<tm>("Alias_change_date" ) );
		}
		if (v.get_indicator("Alias_add_info") != i_null){
			p.setAddInfo( v.template get<std::string>("Alias_add_info" ) );
		}
		if (v.get_indicator("Alias_active") != i_null){
			p.setActive( v.template get<int>("Alias_active" ) );
		}
	}
	static void to_base(const Alias & p, values & v, indicator & ind)
	{
		v.set( "Alias_address", p.getAddress() );
		v.set( "Alias_goto_", p.getGoto() );
		v.set( "Alias_domain", p.getDomain() );
		v.set( "Alias_create_date", p.getCreateDate() );
		v.set( "Alias_change_date", p.getChangeDate() );
		v.set( "Alias_add_info", p.getAddInfo() );
		v.set( "Alias_active", p.getActive() );
		ind = i_ok;
	}
};
}

#endif // ALIASREPOSITORY_H
