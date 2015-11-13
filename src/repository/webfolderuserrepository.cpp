#include "webfolderuserrepository.h"
#include "util.hpp"
WebFolderUserRepository::WebFolderUserRepository(soci::session& db) : dataBase(db)
{
}

WebFolderUserPtr WebFolderUserRepository::select(const WebFolderUser& obj)
{
	soci::row row;
	WebFolderUserPtr webfolderuser(new WebFolderUser);
	dataBase << "SELECT  web_folder_user.web_folder_user_id as WebFolderUser_web_folder_user_id, web_folder_user.sys_userid as WebFolderUser_sys_userid, web_folder_user.sys_groupid as WebFolderUser_sys_groupid, web_folder_user.sys_perm_user as WebFolderUser_sys_perm_user, web_folder_user.sys_perm_group as WebFolderUser_sys_perm_group, web_folder_user.sys_perm_other as WebFolderUser_sys_perm_other, web_folder_user.server_id as WebFolderUser_server_id, web_folder_user.web_folder_id as WebFolderUser_web_folder_id, web_folder_user.username as WebFolderUser_username, web_folder_user.password as WebFolderUser_password, web_folder_user.active as WebFolderUser_active"
	" FROM web_folder_user "
	"WHERE web_folder_user.web_folder_user_id = :WebFolderUser_web_folder_user_id", into(row), use(obj);
	if(!dataBase.got_data())
		webfolderuser.reset();
	else
		type_conversion<WebFolderUser>::from_base(row, i_ok, *webfolderuser);
	return webfolderuser;
}
WebFolderUserList WebFolderUserRepository::select(const string& where)
{
	soci::rowset<row> rs = 	dataBase.prepare << "SELECT  web_folder_user.web_folder_user_id as WebFolderUser_web_folder_user_id, web_folder_user.sys_userid as WebFolderUser_sys_userid, web_folder_user.sys_groupid as WebFolderUser_sys_groupid, web_folder_user.sys_perm_user as WebFolderUser_sys_perm_user, web_folder_user.sys_perm_group as WebFolderUser_sys_perm_group, web_folder_user.sys_perm_other as WebFolderUser_sys_perm_other, web_folder_user.server_id as WebFolderUser_server_id, web_folder_user.web_folder_id as WebFolderUser_web_folder_id, web_folder_user.username as WebFolderUser_username, web_folder_user.password as WebFolderUser_password, web_folder_user.active as WebFolderUser_active "
	" FROM web_folder_user" 
	<< (where.size()?" WHERE "+where:"");
	WebFolderUserList webfolderuserList;
	for(row& r: rs)
	{
		WebFolderUserPtr webfolderuser(new WebFolderUser);
		type_conversion<WebFolderUser>::from_base(r, i_ok, *webfolderuser);
		webfolderuserList.push_back(webfolderuser);
	}
	return webfolderuserList;
}

int WebFolderUserRepository::insert(const WebFolderUser& webfolderuser)
{
	dataBase << "insert into web_folder_user(web_folder_user_id, sys_userid, sys_groupid, sys_perm_user, sys_perm_group, sys_perm_other, server_id, web_folder_id, username, password, active)\
values(:WebFolderUser_web_folder_user_id, :WebFolderUser_sys_userid, :WebFolderUser_sys_groupid, :WebFolderUser_sys_perm_user, :WebFolderUser_sys_perm_group, :WebFolderUser_sys_perm_other, :WebFolderUser_server_id, :WebFolderUser_web_folder_id, :WebFolderUser_username, :WebFolderUser_password, :WebFolderUser_active)", use(webfolderuser);
	int id=0;
	dataBase << "SELECT LAST_INSERT_ID()", soci::into(id);
	return id;
}

void WebFolderUserRepository::remove(const WebFolderUser& webfolderuser)
{
	dataBase << "DELETE from web_folder_user WHERE web_folder_user_id=:WebFolderUser_web_folder_user_id", use(webfolderuser);
}

void WebFolderUserRepository::update(const WebFolderUser& webfolderuser)
{
	dataBase << "update web_folder_user set web_folder_user_id=:WebFolderUser_web_folder_user_id, sys_userid=:WebFolderUser_sys_userid, sys_groupid=:WebFolderUser_sys_groupid, sys_perm_user=:WebFolderUser_sys_perm_user, sys_perm_group=:WebFolderUser_sys_perm_group, sys_perm_other=:WebFolderUser_sys_perm_other, server_id=:WebFolderUser_server_id, web_folder_id=:WebFolderUser_web_folder_id, username=:WebFolderUser_username, password=:WebFolderUser_password, active=:WebFolderUser_active WHERE web_folder_user_id=:WebFolderUser_web_folder_user_id", use(webfolderuser);
}

void WebFolderUserRepository::update(const WebFolderUser& oldObj, const WebFolderUser& newObj)
{
	dataBase << "update web_folder_user set web_folder_user_id=:WebFolderUser_web_folder_user_id, sys_userid=:WebFolderUser_sys_userid, sys_groupid=:WebFolderUser_sys_groupid, sys_perm_user=:WebFolderUser_sys_perm_user, sys_perm_group=:WebFolderUser_sys_perm_group, sys_perm_other=:WebFolderUser_sys_perm_other, server_id=:WebFolderUser_server_id, web_folder_id=:WebFolderUser_web_folder_id, username=:WebFolderUser_username, password=:WebFolderUser_password, active=:WebFolderUser_active WHERE web_folder_user_id='"<<oldObj.getWebFolderUserId()<<"\'", use(newObj);
}

