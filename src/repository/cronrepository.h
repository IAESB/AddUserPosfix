#ifndef CRONREPOSITORY_H
#define CRONREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/cron.h"
using namespace soci;


class CronRepository
{
	soci::session& dataBase;
public:
	CronRepository(soci::session& dataBase);
	int insert(const Cron& cron);
	CronPtr select(const Cron& cron);
	CronList select(const string& where="");
	void update(const Cron& cron);
	void update(const Cron& oldObj, const Cron& newObj);
	void remove(const Cron& cron);
};

namespace soci
{
template<>
struct type_conversion<Cron>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, Cron & p)
	{
		if (v.get_indicator("Cron_id") != i_null){
			p.setId( v.template get<long long>("Cron_id" ) );
		}
		if (v.get_indicator("Cron_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("Cron_sys_userid" ) );
		}
		if (v.get_indicator("Cron_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("Cron_sys_groupid" ) );
		}
		if (v.get_indicator("Cron_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("Cron_sys_perm_user" ) );
		}
		if (v.get_indicator("Cron_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("Cron_sys_perm_group" ) );
		}
		if (v.get_indicator("Cron_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("Cron_sys_perm_other" ) );
		}
		if (v.get_indicator("Cron_server_id") != i_null){
			p.setServerId( v.template get<long long>("Cron_server_id" ) );
		}
		if (v.get_indicator("Cron_parent_domain_id") != i_null){
			p.setParentDomainId( v.template get<long long>("Cron_parent_domain_id" ) );
		}
		if (v.get_indicator("Cron_type") != i_null){
			p.setType( v.template get<std::string>("Cron_type" ) );
		}
		if (v.get_indicator("Cron_command") != i_null){
			p.setCommand( v.template get<std::string>("Cron_command" ) );
		}
		if (v.get_indicator("Cron_run_min") != i_null){
			p.setRunMin( v.template get<std::string>("Cron_run_min" ) );
		}
		if (v.get_indicator("Cron_run_hour") != i_null){
			p.setRunHour( v.template get<std::string>("Cron_run_hour" ) );
		}
		if (v.get_indicator("Cron_run_mday") != i_null){
			p.setRunMday( v.template get<std::string>("Cron_run_mday" ) );
		}
		if (v.get_indicator("Cron_run_month") != i_null){
			p.setRunMonth( v.template get<std::string>("Cron_run_month" ) );
		}
		if (v.get_indicator("Cron_run_wday") != i_null){
			p.setRunWday( v.template get<std::string>("Cron_run_wday" ) );
		}
		if (v.get_indicator("Cron_log") != i_null){
			p.setLog( v.template get<std::string>("Cron_log" ) );
		}
		if (v.get_indicator("Cron_active") != i_null){
			p.setActive( v.template get<std::string>("Cron_active" ) );
		}
	}
	static void to_base(const Cron & p, values & v, indicator & ind)
	{
		v.set( "Cron_id", p.getId() );
		v.set( "Cron_sys_userid", p.getSysUserid() );
		v.set( "Cron_sys_groupid", p.getSysGroupid() );
		v.set( "Cron_sys_perm_user", p.getSysPermUser() );
		v.set( "Cron_sys_perm_group", p.getSysPermGroup() );
		v.set( "Cron_sys_perm_other", p.getSysPermOther() );
		v.set( "Cron_server_id", p.getServerId() );
		v.set( "Cron_parent_domain_id", p.getParentDomainId() );
		v.set( "Cron_type", p.getType() );
		v.set( "Cron_command", p.getCommand() );
		v.set( "Cron_run_min", p.getRunMin() );
		v.set( "Cron_run_hour", p.getRunHour() );
		v.set( "Cron_run_mday", p.getRunMday() );
		v.set( "Cron_run_month", p.getRunMonth() );
		v.set( "Cron_run_wday", p.getRunWday() );
		v.set( "Cron_log", p.getLog() );
		v.set( "Cron_active", p.getActive() );
		ind = i_ok;
	}
};
}

#endif // CRONREPOSITORY_H
