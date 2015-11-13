#ifndef REMOTEUSERREPOSITORY_H
#define REMOTEUSERREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/remoteuser.h"
using namespace soci;


class RemoteUserRepository
{
	soci::session& dataBase;
public:
	RemoteUserRepository(soci::session& dataBase);
	int insert(const RemoteUser& remoteuser);
	RemoteUserPtr select(const RemoteUser& remoteuser);
	RemoteUserList select(const string& where="");
	void update(const RemoteUser& remoteuser);
	void update(const RemoteUser& oldObj, const RemoteUser& newObj);
	void remove(const RemoteUser& remoteuser);
};

namespace soci
{
template<>
struct type_conversion<RemoteUser>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, RemoteUser & p)
	{
		if (v.get_indicator("RemoteUser_remote_userid") != i_null){
			p.setRemoteUserid( v.template get<long long>("RemoteUser_remote_userid" ) );
		}
		if (v.get_indicator("RemoteUser_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("RemoteUser_sys_userid" ) );
		}
		if (v.get_indicator("RemoteUser_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("RemoteUser_sys_groupid" ) );
		}
		if (v.get_indicator("RemoteUser_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("RemoteUser_sys_perm_user" ) );
		}
		if (v.get_indicator("RemoteUser_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("RemoteUser_sys_perm_group" ) );
		}
		if (v.get_indicator("RemoteUser_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("RemoteUser_sys_perm_other" ) );
		}
		if (v.get_indicator("RemoteUser_remote_username") != i_null){
			p.setRemoteUsername( v.template get<std::string>("RemoteUser_remote_username" ) );
		}
		if (v.get_indicator("RemoteUser_remote_password") != i_null){
			p.setRemotePassword( v.template get<std::string>("RemoteUser_remote_password" ) );
		}
		if (v.get_indicator("RemoteUser_remote_functions") != i_null){
			p.setRemoteFunctions( v.template get<std::string>("RemoteUser_remote_functions" ) );
		}
	}
	static void to_base(const RemoteUser & p, values & v, indicator & ind)
	{
		v.set( "RemoteUser_remote_userid", p.getRemoteUserid() );
		v.set( "RemoteUser_sys_userid", p.getSysUserid() );
		v.set( "RemoteUser_sys_groupid", p.getSysGroupid() );
		v.set( "RemoteUser_sys_perm_user", p.getSysPermUser() );
		v.set( "RemoteUser_sys_perm_group", p.getSysPermGroup() );
		v.set( "RemoteUser_sys_perm_other", p.getSysPermOther() );
		v.set( "RemoteUser_remote_username", p.getRemoteUsername() );
		v.set( "RemoteUser_remote_password", p.getRemotePassword() );
		v.set( "RemoteUser_remote_functions", p.getRemoteFunctions() );
		ind = i_ok;
	}
};
}

#endif // REMOTEUSERREPOSITORY_H
