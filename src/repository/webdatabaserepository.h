#ifndef WEBDATABASEREPOSITORY_H
#define WEBDATABASEREPOSITORY_H

#include <iostream>
#include <memory>
#include <vector>
#include <soci/soci.h>
#include "entity/webdatabase.h"
using namespace soci;


class WebDatabaseRepository
{
	soci::session& dataBase;
public:
	WebDatabaseRepository(soci::session& dataBase);
	int insert(const WebDatabase& webdatabase);
	WebDatabasePtr select(const WebDatabase& webdatabase);
	WebDatabaseList select(const string& where="");
	void update(const WebDatabase& webdatabase);
	void update(const WebDatabase& oldObj, const WebDatabase& newObj);
	void remove(const WebDatabase& webdatabase);
};

namespace soci
{
template<>
struct type_conversion<WebDatabase>
{
typedef values base_type;
	template<class T>	static void from_base(const T& v, const indicator& ind, WebDatabase & p)
	{
		if (v.get_indicator("WebDatabase_database_id") != i_null){
			p.setDatabaseId( v.template get<long long>("WebDatabase_database_id" ) );
		}
		if (v.get_indicator("WebDatabase_sys_userid") != i_null){
			p.setSysUserid( v.template get<long long>("WebDatabase_sys_userid" ) );
		}
		if (v.get_indicator("WebDatabase_sys_groupid") != i_null){
			p.setSysGroupid( v.template get<long long>("WebDatabase_sys_groupid" ) );
		}
		if (v.get_indicator("WebDatabase_sys_perm_user") != i_null){
			p.setSysPermUser( v.template get<std::string>("WebDatabase_sys_perm_user" ) );
		}
		if (v.get_indicator("WebDatabase_sys_perm_group") != i_null){
			p.setSysPermGroup( v.template get<std::string>("WebDatabase_sys_perm_group" ) );
		}
		if (v.get_indicator("WebDatabase_sys_perm_other") != i_null){
			p.setSysPermOther( v.template get<std::string>("WebDatabase_sys_perm_other" ) );
		}
		if (v.get_indicator("WebDatabase_server_id") != i_null){
			p.setServerId( v.template get<long long>("WebDatabase_server_id" ) );
		}
		if (v.get_indicator("WebDatabase_parent_domain_id") != i_null){
			p.setParentDomainId( v.template get<long long>("WebDatabase_parent_domain_id" ) );
		}
		if (v.get_indicator("WebDatabase_type") != i_null){
			p.setType( v.template get<std::string>("WebDatabase_type" ) );
		}
		if (v.get_indicator("WebDatabase_database_name") != i_null){
			p.setDatabaseName( v.template get<std::string>("WebDatabase_database_name" ) );
		}
		if (v.get_indicator("WebDatabase_database_name_prefix") != i_null){
			p.setDatabaseNamePrefix( v.template get<std::string>("WebDatabase_database_name_prefix" ) );
		}
		if (v.get_indicator("WebDatabase_database_quota") != i_null){
			p.setDatabaseQuota( v.template get<long long>("WebDatabase_database_quota" ) );
		}
		if (v.get_indicator("WebDatabase_last_quota_notification") != i_null){
			p.setLastQuotaNotification( v.template get<tm>("WebDatabase_last_quota_notification" ) );
		}
		if (v.get_indicator("WebDatabase_database_user_id") != i_null){
			p.setDatabaseUserId( v.template get<long long>("WebDatabase_database_user_id" ) );
		}
		if (v.get_indicator("WebDatabase_database_ro_user_id") != i_null){
			p.setDatabaseRoUserId( v.template get<long long>("WebDatabase_database_ro_user_id" ) );
		}
		if (v.get_indicator("WebDatabase_database_charset") != i_null){
			p.setDatabaseCharset( v.template get<std::string>("WebDatabase_database_charset" ) );
		}
		if (v.get_indicator("WebDatabase_remote_access") != i_null){
			p.setRemoteAccess( v.template get<std::string>("WebDatabase_remote_access" ) );
		}
		if (v.get_indicator("WebDatabase_remote_ips") != i_null){
			p.setRemoteIps( v.template get<std::string>("WebDatabase_remote_ips" ) );
		}
		if (v.get_indicator("WebDatabase_backup_interval") != i_null){
			p.setBackupInterval( v.template get<std::string>("WebDatabase_backup_interval" ) );
		}
		if (v.get_indicator("WebDatabase_backup_copies") != i_null){
			p.setBackupCopies( v.template get<int>("WebDatabase_backup_copies" ) );
		}
		if (v.get_indicator("WebDatabase_active") != i_null){
			p.setActive( v.template get<std::string>("WebDatabase_active" ) );
		}
	}
	static void to_base(const WebDatabase & p, values & v, indicator & ind)
	{
		v.set( "WebDatabase_database_id", p.getDatabaseId() );
		v.set( "WebDatabase_sys_userid", p.getSysUserid() );
		v.set( "WebDatabase_sys_groupid", p.getSysGroupid() );
		v.set( "WebDatabase_sys_perm_user", p.getSysPermUser() );
		v.set( "WebDatabase_sys_perm_group", p.getSysPermGroup() );
		v.set( "WebDatabase_sys_perm_other", p.getSysPermOther() );
		v.set( "WebDatabase_server_id", p.getServerId() );
		v.set( "WebDatabase_parent_domain_id", p.getParentDomainId() );
		v.set( "WebDatabase_type", p.getType() );
		v.set( "WebDatabase_database_name", p.getDatabaseName() );
		v.set( "WebDatabase_database_name_prefix", p.getDatabaseNamePrefix() );
		v.set( "WebDatabase_database_quota", p.getDatabaseQuota() );
		v.set( "WebDatabase_last_quota_notification", p.getLastQuotaNotification() );
		v.set( "WebDatabase_database_user_id", p.getDatabaseUserId() );
		v.set( "WebDatabase_database_ro_user_id", p.getDatabaseRoUserId() );
		v.set( "WebDatabase_database_charset", p.getDatabaseCharset() );
		v.set( "WebDatabase_remote_access", p.getRemoteAccess() );
		v.set( "WebDatabase_remote_ips", p.getRemoteIps() );
		v.set( "WebDatabase_backup_interval", p.getBackupInterval() );
		v.set( "WebDatabase_backup_copies", p.getBackupCopies() );
		v.set( "WebDatabase_active", p.getActive() );
		ind = i_ok;
	}
};
}

#endif // WEBDATABASEREPOSITORY_H
