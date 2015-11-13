#ifndef WEBFOLDERREPOSITORY_H
#define WEBFOLDERREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/webfolder.h"
using namespace soci;


class WebFolderRepository
{
	soci::session& dataBase;
public:
	WebFolderRepository(soci::session& dataBase);
	int insert(const WebFolder& webfolder);
	WebFolderPtr select(const WebFolder& webfolder);
	WebFolderList select(const string& where="");
	void update(const WebFolder& webfolder);
	void update(const WebFolder& oldObj, const WebFolder& newObj);
	void remove(const WebFolder& webfolder);
};

namespace soci
{
template<>
struct type_conversion<WebFolder>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, WebFolder & p)
	{
		if (v.get_indicator("WebFolder_web_folder_id") != i_null){
			p.setWebFolderId( v.template get<long long>("WebFolder_web_folder_id" ) );
		}
		if (v.get_indicator("WebFolder_sys_userid") != i_null){
			p.setSysUserid( v.template get<int>("WebFolder_sys_userid" ) );
		}
		if (v.get_indicator("WebFolder_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<int>("WebFolder_sys_groupid" ) );
		}
		if (v.get_indicator("WebFolder_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("WebFolder_sys_perm_user" ) );
		}
		if (v.get_indicator("WebFolder_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("WebFolder_sys_perm_group" ) );
		}
		if (v.get_indicator("WebFolder_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("WebFolder_sys_perm_other" ) );
		}
		if (v.get_indicator("WebFolder_server_id") != i_null){
			p.setServerId( v.template get<int>("WebFolder_server_id" ) );
		}
		if (v.get_indicator("WebFolder_parent_domain_id") != i_null){
			p.setParentDomainId( v.template get<int>("WebFolder_parent_domain_id" ) );
		}
		if (v.get_indicator("WebFolder_path") != i_null){
			p.setPath( v.template get<std::string>("WebFolder_path" ) );
		}
		if (v.get_indicator("WebFolder_active") != i_null){
			p.setActive( v.template get<std::string>("WebFolder_active" ) );
		}
	}
	static void to_base(const WebFolder & p, values & v, indicator & ind)
	{
		v.set( "WebFolder_web_folder_id", p.getWebFolderId() );
		v.set( "WebFolder_sys_userid", p.getSysUserid() );
		v.set( "WebFolder_sys_groupid", p.getSysGroupid() );
		v.set( "WebFolder_sys_perm_user", p.getSysPermUser() );
		v.set( "WebFolder_sys_perm_group", p.getSysPermGroup() );
		v.set( "WebFolder_sys_perm_other", p.getSysPermOther() );
		v.set( "WebFolder_server_id", p.getServerId() );
		v.set( "WebFolder_parent_domain_id", p.getParentDomainId() );
		v.set( "WebFolder_path", p.getPath() );
		v.set( "WebFolder_active", p.getActive() );
		ind = i_ok;
	}
};
}

#endif // WEBFOLDERREPOSITORY_H
