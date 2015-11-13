#ifndef APSPACKAGESREPOSITORY_H
#define APSPACKAGESREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/apspackages.h"
using namespace soci;


class ApsPackagesRepository
{
	soci::session& dataBase;
public:
	ApsPackagesRepository(soci::session& dataBase);
	int insert(const ApsPackages& apspackages);
	ApsPackagesPtr select(const ApsPackages& apspackages);
	ApsPackagesList select(const string& where="");
	void update(const ApsPackages& apspackages);
	void update(const ApsPackages& oldObj, const ApsPackages& newObj);
	void remove(const ApsPackages& apspackages);
};

namespace soci
{
template<>
struct type_conversion<ApsPackages>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, ApsPackages & p)
	{
		if (v.get_indicator("ApsPackages_id") != i_null){
			p.setId( v.template get<int>("ApsPackages_id" ) );
		}
		if (v.get_indicator("ApsPackages_path") != i_null){
			p.setPath( v.template get<std::string>("ApsPackages_path" ) );
		}
		if (v.get_indicator("ApsPackages_name") != i_null){
			p.setName( v.template get<std::string>("ApsPackages_name" ) );
		}
		if (v.get_indicator("ApsPackages_category") != i_null){
			p.setCategory( v.template get<std::string>("ApsPackages_category" ) );
		}
		if (v.get_indicator("ApsPackages_version") != i_null){
			p.setVersion( v.template get<std::string>("ApsPackages_version" ) );
		}
		if (v.get_indicator("ApsPackages_release") != i_null){
			p.setRelease( v.template get<int>("ApsPackages_release" ) );
		}
		if (v.get_indicator("ApsPackages_package_url") != i_null){
			p.setPackageUrl( v.template get<std::string>("ApsPackages_package_url" ) );
		}
		if (v.get_indicator("ApsPackages_package_status") != i_null){
			p.setPackageStatus( v.template get<int>("ApsPackages_package_status" ) );
		}
	}
	static void to_base(const ApsPackages & p, values & v, indicator & ind)
	{
		v.set( "ApsPackages_id", p.getId() );
		v.set( "ApsPackages_path", p.getPath() );
		v.set( "ApsPackages_name", p.getName() );
		v.set( "ApsPackages_category", p.getCategory() );
		v.set( "ApsPackages_version", p.getVersion() );
		v.set( "ApsPackages_release", p.getRelease() );
		v.set( "ApsPackages_package_url", p.getPackageUrl() );
		v.set( "ApsPackages_package_status", p.getPackageStatus() );
		ind = i_ok;
	}
};
}

#endif // APSPACKAGESREPOSITORY_H
