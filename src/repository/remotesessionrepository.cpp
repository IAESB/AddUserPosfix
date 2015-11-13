#include "remotesessionrepository.h"
#include "util.hpp"
RemoteSessionRepository::RemoteSessionRepository(soci::session& db) : dataBase(db)
{
}

RemoteSessionPtr RemoteSessionRepository::select(const RemoteSession& obj)
{
	soci::row row;
	RemoteSessionPtr remotesession(new RemoteSession);
	dataBase << "SELECT  remote_session.remote_session as RemoteSession_remote_session, remote_session.remote_userid as RemoteSession_remote_userid, remote_session.remote_functions as RemoteSession_remote_functions, remote_session.client_login as RemoteSession_client_login, remote_session.tstamp as RemoteSession_tstamp"
	" FROM remote_session "
	"WHERE remote_session.remote_session = :RemoteSession_remote_session", into(row), use(obj);
	if(!dataBase.got_data())
		remotesession.reset();
	else
		type_conversion<RemoteSession>::from_base(row, i_ok, *remotesession);
	return remotesession;
}
RemoteSessionList RemoteSessionRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  remote_session.remote_session as RemoteSession_remote_session, remote_session.remote_userid as RemoteSession_remote_userid, remote_session.remote_functions as RemoteSession_remote_functions, remote_session.client_login as RemoteSession_client_login, remote_session.tstamp as RemoteSession_tstamp "
	" FROM remote_session" 
	<< (where.size()?" WHERE "+where:"");
	RemoteSessionList remotesessionList;
	for(row& r: rs)
	{
		RemoteSessionPtr remotesession(new RemoteSession);
		type_conversion<RemoteSession>::from_base(r, i_ok, *remotesession);
		remotesessionList.push_back(remotesession);
	}
	return remotesessionList;
}

int RemoteSessionRepository::insert(const RemoteSession& remotesession)
{
	dataBase << "insert into remote_session(remote_session, remote_userid, remote_functions, client_login, tstamp)\
values(:RemoteSession_remote_session, :RemoteSession_remote_userid, :RemoteSession_remote_functions, :RemoteSession_client_login, :RemoteSession_tstamp)", use(remotesession);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void RemoteSessionRepository::remove(const RemoteSession& remotesession)
{
	dataBase << "DELETE from remote_session WHERE remote_session=:RemoteSession_remote_session", use(remotesession);
}

void RemoteSessionRepository::update(const RemoteSession& remotesession)
{
	dataBase << "update remote_session set remote_session=:RemoteSession_remote_session, remote_userid=:RemoteSession_remote_userid, remote_functions=:RemoteSession_remote_functions, client_login=:RemoteSession_client_login, tstamp=:RemoteSession_tstamp WHERE remote_session=:RemoteSession_remote_session", use(remotesession);
}

void RemoteSessionRepository::update(const RemoteSession& oldObj, const RemoteSession& newObj)
{
	dataBase << "update remote_session set remote_session=:RemoteSession_remote_session, remote_userid=:RemoteSession_remote_userid, remote_functions=:RemoteSession_remote_functions, client_login=:RemoteSession_client_login, tstamp=:RemoteSession_tstamp WHERE remote_session='"<<oldObj.getRemoteSession()<<"\'", use(newObj);
}

