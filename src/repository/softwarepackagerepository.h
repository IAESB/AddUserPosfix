#ifndef SOFTWAREPACKAGEREPOSITORY_H
#define SOFTWAREPACKAGEREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/softwarepackage.h"
using namespace soci;


class SoftwarePackageRepository
{
	soci::session& dataBase;
public:
	SoftwarePackageRepository(soci::session& dataBase);
	int insert(const SoftwarePackage& softwarepackage);
	SoftwarePackagePtr select(const SoftwarePackage& softwarepackage);
	SoftwarePackageList select(const string& where="");
	void update(const SoftwarePackage& softwarepackage);
	void update(const SoftwarePackage& oldObj, const SoftwarePackage& newObj);
	void remove(const SoftwarePackage& softwarepackage);
};

namespace soci
{
template<>
struct type_conversion<SoftwarePackage>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, SoftwarePackage & p)
	{
		if (v.get_indicator("SoftwarePackage_package_id") != i_null){
			p.setPackageId( v.template get<long long>("SoftwarePackage_package_id" ) );
		}
		if (v.get_indicator("SoftwarePackage_software_repo_id") != i_null){
			p.setSoftwareRepoId( v.template get<long long>("SoftwarePackage_software_repo_id" ) );
		}
		if (v.get_indicator("SoftwarePackage_package_name") != i_null){
			p.setPackageName( v.template get<std::string>("SoftwarePackage_package_name" ) );
		}
		if (v.get_indicator("SoftwarePackage_package_title") != i_null){
			p.setPackageTitle( v.template get<std::string>("SoftwarePackage_package_title" ) );
		}
		if (v.get_indicator("SoftwarePackage_package_description") != i_null){
			p.setPackageDescription( v.template get<std::string>("SoftwarePackage_package_description" ) );
		}
		if (v.get_indicator("SoftwarePackage_package_version") != i_null){
			p.setPackageVersion( v.template get<std::string>("SoftwarePackage_package_version" ) );
		}
		if (v.get_indicator("SoftwarePackage_package_type") != i_null){
			p.setPackageType( v.template get<std::string>("SoftwarePackage_package_type" ) );
		}
		if (v.get_indicator("SoftwarePackage_package_installable") != i_null){
			p.setPackageInstallable( v.template get<std::string>("SoftwarePackage_package_installable" ) );
		}
		if (v.get_indicator("SoftwarePackage_package_requires_db") != i_null){
			p.setPackageRequiresDb( v.template get<std::string>("SoftwarePackage_package_requires_db" ) );
		}
		if (v.get_indicator("SoftwarePackage_package_remote_functions") != i_null){
			p.setPackageRemoteFunctions( v.template get<std::string>("SoftwarePackage_package_remote_functions" ) );
		}
		if (v.get_indicator("SoftwarePackage_package_key") != i_null){
			p.setPackageKey( v.template get<std::string>("SoftwarePackage_package_key" ) );
		}
		if (v.get_indicator("SoftwarePackage_package_config") != i_null){
			p.setPackageConfig( v.template get<std::string>("SoftwarePackage_package_config" ) );
		}
	}
	static void to_base(const SoftwarePackage & p, values & v, indicator & ind)
	{
		v.set( "SoftwarePackage_package_id", p.getPackageId() );
		v.set( "SoftwarePackage_software_repo_id", p.getSoftwareRepoId() );
		v.set( "SoftwarePackage_package_name", p.getPackageName() );
		v.set( "SoftwarePackage_package_title", p.getPackageTitle() );
		v.set( "SoftwarePackage_package_description", p.getPackageDescription() );
		v.set( "SoftwarePackage_package_version", p.getPackageVersion() );
		v.set( "SoftwarePackage_package_type", p.getPackageType() );
		v.set( "SoftwarePackage_package_installable", p.getPackageInstallable() );
		v.set( "SoftwarePackage_package_requires_db", p.getPackageRequiresDb() );
		v.set( "SoftwarePackage_package_remote_functions", p.getPackageRemoteFunctions() );
		v.set( "SoftwarePackage_package_key", p.getPackageKey() );
		v.set( "SoftwarePackage_package_config", p.getPackageConfig() );
		ind = i_ok;
	}
};
}

#endif // SOFTWAREPACKAGEREPOSITORY_H
