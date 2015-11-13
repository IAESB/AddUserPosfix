#ifndef SYSREMOTEACTIONREPOSITORY_H
#define SYSREMOTEACTIONREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/sysremoteaction.h"
using namespace soci;


class SysRemoteactionRepository
{
	soci::session& dataBase;
public:
	SysRemoteactionRepository(soci::session& dataBase);
	int insert(const SysRemoteaction& sysremoteaction);
	SysRemoteactionPtr select(const SysRemoteaction& sysremoteaction);
	SysRemoteactionList select(const string& where="");
	void update(const SysRemoteaction& sysremoteaction);
	void update(const SysRemoteaction& oldObj, const SysRemoteaction& newObj);
	void remove(const SysRemoteaction& sysremoteaction);
};

namespace soci
{
template<>
struct type_conversion<SysRemoteaction>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, SysRemoteaction & p)
	{
		if (v.get_indicator("SysRemoteaction_action_id") != i_null){
			p.setActionId( v.template get<long long>("SysRemoteaction_action_id" ) );
		}
		if (v.get_indicator("SysRemoteaction_server_id") != i_null){
			p.setServerId( v.template get<long long>("SysRemoteaction_server_id" ) );
		}
		if (v.get_indicator("SysRemoteaction_tstamp") != i_null){
			p.setTstamp( v.template get<int>("SysRemoteaction_tstamp" ) );
		}
		if (v.get_indicator("SysRemoteaction_action_type") != i_null){
			p.setActionType( v.template get<std::string>("SysRemoteaction_action_type" ) );
		}
		if (v.get_indicator("SysRemoteaction_action_param") != i_null){
			p.setActionParam( v.template get<std::string>("SysRemoteaction_action_param" ) );
		}
		if (v.get_indicator("SysRemoteaction_action_state") != i_null){
			p.setActionState( v.template get<std::string>("SysRemoteaction_action_state" ) );
		}
		if (v.get_indicator("SysRemoteaction_response") != i_null){
			p.setResponse( v.template get<std::string>("SysRemoteaction_response" ) );
		}
	}
	static void to_base(const SysRemoteaction & p, values & v, indicator & ind)
	{
		v.set( "SysRemoteaction_action_id", p.getActionId() );
		v.set( "SysRemoteaction_server_id", p.getServerId() );
		v.set( "SysRemoteaction_tstamp", p.getTstamp() );
		v.set( "SysRemoteaction_action_type", p.getActionType() );
		v.set( "SysRemoteaction_action_param", p.getActionParam() );
		v.set( "SysRemoteaction_action_state", p.getActionState() );
		v.set( "SysRemoteaction_response", p.getResponse() );
		ind = i_ok;
	}
};
}

#endif // SYSREMOTEACTIONREPOSITORY_H
