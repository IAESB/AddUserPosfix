#include "apsinstancesrepository.h"
#include "util.hpp"
ApsInstancesRepository::ApsInstancesRepository(soci::session& db) : dataBase(db)
{
}

ApsInstancesPtr ApsInstancesRepository::select(const ApsInstances& obj)
{
	soci::row row;
	ApsInstancesPtr apsinstances(new ApsInstances);
	dataBase << "SELECT  aps_instances.id as ApsInstances_id, aps_instances.sys_userid as ApsInstances_sys_userid, aps_instances.sys_groupid as ApsInstances_sys_groupid, aps_instances.sys_perm_user as ApsInstances_sys_perm_user, aps_instances.sys_perm_group as ApsInstances_sys_perm_group, aps_instances.sys_perm_other as ApsInstances_sys_perm_other, aps_instances.server_id as ApsInstances_server_id, aps_instances.customer_id as ApsInstances_customer_id, aps_instances.package_id as ApsInstances_package_id, aps_instances.instance_status as ApsInstances_instance_status"
	" FROM aps_instances "
	"WHERE aps_instances.id = :ApsInstances_id", into(row), use(obj);
	if(!dataBase.got_data())
		apsinstances.reset();
	else
		type_conversion<ApsInstances>::from_base(row, i_ok, *apsinstances);
	return apsinstances;
}
ApsInstancesList ApsInstancesRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  aps_instances.id as ApsInstances_id, aps_instances.sys_userid as ApsInstances_sys_userid, aps_instances.sys_groupid as ApsInstances_sys_groupid, aps_instances.sys_perm_user as ApsInstances_sys_perm_user, aps_instances.sys_perm_group as ApsInstances_sys_perm_group, aps_instances.sys_perm_other as ApsInstances_sys_perm_other, aps_instances.server_id as ApsInstances_server_id, aps_instances.customer_id as ApsInstances_customer_id, aps_instances.package_id as ApsInstances_package_id, aps_instances.instance_status as ApsInstances_instance_status "
	" FROM aps_instances" 
	<< (where.size()?" WHERE "+where:"");
	ApsInstancesList apsinstancesList;
	for(row& r: rs)
	{
		ApsInstancesPtr apsinstances(new ApsInstances);
		type_conversion<ApsInstances>::from_base(r, i_ok, *apsinstances);
		apsinstancesList.push_back(apsinstances);
	}
	return apsinstancesList;
}

int ApsInstancesRepository::insert(const ApsInstances& apsinstances)
{
	dataBase << "insert into aps_instances(id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, customer_id, package_id, instance_status)\
values(:ApsInstances_sys_userid, :ApsInstances_sys_groupid, :ApsInstances_sys_perm_user, :ApsInstances_sys_perm_group, :ApsInstances_sys_perm_other, :ApsInstances_server_id, :ApsInstances_customer_id, :ApsInstances_package_id, :ApsInstances_instance_status)", use(apsinstances);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void ApsInstancesRepository::remove(const ApsInstances& apsinstances)
{
	dataBase << "DELETE from aps_instances WHERE id=:ApsInstances_id", use(apsinstances);
}

void ApsInstancesRepository::update(const ApsInstances& apsinstances)
{
	dataBase << "update aps_instances set sys_userid=:ApsInstances_sys_userid, sys_groupid=:ApsInstances_sys_groupid, sys_perm_user=:ApsInstances_sys_perm_user, sys_perm_group=:ApsInstances_sys_perm_group, sys_perm_other=:ApsInstances_sys_perm_other, server_id=:ApsInstances_server_id, customer_id=:ApsInstances_customer_id, package_id=:ApsInstances_package_id, instance_status=:ApsInstances_instance_status WHERE id=:ApsInstances_id", use(apsinstances);
}

void ApsInstancesRepository::update(const ApsInstances& oldObj, const ApsInstances& newObj)
{
	dataBase << "update aps_instances set sys_userid=:ApsInstances_sys_userid, sys_groupid=:ApsInstances_sys_groupid, sys_perm_user=:ApsInstances_sys_perm_user, sys_perm_group=:ApsInstances_sys_perm_group, sys_perm_other=:ApsInstances_sys_perm_other, server_id=:ApsInstances_server_id, customer_id=:ApsInstances_customer_id, package_id=:ApsInstances_package_id, instance_status=:ApsInstances_instance_status WHERE id='"<<oldObj.getId()<<"\'", use(newObj);
}

