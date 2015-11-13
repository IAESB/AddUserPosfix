#include "sysconfigrepository.h"
#include "util.hpp"
SysConfigRepository::SysConfigRepository(soci::session& db) : dataBase(db)
{
}

SysConfigPtr SysConfigRepository::select(const SysConfig& obj)
{
	soci::row row;
	SysConfigPtr sysconfig(new SysConfig);
	dataBase << "SELECT  sys_config.group as SysConfig_group, sys_config.name as SysConfig_name, sys_config.value as SysConfig_value"
	" FROM sys_config "
	"WHERE sys_config.group = :SysConfig_group AND sys_config.name = :SysConfig_name", into(row), use(obj);
	if(!dataBase.got_data())
		sysconfig.reset();
	else
		type_conversion<SysConfig>::from_base(row, i_ok, *sysconfig);
	return sysconfig;
}
SysConfigList SysConfigRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  sys_config.group as SysConfig_group, sys_config.name as SysConfig_name, sys_config.value as SysConfig_value "
	" FROM sys_config" 
	<< (where.size()?" WHERE "+where:"");
	SysConfigList sysconfigList;
	for(row& r: rs)
	{
		SysConfigPtr sysconfig(new SysConfig);
		type_conversion<SysConfig>::from_base(r, i_ok, *sysconfig);
		sysconfigList.push_back(sysconfig);
	}
	return sysconfigList;
}

int SysConfigRepository::insert(const SysConfig& sysconfig)
{
	dataBase << "insert into sys_config(group, name, value)\
values(:SysConfig_group, :SysConfig_name, :SysConfig_value)", use(sysconfig);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void SysConfigRepository::remove(const SysConfig& sysconfig)
{
	dataBase << "DELETE from sys_config WHERE group=:SysConfig_group AND name=:SysConfig_name", use(sysconfig);
}

void SysConfigRepository::update(const SysConfig& sysconfig)
{
	dataBase << "update sys_config set group=:SysConfig_group, name=:SysConfig_name, value=:SysConfig_value WHERE group=:SysConfig_group AND name=:SysConfig_name", use(sysconfig);
}

void SysConfigRepository::update(const SysConfig& oldObj, const SysConfig& newObj)
{
	dataBase << "update sys_config set group=:SysConfig_group, name=:SysConfig_name, value=:SysConfig_value WHERE group='"<<oldObj.getGroup()<<"\'' AND name='"<<oldObj.getName()<<"\'", use(newObj);
}

