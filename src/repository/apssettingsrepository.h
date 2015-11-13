#ifndef APSSETTINGSREPOSITORY_H
#define APSSETTINGSREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/apssettings.h"
using namespace soci;


class ApsSettingsRepository
{
	soci::session& dataBase;
public:
	ApsSettingsRepository(soci::session& dataBase);
	int insert(const ApsSettings& apssettings);
	ApsSettingsPtr select(const ApsSettings& apssettings);
	ApsSettingsList select(const string& where="");
	void update(const ApsSettings& apssettings);
	void update(const ApsSettings& oldObj, const ApsSettings& newObj);
	void remove(const ApsSettings& apssettings);
};

namespace soci
{
template<>
struct type_conversion<ApsSettings>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, ApsSettings & p)
	{
		if (v.get_indicator("ApsSettings_id") != i_null){
			p.setId( v.template get<int>("ApsSettings_id" ) );
		}
		if (v.get_indicator("ApsSettings_name") != i_null){
			p.setName( v.template get<std::string>("ApsSettings_name" ) );
		}
		if (v.get_indicator("ApsSettings_value") != i_null){
			p.setValue( v.template get<std::string>("ApsSettings_value" ) );
		}
	}
	static void to_base(const ApsSettings & p, values & v, indicator & ind)
	{
		v.set( "ApsSettings_id", p.getId() );
		v.set( "ApsSettings_name", p.getName() );
		v.set( "ApsSettings_value", p.getValue() );
		ind = i_ok;
	}
};
}

#endif // APSSETTINGSREPOSITORY_H
