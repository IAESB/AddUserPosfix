#include "webdatabaseuserrepository.h"
#include "util.hpp"
WebDatabaseUserRepository::WebDatabaseUserRepository(soci::session& db) : dataBase(db)
{
}

WebDatabaseUserPtr WebDatabaseUserRepository::select(const WebDatabaseUser& obj)
{
	soci::row row;
	WebDatabaseUserPtr webdatabaseuser(new WebDatabaseUser);
	dataBase << "SELECT  web_database_user.database_user_id as WebDatabaseUser_database_user_id, web_database_user.sys_userid as WebDatabaseUser_sys_userid, web_database_user.sys_groupid as WebDatabaseUser_sys_groupid, web_database_user.sys_perm_user as WebDatabaseUser_sys_perm_user, web_database_user.sys_perm_group as WebDatabaseUser_sys_perm_group, web_database_user.sys_perm_other as WebDatabaseUser_sys_perm_other, web_database_user.server_id as WebDatabaseUser_server_id, web_database_user.database_user as WebDatabaseUser_database_user, web_database_user.database_user_prefix as WebDatabaseUser_database_user_prefix, web_database_user.database_password as WebDatabaseUser_database_password, web_database_user.database_password_mongo as WebDatabaseUser_database_password_mongo"
	" FROM web_database_user "
	"WHERE web_database_user.database_user_id = :WebDatabaseUser_database_user_id", into(row), use(obj);
	if(!dataBase.got_data())
		webdatabaseuser.reset();
	else
		type_conversion<WebDatabaseUser>::from_base(row, i_ok, *webdatabaseuser);
	return webdatabaseuser;
}
WebDatabaseUserList WebDatabaseUserRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  web_database_user.database_user_id as WebDatabaseUser_database_user_id, web_database_user.sys_userid as WebDatabaseUser_sys_userid, web_database_user.sys_groupid as WebDatabaseUser_sys_groupid, web_database_user.sys_perm_user as WebDatabaseUser_sys_perm_user, web_database_user.sys_perm_group as WebDatabaseUser_sys_perm_group, web_database_user.sys_perm_other as WebDatabaseUser_sys_perm_other, web_database_user.server_id as WebDatabaseUser_server_id, web_database_user.database_user as WebDatabaseUser_database_user, web_database_user.database_user_prefix as WebDatabaseUser_database_user_prefix, web_database_user.database_password as WebDatabaseUser_database_password, web_database_user.database_password_mongo as WebDatabaseUser_database_password_mongo "
	" FROM web_database_user" 
	<< (where.size()?" WHERE "+where:"");
	WebDatabaseUserList webdatabaseuserList;
	for(row& r: rs)
	{
		WebDatabaseUserPtr webdatabaseuser(new WebDatabaseUser);
		type_conversion<WebDatabaseUser>::from_base(r, i_ok, *webdatabaseuser);
		webdatabaseuserList.push_back(webdatabaseuser);
	}
	return webdatabaseuserList;
}

int WebDatabaseUserRepository::insert(const WebDatabaseUser& webdatabaseuser)
{
	dataBase << "insert into web_database_user(database_user_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, database_user, database_user_prefix, database_password, database_password_mongo)\
values(:WebDatabaseUser_database_user_id, :WebDatabaseUser_sys_userid, :WebDatabaseUser_sys_groupid, :WebDatabaseUser_sys_perm_user, :WebDatabaseUser_sys_perm_group, :WebDatabaseUser_sys_perm_other, :WebDatabaseUser_server_id, :WebDatabaseUser_database_user, :WebDatabaseUser_database_user_prefix, :WebDatabaseUser_database_password, :WebDatabaseUser_database_password_mongo)", use(webdatabaseuser);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void WebDatabaseUserRepository::remove(const WebDatabaseUser& webdatabaseuser)
{
	dataBase << "DELETE from web_database_user WHERE database_user_id=:WebDatabaseUser_database_user_id", use(webdatabaseuser);
}

void WebDatabaseUserRepository::update(const WebDatabaseUser& webdatabaseuser)
{
	dataBase << "update web_database_user set database_user_id=:WebDatabaseUser_database_user_id, sys_userid=:WebDatabaseUser_sys_userid, sys_groupid=:WebDatabaseUser_sys_groupid, sys_perm_user=:WebDatabaseUser_sys_perm_user, sys_perm_group=:WebDatabaseUser_sys_perm_group, sys_perm_other=:WebDatabaseUser_sys_perm_other, server_id=:WebDatabaseUser_server_id, database_user=:WebDatabaseUser_database_user, database_user_prefix=:WebDatabaseUser_database_user_prefix, database_password=:WebDatabaseUser_database_password, database_password_mongo=:WebDatabaseUser_database_password_mongo WHERE database_user_id=:WebDatabaseUser_database_user_id", use(webdatabaseuser);
}

void WebDatabaseUserRepository::update(const WebDatabaseUser& oldObj, const WebDatabaseUser& newObj)
{
	dataBase << "update web_database_user set database_user_id=:WebDatabaseUser_database_user_id, sys_userid=:WebDatabaseUser_sys_userid, sys_groupid=:WebDatabaseUser_sys_groupid, sys_perm_user=:WebDatabaseUser_sys_perm_user, sys_perm_group=:WebDatabaseUser_sys_perm_group, sys_perm_other=:WebDatabaseUser_sys_perm_other, server_id=:WebDatabaseUser_server_id, database_user=:WebDatabaseUser_database_user, database_user_prefix=:WebDatabaseUser_database_user_prefix, database_password=:WebDatabaseUser_database_password, database_password_mongo=:WebDatabaseUser_database_password_mongo WHERE database_user_id='"<<oldObj.getDatabaseUserId()<<"\'", use(newObj);
}

