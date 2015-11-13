#ifndef SHELLUSERREPOSITORY_H
#define SHELLUSERREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/shelluser.h"
using namespace soci;


class ShellUserRepository
{
	soci::session& dataBase;
public:
	ShellUserRepository(soci::session& dataBase);
	int insert(const ShellUser& shelluser);
	ShellUserPtr select(const ShellUser& shelluser);
	ShellUserList select(const string& where="");
	void update(const ShellUser& shelluser);
	void update(const ShellUser& oldObj, const ShellUser& newObj);
	void remove(const ShellUser& shelluser);
};

namespace soci
{
template<>
struct type_conversion<ShellUser>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, ShellUser & p)
	{
		if (v.get_indicator("ShellUser_shell_user_id") != i_null){
			p.setShellUserId( v.template get<long long>("ShellUser_shell_user_id" ) );
		}
		if (v.get_indicator("ShellUser_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("ShellUser_sys_userid" ) );
		}
		if (v.get_indicator("ShellUser_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("ShellUser_sys_groupid" ) );
		}
		if (v.get_indicator("ShellUser_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("ShellUser_sys_perm_user" ) );
		}
		if (v.get_indicator("ShellUser_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("ShellUser_sys_perm_group" ) );
		}
		if (v.get_indicator("ShellUser_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("ShellUser_sys_perm_other" ) );
		}
		if (v.get_indicator("ShellUser_server_id") != i_null){
			p.setServerId( v.template get<long long>("ShellUser_server_id" ) );
		}
		if (v.get_indicator("ShellUser_parent_domain_id") != i_null){
			p.setParentDomainId( v.template get<long long>("ShellUser_parent_domain_id" ) );
		}
		if (v.get_indicator("ShellUser_username") != i_null){
			p.setUsername( v.template get<std::string>("ShellUser_username" ) );
		}
		if (v.get_indicator("ShellUser_username_prefix") != i_null){
			p.setUsernamePrefix( v.template get<std::string>("ShellUser_username_prefix" ) );
		}
		if (v.get_indicator("ShellUser_password") != i_null){
			p.setPassword( v.template get<std::string>("ShellUser_password" ) );
		}
		if (v.get_indicator("ShellUser_quota_size") != i_null){
			p.setQuotaSize( v.template get<long long>("ShellUser_quota_size" ) );
		}
		if (v.get_indicator("ShellUser_active") != i_null){
			p.setActive( v.template get<std::string>("ShellUser_active" ) );
		}
		if (v.get_indicator("ShellUser_puser") != i_null){
			p.setPuser( v.template get<std::string>("ShellUser_puser" ) );
		}
		if (v.get_indicator("ShellUser_pgroup") != i_null){
			p.setPgroup( v.template get<std::string>("ShellUser_pgroup" ) );
		}
		if (v.get_indicator("ShellUser_shell") != i_null){
			p.setShell( v.template get<std::string>("ShellUser_shell" ) );
		}
		if (v.get_indicator("ShellUser_dir") != i_null){
			p.setDir( v.template get<std::string>("ShellUser_dir" ) );
		}
		if (v.get_indicator("ShellUser_chroot") != i_null){
			p.setChroot( v.template get<std::string>("ShellUser_chroot" ) );
		}
		if (v.get_indicator("ShellUser_ssh_rsa") != i_null){
			p.setSshRsa( v.template get<std::string>("ShellUser_ssh_rsa" ) );
		}
	}
	static void to_base(const ShellUser & p, values & v, indicator & ind)
	{
		v.set( "ShellUser_shell_user_id", p.getShellUserId() );
		v.set( "ShellUser_sys_userid", p.getSysUserid() );
		v.set( "ShellUser_sys_groupid", p.getSysGroupid() );
		v.set( "ShellUser_sys_perm_user", p.getSysPermUser() );
		v.set( "ShellUser_sys_perm_group", p.getSysPermGroup() );
		v.set( "ShellUser_sys_perm_other", p.getSysPermOther() );
		v.set( "ShellUser_server_id", p.getServerId() );
		v.set( "ShellUser_parent_domain_id", p.getParentDomainId() );
		v.set( "ShellUser_username", p.getUsername() );
		v.set( "ShellUser_username_prefix", p.getUsernamePrefix() );
		v.set( "ShellUser_password", p.getPassword() );
		v.set( "ShellUser_quota_size", p.getQuotaSize() );
		v.set( "ShellUser_active", p.getActive() );
		v.set( "ShellUser_puser", p.getPuser() );
		v.set( "ShellUser_pgroup", p.getPgroup() );
		v.set( "ShellUser_shell", p.getShell() );
		v.set( "ShellUser_dir", p.getDir() );
		v.set( "ShellUser_chroot", p.getChroot() );
		v.set( "ShellUser_ssh_rsa", p.getSshRsa() );
		ind = i_ok;
	}
};
}

#endif // SHELLUSERREPOSITORY_H
