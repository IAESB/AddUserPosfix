#ifndef CLIENTCIRCLEREPOSITORY_H
#define CLIENTCIRCLEREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/clientcircle.h"
using namespace soci;


class ClientCircleRepository
{
	soci::session& dataBase;
public:
	ClientCircleRepository(soci::session& dataBase);
	int insert(const ClientCircle& clientcircle);
	ClientCirclePtr select(const ClientCircle& clientcircle);
	ClientCircleList select(const string& where="");
	void update(const ClientCircle& clientcircle);
	void update(const ClientCircle& oldObj, const ClientCircle& newObj);
	void remove(const ClientCircle& clientcircle);
};

namespace soci
{
template<>
struct type_conversion<ClientCircle>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, ClientCircle & p)
	{
		if (v.get_indicator("ClientCircle_circle_id") != i_null){
			p.setCircleId( v.template get<int>("ClientCircle_circle_id" ) );
		}
		if (v.get_indicator("ClientCircle_sys_userid") != i_null){
			p.setSysUserid( v.template get<int>("ClientCircle_sys_userid" ) );
		}
		if (v.get_indicator("ClientCircle_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<int>("ClientCircle_sys_groupid" ) );
		}
		if (v.get_indicator("ClientCircle_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("ClientCircle_sys_perm_user" ) );
		}
		if (v.get_indicator("ClientCircle_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("ClientCircle_sys_perm_group" ) );
		}
		if (v.get_indicator("ClientCircle_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("ClientCircle_sys_perm_other" ) );
		}
		if (v.get_indicator("ClientCircle_circle_name") != i_null){
			p.setCircleName( v.template get<std::string>("ClientCircle_circle_name" ) );
		}
		if (v.get_indicator("ClientCircle_client_ids") != i_null){
			p.setClientIds( v.template get<std::string>("ClientCircle_client_ids" ) );
		}
		if (v.get_indicator("ClientCircle_description") != i_null){
			p.setDescription( v.template get<std::string>("ClientCircle_description" ) );
		}
		if (v.get_indicator("ClientCircle_active") != i_null){
			p.setActive( v.template get<std::string>("ClientCircle_active" ) );
		}
	}
	static void to_base(const ClientCircle & p, values & v, indicator & ind)
	{
		v.set( "ClientCircle_circle_id", p.getCircleId() );
		v.set( "ClientCircle_sys_userid", p.getSysUserid() );
		v.set( "ClientCircle_sys_groupid", p.getSysGroupid() );
		v.set( "ClientCircle_sys_perm_user", p.getSysPermUser() );
		v.set( "ClientCircle_sys_perm_group", p.getSysPermGroup() );
		v.set( "ClientCircle_sys_perm_other", p.getSysPermOther() );
		v.set( "ClientCircle_circle_name", p.getCircleName() );
		v.set( "ClientCircle_client_ids", p.getClientIds() );
		v.set( "ClientCircle_description", p.getDescription() );
		v.set( "ClientCircle_active", p.getActive() );
		ind = i_ok;
	}
};
}

#endif // CLIENTCIRCLEREPOSITORY_H
