#include "sysgrouprepository.h"
#include "util.hpp"
SysGroupRepository::SysGroupRepository(soci::session& db) : dataBase(db)
{
}

SysGroupPtr SysGroupRepository::select(const SysGroup& obj)
{
	soci::row row;
	SysGroupPtr sysgroup(new SysGroup);
	dataBase << "SELECT  sys_group.groupid as SysGroup_groupid, sys_group.name as SysGroup_name, sys_group.description as SysGroup_description, sys_group.client_id as SysGroup_client_id"
	" FROM sys_group "
	"WHERE sys_group.groupid = :SysGroup_groupid", into(row), use(obj);
	if(!dataBase.got_data())
		sysgroup.reset();
	else
		type_conversion<SysGroup>::from_base(row, i_ok, *sysgroup);
	return sysgroup;
}
SysGroupList SysGroupRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  sys_group.groupid as SysGroup_groupid, sys_group.name as SysGroup_name, sys_group.description as SysGroup_description, sys_group.client_id as SysGroup_client_id "
	" FROM sys_group" 
	<< (where.size()?" WHERE "+where:"");
	SysGroupList sysgroupList;
	for(row& r: rs)
	{
		SysGroupPtr sysgroup(new SysGroup);
		type_conversion<SysGroup>::from_base(r, i_ok, *sysgroup);
		sysgroupList.push_back(sysgroup);
	}
	return sysgroupList;
}

int SysGroupRepository::insert(const SysGroup& sysgroup)
{
	dataBase << "insert into sys_group(groupid, name, description, client_id)\
values(:SysGroup_groupid, :SysGroup_name, :SysGroup_description, :SysGroup_client_id)", use(sysgroup);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void SysGroupRepository::remove(const SysGroup& sysgroup)
{
	dataBase << "DELETE from sys_group WHERE groupid=:SysGroup_groupid", use(sysgroup);
}

void SysGroupRepository::update(const SysGroup& sysgroup)
{
	dataBase << "update sys_group set groupid=:SysGroup_groupid, name=:SysGroup_name, description=:SysGroup_description, client_id=:SysGroup_client_id WHERE groupid=:SysGroup_groupid", use(sysgroup);
}

void SysGroupRepository::update(const SysGroup& oldObj, const SysGroup& newObj)
{
	dataBase << "update sys_group set groupid=:SysGroup_groupid, name=:SysGroup_name, description=:SysGroup_description, client_id=:SysGroup_client_id WHERE groupid='"<<oldObj.getGroupid()<<"\'", use(newObj);
}

