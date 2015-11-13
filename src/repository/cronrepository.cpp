#include "cronrepository.h"
#include "util.hpp"
CronRepository::CronRepository(soci::session& db) : dataBase(db)
{
}

CronPtr CronRepository::select(const Cron& obj)
{
	soci::row row;
	CronPtr cron(new Cron);
	dataBase << "SELECT  cron.id as Cron_id, cron.sys_userid as Cron_sys_userid, cron.sys_groupid as Cron_sys_groupid, cron.sys_perm_user as Cron_sys_perm_user, cron.sys_perm_group as Cron_sys_perm_group, cron.sys_perm_other as Cron_sys_perm_other, cron.server_id as Cron_server_id, cron.parent_domain_id as Cron_parent_domain_id, cron.type as Cron_type, cron.command as Cron_command, cron.run_min as Cron_run_min, cron.run_hour as Cron_run_hour, cron.run_mday as Cron_run_mday, cron.run_month as Cron_run_month, cron.run_wday as Cron_run_wday, cron.log as Cron_log, cron.active as Cron_active"
	" FROM cron "
	"WHERE cron.id = :Cron_id", into(row), use(obj);
	if(!dataBase.got_data())
		cron.reset();
	else
		type_conversion<Cron>::from_base(row, i_ok, *cron);
	return cron;
}
CronList CronRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  cron.id as Cron_id, cron.sys_userid as Cron_sys_userid, cron.sys_groupid as Cron_sys_groupid, cron.sys_perm_user as Cron_sys_perm_user, cron.sys_perm_group as Cron_sys_perm_group, cron.sys_perm_other as Cron_sys_perm_other, cron.server_id as Cron_server_id, cron.parent_domain_id as Cron_parent_domain_id, cron.type as Cron_type, cron.command as Cron_command, cron.run_min as Cron_run_min, cron.run_hour as Cron_run_hour, cron.run_mday as Cron_run_mday, cron.run_month as Cron_run_month, cron.run_wday as Cron_run_wday, cron.log as Cron_log, cron.active as Cron_active "
	" FROM cron" 
	<< (where.size()?" WHERE "+where:"");
	CronList cronList;
	for(row& r: rs)
	{
		CronPtr cron(new Cron);
		type_conversion<Cron>::from_base(r, i_ok, *cron);
		cronList.push_back(cron);
	}
	return cronList;
}

int CronRepository::insert(const Cron& cron)
{
	dataBase << "insert into cron(id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, parent_domain_id, type, command, run_min, run_hour, run_mday, run_month, run_wday, log, active)\
values(:Cron_sys_userid, :Cron_sys_groupid, :Cron_sys_perm_user, :Cron_sys_perm_group, :Cron_sys_perm_other, :Cron_server_id, :Cron_parent_domain_id, :Cron_type, :Cron_command, :Cron_run_min, :Cron_run_hour, :Cron_run_mday, :Cron_run_month, :Cron_run_wday, :Cron_log, :Cron_active)", use(cron);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void CronRepository::remove(const Cron& cron)
{
	dataBase << "DELETE from cron WHERE id=:Cron_id", use(cron);
}

void CronRepository::update(const Cron& cron)
{
	dataBase << "update cron set sys_userid=:Cron_sys_userid, sys_groupid=:Cron_sys_groupid, sys_perm_user=:Cron_sys_perm_user, sys_perm_group=:Cron_sys_perm_group, sys_perm_other=:Cron_sys_perm_other, server_id=:Cron_server_id, parent_domain_id=:Cron_parent_domain_id, type=:Cron_type, command=:Cron_command, run_min=:Cron_run_min, run_hour=:Cron_run_hour, run_mday=:Cron_run_mday, run_month=:Cron_run_month, run_wday=:Cron_run_wday, log=:Cron_log, active=:Cron_active WHERE id=:Cron_id", use(cron);
}

void CronRepository::update(const Cron& oldObj, const Cron& newObj)
{
	dataBase << "update cron set sys_userid=:Cron_sys_userid, sys_groupid=:Cron_sys_groupid, sys_perm_user=:Cron_sys_perm_user, sys_perm_group=:Cron_sys_perm_group, sys_perm_other=:Cron_sys_perm_other, server_id=:Cron_server_id, parent_domain_id=:Cron_parent_domain_id, type=:Cron_type, command=:Cron_command, run_min=:Cron_run_min, run_hour=:Cron_run_hour, run_mday=:Cron_run_mday, run_month=:Cron_run_month, run_wday=:Cron_run_wday, log=:Cron_log, active=:Cron_active WHERE id='"<<oldObj.getId()<<"\'", use(newObj);
}

