#include "syssessionrepository.h"
#include "util.hpp"
SysSessionRepository::SysSessionRepository(soci::session& db) : dataBase(db)
{
}

SysSessionPtr SysSessionRepository::select(const SysSession& obj)
{
	soci::row row;
	SysSessionPtr syssession(new SysSession);
	dataBase << "SELECT  sys_session.session_id as SysSession_session_id, sys_session.date_created as SysSession_date_created, sys_session.last_updated as SysSession_last_updated, sys_session.permanent as SysSession_permanent, sys_session.session_data as SysSession_session_data"
	" FROM sys_session "
	"WHERE sys_session.session_id = :SysSession_session_id AND sys_session.last_updated = :SysSession_last_updated", into(row), use(obj);
	if(!dataBase.got_data())
		syssession.reset();
	else
		type_conversion<SysSession>::from_base(row, i_ok, *syssession);
	return syssession;
}
SysSessionList SysSessionRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  sys_session.session_id as SysSession_session_id, sys_session.date_created as SysSession_date_created, sys_session.last_updated as SysSession_last_updated, sys_session.permanent as SysSession_permanent, sys_session.session_data as SysSession_session_data "
	" FROM sys_session" 
	<< (where.size()?" WHERE "+where:"");
	SysSessionList syssessionList;
	for(row& r: rs)
	{
		SysSessionPtr syssession(new SysSession);
		type_conversion<SysSession>::from_base(r, i_ok, *syssession);
		syssessionList.push_back(syssession);
	}
	return syssessionList;
}

int SysSessionRepository::insert(const SysSession& syssession)
{
	dataBase << "insert into sys_session(session_id, date_created, last_updated, permanent, session_data)\
values(:SysSession_session_id, :SysSession_date_created, :SysSession_last_updated, :SysSession_permanent, :SysSession_session_data)", use(syssession);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void SysSessionRepository::remove(const SysSession& syssession)
{
	dataBase << "DELETE from sys_session WHERE session_id=:SysSession_session_id AND last_updated=:SysSession_last_updated", use(syssession);
}

void SysSessionRepository::update(const SysSession& syssession)
{
	dataBase << "update sys_session set session_id=:SysSession_session_id, date_created=:SysSession_date_created, last_updated=:SysSession_last_updated, permanent=:SysSession_permanent, session_data=:SysSession_session_data WHERE session_id=:SysSession_session_id AND last_updated=:SysSession_last_updated", use(syssession);
}

void SysSessionRepository::update(const SysSession& oldObj, const SysSession& newObj)
{
	dataBase << "update sys_session set session_id=:SysSession_session_id, date_created=:SysSession_date_created, last_updated=:SysSession_last_updated, permanent=:SysSession_permanent, session_data=:SysSession_session_data WHERE session_id='"<<oldObj.getSessionId()<<"\'' AND last_updated='"<<to_string(oldObj.getLastUpdated())<<"\'", use(newObj);
}

