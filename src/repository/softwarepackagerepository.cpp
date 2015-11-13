#include "softwarepackagerepository.h"
#include "util.hpp"
SoftwarePackageRepository::SoftwarePackageRepository(soci::session& db) : dataBase(db)
{
}

SoftwarePackagePtr SoftwarePackageRepository::select(const SoftwarePackage& obj)
{
	soci::row row;
	SoftwarePackagePtr softwarepackage(new SoftwarePackage);
	dataBase << "SELECT  software_package.package_id as SoftwarePackage_package_id, software_package.software_repo_id as SoftwarePackage_software_repo_id, software_package.package_name as SoftwarePackage_package_name, software_package.package_title as SoftwarePackage_package_title, software_package.package_description as SoftwarePackage_package_description, software_package.package_version as SoftwarePackage_package_version, software_package.package_type as SoftwarePackage_package_type, software_package.package_installable as SoftwarePackage_package_installable, software_package.package_requires_db as SoftwarePackage_package_requires_db, software_package.package_remote_functions as SoftwarePackage_package_remote_functions, software_package.package_key as SoftwarePackage_package_key, software_package.package_config as SoftwarePackage_package_config"
	" FROM software_package "
	"WHERE software_package.package_id = :SoftwarePackage_package_id AND software_package.package_name = :SoftwarePackage_package_name", into(row), use(obj);
	if(!dataBase.got_data())
		softwarepackage.reset();
	else
		type_conversion<SoftwarePackage>::from_base(row, i_ok, *softwarepackage);
	return softwarepackage;
}
SoftwarePackageList SoftwarePackageRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  software_package.package_id as SoftwarePackage_package_id, software_package.software_repo_id as SoftwarePackage_software_repo_id, software_package.package_name as SoftwarePackage_package_name, software_package.package_title as SoftwarePackage_package_title, software_package.package_description as SoftwarePackage_package_description, software_package.package_version as SoftwarePackage_package_version, software_package.package_type as SoftwarePackage_package_type, software_package.package_installable as SoftwarePackage_package_installable, software_package.package_requires_db as SoftwarePackage_package_requires_db, software_package.package_remote_functions as SoftwarePackage_package_remote_functions, software_package.package_key as SoftwarePackage_package_key, software_package.package_config as SoftwarePackage_package_config "
	" FROM software_package" 
	<< (where.size()?" WHERE "+where:"");
	SoftwarePackageList softwarepackageList;
	for(row& r: rs)
	{
		SoftwarePackagePtr softwarepackage(new SoftwarePackage);
		type_conversion<SoftwarePackage>::from_base(r, i_ok, *softwarepackage);
		softwarepackageList.push_back(softwarepackage);
	}
	return softwarepackageList;
}

int SoftwarePackageRepository::insert(const SoftwarePackage& softwarepackage)
{
	dataBase << "insert into software_package(package_id, software_repo_id, package_name, package_title, package_description, package_version, package_type, package_installable, package_requires_db, package_remote_functions, package_key, package_config)\
values(:SoftwarePackage_package_id, :SoftwarePackage_software_repo_id, :SoftwarePackage_package_name, :SoftwarePackage_package_title, :SoftwarePackage_package_description, :SoftwarePackage_package_version, :SoftwarePackage_package_type, :SoftwarePackage_package_installable, :SoftwarePackage_package_requires_db, :SoftwarePackage_package_remote_functions, :SoftwarePackage_package_key, :SoftwarePackage_package_config)", use(softwarepackage);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void SoftwarePackageRepository::remove(const SoftwarePackage& softwarepackage)
{
	dataBase << "DELETE from software_package WHERE package_id=:SoftwarePackage_package_id AND package_name=:SoftwarePackage_package_name", use(softwarepackage);
}

void SoftwarePackageRepository::update(const SoftwarePackage& softwarepackage)
{
	dataBase << "update software_package set package_id=:SoftwarePackage_package_id, software_repo_id=:SoftwarePackage_software_repo_id, package_name=:SoftwarePackage_package_name, package_title=:SoftwarePackage_package_title, package_description=:SoftwarePackage_package_description, package_version=:SoftwarePackage_package_version, package_type=:SoftwarePackage_package_type, package_installable=:SoftwarePackage_package_installable, package_requires_db=:SoftwarePackage_package_requires_db, package_remote_functions=:SoftwarePackage_package_remote_functions, package_key=:SoftwarePackage_package_key, package_config=:SoftwarePackage_package_config WHERE package_id=:SoftwarePackage_package_id AND package_name=:SoftwarePackage_package_name", use(softwarepackage);
}

void SoftwarePackageRepository::update(const SoftwarePackage& oldObj, const SoftwarePackage& newObj)
{
	dataBase << "update software_package set package_id=:SoftwarePackage_package_id, software_repo_id=:SoftwarePackage_software_repo_id, package_name=:SoftwarePackage_package_name, package_title=:SoftwarePackage_package_title, package_description=:SoftwarePackage_package_description, package_version=:SoftwarePackage_package_version, package_type=:SoftwarePackage_package_type, package_installable=:SoftwarePackage_package_installable, package_requires_db=:SoftwarePackage_package_requires_db, package_remote_functions=:SoftwarePackage_package_remote_functions, package_key=:SoftwarePackage_package_key, package_config=:SoftwarePackage_package_config WHERE package_id='"<<oldObj.getPackageId()<<"\'' AND package_name='"<<oldObj.getPackageName()<<"\'", use(newObj);
}

