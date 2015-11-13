#ifndef SYSCONFIGREPOSITORY_H
#define SYSCONFIGREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/sysconfig.h"
using namespace soci;


class SysConfigRepository
{
	soci::session& dataBase;
public:
	SysConfigRepository(soci::session& dataBase);
	int insert(const SysConfig& sysconfig);
	SysConfigPtr select(const SysConfig& sysconfig);
	SysConfigList select(const string& where="");
	void update(const SysConfig& sysconfig);
	void update(const SysConfig& oldObj, const SysConfig& newObj);
	void remove(const SysConfig& sysconfig);
};

namespace soci
{
template<>
struct type_conversion<SysConfig>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, SysConfig & p)
	{
		if (v.get_indicator("SysConfig_group") != i_null){
			p.setGroup( v.template get<std::string>("SysConfig_group" ) );
		}
		if (v.get_indicator("SysConfig_name") != i_null){
			p.setName( v.template get<std::string>("SysConfig_name" ) );
		}
		if (v.get_indicator("SysConfig_value") != i_null){
			p.setValue( v.template get<std::string>("SysConfig_value" ) );
		}
	}
	static void to_base(const SysConfig & p, values & v, indicator & ind)
	{
		v.set( "SysConfig_group", p.getGroup() );
		v.set( "SysConfig_name", p.getName() );
		v.set( "SysConfig_value", p.getValue() );
		ind = i_ok;
	}
};
}

#endif // SYSCONFIGREPOSITORY_H
