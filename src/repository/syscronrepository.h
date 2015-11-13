#ifndef SYSCRONREPOSITORY_H
#define SYSCRONREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/syscron.h"
using namespace soci;


class SysCronRepository
{
	soci::session& dataBase;
public:
	SysCronRepository(soci::session& dataBase);
	int insert(const SysCron& syscron);
	SysCronPtr select(const SysCron& syscron);
	SysCronList select(const string& where="");
	void update(const SysCron& syscron);
	void update(const SysCron& oldObj, const SysCron& newObj);
	void remove(const SysCron& syscron);
};

namespace soci
{
template<>
struct type_conversion<SysCron>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, SysCron & p)
	{
		if (v.get_indicator("SysCron_name") != i_null){
			p.setName( v.template get<std::string>("SysCron_name" ) );
		}
		if (v.get_indicator("SysCron_last_run") != i_null){
			p.setLastRun( v.template get<tm>("SysCron_last_run" ) );
		}
		if (v.get_indicator("SysCron_next_run") != i_null){
			p.setNextRun( v.template get<tm>("SysCron_next_run" ) );
		}
		if (v.get_indicator("SysCron_running") != i_null){
			p.setRunning( v.template get<int>("SysCron_running" ) );
		}
	}
	static void to_base(const SysCron & p, values & v, indicator & ind)
	{
		v.set( "SysCron_name", p.getName() );
		v.set( "SysCron_last_run", p.getLastRun() );
		v.set( "SysCron_next_run", p.getNextRun() );
		v.set( "SysCron_running", p.getRunning() );
		ind = i_ok;
	}
};
}

#endif // SYSCRONREPOSITORY_H
