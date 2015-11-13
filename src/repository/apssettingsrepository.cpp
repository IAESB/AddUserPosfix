#include "apssettingsrepository.h"
#include "util.hpp"
ApsSettingsRepository::ApsSettingsRepository(soci::session& db) : dataBase(db)
{
}

ApsSettingsPtr ApsSettingsRepository::select(const ApsSettings& obj)
{
	soci::row row;
	ApsSettingsPtr apssettings(new ApsSettings);
	dataBase << "SELECT  aps_settings.id as ApsSettings_id, aps_settings.name as ApsSettings_name, aps_settings.value as ApsSettings_value"
	" FROM aps_settings "
	"WHERE aps_settings.id = :ApsSettings_id AND aps_settings.name = :ApsSettings_name", into(row), use(obj);
	if(!dataBase.got_data())
		apssettings.reset();
	else
		type_conversion<ApsSettings>::from_base(row, i_ok, *apssettings);
	return apssettings;
}
ApsSettingsList ApsSettingsRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  aps_settings.id as ApsSettings_id, aps_settings.name as ApsSettings_name, aps_settings.value as ApsSettings_value "
	" FROM aps_settings" 
	<< (where.size()?" WHERE "+where:"");
	ApsSettingsList apssettingsList;
	for(row& r: rs)
	{
		ApsSettingsPtr apssettings(new ApsSettings);
		type_conversion<ApsSettings>::from_base(r, i_ok, *apssettings);
		apssettingsList.push_back(apssettings);
	}
	return apssettingsList;
}

int ApsSettingsRepository::insert(const ApsSettings& apssettings)
{
	dataBase << "insert into aps_settings(id, name, value)\
values(:ApsSettings_name, :ApsSettings_value)", use(apssettings);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void ApsSettingsRepository::remove(const ApsSettings& apssettings)
{
	dataBase << "DELETE from aps_settings WHERE id=:ApsSettings_id AND name=:ApsSettings_name", use(apssettings);
}

void ApsSettingsRepository::update(const ApsSettings& apssettings)
{
	dataBase << "update aps_settings set name=:ApsSettings_name, value=:ApsSettings_value WHERE id=:ApsSettings_id AND name=:ApsSettings_name", use(apssettings);
}

void ApsSettingsRepository::update(const ApsSettings& oldObj, const ApsSettings& newObj)
{
	dataBase << "update aps_settings set name=:ApsSettings_name, value=:ApsSettings_value WHERE id='"<<oldObj.getId()<<"\'' AND name='"<<oldObj.getName()<<"\'", use(newObj);
}

