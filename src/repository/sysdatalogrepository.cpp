#include "sysdatalogrepository.h"
#include "util.hpp"
SysDatalogRepository::SysDatalogRepository(soci::session& db) : dataBase(db)
{
}

SysDatalogPtr SysDatalogRepository::select(const SysDatalog& obj)
{
	soci::row row;
	SysDatalogPtr sysdatalog(new SysDatalog);
	dataBase << "SELECT  sys_datalog.datalog_id as SysDatalog_datalog_id, sys_datalog.server_id as SysDatalog_server_id, sys_datalog.dbtable as SysDatalog_dbtable, sys_datalog.dbidx as SysDatalog_dbidx, sys_datalog.action as SysDatalog_action, sys_datalog.tstamp as SysDatalog_tstamp, sys_datalog.user as SysDatalog_user, sys_datalog.data as SysDatalog_data, sys_datalog.status as SysDatalog_status, sys_datalog.error as SysDatalog_error"
	" FROM sys_datalog "
	"WHERE sys_datalog.datalog_id = :SysDatalog_datalog_id AND sys_datalog.server_id = :SysDatalog_server_id", into(row), use(obj);
	if(!dataBase.got_data())
		sysdatalog.reset();
	else
		type_conversion<SysDatalog>::from_base(row, i_ok, *sysdatalog);
	return sysdatalog;
}
SysDatalogList SysDatalogRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  sys_datalog.datalog_id as SysDatalog_datalog_id, sys_datalog.server_id as SysDatalog_server_id, sys_datalog.dbtable as SysDatalog_dbtable, sys_datalog.dbidx as SysDatalog_dbidx, sys_datalog.action as SysDatalog_action, sys_datalog.tstamp as SysDatalog_tstamp, sys_datalog.user as SysDatalog_user, sys_datalog.data as SysDatalog_data, sys_datalog.status as SysDatalog_status, sys_datalog.error as SysDatalog_error "
	" FROM sys_datalog" 
	<< (where.size()?" WHERE "+where:"");
	SysDatalogList sysdatalogList;
	for(row& r: rs)
	{
		SysDatalogPtr sysdatalog(new SysDatalog);
		type_conversion<SysDatalog>::from_base(r, i_ok, *sysdatalog);
		sysdatalogList.push_back(sysdatalog);
	}
	return sysdatalogList;
}

int SysDatalogRepository::insert(const SysDatalog& sysdatalog)
{
	dataBase << "insert into sys_datalog(datalog_id, server_id, dbtable, dbidx, action, tstamp, user, data, status, error)\
values(:SysDatalog_datalog_id, :SysDatalog_server_id, :SysDatalog_dbtable, :SysDatalog_dbidx, :SysDatalog_action, :SysDatalog_tstamp, :SysDatalog_user, :SysDatalog_data, :SysDatalog_status, :SysDatalog_error)", use(sysdatalog);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void SysDatalogRepository::remove(const SysDatalog& sysdatalog)
{
	dataBase << "DELETE from sys_datalog WHERE datalog_id=:SysDatalog_datalog_id AND server_id=:SysDatalog_server_id", use(sysdatalog);
}

void SysDatalogRepository::update(const SysDatalog& sysdatalog)
{
	dataBase << "update sys_datalog set datalog_id=:SysDatalog_datalog_id, server_id=:SysDatalog_server_id, dbtable=:SysDatalog_dbtable, dbidx=:SysDatalog_dbidx, action=:SysDatalog_action, tstamp=:SysDatalog_tstamp, user=:SysDatalog_user, data=:SysDatalog_data, status=:SysDatalog_status, error=:SysDatalog_error WHERE datalog_id=:SysDatalog_datalog_id AND server_id=:SysDatalog_server_id", use(sysdatalog);
}

void SysDatalogRepository::update(const SysDatalog& oldObj, const SysDatalog& newObj)
{
	dataBase << "update sys_datalog set datalog_id=:SysDatalog_datalog_id, server_id=:SysDatalog_server_id, dbtable=:SysDatalog_dbtable, dbidx=:SysDatalog_dbidx, action=:SysDatalog_action, tstamp=:SysDatalog_tstamp, user=:SysDatalog_user, data=:SysDatalog_data, status=:SysDatalog_status, error=:SysDatalog_error WHERE datalog_id='"<<oldObj.getDatalogId()<<"\'' AND server_id='"<<oldObj.getServerId()<<"\'", use(newObj);
}

