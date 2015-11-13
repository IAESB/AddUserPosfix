#ifndef WEBFOLDERUSERREPOSITORY_H
#define WEBFOLDERUSERREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/webfolderuser.h"
using namespace soci;


class WebFolderUserRepository
{
	soci::session& dataBase;
public:
	WebFolderUserRepository(soci::session& dataBase);
	int insert(const WebFolderUser& webfolderuser);
	WebFolderUserPtr select(const WebFolderUser& webfolderuser);
	WebFolderUserList select(const string& where="");
	void update(const WebFolderUser& webfolderuser);
	void update(const WebFolderUser& oldObj, const WebFolderUser& newObj);
	void remove(const WebFolderUser& webfolderuser);
};

namespace soci
{
template<>
struct type_conversion<WebFolderUser>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, WebFolderUser & p)
	{
		if (v.get_indicator("WebFolderUser_web_folder_user_id") != i_null){
			p.setWebFolderUserId( v.template get<long long>("WebFolderUser_web_folder_user_id" ) );
		}
		if (v.get_indicator("WebFolderUser_sys_userid") != i_null){
			p.setSysUserid( v.template get<int>("WebFolderUser_sys_userid" ) );
		}
		if (v.get_indicator("WebFolderUser_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<int>("WebFolderUser_sys_groupid" ) );
		}
		if (v.get_indicator("WebFolderUser_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("WebFolderUser_sys_perm_user" ) );
		}
		if (v.get_indicator("WebFolderUser_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("WebFolderUser_sys_perm_group" ) );
		}
		if (v.get_indicator("WebFolderUser_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("WebFolderUser_sys_perm_other" ) );
		}
		if (v.get_indicator("WebFolderUser_server_id") != i_null){
			p.setServerId( v.template get<int>("WebFolderUser_server_id" ) );
		}
		if (v.get_indicator("WebFolderUser_web_folder_id") != i_null){
			p.setWebFolderId( v.template get<int>("WebFolderUser_web_folder_id" ) );
		}
		if (v.get_indicator("WebFolderUser_username") != i_null){
			p.setUsername( v.template get<std::string>("WebFolderUser_username" ) );
		}
		if (v.get_indicator("WebFolderUser_password") != i_null){
			p.setPassword( v.template get<std::string>("WebFolderUser_password" ) );
		}
		if (v.get_indicator("WebFolderUser_active") != i_null){
			p.setActive( v.template get<std::string>("WebFolderUser_active" ) );
		}
	}
	static void to_base(const WebFolderUser & p, values & v, indicator & ind)
	{
		v.set( "WebFolderUser_web_folder_user_id", p.getWebFolderUserId() );
		v.set( "WebFolderUser_sys_userid", p.getSysUserid() );
		v.set( "WebFolderUser_sys_groupid", p.getSysGroupid() );
		v.set( "WebFolderUser_sys_perm_user", p.getSysPermUser() );
		v.set( "WebFolderUser_sys_perm_group", p.getSysPermGroup() );
		v.set( "WebFolderUser_sys_perm_other", p.getSysPermOther() );
		v.set( "WebFolderUser_server_id", p.getServerId() );
		v.set( "WebFolderUser_web_folder_id", p.getWebFolderId() );
		v.set( "WebFolderUser_username", p.getUsername() );
		v.set( "WebFolderUser_password", p.getPassword() );
		v.set( "WebFolderUser_active", p.getActive() );
		ind = i_ok;
	}
};
}

#endif // WEBFOLDERUSERREPOSITORY_H
