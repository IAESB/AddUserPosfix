#include "webdatabaserepository.h"
#include "util.hpp"
WebDatabaseRepository::WebDatabaseRepository(soci::session& db) : dataBase(db)
{
}

WebDatabasePtr WebDatabaseRepository::select(const WebDatabase& obj)
{
	soci::row row;
	WebDatabasePtr webdatabase(new WebDatabase);
	dataBase << "SELECT  web_database.database_id as WebDatabase_database_id, web_database.sys_userid as WebDatabase_sys_userid, web_database.sys_groupid as WebDatabase_sys_groupid, web_database.sys_perm_user as WebDatabase_sys_perm_user, web_database.sys_perm_group as WebDatabase_sys_perm_group, web_database.sys_perm_other as WebDatabase_sys_perm_other, web_database.server_id as WebDatabase_server_id, web_database.parent_domain_id as WebDatabase_parent_domain_id, web_database.type as WebDatabase_type, web_database.database_name as WebDatabase_database_name, web_database.database_name_prefix as WebDatabase_database_name_prefix, web_database.database_quota as WebDatabase_database_quota, web_database.last_quota_notification as WebDatabase_last_quota_notification, web_database.database_user_id as WebDatabase_database_user_id, web_database.database_ro_user_id as WebDatabase_database_ro_user_id, web_database.database_charset as WebDatabase_database_charset, web_database.remote_access as WebDatabase_remote_access, web_database.remote_ips as WebDatabase_remote_ips, web_database.backup_interval as WebDatabase_backup_interval, web_database.backup_copies as WebDatabase_backup_copies, web_database.active as WebDatabase_active"
	" FROM web_database "
	"WHERE web_database.database_id = :WebDatabase_database_id AND web_database.database_user_id = :WebDatabase_database_user_id AND web_database.database_ro_user_id = :WebDatabase_database_ro_user_id", into(row), use(obj);
	if(!dataBase.got_data())
		webdatabase.reset();
	else
		type_conversion<WebDatabase>::from_base(row, i_ok, *webdatabase);
	return webdatabase;
}
WebDatabaseList WebDatabaseRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  web_database.database_id as WebDatabase_database_id, web_database.sys_userid as WebDatabase_sys_userid, web_database.sys_groupid as WebDatabase_sys_groupid, web_database.sys_perm_user as WebDatabase_sys_perm_user, web_database.sys_perm_group as WebDatabase_sys_perm_group, web_database.sys_perm_other as WebDatabase_sys_perm_other, web_database.server_id as WebDatabase_server_id, web_database.parent_domain_id as WebDatabase_parent_domain_id, web_database.type as WebDatabase_type, web_database.database_name as WebDatabase_database_name, web_database.database_name_prefix as WebDatabase_database_name_prefix, web_database.database_quota as WebDatabase_database_quota, web_database.last_quota_notification as WebDatabase_last_quota_notification, web_database.database_user_id as WebDatabase_database_user_id, web_database.database_ro_user_id as WebDatabase_database_ro_user_id, web_database.database_charset as WebDatabase_database_charset, web_database.remote_access as WebDatabase_remote_access, web_database.remote_ips as WebDatabase_remote_ips, web_database.backup_interval as WebDatabase_backup_interval, web_database.backup_copies as WebDatabase_backup_copies, web_database.active as WebDatabase_active "
	" FROM web_database" 
	<< (where.size()?" WHERE "+where:"");
	WebDatabaseList webdatabaseList;
	for(row& r: rs)
	{
		WebDatabasePtr webdatabase(new WebDatabase);
		type_conversion<WebDatabase>::from_base(r, i_ok, *webdatabase);
		webdatabaseList.push_back(webdatabase);
	}
	return webdatabaseList;
}

