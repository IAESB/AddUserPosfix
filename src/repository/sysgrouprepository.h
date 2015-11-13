#ifndef SYSGROUPREPOSITORY_H
#define SYSGROUPREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/sysgroup.h"
using namespace soci;


class SysGroupRepository
{
	soci::session& dataBase;
public:
	SysGroupRepository(soci::session& dataBase);
	int insert(const SysGroup& sysgroup);
	SysGroupPtr select(const SysGroup& sysgroup);
	SysGroupList select(const string& where="");
	void update(const SysGroup& sysgroup);
	void update(const SysGroup& oldObj, const SysGroup& newObj);
	void remove(const SysGroup& sysgroup);
};

namespace soci
{
template<>
struct type_conversion<SysGroup>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, SysGroup & p)
	{
		if (v.get_indicator("SysGroup_groupid") != i_null){
			p.setGroupid( v.template get<long long>("SysGroup_groupid" ) );
		}
		if (v.get_indicator("SysGroup_name") != i_null){
			p.setName( v.template get<std::string>("SysGroup_name" ) );
		}
		if (v.get_indicator("SysGroup_description") != i_null){
			p.setDescription( v.template get<std::string>("SysGroup_description" ) );
		}
		if (v.get_indicator("SysGroup_client_id") != i_null){
			p.setClientId( v.template get<long long>("SysGroup_client_id" ) );
		}
	}
	static void to_base(const SysGroup & p, values & v, indicator & ind)
	{
		v.set( "SysGroup_groupid", p.getGroupid() );
		v.set( "SysGroup_name", p.getName() );
		v.set( "SysGroup_description", p.getDescription() );
		v.set( "SysGroup_client_id", p.getClientId() );
		ind = i_ok;
	}
};
}

#endif // SYSGROUPREPOSITORY_H
