#include "sysfilesyncrepository.h"
#include "util.hpp"
SysFilesyncRepository::SysFilesyncRepository(soci::session& db) : dataBase(db)
{
}

SysFilesyncPtr SysFilesyncRepository::select(const SysFilesync& obj)
{
	soci::row row;
	SysFilesyncPtr sysfilesync(new SysFilesync);
	dataBase << "SELECT  sys_filesync.id as SysFilesync_id, sys_filesync.jobname as SysFilesync_jobname, sys_filesync.sync_interval_minutes as SysFilesync_sync_interval_minutes, sys_filesync.ftp_host as SysFilesync_ftp_host, sys_filesync.ftp_path as SysFilesync_ftp_path, sys_filesync.ftp_username as SysFilesync_ftp_username, sys_filesync.ftp_password as SysFilesync_ftp_password, sys_filesync.local_path as SysFilesync_local_path, sys_filesync.wput_options as SysFilesync_wput_options, sys_filesync.active as SysFilesync_active"
	" FROM sys_filesync "
	"WHERE sys_filesync.id = :SysFilesync_id", into(row), use(obj);
	if(!dataBase.got_data())
		sysfilesync.reset();
	else
		type_conversion<SysFilesync>::from_base(row, i_ok, *sysfilesync);
	return sysfilesync;
}
SysFilesyncList SysFilesyncRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  sys_filesync.id as SysFilesync_id, sys_filesync.jobname as SysFilesync_jobname, sys_filesync.sync_interval_minutes as SysFilesync_sync_interval_minutes, sys_filesync.ftp_host as SysFilesync_ftp_host, sys_filesync.ftp_path as SysFilesync_ftp_path, sys_filesync.ftp_username as SysFilesync_ftp_username, sys_filesync.ftp_password as SysFilesync_ftp_password, sys_filesync.local_path as SysFilesync_local_path, sys_filesync.wput_options as SysFilesync_wput_options, sys_filesync.active as SysFilesync_active "
	" FROM sys_filesync" 
	<< (where.size()?" WHERE "+where:"");
	SysFilesyncList sysfilesyncList;
	for(row& r: rs)
	{
		SysFilesyncPtr sysfilesync(new SysFilesync);
		type_conversion<SysFilesync>::from_base(r, i_ok, *sysfilesync);
		sysfilesyncList.push_back(sysfilesync);
	}
	return sysfilesyncList;
}

int SysFilesyncRepository::insert(const SysFilesync& sysfilesync)
{
	dataBase << "insert into sys_filesync(id, jobname, sync_interval_minutes, ftp_host, ftp_path, ftp_username, ftp_password, local_path, wput_options, active)\
values(:SysFilesync_jobname, :SysFilesync_sync_interval_minutes, :SysFilesync_ftp_host, :SysFilesync_ftp_path, :SysFilesync_ftp_username, :SysFilesync_ftp_password, :SysFilesync_local_path, :SysFilesync_wput_options, :SysFilesync_active)", use(sysfilesync);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void SysFilesyncRepository::remove(const SysFilesync& sysfilesync)
{
	dataBase << "DELETE from sys_filesync WHERE id=:SysFilesync_id", use(sysfilesync);
}

void SysFilesyncRepository::update(const SysFilesync& sysfilesync)
{
	dataBase << "update sys_filesync set jobname=:SysFilesync_jobname, sync_interval_minutes=:SysFilesync_sync_interval_minutes, ftp_host=:SysFilesync_ftp_host, ftp_path=:SysFilesync_ftp_path, ftp_username=:SysFilesync_ftp_username, ftp_password=:SysFilesync_ftp_password, local_path=:SysFilesync_local_path, wput_options=:SysFilesync_wput_options, active=:SysFilesync_active WHERE id=:SysFilesync_id", use(sysfilesync);
}

void SysFilesyncRepository::update(const SysFilesync& oldObj, const SysFilesync& newObj)
{
	dataBase << "update sys_filesync set jobname=:SysFilesync_jobname, sync_interval_minutes=:SysFilesync_sync_interval_minutes, ftp_host=:SysFilesync_ftp_host, ftp_path=:SysFilesync_ftp_path, ftp_username=:SysFilesync_ftp_username, ftp_password=:SysFilesync_ftp_password, local_path=:SysFilesync_local_path, wput_options=:SysFilesync_wput_options, active=:SysFilesync_active WHERE id='"<<oldObj.getId()<<"\'", use(newObj);
}