int WebDatabaseRepository::insert(const WebDatabase& webdatabase)
{
	dataBase << "insert into web_database(database_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, parent_domain_id, type, database_name, database_name_prefix, database_quota, last_quota_notification, database_user_id, database_ro_user_id, database_charset, remote_access, remote_ips, backup_interval, backup_copies, active)\
values(:WebDatabase_database_id, :WebDatabase_sys_userid, :WebDatabase_sys_groupid, :WebDatabase_sys_perm_user, :WebDatabase_sys_perm_group, :WebDatabase_sys_perm_other, :WebDatabase_server_id, :WebDatabase_parent_domain_id, :WebDatabase_type, :WebDatabase_database_name, :WebDatabase_database_name_prefix, :WebDatabase_database_quota, :WebDatabase_last_quota_notification, :WebDatabase_database_user_id, :WebDatabase_database_ro_user_id, :WebDatabase_database_charset, :WebDatabase_remote_access, :WebDatabase_remote_ips, :WebDatabase_backup_interval, :WebDatabase_backup_copies, :WebDatabase_active)", use(webdatabase);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void WebDatabaseRepository::remove(const WebDatabase& webdatabase)
{
	dataBase << "DELETE from web_database WHERE database_id=:WebDatabase_database_id AND database_user_id=:WebDatabase_database_user_id AND database_ro_user_id=:WebDatabase_database_ro_user_id", use(webdatabase);
}

void WebDatabaseRepository::update(const WebDatabase& webdatabase)
{
	dataBase << "update web_database set database_id=:WebDatabase_database_id, sys_userid=:WebDatabase_sys_userid, sys_groupid=:WebDatabase_sys_groupid, sys_perm_user=:WebDatabase_sys_perm_user, sys_perm_group=:WebDatabase_sys_perm_group, sys_perm_other=:WebDatabase_sys_perm_other, server_id=:WebDatabase_server_id, parent_domain_id=:WebDatabase_parent_domain_id, type=:WebDatabase_type, database_name=:WebDatabase_database_name, database_name_prefix=:WebDatabase_database_name_prefix, database_quota=:WebDatabase_database_quota, last_quota_notification=:WebDatabase_last_quota_notification, database_user_id=:WebDatabase_database_user_id, database_ro_user_id=:WebDatabase_database_ro_user_id, database_charset=:WebDatabase_database_charset, remote_access=:WebDatabase_remote_access, remote_ips=:WebDatabase_remote_ips, backup_interval=:WebDatabase_backup_interval, backup_copies=:WebDatabase_backup_copies, active=:WebDatabase_active WHERE database_id=:WebDatabase_database_id AND database_user_id=:WebDatabase_database_user_id AND database_ro_user_id=:WebDatabase_database_ro_user_id", use(webdatabase);
}

void WebDatabaseRepository::update(const WebDatabase& oldObj, const WebDatabase& newObj)
{
	dataBase << "update web_database set database_id=:WebDatabase_database_id, sys_userid=:WebDatabase_sys_userid, sys_groupid=:WebDatabase_sys_groupid, sys_perm_user=:WebDatabase_sys_perm_user, sys_perm_group=:WebDatabase_sys_perm_group, sys_perm_other=:WebDatabase_sys_perm_other, server_id=:WebDatabase_server_id, parent_domain_id=:WebDatabase_parent_domain_id, type=:WebDatabase_type, database_name=:WebDatabase_database_name, database_name_prefix=:WebDatabase_database_name_prefix, database_quota=:WebDatabase_database_quota, last_quota_notification=:WebDatabase_last_quota_notification, database_user_id=:WebDatabase_database_user_id, database_ro_user_id=:WebDatabase_database_ro_user_id, database_charset=:WebDatabase_database_charset, remote_access=:WebDatabase_remote_access, remote_ips=:WebDatabase_remote_ips, backup_interval=:WebDatabase_backup_interval, backup_copies=:WebDatabase_backup_copies, active=:WebDatabase_active WHERE database_id='"<<oldObj.getDatabaseId()<<"\'' AND database_user_id='"<<oldObj.getDatabaseUserId()<<"\'' AND database_ro_user_id='"<<oldObj.getDatabaseRoUserId()<<"\'", use(newObj);
}

