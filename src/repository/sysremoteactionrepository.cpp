#include "sysremoteactionrepository.h"
#include "util.hpp"
SysRemoteactionRepository::SysRemoteactionRepository(soci::session& db) : dataBase(db)
{
}

SysRemoteactionPtr SysRemoteactionRepository::select(const SysRemoteaction& obj)
{
	soci::row row;
	SysRemoteactionPtr sysremoteaction(new SysRemoteaction);
	dataBase << "SELECT  sys_remoteaction.action_id as SysRemoteaction_action_id, sys_remoteaction.server_id as SysRemoteaction_server_id, sys_remoteaction.tstamp as SysRemoteaction_tstamp, sys_remoteaction.action_type as SysRemoteaction_action_type, sys_remoteaction.action_param as SysRemoteaction_action_param, sys_remoteaction.action_state as SysRemoteaction_action_state, sys_remoteaction.response as SysRemoteaction_response"
	" FROM sys_remoteaction "
	"WHERE sys_remoteaction.action_id = :SysRemoteaction_action_id AND sys_remoteaction.server_id = :SysRemoteaction_server_id", into(row), use(obj);
	if(!dataBase.got_data())
		sysremoteaction.reset();
	else
		type_conversion<SysRemoteaction>::from_base(row, i_ok, *sysremoteaction);
	return sysremoteaction;
}
SysRemoteactionList SysRemoteactionRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  sys_remoteaction.action_id as SysRemoteaction_action_id, sys_remoteaction.server_id as SysRemoteaction_server_id, sys_remoteaction.tstamp as SysRemoteaction_tstamp, sys_remoteaction.action_type as SysRemoteaction_action_type, sys_remoteaction.action_param as SysRemoteaction_action_param, sys_remoteaction.action_state as SysRemoteaction_action_state, sys_remoteaction.response as SysRemoteaction_response "
	" FROM sys_remoteaction" 
	<< (where.size()?" WHERE "+where:"");
	SysRemoteactionList sysremoteactionList;
	for(row& r: rs)
	{
		SysRemoteactionPtr sysremoteaction(new SysRemoteaction);
		type_conversion<SysRemoteaction>::from_base(r, i_ok, *sysremoteaction);
		sysremoteactionList.push_back(sysremoteaction);
	}
	return sysremoteactionList;
}

int SysRemoteactionRepository::insert(const SysRemoteaction& sysremoteaction)
{
	dataBase << "insert into sys_remoteaction(action_id, server_id, tstamp, action_type, action_param, action_state, response)\
values(:SysRemoteaction_action_id, :SysRemoteaction_server_id, :SysRemoteaction_tstamp, :SysRemoteaction_action_type, :SysRemoteaction_action_param, :SysRemoteaction_action_state, :SysRemoteaction_response)", use(sysremoteaction);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void SysRemoteactionRepository::remove(const SysRemoteaction& sysremoteaction)
{
	dataBase << "DELETE from sys_remoteaction WHERE action_id=:SysRemoteaction_action_id AND server_id=:SysRemoteaction_server_id", use(sysremoteaction);
}

void SysRemoteactionRepository::update(const SysRemoteaction& sysremoteaction)
{
	dataBase << "update sys_remoteaction set action_id=:SysRemoteaction_action_id, server_id=:SysRemoteaction_server_id, tstamp=:SysRemoteaction_tstamp, action_type=:SysRemoteaction_action_type, action_param=:SysRemoteaction_action_param, action_state=:SysRemoteaction_action_state, response=:SysRemoteaction_response WHERE action_id=:SysRemoteaction_action_id AND server_id=:SysRemoteaction_server_id", use(sysremoteaction);
}

void SysRemoteactionRepository::update(const SysRemoteaction& oldObj, const SysRemoteaction& newObj)
{
	dataBase << "update sys_remoteaction set action_id=:SysRemoteaction_action_id, server_id=:SysRemoteaction_server_id, tstamp=:SysRemoteaction_tstamp, action_type=:SysRemoteaction_action_type, action_param=:SysRemoteaction_action_param, action_state=:SysRemoteaction_action_state, response=:SysRemoteaction_response WHERE action_id='"<<oldObj.getActionId()<<"\'' AND server_id='"<<oldObj.getServerId()<<"\'", use(newObj);
}

