#ifndef APSINSTANCESSETTINGSREPOSITORY_H
#define APSINSTANCESSETTINGSREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/apsinstancessettings.h"
using namespace soci;


class ApsInstancesSettingsRepository
{
	soci::session& dataBase;
public:
	ApsInstancesSettingsRepository(soci::session& dataBase);
	int insert(const ApsInstancesSettings& apsinstancessettings);
	ApsInstancesSettingsPtr select(const ApsInstancesSettings& apsinstancessettings);
	ApsInstancesSettingsList select(const string& where="");
	void update(const ApsInstancesSettings& apsinstancessettings);
	void update(const ApsInstancesSettings& oldObj, const ApsInstancesSettings& newObj);
	void remove(const ApsInstancesSettings& apsinstancessettings);
};

namespace soci
{
template<>
struct type_conversion<ApsInstancesSettings>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, ApsInstancesSettings & p)
	{
		if (v.get_indicator("ApsInstancesSettings_id") != i_null){
			p.setId( v.template get<int>("ApsInstancesSettings_id" ) );
		}
		if (v.get_indicator("ApsInstancesSettings_server_id") != i_null){
			p.setServerId( v.template get<int>("ApsInstancesSettings_server_id" ) );
		}
		if (v.get_indicator("ApsInstancesSettings_instance_id") != i_null){
			p.setInstanceId( v.template get<int>("ApsInstancesSettings_instance_id" ) );
		}
		if (v.get_indicator("ApsInstancesSettings_name") != i_null){
			p.setName( v.template get<std::string>("ApsInstancesSettings_name" ) );
		}
		if (v.get_indicator("ApsInstancesSettings_value") != i_null){
			p.setValue( v.template get<std::string>("ApsInstancesSettings_value" ) );
		}
	}
	static void to_base(const ApsInstancesSettings & p, values & v, indicator & ind)
	{
		v.set( "ApsInstancesSettings_id", p.getId() );
		v.set( "ApsInstancesSettings_server_id", p.getServerId() );
		v.set( "ApsInstancesSettings_instance_id", p.getInstanceId() );
		v.set( "ApsInstancesSettings_name", p.getName() );
		v.set( "ApsInstancesSettings_value", p.getValue() );
		ind = i_ok;
	}
};
}

#endif // APSINSTANCESSETTINGSREPOSITORY_H
