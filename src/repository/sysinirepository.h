#ifndef SYSINIREPOSITORY_H
#define SYSINIREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/sysini.h"
using namespace soci;


class SysIniRepository
{
	soci::session& dataBase;
public:
	SysIniRepository(soci::session& dataBase);
	int insert(const SysIni& sysini);
	SysIniPtr select(const SysIni& sysini);
	SysIniList select(const string& where="");
	void update(const SysIni& sysini);
	void update(const SysIni& oldObj, const SysIni& newObj);
	void remove(const SysIni& sysini);
};

namespace soci
{
template<>
struct type_conversion<SysIni>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, SysIni & p)
	{
		if (v.get_indicator("SysIni_sysini_id") != i_null){
			p.setSysiniId( v.template get<long long>("SysIni_sysini_id" ) );
		}
		if (v.get_indicator("SysIni_config") != i_null){
			p.setConfig( v.template get<std::string>("SysIni_config" ) );
		}
	}
	static void to_base(const SysIni & p, values & v, indicator & ind)
	{
		v.set( "SysIni_sysini_id", p.getSysiniId() );
		v.set( "SysIni_config", p.getConfig() );
		ind = i_ok;
	}
};
}

#endif // SYSINIREPOSITORY_H
