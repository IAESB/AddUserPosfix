#include "softwareupdaterepository.h"
#include "util.hpp"
SoftwareUpdateRepository::SoftwareUpdateRepository(soci::session& db) : dataBase(db)
{
}

SoftwareUpdatePtr SoftwareUpdateRepository::select(const SoftwareUpdate& obj)
{
	soci::row row;
	SoftwareUpdatePtr softwareupdate(new SoftwareUpdate);
	dataBase << "SELECT  software_update.software_update_id as SoftwareUpdate_software_update_id, software_update.software_repo_id as SoftwareUpdate_software_repo_id, software_update.package_name as SoftwareUpdate_package_name, software_update.update_url as SoftwareUpdate_update_url, software_update.update_md5 as SoftwareUpdate_update_md5, software_update.update_dependencies as SoftwareUpdate_update_dependencies, software_update.update_title as SoftwareUpdate_update_title, software_update.v1 as SoftwareUpdate_v1, software_update.v2 as SoftwareUpdate_v2, software_update.v3 as SoftwareUpdate_v3, software_update.v4 as SoftwareUpdate_v4, software_update.type as SoftwareUpdate_type"
	" FROM software_update "
	"WHERE software_update.software_update_id = :SoftwareUpdate_software_update_id", into(row), use(obj);
	if(!dataBase.got_data())
		softwareupdate.reset();
	else
		type_conversion<SoftwareUpdate>::from_base(row, i_ok, *softwareupdate);
	return softwareupdate;
}
SoftwareUpdateList SoftwareUpdateRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  software_update.software_update_id as SoftwareUpdate_software_update_id, software_update.software_repo_id as SoftwareUpdate_software_repo_id, software_update.package_name as SoftwareUpdate_package_name, software_update.update_url as SoftwareUpdate_update_url, software_update.update_md5 as SoftwareUpdate_update_md5, software_update.update_dependencies as SoftwareUpdate_update_dependencies, software_update.update_title as SoftwareUpdate_update_title, software_update.v1 as SoftwareUpdate_v1, software_update.v2 as SoftwareUpdate_v2, software_update.v3 as SoftwareUpdate_v3, software_update.v4 as SoftwareUpdate_v4, software_update.type as SoftwareUpdate_type "
	" FROM software_update" 
	<< (where.size()?" WHERE "+where:"");
	SoftwareUpdateList softwareupdateList;
	for(row& r: rs)
	{
		SoftwareUpdatePtr softwareupdate(new SoftwareUpdate);
		type_conversion<SoftwareUpdate>::from_base(r, i_ok, *softwareupdate);
		softwareupdateList.push_back(softwareupdate);
	}
	return softwareupdateList;
}

int SoftwareUpdateRepository::insert(const SoftwareUpdate& softwareupdate)
{
	dataBase << "insert into software_update(software_update_id, software_repo_id, package_name, update_url, update_md5, update_dependencies, update_title, v1, v2, v3, v4, type)\
values(:SoftwareUpdate_software_update_id, :SoftwareUpdate_software_repo_id, :SoftwareUpdate_package_name, :SoftwareUpdate_update_url, :SoftwareUpdate_update_md5, :SoftwareUpdate_update_dependencies, :SoftwareUpdate_update_title, :SoftwareUpdate_v1, :SoftwareUpdate_v2, :SoftwareUpdate_v3, :SoftwareUpdate_v4, :SoftwareUpdate_type)", use(softwareupdate);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void SoftwareUpdateRepository::remove(const SoftwareUpdate& softwareupdate)
{
	dataBase << "DELETE from software_update WHERE software_update_id=:SoftwareUpdate_software_update_id", use(softwareupdate);
}

void SoftwareUpdateRepository::update(const SoftwareUpdate& softwareupdate)
{
	dataBase << "update software_update set software_update_id=:SoftwareUpdate_software_update_id, software_repo_id=:SoftwareUpdate_software_repo_id, package_name=:SoftwareUpdate_package_name, update_url=:SoftwareUpdate_update_url, update_md5=:SoftwareUpdate_update_md5, update_dependencies=:SoftwareUpdate_update_dependencies, update_title=:SoftwareUpdate_update_title, v1=:SoftwareUpdate_v1, v2=:SoftwareUpdate_v2, v3=:SoftwareUpdate_v3, v4=:SoftwareUpdate_v4, type=:SoftwareUpdate_type WHERE software_update_id=:SoftwareUpdate_software_update_id", use(softwareupdate);
}

void SoftwareUpdateRepository::update(const SoftwareUpdate& oldObj, const SoftwareUpdate& newObj)
{
	dataBase << "update software_update set software_update_id=:SoftwareUpdate_software_update_id, software_repo_id=:SoftwareUpdate_software_repo_id, package_name=:SoftwareUpdate_package_name, update_url=:SoftwareUpdate_update_url, update_md5=:SoftwareUpdate_update_md5, update_dependencies=:SoftwareUpdate_update_dependencies, update_title=:SoftwareUpdate_update_title, v1=:SoftwareUpdate_v1, v2=:SoftwareUpdate_v2, v3=:SoftwareUpdate_v3, v4=:SoftwareUpdate_v4, type=:SoftwareUpdate_type WHERE software_update_id='"<<oldObj.getSoftwareUpdateId()<<"\'", use(newObj);
}

