#ifndef SYSSESSIONREPOSITORY_H
#define SYSSESSIONREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/syssession.h"
using namespace soci;


class SysSessionRepository
{
	soci::session& dataBase;
public:
	SysSessionRepository(soci::session& dataBase);
	int insert(const SysSession& syssession);
	SysSessionPtr select(const SysSession& syssession);
	SysSessionList select(const string& where="");
	void update(const SysSession& syssession);
	void update(const SysSession& oldObj, const SysSession& newObj);
	void remove(const SysSession& syssession);
};

namespace soci
{
template<>
struct type_conversion<SysSession>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, SysSession & p)
	{
		if (v.get_indicator("SysSession_session_id") != i_null){
			p.setSessionId( v.template get<std::string>("SysSession_session_id" ) );
		}
		if (v.get_indicator("SysSession_date_created") != i_null){
			p.setDateCreated( v.template get<tm>("SysSession_date_created" ) );
		}
		if (v.get_indicator("SysSession_last_updated") != i_null){
			p.setLastUpdated( v.template get<tm>("SysSession_last_updated" ) );
		}
		if (v.get_indicator("SysSession_permanent") != i_null){
			p.setPermanent( v.template get<std::string>("SysSession_permanent" ) );
		}
		if (v.get_indicator("SysSession_session_data") != i_null){
			p.setSessionData( v.template get<std::string>("SysSession_session_data" ) );
		}
	}
	static void to_base(const SysSession & p, values & v, indicator & ind)
	{
		v.set( "SysSession_session_id", p.getSessionId() );
		v.set( "SysSession_date_created", p.getDateCreated() );
		v.set( "SysSession_last_updated", p.getLastUpdated() );
		v.set( "SysSession_permanent", p.getPermanent() );
		v.set( "SysSession_session_data", p.getSessionData() );
		ind = i_ok;
	}
};
}

#endif // SYSSESSIONREPOSITORY_H
