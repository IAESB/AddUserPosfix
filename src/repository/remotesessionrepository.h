#ifndef REMOTESESSIONREPOSITORY_H
#define REMOTESESSIONREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/remotesession.h"
using namespace soci;


class RemoteSessionRepository
{
	soci::session& dataBase;
public:
	RemoteSessionRepository(soci::session& dataBase);
	int insert(const RemoteSession& remotesession);
	RemoteSessionPtr select(const RemoteSession& remotesession);
	RemoteSessionList select(const string& where="");
	void update(const RemoteSession& remotesession);
	void update(const RemoteSession& oldObj, const RemoteSession& newObj);
	void remove(const RemoteSession& remotesession);
};

namespace soci
{
template<>
struct type_conversion<RemoteSession>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, RemoteSession & p)
	{
		if (v.get_indicator("RemoteSession_remote_session") != i_null){
			p.setRemoteSession( v.template get<std::string>("RemoteSession_remote_session" ) );
		}
		if (v.get_indicator("RemoteSession_remote_userid") != i_null){
			p.setRemoteUserid( v.template get<long long>("RemoteSession_remote_userid" ) );
		}
		if (v.get_indicator("RemoteSession_remote_functions") != i_null){
			p.setRemoteFunctions( v.template get<std::string>("RemoteSession_remote_functions" ) );
		}
		if (v.get_indicator("RemoteSession_client_login") != i_null){
			p.setClientLogin( v.template get<int>("RemoteSession_client_login" ) );
		}
		if (v.get_indicator("RemoteSession_tstamp") != i_null){
			p.setTstamp( v.template get<long long>("RemoteSession_tstamp" ) );
		}
	}
	static void to_base(const RemoteSession & p, values & v, indicator & ind)
	{
		v.set( "RemoteSession_remote_session", p.getRemoteSession() );
		v.set( "RemoteSession_remote_userid", p.getRemoteUserid() );
		v.set( "RemoteSession_remote_functions", p.getRemoteFunctions() );
		v.set( "RemoteSession_client_login", p.getClientLogin() );
		v.set( "RemoteSession_tstamp", p.getTstamp() );
		ind = i_ok;
	}
};
}

#endif // REMOTESESSIONREPOSITORY_H
