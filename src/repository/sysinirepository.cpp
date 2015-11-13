#include "sysinirepository.h"
#include "util.hpp"
SysIniRepository::SysIniRepository(soci::session& db) : dataBase(db)
{
}

SysIniPtr SysIniRepository::select(const SysIni& obj)
{
	soci::row row;
	SysIniPtr sysini(new SysIni);
	dataBase << "SELECT  sys_ini.sysini_id as SysIni_sysini_id, sys_ini.config as SysIni_config"
	" FROM sys_ini "
	"WHERE sys_ini.sysini_id = :SysIni_sysini_id", into(row), use(obj);
	if(!dataBase.got_data())
		sysini.reset();
	else
		type_conversion<SysIni>::from_base(row, i_ok, *sysini);
	return sysini;
}
SysIniList SysIniRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  sys_ini.sysini_id as SysIni_sysini_id, sys_ini.config as SysIni_config "
	" FROM sys_ini" 
	<< (where.size()?" WHERE "+where:"");
	SysIniList sysiniList;
	for(row& r: rs)
	{
		SysIniPtr sysini(new SysIni);
		type_conversion<SysIni>::from_base(r, i_ok, *sysini);
		sysiniList.push_back(sysini);
	}
	return sysiniList;
}

int SysIniRepository::insert(const SysIni& sysini)
{
	dataBase << "insert into sys_ini(sysini_id, config)\
values(:SysIni_sysini_id, :SysIni_config)", use(sysini);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void SysIniRepository::remove(const SysIni& sysini)
{
	dataBase << "DELETE from sys_ini WHERE sysini_id=:SysIni_sysini_id", use(sysini);
}

void SysIniRepository::update(const SysIni& sysini)
{
	dataBase << "update sys_ini set sysini_id=:SysIni_sysini_id, config=:SysIni_config WHERE sysini_id=:SysIni_sysini_id", use(sysini);
}

void SysIniRepository::update(const SysIni& oldObj, const SysIni& newObj)
{
	dataBase << "update sys_ini set sysini_id=:SysIni_sysini_id, config=:SysIni_config WHERE sysini_id='"<<oldObj.getSysiniId()<<"\'", use(newObj);
}

