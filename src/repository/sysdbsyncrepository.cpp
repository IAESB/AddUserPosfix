#include "sysdbsyncrepository.h"
#include "util.hpp"
SysDbsyncRepository::SysDbsyncRepository(soci::session& db) : dataBase(db)
{
}

SysDbsyncPtr SysDbsyncRepository::select(const SysDbsync& obj)
{
	soci::row row;
	SysDbsyncPtr sysdbsync(new SysDbsync);
	dataBase << "SELECT  sys_dbsync.id as SysDbsync_id, sys_dbsync.jobname as SysDbsync_jobname, sys_dbsync.sync_interval_minutes as SysDbsync_sync_interval_minutes, sys_dbsync.db_type as SysDbsync_db_type, sys_dbsync.db_host as SysDbsync_db_host, sys_dbsync.db_name as SysDbsync_db_name, sys_dbsync.db_username as SysDbsync_db_username, sys_dbsync.db_password as SysDbsync_db_password, sys_dbsync.db_tables as SysDbsync_db_tables, sys_dbsync.empty_datalog as SysDbsync_empty_datalog, sys_dbsync.sync_datalog_external as SysDbsync_sync_datalog_external, sys_dbsync.active as SysDbsync_active, sys_dbsync.last_datalog_id as SysDbsync_last_datalog_id"
	" FROM sys_dbsync "
	"WHERE sys_dbsync.id = :SysDbsync_id AND sys_dbsync.last_datalog_id = :SysDbsync_last_datalog_id", into(row), use(obj);
	if(!dataBase.got_data())
		sysdbsync.reset();
	else
		type_conversion<SysDbsync>::from_base(row, i_ok, *sysdbsync);
	return sysdbsync;
}
SysDbsyncList SysDbsyncRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  sys_dbsync.id as SysDbsync_id, sys_dbsync.jobname as SysDbsync_jobname, sys_dbsync.sync_interval_minutes as SysDbsync_sync_interval_minutes, sys_dbsync.db_type as SysDbsync_db_type, sys_dbsync.db_host as SysDbsync_db_host, sys_dbsync.db_name as SysDbsync_db_name, sys_dbsync.db_username as SysDbsync_db_username, sys_dbsync.db_password as SysDbsync_db_password, sys_dbsync.db_tables as SysDbsync_db_tables, sys_dbsync.empty_datalog as SysDbsync_empty_datalog, sys_dbsync.sync_datalog_external as SysDbsync_sync_datalog_external, sys_dbsync.active as SysDbsync_active, sys_dbsync.last_datalog_id as SysDbsync_last_datalog_id "
	" FROM sys_dbsync" 
	<< (where.size()?" WHERE "+where:"");
	SysDbsyncList sysdbsyncList;
	for(row& r: rs)
	{
		SysDbsyncPtr sysdbsync(new SysDbsync);
		type_conversion<SysDbsync>::from_base(r, i_ok, *sysdbsync);
		sysdbsyncList.push_back(sysdbsync);
	}
	return sysdbsyncList;
}

int SysDbsyncRepository::insert(const SysDbsync& sysdbsync)
{
	dataBase << "insert into sys_dbsync(id, jobname, sync_interval_minutes, db_type, db_host, db_name, db_username, db_password, db_tables, empty_datalog, sync_datalog_external, active, last_datalog_id)\
values(:SysDbsync_jobname, :SysDbsync_sync_interval_minutes, :SysDbsync_db_type, :SysDbsync_db_host, :SysDbsync_db_name, :SysDbsync_db_username, :SysDbsync_db_password, :SysDbsync_db_tables, :SysDbsync_empty_datalog, :SysDbsync_sync_datalog_external, :SysDbsync_active, :SysDbsync_last_datalog_id)", use(sysdbsync);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void SysDbsyncRepository::remove(const SysDbsync& sysdbsync)
{
	dataBase << "DELETE from sys_dbsync WHERE id=:SysDbsync_id AND last_datalog_id=:SysDbsync_last_datalog_id", use(sysdbsync);
}

void SysDbsyncRepository::update(const SysDbsync& sysdbsync)
{
	dataBase << "update sys_dbsync set jobname=:SysDbsync_jobname, sync_interval_minutes=:SysDbsync_sync_interval_minutes, db_type=:SysDbsync_db_type, db_host=:SysDbsync_db_host, db_name=:SysDbsync_db_name, db_username=:SysDbsync_db_username, db_password=:SysDbsync_db_password, db_tables=:SysDbsync_db_tables, empty_datalog=:SysDbsync_empty_datalog, sync_datalog_external=:SysDbsync_sync_datalog_external, active=:SysDbsync_active, last_datalog_id=:SysDbsync_last_datalog_id WHERE id=:SysDbsync_id AND last_datalog_id=:SysDbsync_last_datalog_id", use(sysdbsync);
}

void SysDbsyncRepository::update(const SysDbsync& oldObj, const SysDbsync& newObj)
{
	dataBase << "update sys_dbsync set jobname=:SysDbsync_jobname, sync_interval_minutes=:SysDbsync_sync_interval_minutes, db_type=:SysDbsync_db_type, db_host=:SysDbsync_db_host, db_name=:SysDbsync_db_name, db_username=:SysDbsync_db_username, db_password=:SysDbsync_db_password, db_tables=:SysDbsync_db_tables, empty_datalog=:SysDbsync_empty_datalog, sync_datalog_external=:SysDbsync_sync_datalog_external, active=:SysDbsync_active, last_datalog_id=:SysDbsync_last_datalog_id WHERE id='"<<oldObj.getId()<<"\'' AND last_datalog_id='"<<oldObj.getLastDatalogId()<<"\'", use(newObj);
}

