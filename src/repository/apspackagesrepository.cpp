#include "apspackagesrepository.h"
#include "util.hpp"
ApsPackagesRepository::ApsPackagesRepository(soci::session& db) : dataBase(db)
{
}

ApsPackagesPtr ApsPackagesRepository::select(const ApsPackages& obj)
{
	soci::row row;
	ApsPackagesPtr apspackages(new ApsPackages);
	dataBase << "SELECT  aps_packages.id as ApsPackages_id, aps_packages.path as ApsPackages_path, aps_packages.name as ApsPackages_name, aps_packages.category as ApsPackages_category, aps_packages.version as ApsPackages_version, aps_packages.release as ApsPackages_release, aps_packages.package_url as ApsPackages_package_url, aps_packages.package_status as ApsPackages_package_status"
	" FROM aps_packages "
	"WHERE aps_packages.id = :ApsPackages_id", into(row), use(obj);
	if(!dataBase.got_data())
		apspackages.reset();
	else
		type_conversion<ApsPackages>::from_base(row, i_ok, *apspackages);
	return apspackages;
}
ApsPackagesList ApsPackagesRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  aps_packages.id as ApsPackages_id, aps_packages.path as ApsPackages_path, aps_packages.name as ApsPackages_name, aps_packages.category as ApsPackages_category, aps_packages.version as ApsPackages_version, aps_packages.release as ApsPackages_release, aps_packages.package_url as ApsPackages_package_url, aps_packages.package_status as ApsPackages_package_status "
	" FROM aps_packages" 
	<< (where.size()?" WHERE "+where:"");
	ApsPackagesList apspackagesList;
	for(row& r: rs)
	{
		ApsPackagesPtr apspackages(new ApsPackages);
		type_conversion<ApsPackages>::from_base(r, i_ok, *apspackages);
		apspackagesList.push_back(apspackages);
	}
	return apspackagesList;
}

int ApsPackagesRepository::insert(const ApsPackages& apspackages)
{
	dataBase << "insert into aps_packages(id, path, name, category, version, release, package_url, package_status)\
values(:ApsPackages_path, :ApsPackages_name, :ApsPackages_category, :ApsPackages_version, :ApsPackages_release, :ApsPackages_package_url, :ApsPackages_package_status)", use(apspackages);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void ApsPackagesRepository::remove(const ApsPackages& apspackages)
{
	dataBase << "DELETE from aps_packages WHERE id=:ApsPackages_id", use(apspackages);
}

void ApsPackagesRepository::update(const ApsPackages& apspackages)
{
	dataBase << "update aps_packages set path=:ApsPackages_path, name=:ApsPackages_name, category=:ApsPackages_category, version=:ApsPackages_version, release=:ApsPackages_release, package_url=:ApsPackages_package_url, package_status=:ApsPackages_package_status WHERE id=:ApsPackages_id", use(apspackages);
}

void ApsPackagesRepository::update(const ApsPackages& oldObj, const ApsPackages& newObj)
{
	dataBase << "update aps_packages set path=:ApsPackages_path, name=:ApsPackages_name, category=:ApsPackages_category, version=:ApsPackages_version, release=:ApsPackages_release, package_url=:ApsPackages_package_url, package_status=:ApsPackages_package_status WHERE id='"<<oldObj.getId()<<"\'", use(newObj);
}

