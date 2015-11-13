#include "syscronrepository.h"
#include "util.hpp"
SysCronRepository::SysCronRepository(soci::session& db) : dataBase(db)
{
}

SysCronPtr SysCronRepository::select(const SysCron& obj)
{
	soci::row row;
	SysCronPtr syscron(new SysCron);
	dataBase << "SELECT  sys_cron.name as SysCron_name, sys_cron.last_run as SysCron_last_run, sys_cron.next_run as SysCron_next_run, sys_cron.running as SysCron_running"
	" FROM sys_cron "
	"WHERE sys_cron.name = :SysCron_name", into(row), use(obj);
	if(!dataBase.got_data())
		syscron.reset();
	else
		type_conversion<SysCron>::from_base(row, i_ok, *syscron);
	return syscron;
}
SysCronList SysCronRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  sys_cron.name as SysCron_name, sys_cron.last_run as SysCron_last_run, sys_cron.next_run as SysCron_next_run, sys_cron.running as SysCron_running "
	" FROM sys_cron" 
	<< (where.size()?" WHERE "+where:"");
	SysCronList syscronList;
	for(row& r: rs)
	{
		SysCronPtr syscron(new SysCron);
		type_conversion<SysCron>::from_base(r, i_ok, *syscron);
		syscronList.push_back(syscron);
	}
	return syscronList;
}

int SysCronRepository::insert(const SysCron& syscron)
{
	dataBase << "insert into sys_cron(name, last_run, next_run, running)\
values(:SysCron_name, :SysCron_last_run, :SysCron_next_run, :SysCron_running)", use(syscron);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void SysCronRepository::remove(const SysCron& syscron)
{
	dataBase << "DELETE from sys_cron WHERE name=:SysCron_name", use(syscron);
}

void SysCronRepository::update(const SysCron& syscron)
{
	dataBase << "update sys_cron set name=:SysCron_name, last_run=:SysCron_last_run, next_run=:SysCron_next_run, running=:SysCron_running WHERE name=:SysCron_name", use(syscron);
}

void SysCronRepository::update(const SysCron& oldObj, const SysCron& newObj)
{
	dataBase << "update sys_cron set name=:SysCron_name, last_run=:SysCron_last_run, next_run=:SysCron_next_run, running=:SysCron_running WHERE name='"<<oldObj.getName()<<"\'", use(newObj);
}

