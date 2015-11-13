#include "apsinstancessettingsrepository.h"
#include "util.hpp"
ApsInstancesSettingsRepository::ApsInstancesSettingsRepository(soci::session& db) : dataBase(db)
{
}

ApsInstancesSettingsPtr ApsInstancesSettingsRepository::select(const ApsInstancesSettings& obj)
{
	soci::row row;
	ApsInstancesSettingsPtr apsinstancessettings(new ApsInstancesSettings);
	dataBase << "SELECT  aps_instances_settings.id as ApsInstancesSettings_id, aps_instances_settings.server_id as ApsInstancesSettings_server_id, aps_instances_settings.instance_id as ApsInstancesSettings_instance_id, aps_instances_settings.name as ApsInstancesSettings_name, aps_instances_settings.value as ApsInstancesSettings_value"
	" FROM aps_instances_settings "
	"WHERE aps_instances_settings.id = :ApsInstancesSettings_id", into(row), use(obj);
	if(!dataBase.got_data())
		apsinstancessettings.reset();
	else
		type_conversion<ApsInstancesSettings>::from_base(row, i_ok, *apsinstancessettings);
	return apsinstancessettings;
}
ApsInstancesSettingsList ApsInstancesSettingsRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  aps_instances_settings.id as ApsInstancesSettings_id, aps_instances_settings.server_id as ApsInstancesSettings_server_id, aps_instances_settings.instance_id as ApsInstancesSettings_instance_id, aps_instances_settings.name as ApsInstancesSettings_name, aps_instances_settings.value as ApsInstancesSettings_value "
	" FROM aps_instances_settings" 
	<< (where.size()?" WHERE "+where:"");
	ApsInstancesSettingsList apsinstancessettingsList;
	for(row& r: rs)
	{
		ApsInstancesSettingsPtr apsinstancessettings(new ApsInstancesSettings);
		type_conversion<ApsInstancesSettings>::from_base(r, i_ok, *apsinstancessettings);
		apsinstancessettingsList.push_back(apsinstancessettings);
	}
	return apsinstancessettingsList;
}

int ApsInstancesSettingsRepository::insert(const ApsInstancesSettings& apsinstancessettings)
{
	dataBase << "insert into aps_instances_settings(id, server_id, instance_id, name, value)\
values(:ApsInstancesSettings_server_id, :ApsInstancesSettings_instance_id, :ApsInstancesSettings_name, :ApsInstancesSettings_value)", use(apsinstancessettings);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void ApsInstancesSettingsRepository::remove(const ApsInstancesSettings& apsinstancessettings)
{
	dataBase << "DELETE from aps_instances_settings WHERE id=:ApsInstancesSettings_id", use(apsinstancessettings);
}

void ApsInstancesSettingsRepository::update(const ApsInstancesSettings& apsinstancessettings)
{
	dataBase << "update aps_instances_settings set server_id=:ApsInstancesSettings_server_id, instance_id=:ApsInstancesSettings_instance_id, name=:ApsInstancesSettings_name, value=:ApsInstancesSettings_value WHERE id=:ApsInstancesSettings_id", use(apsinstancessettings);
}

void ApsInstancesSettingsRepository::update(const ApsInstancesSettings& oldObj, const ApsInstancesSettings& newObj)
{
	dataBase << "update aps_instances_settings set server_id=:ApsInstancesSettings_server_id, instance_id=:ApsInstancesSettings_instance_id, name=:ApsInstancesSettings_name, value=:ApsInstancesSettings_value WHERE id='"<<oldObj.getId()<<"\'", use(newObj);
}

