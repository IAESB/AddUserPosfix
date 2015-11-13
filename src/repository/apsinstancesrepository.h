#ifndef APSINSTANCESREPOSITORY_H
#define APSINSTANCESREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/apsinstances.h"
using namespace soci;


class ApsInstancesRepository
{
	soci::session& dataBase;
public:
	ApsInstancesRepository(soci::session& dataBase);
	int insert(const ApsInstances& apsinstances);
	ApsInstancesPtr select(const ApsInstances& apsinstances);
	ApsInstancesList select(const string& where="");
	void update(const ApsInstances& apsinstances);
	void update(const ApsInstances& oldObj, const ApsInstances& newObj);
	void remove(const ApsInstances& apsinstances);
};

namespace soci
{
template<>
struct type_conversion<ApsInstances>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, ApsInstances & p)
	{
		if (v.get_indicator("ApsInstances_id") != i_null){
			p.setId( v.template get<int>("ApsInstances_id" ) );
		}
		if (v.get_indicator("ApsInstances_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("ApsInstances_sys_userid" ) );
		}
		if (v.get_indicator("ApsInstances_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("ApsInstances_sys_groupid" ) );
		}
		if (v.get_indicator("ApsInstances_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("ApsInstances_sys_perm_user" ) );
		}
		if (v.get_indicator("ApsInstances_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("ApsInstances_sys_perm_group" ) );
		}
		if (v.get_indicator("ApsInstances_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("ApsInstances_sys_perm_other" ) );
		}
		if (v.get_indicator("ApsInstances_server_id") != i_null){
			p.setServerId( v.template get<int>("ApsInstances_server_id" ) );
		}
		if (v.get_indicator("ApsInstances_customer_id") != i_null){
			p.setCustomerId( v.template get<int>("ApsInstances_customer_id" ) );
		}
		if (v.get_indicator("ApsInstances_package_id") != i_null){
			p.setPackageId( v.template get<int>("ApsInstances_package_id" ) );
		}
		if (v.get_indicator("ApsInstances_instance_status") != i_null){
			p.setInstanceStatus( v.template get<int>("ApsInstances_instance_status" ) );
		}
	}
	static void to_base(const ApsInstances & p, values & v, indicator & ind)
	{
		v.set( "ApsInstances_id", p.getId() );
		v.set( "ApsInstances_sys_userid", p.getSysUserid() );
		v.set( "ApsInstances_sys_groupid", p.getSysGroupid() );
		v.set( "ApsInstances_sys_perm_user", p.getSysPermUser() );
		v.set( "ApsInstances_sys_perm_group", p.getSysPermGroup() );
		v.set( "ApsInstances_sys_perm_other", p.getSysPermOther() );
		v.set( "ApsInstances_server_id", p.getServerId() );
		v.set( "ApsInstances_customer_id", p.getCustomerId() );
		v.set( "ApsInstances_package_id", p.getPackageId() );
		v.set( "ApsInstances_instance_status", p.getInstanceStatus() );
		ind = i_ok;
	}
};
}

#endif // APSINSTANCESREPOSITORY_H
